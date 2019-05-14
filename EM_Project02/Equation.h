#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Matrix.h"
#define threshold 10E-8

class Equation {
public:	

	/* Method */
	double goldenSectionSearch(double, double, double, double);
	double f(double, double);
	double dX(double, double);
	double dY(double, double);
	Matrix Gradient();
	Matrix Hessian();

	/* Optimization Method */
	void Steepest_Descent(double x, double y, double xMin, double xMax, double yMin, double yMax);	// Example Call


	/* Extra Method */
	friend std::vector<std::string> postfix(std::string);	// postfix
	void SetEquation(std::vector<std::string>);

	/* Member */
	std::vector<std::string> equation;
};

int priority(char);
