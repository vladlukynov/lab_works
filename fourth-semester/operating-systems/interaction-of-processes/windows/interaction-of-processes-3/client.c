#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib, "Ws2_32.lib")

#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <Windows.h>

#define BUFF_SIZE 256

int main(int argc, char* argv[])
{
  SOCKET clientSock;

  SOCKADDR_IN serverAddr;
  struct hostent* pHostEnt;
  char clientHostName[64];
  char serverHostName[64];

  WSADATA wsaData;

  WORD version = MAKEWORD(2, 2);

  if (WSAStartup(version, &wsaData))
  {
    printf("WSA service failed to initialize with error % d \n", WSAGetLastError());
    exit(1);
  };

  /* Создаем сокет */
  clientSock = socket(AF_INET, SOCK_STREAM, 0);

  if (clientSock < 0)
  {
    printf("Socket initialization failed \n");
    exit(1);
  };

  /* Определяем адрес хоста */
  gethostname(clientHostName, 64);
  printf("Client is running on %s \n", clientHostName);

  printf("Please, enter server host name: ");
  scanf_s("%s", serverHostName, 64);

  printf("We are going to connect with Server %s \n", serverHostName);

  pHostEnt = gethostbyname(serverHostName);

  if (pHostEnt == NULL)
  {
    printf("Can't get host by name.");
    exit(1);
  };

  /* Соединение с сервером */

  memcpy(&serverAddr.sin_addr, pHostEnt->h_addr, 4);
  serverAddr.sin_port = htons(40842);
  serverAddr.sin_family = AF_INET;

  if (connect(clientSock, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) != 0)
  {
    printf("Connect error. \n");
    closesocket(clientSock);
    exit(1);
  };

  printf("Successfull connection\n");

  while (TRUE)
  {
    char str[BUFF_SIZE];
    printf("Enter message: ");
    scanf_s("%s", str, BUFF_SIZE);
    send(clientSock, str, BUFF_SIZE, 0);
    if (strcmp(str, "stop") == 0)
    {
      break;
    }
  }

  closesocket(clientSock);

  WSACleanup();
  return 0;
}
