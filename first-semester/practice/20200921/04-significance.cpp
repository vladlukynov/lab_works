#include <iostream>
int main()
{
  long int a = 1;
  float b = 1.0;
  while (a == static_cast<int>(b))
  {
    a += 1;
    b = a;
  }
  std::cout << a << " " << static_cast<int>(b);
  return 0;
}

