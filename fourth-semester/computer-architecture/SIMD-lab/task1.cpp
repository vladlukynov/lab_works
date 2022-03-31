#include <iostream>
#include <xmmintrin.h>
#include <mmintrin.h>
#include <immintrin.h>

int main()
{
  std::cout << "MMX\n";
  char qw1[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
  char qw2[8] = { 2, 2, 1, 2, 2, 1, 2, 2 };

  _asm
  {
    movq mm0, qw1
    movq mm1, qw2
    pcmpeqb mm0, mm1
    movq qw1, mm0
  }
  _mm_empty();

  std::cout << "Comparing elements for equality\n";
  for (int i = 0; i < 8; i++)
  {
    std::cout << (qw1[i] & 0x1 ? "true" : "false") << "\t";
  }
  std::cout << "\n\n";

  std::cout << "SSE1\n";
  float c[4] = { 1, 7, 3, 2 };
  float d[4] = { 5, 3, 1, 3 };
  _asm
  {
    movups xmm0, c
    movups xmm1, d
    subps xmm0, xmm1
    movups c, xmm0
  }

  std::cout << "Subtracting elements\n";
  for (int i = 0; i < 4; i++)
  {
    std::cout << c[i] << " ";
  }
  std::cout << "\n\n";


  std::cout << "SSE2\n";
  std::cout << "Finding the largest number\n";
  double f[2] = { 4, 36 };

  _asm
  {
    movups xmm1, f
    maxpd xmm0, xmm1
    movups f, xmm0
  }
  std::cout << "The largest number: " <<  f[0];
  std::cout << "\n\n";


  std::cout << "AVX\n";
  std::cout << "Multiply elements\n";
  double a128[4] = { 3, 18, 3, 19 };
  double b128[4] = { 17, 2, 19, 4 };
  _asm
  {
    vmovups ymm0, a128
    vmovups ymm1, b128
    vmulpd ymm3, ymm0, ymm1
    vmovups a128, ymm3
  }

  for (int i = 0; i < 4; i++)
  {
   std::cout << a128[i] << " ";
  }
  std::cout << "\n\n";
  
  return 0;
}
