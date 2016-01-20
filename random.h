#pragma once

#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>

// random uniform
double Randu(void);

// random unit normal
double Randn(void);

// random exponential
double RandExp(double lambda);

// random categorical
int RandCat(const std::vector<double> &p);

// random gamma
double RandGamma(double a, double b);

// random beta
double RandBeta(double a, double b);
