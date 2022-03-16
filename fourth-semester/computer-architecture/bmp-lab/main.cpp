#include <iostream>
#include <Windows.h>

int main()
{
  const char* inName = "input1.bmp";
  const char* outName = "output1.bmp";

  std::cout << std::hex;
  std::remove(outName);

  BITMAPFILEHEADER bmpFile;
  BITMAPINFOHEADER bmpInfo;
  DWORD RW;
  HANDLE input;
  HANDLE output;
  RGBQUAD palette[16];
  BYTE* inBuf;
  RGBTRIPLE* outBuf;

  input = CreateFile(inName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
  output = CreateFile(outName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);

  ReadFile(input, &bmpFile, sizeof(bmpFile), &RW, NULL);
  ReadFile(input, &bmpInfo, sizeof(bmpInfo), &RW, NULL);
  ReadFile(input, palette, sizeof(RGBQUAD) * 16, &RW, NULL);

  SetFilePointer(input, bmpFile.bfOffBits, NULL, FILE_BEGIN);

  int width = bmpInfo.biWidth;
  int height = bmpInfo.biHeight;

  inBuf = new BYTE[width / 2];
  outBuf = new RGBTRIPLE[width];

  bmpFile.bfOffBits = sizeof(bmpFile) + sizeof(bmpInfo);
  bmpInfo.biBitCount = 24;
  bmpFile.bfSize = bmpFile.bfOffBits + 3 * width * height + height * (width % 4);

  WriteFile(output, &bmpFile, sizeof(bmpFile), &RW, NULL);
  WriteFile(output, &bmpInfo, sizeof(bmpInfo), &RW, NULL);

  for (int i = 0; i < height; i++)
  {
    ReadFile(input, inBuf, sizeof(BYTE) * (width / 2), &RW, NULL);

    int pixel = 0;
    for (int i = 0; i < width / 2; i++)
    {
      outBuf[pixel].rgbtRed = palette[inBuf[i] >> 4].rgbRed;
      outBuf[pixel].rgbtGreen = palette[inBuf[i] >> 4].rgbGreen;
      outBuf[pixel].rgbtBlue = palette[inBuf[i] >> 4].rgbBlue;
      pixel++;

      outBuf[pixel].rgbtRed = palette[inBuf[i] & 0xF].rgbRed;
      outBuf[pixel].rgbtGreen = palette[inBuf[i] & 0xF].rgbGreen;
      outBuf[pixel].rgbtBlue = palette[inBuf[i] & 0xF].rgbBlue;
      pixel++;
    }
    WriteFile(output, outBuf, sizeof(RGBTRIPLE) * width, &RW, NULL);

    WriteFile(output, palette, width % 4, &RW, NULL);

    SetFilePointer(input, (3 * width) % 4, NULL, FILE_CURRENT);
  }

  CloseHandle(input);
  delete[] inBuf;
  delete[] outBuf;

  return 0;
}
