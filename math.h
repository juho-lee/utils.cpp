#pragma once

#include <cmath>

#ifdef _WIN32
#if _MSC_VER >= 1800
#define INF INFINITY
#else
#include <limits>
#define INF std::numeric_limits<double>::infinity()
#endif
#else
#define INF INFINITY
#endif

#define PI 3.141592653589793238462

// log(Gamma(x))
// Written by Tom Minka, in lightspeed MATLAB toolbox
// http://research.microsoft.com/en-us/um/people/minka/software/lightspeed/
double LogGamma(double x);

// first derivative of log(Gamma(x))
// copied from https://github.com/Blei-Lab/lda-c/
double DiGamma(double x);

// second derivative of log(Gamma(x))
// copied from https://github.com/Blei-Lab/lda-c/
double TriGamma(double x);

// log(exp(a) + exp(b))
double LogSumExp(double a, double b);
