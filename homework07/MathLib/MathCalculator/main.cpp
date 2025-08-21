#include "MathLib.h"
#include <iostream>

void waitForAnswer() {
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore();
	std::cin.get();
}

void clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

int main() {

	int demoType;
	do {
		std::cout << "\n\nOperation type:" << std::endl;
		std::cout << "1. Basic ariphmetic functions" << std::endl;
		std::cout << "2. Math functions" << std::endl;
		std::cout << "3. Int number functions" << std::endl;
		std::cout << "4. Array functions" << std::endl;
		std::cout << "5. Utility functions" << std::endl;
		std::cout << "0. Back to Main Menu" << std::endl;


		while (1) {
			std::cout << "\nPlase enter which type of operation(from 1 to 5) you want to do: ";
			std::cin >> demoType;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				continue;
			}
			if (demoType <= 0 || demoType > 5)
				continue;

			break;
		}
		


		std::cout << demoType;

		switch (demoType)
		{
		case 0:
			clearScreen();
			std::cout << "Thank you for exploring using my library!" << std::endl;
			break;
			
		case 1: {
			std::cout << "\nBasic ariphmetic functions\nPlease enter two numbers:";
			int a{}, b{};
			std::cout << "\nA: ";
			std::cin >> a;
			std::cout << "\nB: ";
			std::cin >> b;

			std::cout << "\nAdd: " << add(a, b)
				<< "\nSubstract: " << subtract(a, b)
				<< "\nMultiply: " << multiply(a, b)
				<< "\nDivision:" << divide(a, b);
			break;

		}
		case 2: {
			std::cout << "\nMath functions\n";
			for (int i = 0; i < 10; i++)
			{
				std::cout << "\nI: " << i << " in " << i << " exponent = " << power(i, i);
				std::cout << "\nSquare root of " << i << " = " << squareRoot(i);
				std::cout << "\nAbsolute value of " << -1 * i << " = " << absoluteValue(-1 * i);
			}
			break;
		}
		case 3: {
			std::cout << "\nInt number functions\n";
			for (int i = 0; i < 10; i++)
			{
				std::cout << "\nFactorial of " << i << " : " << factorial(i);
				std::cout << "\nIs number " << i << " prime: ";
				if (isPrime(i))
					std::cout << "YES\n";
				std::cout << "probably not :c\n";
				std::cout << "\nGreatest divisor of " << i * 12 << " and " << i * 5 << " is: "
					<< gcd(i * 12, i * 5) << std::endl;
			}
			break;
		}
		case 4: {
			std::cout << "\nArray functions\n";
			double testArr[]{ 23.65, 12.45, 45.34,45.37,0.01, 7.5,76.56,109.00,2.1,3.5 };
			int size = 10;
			std::cout << "\nmax: " << findMax(testArr, size);
			std::cout << "\nmin: " << findMin(testArr, size);
			std::cout << "\nsum: " << calculateSum(testArr, size);
			std::cout << "\navg: " << calculateAverage(testArr, size);
			std::cout << "\nsorting array...\nbefore:\n";
			for (auto& i : testArr)
			{
				std::cout << " " << i;
			}
			sortArray(testArr, size);
			std::cout << "\nafter:\n";
			for (auto& i : testArr)
			{
				std::cout << " " << i;
			}
			break;
		}
		case 5: {
			std::cout << "\nUtility functions\n";
			for (int i = 0; i < 10; i++)
			{
				if (isEven(i))
					std::cout << "\n" << i << " is even";
				if (isOdd(i))
					std::cout << "\n" << i << " is odd";
				std::cout << "\nFibo-number under position " << i << " is: " << fibonacci(i);
			}
			break;
		}
		default: 
			std::cout << "Invalid choice!" << std::endl;
			waitForAnswer();
		}

	} while (demoType != 0);
	
	

	return 0;
}

