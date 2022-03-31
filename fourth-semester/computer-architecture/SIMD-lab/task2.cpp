#include <iostream>
#include <xmmintrin.h>
#include <mmintrin.h>
#include <immintrin.h>

int main()
{
  char qw1[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
  char qw2[8] = { 2, 2, 1, 2, 2, 1, 2, 2 };

  char a128[4] = { 5, 7, 3, 19 };
  char b128[4] = { 4, 2, 19, 4 };

  float c[4] = { 1, 2, 3, 4 };
  float d[4] = { 5, 6, 7, 8 };

  __m64 m64 = _mm_add_pi8(*(__m64*)(qw1), *(__m64*)(qw2));
  __m128 m128 = _mm_or_ps(*(__m128*)(a128), *(__m128*)(b128));
  __m256 m256 = _mm256_add_ps(*(__m256*)(c), *(__m256*)(d));

  char* array1 = (char*)&m64;
  char* array2 = (char*)&m128;
  float* array3 = (float*)&m256;

  _mm_empty();

  std::cout << "m64\n";
  for (int i = 0; i < 8; i++)
  {
    std::cout << (int)array1[i] << " ";
  }
  std::cout << "\n\n";

  std::cout << "m128\n";
  for (int i = 0; i < 4; i++)
  {
    std::cout << (int)array2[i] << " ";
  }
  std::cout << "\n\n";

  std::cout << "m256\n";
  for (int i = 0; i < 4; i++)
  {
    std::cout << (int)array3[i] << " ";
  }
  std::cout << "\n\n";

  return 0;
}
