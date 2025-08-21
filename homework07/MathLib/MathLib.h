﻿#pragma once
#include <algorithm>
#include <math.h>
#include <cassert>
#include <iostream>

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);


double power(double base, int exponent); // піднесення до степеня
double squareRoot(double value); // квадратний корінь
double absoluteValue(double value); // абсолютне значення

//Функції з цілими числами :

int factorial(int n); // факторіал числа
bool isPrime(int number); // перевірка чи число просте
int gcd(int a, int b); // найбільший спільний дільник

//Робота з масивами :

double findMax(const double arr[], int size); // максимум масиву
double findMin(const double arr[], int size); // мінімум масиву
double calculateSum(const double arr[], int size); // сума елементів
double calculateAverage(const double arr[], int size); // середнє арифметичне
void sortArray(double arr[], int size); // сортування масиву

//Утилітарні функції :

bool isEven(int number); // перевірка на парність
bool isOdd(int number); // перевірка на непарність
int fibonacci(int n); // n - те число Ф