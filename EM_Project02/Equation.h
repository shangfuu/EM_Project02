#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Matrix.h"
#define threshold 10E-7
#define tau 1E-5

class Equation {
public:	

	Equation();

	/* Method */
	double goldenSectionSearch(double, double, double, Vector);	// a, b, c, index, mode	
	double f(double, double);
	double f(const Vector&);
	double dX(double, double);
	double dY(double, double);
	Matrix Gradient(const Vector& X);
	Matrix Hessian(const Vector& X);

	/* Optimization Method */
	void Powell(double, double, double, double, double, double, System::Windows::Forms::TextBox^ Output);
	void Steepest_Descent(double x, double y, double xMin, double xMax, double yMin, double yMax, System::Windows::Forms::TextBox^);

	/* Extra Method */
	friend std::vector<std::string> postfix(std::string);	// postfix
	void SetEquation(std::vector<std::string>);

	/* Member */
	std::vector<std::string> equation;
	int dim;	// Only x return 1, Only Y return 2, Both return 3, No meet return 0
	Vector X;	// X Y put in this Vector	e.g X = < x, y >
	std::vector<double> sorting(std::vector<double>);
};

int priority(char);
double compare(double max, double min, double x);
double resphi = 2 - ((1 + sqrt(5)) / 2);