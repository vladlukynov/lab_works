#ifndef PARSER_HPP
#define PARSER_HPP

#include <functional>

#include "phonebook-interface.hpp"

using Command = std::function<void(PhoneBookInterface &, std::ostream &)>;

Command parseCommand(const std::string &command);

namespace details
{
  Command parseAddCommand(std::istringstream &command);
  Command parseStoreCommand(std::istringstream &command);
  Command parseInsertCommand(std::istringstream &command);
  Command parseDeleteCommand(std::istringstream &command);
  Command parseShowCommand(std::istringstream &command);
  Command parseMoveCommand(std::istringstream &command);

  bool getNumber(std::string &number, std::istringstream &stream);
  bool getName(std::string &name, std::istringstream &stream);
  bool getMarkName(std::string &markName, std::istringstream &stream);
  bool isTrash(std::istringstream &stream);

  void printInvalidCommand(PhoneBookInterface &, std::ostream &output);
  void printInvalidStep(PhoneBookInterface &, std::ostream &output);
}

#endif
