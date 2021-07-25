#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

#include "tasks.hpp"

int main(int argc, char *argv[])
{
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  if (argc != 1)
  {
    std::stringstream input(argv[1]);
    int typeOfTask = 0;
    input >> typeOfTask;
    if (!input.eof())
    {
      std::cerr << "Error first argument";
      return 1;
    }
    switch (typeOfTask)
    {
      case 1:
      {
        try
        {
          if (argc >= 3)
          {
            task1(getTypeOfSort(argv[2]));
          }
          else
          {
            std::cerr << "Insufficient arguments for 1 task";
            return 1;
          }
        }
        catch (std::invalid_argument &exception)
        {
          std::cerr << exception.what() << "\n";
          return 1;
        }
        catch (std::runtime_error &exception)
        {
          std::cerr << exception.what() << "\n";
          return 2;
        }
        break;
      }
      case 2:
      {
        try
        {
          if (argc >= 3)
          {
            task2(argv[2]);
          }
          else
          {
            std::cerr << "Insufficient arguments for 2 task";
            return 1;
          }
        }
        catch (std::invalid_argument &exception)
        {
          std::cerr << exception.what() << "\n";
          return 1;
        }
        catch (std::runtime_error &exception)
        {
          std::cerr << exception.what() << "\n";
          return 2;
        }
        catch (std::bad_alloc &)
        {
          std::cerr << "bad_alloc" << "\n";
          return 2;
        }
        break;
      }
      case 3:
      {
        try
        {
          if (argc >= 2)
          {
            task3();
          }
          else
          {
            std::cerr << "Insufficient arguments for 3 task";
            return 1;
          }
        }
        catch (std::invalid_argument &exception)
        {
          std::cerr << exception.what() << "\n";
          return 1;
        }
        catch (std::runtime_error &exception)
        {
          std::cerr << exception.what() << "\n";
          return 2;
        }
        break;
      }
      case 4:
      {
        try
        {
          if (argc >= 4)
          {
            std::stringstream sizeStream(argv[3]);
            int size(0);
            sizeStream >> size;
            if (sizeStream.eof())
            {
              task4(getTypeOfSort(argv[2]), size);
            }
            else
            {
              std::cerr << "Incorrect size argument";
              return 1;
            }
          }
          else
          {
            std::cerr << "Insufficient arguments for 4 task";
            return 1;
          }
        }
        catch (std::invalid_argument &exception)
        {
          std::cerr << exception.what() << "\n";
          return 1;
        }
        catch (std::runtime_error &exception)
        {
          std::cerr << exception.what() << "\n";
          return 2;
        }
        break;
      }
      default:
      {
        std::cerr << "First argument is not valid";
        return 1;
      }
    }
  }
  else
  {
    std::cerr << "No arguments";
    return 1;
  }
  return 0;
}
