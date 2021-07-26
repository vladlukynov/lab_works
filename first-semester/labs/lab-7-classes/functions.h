#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "array.h"

void openFile();
void readFile(std::ifstream &fileIn);
int countString(std::ifstream &fileIn);
void cleanData(Array<MyString> &data);
void oldEmployee(Array<EmployeeCard> &employee, int employeeCount);
void printData(Array<EmployeeCard> &employee, int employeeCount);
void outputFile(Array<EmployeeCard> &employee, int employeeCount);

#endif
