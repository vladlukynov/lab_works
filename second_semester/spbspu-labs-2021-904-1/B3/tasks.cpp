#include "tasks.hpp"

#include <algorithm>
#include <string>
#include <sstream>

#include "phonebook-interface.hpp"
#include "parser.hpp"
#include "factorial-container.hpp"

void task1(std::istream &input, std::ostream &output)
{
  PhoneBookInterface phoneBookInterface;
  std::string command;
  while (std::getline(input, command))
  {
    Command executeCommand = parseCommand(command);
    executeCommand(phoneBookInterface, output);
  }
}

void task2(std::ostream &output)
{
  FactorialContainer container(10);
  std::copy(container.begin(), container.end(), std::ostream_iterator<size_t>(output, " "));
  output << "\n";
  std::copy(container.rbegin(), container.rend(), std::ostream_iterator<size_t>(output, " "));
  output << "\n";
}
