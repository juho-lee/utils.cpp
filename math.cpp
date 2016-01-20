#include "math.h"

// log(Gamma(x))
// Written by Tom Minka, in lightspeed MATLAB toolbox
// http://research.microsoft.com/en-us/um/people/minka/software/lightspeed/
double LogGamma(double x)
{
    const static double ln_sqrt_2PI = 0.91893853320467274178;
    static double gamma_series[] = {
        76.18009172947146,
        -86.50532032941677,
        24.01409824083091,
        -1.231739572450155,
        0.1208650973866179e-2,
        -0.5395239384953e-5
    };

    int i;
    double denom, x1, series;
    if (x <= 0) return INF;
    if (x == 1 || x == 2) return 0;

    /* Lanczos method */
    denom = x + 1;
    x1 = x + 5.5;
    series = 1.000000000190015;
    for (i = 0; i < 6; i++) {
        series += gamma_series[i] / denom;
        denom += 1.0;
    }
    return (ln_sqrt_2PI + (x + 0.5) * log(x1) - x1 + log(series / x));
}

// copied from https://github.com/Blei-Lab/lda-c/
double DiGamma(double x)
{
	double p;
	x = x + 6;
	p = 1 / (x*x);
	p = (((0.004166666666667*p - 0.003968253986254)*p +
		0.008333333333333)*p - 0.083333333333333)*p;
	p = p + log(x) - 0.5 / x - 1 / (x - 1) - 1 / (x - 2)
		- 1 / (x - 3) - 1 / (x - 4) - 1 / (x - 5) - 1 / (x - 6);
	return p;
}

// copied from https://github.com/Blei-Lab/lda-c/
double TriGamma(double x)
{
	double p;
	int i;

	x = x + 6;
	p = 1 / (x*x);
	p = (((((0.075757575757576*p - 0.033333333333333)*p + 0.0238095238095238)
		*p - 0.033333333333333)*p + 0.166666666666667)*p + 1) / x + 0.5*p;
	for (i = 0; i < 6; i++) {
		x = x - 1;
		p = 1 / (x*x) + p;
	}
	return p;
}

double LogSumExp(double a, double b)
{
    if (a == -INF && b == -INF) return -INF;
    if (a > b) return a + log(1 + exp(b - a));
    else return b + log(1 + exp(a - b));
}
