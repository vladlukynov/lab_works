#include <iostream>
#include <sstream>

#include "tasks.hpp"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Wrong number of arguments\n";
    return 1;
  }
  std::istringstream stream(argv[1]);
  int taskNumber = 0;
  stream >> taskNumber;
  if (!stream.eof())
  {
    std::cerr << "The argument is not a number\n";
    return 1;
  }
  switch (taskNumber)
  {
    case 1:
    {
      try
      {
        task1(std::cin, std::cout);
        break;
      }
      catch (const std::invalid_argument &error)
      {
        std::cerr << error.what() << "\n";
        return 2;
      }
      catch (const std::logic_error &error)
      {
        std::cerr << error.what() << "\n";
        return 2;
      }
      catch (const std::runtime_error &error)
      {
        std::cerr << error.what() << "\n";
        return 2;
      }
      catch (const std::exception &error)
      {
        std::cerr << error.what() << "\n";
        return 2;
      }
    }
    case 2:
    {
      try
      {
        task2(std::cout);
        break;
      }
      catch (const std::out_of_range &error)
      {
        std::cerr << error.what() << "\n";
        return 2;
      }
      catch (const std::overflow_error &error)
      {
        std::cerr << error.what() << "\n";
        return 2;
      }
      catch (const std::exception &error)
      {
        std::cerr << error.what() << "\n";
        return 2;
      }
    }
    default:
    {
      std::cerr << "Argument must be 1 or 2\n";
      return 1;
    }
  }
  return 0;
}
