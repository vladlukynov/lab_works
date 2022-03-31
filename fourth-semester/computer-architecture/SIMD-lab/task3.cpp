#include <iostream>
#include <xmmintrin.h>
#include <mmintrin.h>
#include <immintrin.h>
#include <dvec.h>

int main()
{
  char a128[4] = { 3, 7, 3, 19 };
  char b128[4] = { 3, 2, 19, 4 };

  I16vec8 vec1(*(__m128i*) & a128);
  I16vec8 vec2(*(__m128i*) & b128);
  I16vec8 vec3 = vec1 + vec2;

  char* array1 = (char*)&vec3;

  std::cout << "dvec\n";
  for (int i = 0; i < 4; i++)
  {
    std::cout << (int)array1[i] << " ";
  }
  std::cout << "\n";

  return 0;
}
