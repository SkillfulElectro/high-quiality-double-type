#include "Fraction.h"
#include <cmath>

std::ostream& operator<<(std::ostream& os
	, const Fraction alpha) {
	return os << alpha.numerator << '/' <<
		alpha.denominator << '\n';
}

/*
	o o
	o o
*/
int Fraction::power(int base, int times) {
	int holder{ base };
	for (int i{ 0 }; i < times - 1; ++i) {
		base *= holder;
	}
	return base;
}

Fraction operator*(const Fraction& first
	, const Fraction& second) 
{
	int number_holder{ first.denominator };
	int count_first{ 0 };
	for (; number_holder != 0; ++count_first) {
		number_holder /= 10;
	}

	number_holder = second.denominator;
	int count_second{ 0 };
	for (; number_holder != 0; ++count_second) {
		number_holder /= 10;
	}

	int num1{ (static_cast<int>(first.numerator
		* pow(10,count_first)))
		+ first.denominator }
		, num2{ (static_cast<int>(second.numerator
			* pow(10,count_second)))
		+ second.denominator };
	
	long long int mult{ num1 * num2 };
	int frac{ count_first + count_second };
	
	return { static_cast<int>(mult / pow(10,frac))
		,static_cast<int>(mult %
		Fraction::power(10,frac)) };
}

Fraction operator*(const int& first
	, const Fraction& second) {
	int number_holder = second.denominator;
	int count_second{ 0 };
	for (; number_holder != 0; ++count_second) {
		number_holder /= 10;
	}

	long long int num{ (static_cast<int>(second.numerator
			* pow(10,count_second)))
		+ second.denominator };

	num *= first;
	return { static_cast<int>(num / pow(10,count_second))
		,static_cast<int>(num %
		Fraction::power(10,count_second)) };
}

Fraction operator*(const Fraction& first
	, const int& second) {
	return second * first;
}
