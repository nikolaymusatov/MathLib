#include "math.h"

long double my_nearbyintl(long double x) {
  int64_t half_res = 2 * x - (int64_t)x;
  long double res = half_res;
  return res;
}

long double my_factorial(long long int x) {
  long double res = 0.0;
  if (x == 1 || x == 0)
    res = 1;
  else
    res = x * my_factorial(x - 1);
  return res;
}

long double my_int_pow(double x, int i) {
  long double res = 1;
  if (i != 0) {
    while (i > 0) {
      res *= x;
      i--;
    }
  }
  return res;
}