#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Variable {
	string name;
	double exp;
};

struct Term {
	double coeff;
	vector<Variable>vars;
};

class Equation
{
public:
	Equation();
	vector<Term>equation;
};

