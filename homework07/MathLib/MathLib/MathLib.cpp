// MathLib.cpp : Defines the functions for the static library.


#include "MathLib.h"


double add(double a, double b)
{
	return a + b;
}

double subtract(double a, double b)
{
	return a - b;
}

double multiply(double a, double b)
{
	return a * b;
}

double divide(double a, double b)
{
	assert(b > 0);
	return a / b; // division by 0
}

double power(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	
	double result = base; 
	
	for (size_t i = 1; i < exponent; i++)
	{
		result *= base;
	}
	return result;
}

double squareRoot(double value)
{
	return sqrt(value);
}

double absoluteValue(double value)
{
	return abs(value);
}

int factorial(int n)
{
	int result = 1;
	for (int i = n; i > 1; i--)
	{
		result *= i;
	}

	return result;
}

bool isPrime(int number)
{

	int cnt = 0;

	// If number is less than/equal to 1,
	// it is not prime
	if (number <= 1)
		return false;
	else {

		// Count the divisors of n
		for (int i = 1; i <= number; i++) {
			if (number % i == 0)
				cnt++;
		}

		// If n is divisible by more than 2 
		// numbers then it is not prime
		if (cnt > 2)
			return false;

		// else it is prime
		else
			return true;
	}
	return true;;
}

int gcd(int a, int b)
{
	
	if (a == 0 || b == 0) {
		std::cout << "One of numbers is 0";
		return 0;
	}
	int greater = 0;
	int lower = 0;

	if (a > b) {
		greater = a;
		lower = b;
	}
	else {
		greater = b;
		lower = a;
	}

	int maxDivisor = 1;
	for (int i = lower; i > 0; i--)
	{
		if (((a % i) == 0) && ((b % i) == 0))
			return i;
	}
	return maxDivisor;
}

double findMax(const double arr[], int size)
{
	double maxValue = *arr;

	for (size_t i = 0; i < size; i++)
	{
		(arr[i] > maxValue) ? maxValue = arr[i] : maxValue;
	}
	return  maxValue;
}

double findMin(const double arr[], int size)
{
	double minValue = *arr;

	for (size_t i = 0; i < size; i++)
	{
		(arr[i] < minValue) ? minValue = arr[i] : minValue;
	}
	return  minValue;
}

double calculateSum(const double arr[], int size)
{
	double sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

double calculateAverage(const double arr[], int size)
{
	double sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum / size;
	
}

void sortArray(double arr[], int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		size_t lesserIndex = i;
		for (size_t j = i + 1; j < size; j++) {
			if (arr[j] < arr[lesserIndex])
				lesserIndex = j;
		}
		std::swap(arr[i], arr[lesserIndex]);
	}
}

bool isEven(int number)
{
	return ((number % 2) == 0);
}

bool isOdd(int number)
{
	return !((number % 2) == 0);
}

int fibonacci(int n)
{
	if (n <= 1)
		return n;
	
	if (n > 1) {

		return fibonacci(n - 1) + fibonacci(n - 2);
	}
		
}

