#ifndef TASKS_HPP
#define TASKS_HPP

void countIntegral(double* argArray, double* resArray);
double createLagrange(double x, int N, const double *x_, const double *f);
double countSpline(int N, double* x, double* f, double U);

#endif
