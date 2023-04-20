#pragma once
#include <iostream>

class Fraction
{
	int numerator;
	int denominator;

	static int power(int base,int times);
public:
	Fraction(int numerator, int demoninator) {
		this->numerator = numerator;
		this->denominator = demoninator;
	}
	friend std::ostream& operator<<(std::ostream&
		,const Fraction);
	friend Fraction operator*(const Fraction& first
		, const Fraction& second);
	friend Fraction operator*(const int& first
		, const Fraction& second);
	friend Fraction operator*(const Fraction& first
		, const int& second);
};

