#include "math.h"

int my_abs(int x) { return x < 0 ? -x : x; }

long double my_acos(double x) { return -my_asin(x) + MY_PI / 2; }

long double my_asin(double x) {
  long double res = 0;
  if (x == 1)
    res = MY_PI / 2;
  else if (x == -1)
    res = -MY_PI / 2;
  else if (x > -1 && x < 1) {
    if (my_fabs(x) < 0.5) {
      long double res_1 = 40;
      for (int i = 0; my_fabs(res - res_1) > MY_EPS; i++) {
        res_1 = res;
        res += my_int_pow(x, 2 * i + 1) *
               (my_factorial(2 * i) / (my_int_pow(4, i) * my_factorial(i) *
                                       my_factorial(i) * (2 * i + 1)));
      }
    } else {
      res = MY_PI / 2 - 2 * my_asin(my_sqrt((1 - x) / 2));
    }
  } else {
    res = MY_NAN;
  }
  return res;
}

long double my_atan(double x) {
  long double result = MY_NAN;
  int sign;
  if (x >= 0) {
    sign = 1;
  } else {
    x *= -1;
    sign = -1;
  }
  if (x == x) {
    if (my_fabs(x) != MY_INF && x < 1e7) {
      result = my_asin(x / my_pow(1 + x * x, 0.5)) * sign;
    } else {
      result = MY_PI / 2 * sign;
    }
  }
  return result;
}

long double my_ceil(double x) {
  long double res = 0.0;
  if (x == MY_INF || x == -MY_INF)
    res = x;
  else if (x != x)
    res = MY_NAN;
  else
    res = (int64_t)x;
  return res < x ? (long double)(res + 1) : (long double)res;
}

long double my_cos(double x) {
  long double res;
  if (x == MY_INF || x == -MY_INF || x != x) {
    res = MY_NAN;
  } else {
    x = my_fmod(x, 2 * MY_PI);
    res = 1;
    long double res_1 = 40;
    for (int i = 1; my_fabs(res - res_1) > MY_EPS; i++) {
      res_1 = res;
      res += my_int_pow(-1.0, i) * my_int_pow(x, i * 2) / my_factorial(2 * i);
    }
  }
  return res;
}

long double my_exp(double x) {
  long double res = 1;
  long double res_1 = 0;
  for (int i = 1; my_fabs(res - res_1) > MY_EPS; i++) {
    res_1 = res;
    res += my_int_pow(my_fabs(x), i) / my_factorial(i);
  }
  if (x < 0) res = 1 / res;
  return res;
}

long double my_fabs(double x) {
  return x < 0 ? (long double)-x : (long double)x;
}

long double my_floor(double x) {
  long double res = 0.0;
  if (x == MY_INF || x == -MY_INF)
    res = x;
  else if (x != x)
    res = MY_NAN;
  else
    res = (int64_t)x;
  return res > x ? (long double)(res - 1) : (long double)res;
}

long double my_fmod(double x, double y) {
  long double res;
  if (x != x || x == MY_INF || x == -MY_INF || y != y || y == 0.0)
    res = MY_NAN;
  else
    res = (long double)(x - (int64_t)(x / y) * y);
  return res;
}

long double my_log(double x) {
  long double res = 0;
  if (x == MY_INF)
    res = x;
  else if (x == 0)
    res = MY_INF;
  else if (x > 0) {
    long double res_1 = -10;
    int e_power = 0;
    while (x > MY_E) {
      x /= MY_E;
      e_power++;
    }
    while (my_fabs(res - res_1) > MY_EPS) {
      res_1 = res;
      res = res + 2 * (x - my_exp(res)) / (x + my_exp(res));
    }
    res += e_power;
  } else {
    res = MY_NAN;
  }
  return res;
}

long double my_pow(double base, double exp) {
  long double res;
  if (base == 1)
    res = 1;
  else if (base == 0)
    res = 0;
  else if (my_fabs(base) == MY_INF)
    res = MY_INF;
  else {
    if (my_nearbyintl(exp) == exp) {
      res = my_int_pow(base, exp);
    } else {
      if (base < 0 && my_fabs(base) != MY_INF)
        res = MY_NAN;
      else
        res = my_exp(exp * my_log(base));
    }
  }
  return res;
}

long double my_sin(double x) {
  long double res;
  if (x == MY_INF || x == -MY_INF || x != x)
    res = MY_NAN;
  else {
    x = my_fmod(x, 2 * MY_PI);
    res = 0;
    long double res_1 = 1;
    for (int i = 1; my_fabs(res - res_1) > MY_EPS; i++) {
      res_1 = res;
      res += my_int_pow(-1.0, i - 1) * my_int_pow(x, i * 2 - 1) /
             my_factorial(2 * i - 1);
    }
  }
  return res;
}

long double my_tan(double x) {
  long double res;
  if (x == MY_INF || x == -MY_INF || x != x)
    res = MY_NAN;
  else {
    x = my_fmod(x, 2 * MY_PI);
    res = my_sin(x) / my_cos(x);
  }
  return res;
}

long double my_sqrt(double x) {
  long double res;
  if (x != x || x == -MY_INF || x < 0) {
    res = MY_NAN;
  } else {
    if (x == MY_INF || x == 0)
      res = x;
    else
      res = my_pow(x, 0.5);
  }
  return res;
}
