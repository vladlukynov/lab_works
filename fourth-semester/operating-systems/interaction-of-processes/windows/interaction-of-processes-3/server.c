#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <stdio.h>

#define BUFF_SIZE 256

int main(int argc, char* argv[])
{
  SOCKET serverSock;
  SOCKET newServerSocket;

  SOCKADDR_IN serverAddr;
  SOCKADDR_IN clientAddr;
  struct hostent* pHostEnt;
  char hostName[64];
  int addrLen = sizeof(serverAddr);

  WSADATA wsaData;

  WORD version = MAKEWORD(2, 2);

  if (WSAStartup(version, &wsaData))
  {
    printf("WSA service failed to initialize with error %d \n", WSAGetLastError());
    exit(1);
  };

  /* Create the socket */
  serverSock = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSock < 0)
  {
    printf("Socket initialization failed with error %d \n", WSAGetLastError());
    exit(1);
  };

  gethostname(hostName, 64);
  pHostEnt = gethostbyname(hostName);
  if (pHostEnt == NULL)
  {
    printf("Can't get host by name.");
    exit(1);
  };

  printf("Server is running on %s \n", hostName);

  /* Связывание сокета */

  memcpy(&serverAddr.sin_addr, pHostEnt->h_addr, 4);
  serverAddr.sin_port = htons(40842);
  serverAddr.sin_family = AF_INET;

  if (bind(serverSock, (SOCKADDR*)&serverAddr, addrLen) != 0)
  {
    printf("Bind failed with error %d \n", WSAGetLastError());
    closesocket(serverSock);
    exit(1);
  };

  /* Сервер слушает */
  if (listen(serverSock, 3))
  {
    printf("Listen failed with error %d \n", WSAGetLastError());
    closesocket(serverSock);
    exit(1);
  };

  /* Установление соединения */
  newServerSocket = accept(serverSock, (SOCKADDR*)&clientAddr, &addrLen);
  if (newServerSocket < 0)
  {
    printf("Accept failed with error %d \n", WSAGetLastError());
    exit(1);
  };
  printf("Successfull connection\n");

  while (TRUE)
  {
    char str[BUFF_SIZE];
    recv(newServerSocket, str, BUFF_SIZE, 0);
    if (strcmp(str, "stop") == 0)
    {
      break;
    }
    printf("%s\n", str);
  }

  closesocket(newServerSocket);

  WSACleanup();
  return 0;
}
