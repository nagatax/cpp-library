#ifndef MATH
#define MATH

using math_function = double (*)(double);

std::string convert_base_number(unsigned int target, int base_number);
double differentiate(math_function f, double x, double h = 1e-5);
double differentiate_second(math_function f, double x, double h = 1e-4);
int factorial(int n);
int get_random_number(unsigned int, unsigned int);
bool is_prime(unsigned int);
bool is_leap(const int);

#endif
