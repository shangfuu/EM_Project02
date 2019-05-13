#pragma once
#include <iostream>
#include <string>
#include <vector>
#define threshold 10E-8

class Equation {
public:	

	/* Method */
	double goldenSectionSearch(double, double, double, double);
	double f(double);
	double f(double, double);
	double differentationX(double, double);
	double differentationY(double, double);

	/* Optimization Method */


	/* Extra Method */
	friend std::vector<std::string> postfix(std::string);	// postfix
	void SetEquation(std::vector<std::string>);

	/* Member */
	std::vector<std::string> equation;

};
int priority(char);
