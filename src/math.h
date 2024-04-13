#ifndef SRC_MATH_H_
#define SRC_MATH_H_
#define MY_EPS 1e-9
#define MY_PI 3.14159265358979323846264338327950288
#define MY_E 2.7182818284590452353602874713526624
#define MY_INF 1.0 / 0.0
#define MY_NAN 0.0 / 0.0

#include <stdint.h>
#include <stdio.h>

int my_abs(int x);
long double my_acos(double x);
long double my_asin(double x);
long double my_atan(double x);
long double my_ceil(double x);
long double my_cos(double x);
long double my_exp(double x);
long double my_fabs(double x);
long double my_floor(double x);
long double my_fmod(double x, double y);
long double my_log(double x);
long double my_pow(double base, double exp);
long double my_sin(double x);
long double my_sqrt(double x);
long double my_tan(double x);
long double my_nearbyintl(long double x);
long double my_factorial(long long int x);
long double my_int_pow(double x, int i);

#endif  //  SRC_MATH_H_
