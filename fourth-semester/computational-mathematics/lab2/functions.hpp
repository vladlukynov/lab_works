#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>

void initEMatrix(std::vector<std::vector<double>> &matrix, int N);
void printMatrix(const std::vector<std::vector<double>> &matrix, int N);
void countInverseMatrix(const std::vector<std::vector<double>> &matrix,
                        const std::vector<std::vector<double>> &E,
                        std::vector<std::vector<double>> &result,
                        int N, double &condValue);
void multiplyMatrices(const std::vector<std::vector<double>> &matrix1,
                      const std::vector<std::vector<double>> &matrix2,
                      std::vector<std::vector<double>> &result, int N);
void subtractMatrices(const std::vector<std::vector<double>> &matrix1,
                      const std::vector<std::vector<double>> &matrix2,
                      std::vector<std::vector<double>> &result, int N);
double calculateRate(const std::vector<std::vector<double>> &matrix, int N);

#endif
