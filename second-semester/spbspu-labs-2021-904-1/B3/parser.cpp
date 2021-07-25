#include "parser.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <unordered_map>

Command parseCommand(const std::string &command)
{
  std::istringstream commandStream(command);
  std::string currentCommand;
  commandStream >> currentCommand;
  std::unordered_map<std::string, std::function<Command(std::istringstream &)>> commands
    {
      {"add",    &details::parseAddCommand},
      {"store",  &details::parseStoreCommand},
      {"insert", &details::parseInsertCommand},
      {"delete", &details::parseDeleteCommand},
      {"show",   &details::parseShowCommand},
      {"move",   &details::parseMoveCommand}
    };
  auto commandIterator = commands.find(currentCommand);
  if (commandIterator == commands.end())
  {
    return &details::printInvalidCommand;
  }
  return commandIterator->second(commandStream);
}

Command details::parseAddCommand(std::istringstream &command)
{
  PhoneBook::record_t record;
  if (getNumber(record.number, command) && getName(record.name, command) && !isTrash(command))
  {
    return std::bind(&PhoneBookInterface::add, std::placeholders::_1, record);
  }
  return &printInvalidCommand;
}

Command details::parseStoreCommand(std::istringstream &command)
{
  std::string markName;
  std::string newMarkName;
  if (getMarkName(markName, command) && getMarkName(newMarkName, command) && !isTrash(command))
  {
    return std::bind(&PhoneBookInterface::store, std::placeholders::_1, markName, newMarkName, std::placeholders::_2);
  }
  return &printInvalidCommand;
}

Command details::parseInsertCommand(std::istringstream &command)
{
  std::string position;
  std::string markName;
  PhoneBook::record_t recordToAdd;
  command >> position;
  if (getMarkName(markName, command) && getNumber(recordToAdd.number, command) && getName(recordToAdd.name, command) &&
      !isTrash(command))
  {
    if (position == "before")
    {
      return std::bind(&PhoneBookInterface::insertBefore, std::placeholders::_1, markName, recordToAdd, std::placeholders::_2);
    }
    else if (position == "after")
    {
      return std::bind(&PhoneBookInterface::insertAfter, std::placeholders::_1, markName, recordToAdd, std::placeholders::_2);
    }
  }
  return &printInvalidCommand;
}

Command details::parseDeleteCommand(std::istringstream &command)
{
  std::string markName;
  if (getMarkName(markName, command) && !isTrash(command))
  {
    return std::bind(&PhoneBookInterface::deleteMark, std::placeholders::_1, markName, std::placeholders::_2);
  }
  return &printInvalidCommand;
}

Command details::parseShowCommand(std::istringstream &command)
{
  std::string markName;
  if (getMarkName(markName, command) && !isTrash(command))
  {
    return std::bind(&PhoneBookInterface::show, std::placeholders::_1, markName, std::placeholders::_2);
  }
  return &printInvalidCommand;
}

Command details::parseMoveCommand(std::istringstream &command)
{
  std::string markName;
  std::string steps;
  if (getMarkName(markName, command))
  {
    command >> steps;
    if (steps.empty() || isTrash(command))
    {
      return &printInvalidCommand;
    }
    if (steps == "first")
    {
      return std::bind(&PhoneBookInterface::moveToFirstOrLast, std::placeholders::_1, markName,
          PhoneBookInterface::step_t::first, std::placeholders::_2);
    }
    else if (steps == "last")
    {
      return std::bind(&PhoneBookInterface::moveToFirstOrLast, std::placeholders::_1, markName,
          PhoneBookInterface::step_t::last, std::placeholders::_2);
    }
    else
    {
      std::istringstream tempStream(steps);
      int intSteps = 0;
      tempStream >> intSteps;
      if (!tempStream.fail())
      {
        return std::bind(&PhoneBookInterface::moveOnSteps, std::placeholders::_1, markName, intSteps, std::placeholders::_2);
      }
      return &printInvalidStep;
    }
  }
  return &printInvalidCommand;
}

bool details::getNumber(std::string &number, std::istringstream &stream)
{
  stream >> number;
  if (number.empty())
  {
    return false;
  }
  for (size_t i = 0; i < number.size(); i++)
  {
    if (!isdigit(number[i]))
    {
      return false;
    }
  }
  return true;
}

bool details::getName(std::string &name, std::istringstream &stream)
{
  std::string tempName;
  stream >> std::ws;
  char current;
  bool isEnd = false;
  if (stream.peek() != '\"')
  {
    return false;
  }
  stream.get();
  while ((stream.peek() != EOF) && (stream.peek() != '\n'))
  {
    if (stream.peek() == '\\')
    {
      stream.get(current);
      if ((stream.peek() == '\"') || (stream.peek() == '\\'))
      {
        stream.get(current);
        tempName.push_back(current);
        continue;
      }
      else
      {
        tempName.push_back(current);
        continue;
      }
    }
    else if (stream.peek() == '\"')
    {
      stream.get();
      isEnd = true;
      break;
    }
    else
    {
      stream.get(current);
      tempName.push_back(current);
    }
  }
  if (!isEnd || tempName.empty())
  {
    return false;
  }
  name = tempName;
  return true;
}

bool details::getMarkName(std::string &markName, std::istringstream &stream)
{
  stream >> markName;
  if (markName.empty())
  {
    return false;
  }
  for (size_t i = 0; i < markName.size(); i++)
  {
    if (!isalnum(markName[i]) && (markName[i] != '-'))
    {
      return false;
    }
  }
  return true;
}

bool details::isTrash(std::istringstream &stream)
{
  if (stream.fail())
  {
    throw std::runtime_error("Error reading stream");
  }
  std::string tempString;
  stream >> tempString;
  return !tempString.empty();
}

void details::printInvalidCommand(PhoneBookInterface &, std::ostream &output)
{
  output << "<INVALID COMMAND>\n";
}

void details::printInvalidStep(PhoneBookInterface &, std::ostream &output)
{
  output << "<INVALID STEP>\n";
}
