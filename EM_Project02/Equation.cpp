#include "Equation.h"

Equation::Equation()
{
}

std::vector<std::string> postfix(std::string str) {
	std::vector<char> stack;
	std::vector<std::string> postfix;
	std::string buff = "";
	for (unsigned int i = 0; i < str.length(); i++) {
		if (i == 0 && str[i] == '-') {
			buff += '-';
		}
		else if (i != 0 && (priority(str[i - 1]) > 0) && str[i] == '-') {
			buff += '-';
		}
		else {
			if (str[i] == '(' || str[i] == ')') {
				if (buff != "") {
					postfix.push_back(buff);
					if (buff == "sin" || buff == "cos" || buff == "tan" || buff == "csc" || buff == "sec" || buff == "tan") {
						stack.push_back('$');
					}
					buff = "";
				}
				if (str[i] == '(') {
					stack.push_back(str[i]);
					continue;
				}
				else {
					while (stack[stack.size() - 1] != '(') {
						buff += stack[stack.size() - 1];
						stack.pop_back();
						postfix.push_back(buff);
						buff = "";
					}
					stack.pop_back();
					if (stack[stack.size() - 1] == '$') {
						buff += stack[stack.size() - 1];
						stack.pop_back();
						postfix.push_back(buff);
						buff = "";
					}
					continue;
				}
			}
			if (str[i] == '-' || str[i] == '+' || str[i] == '*' || str[i] == '^') {
				if (buff != "") {
					postfix.push_back(buff);
					buff = "";
				}
				while ((stack.size() > 0) && (priority(stack[stack.size() - 1]) >= priority(str[i]))) {
					buff += stack[stack.size() - 1];
					stack.pop_back();
					postfix.push_back(buff);
					buff = "";
				}
				stack.push_back(str[i]);
			}
			else {
				buff += str[i];
			}
		}
	}
	while (stack.size() > 0) {
		if (buff != "") {
			postfix.push_back(buff);
			buff = "";
		}
		buff += stack[stack.size() - 1];
		stack.pop_back();
		postfix.push_back(buff);
		buff = "";
	}
	return postfix;
}

int priority(char op) {
	switch (op) {
	case'$':
		return 4;
	case '^':
		return 3;
	case '*':
		return 2;
	case '+':case '-':
		return 1;
	default:
		return 0;
	}
}

void Equation::SetEquation(std::vector<std::string>equ)
{
	equation = equ;

	// calculate dim
	bool meetX = false, meetY = false;
	for (int i = 0; i < equation.size(); i++) {
		if (equation[i] == "x" && !meetX)
			meetX = true;
		else if (equation[i] == "y" && !meetY)
			meetY = true;

		if (meetX && meetY) break; // Terminate Earlier if meet both XY
	}

	if (meetX && meetY)	dim = 3;
	else if (meetY) dim = 2;
	else if (meetX) dim = 1;
	else dim = 0;	// No meet
}

double Equation::goldenSectionSearch(double a, double b, double c, double tau)
{
	double x;
	double resphi = 2 - ((1 + sqrt(5)) / 2);

	if (c - b > b - a) {
		x = b + resphi * (c - b);
	}
	else {
		x = b - resphi * (b - a);
	}

	if (abs(c - a) < tau * (abs(b) + abs(x))) {
		return (c + a) / 2;
	}
	if (f(x, 0) < f(b, 0)) {
		if (c - b > b - a)	return goldenSectionSearch(b, x, c, tau);
		else return goldenSectionSearch(a, x, b, tau);
	}
	else {
		if (c - b > b - a) return goldenSectionSearch(a, b, x, tau);
		else return goldenSectionSearch(x, b, c, tau);
	}
}

double Equation::f(double x, double y) {
	std::vector<double> var;
	double buff = 0;
	std::string temp = "";
	for (unsigned int i = 0; i < equation.size(); i++) {
		if (equation[i] == "x") {
			var.push_back(x);
		}
		else if (equation[i] == "y") {
			var.push_back(y);
		}
		else if (equation[i] == "+") {
			var[var.size() - 2] += var[var.size() - 1];
			var.pop_back();
		}
		else if (equation[i] == "-") {
			var[var.size() - 2] -= var[var.size() - 1];
			var.pop_back();
		}
		else if (equation[i] == "*") {
			var[var.size() - 2] *= var[var.size() - 1];
			var.pop_back();
		}
		else if (equation[i] == "^") {
			var[var.size() - 2] = pow(var[var.size() - 2], var[var.size() - 1]);
			var.pop_back();
		}
		else if (equation[i] == "sin" || equation[i] == "cos" || equation[i] == "tan" || equation[i] == "sec" || equation[i] == "csc" || equation[i] == "cot") {
			temp = equation[i];
		}
		else if (equation[i] == "$") {
			if (temp == "sin") {
				var[var.size() - 1] = sin(var[var.size() - 1]);
			}
			else if (temp == "cos") {
				var[var.size() - 1] = cos(var[var.size() - 1]);
			}
			else if (temp == "tan") {
				var[var.size() - 1] = tan(var[var.size() - 1]);
			}
			else if (temp == "sec") {
				var[var.size() - 1] = 1 / cos(var[var.size() - 1]);
			}
			else if (temp == "csc") {
				var[var.size() - 1] = 1 / sin(var[var.size() - 1]);
			}
			else if (temp == "cot") {
				var[var.size() - 1] = 1 / tan(var[var.size() - 1]);
			}
		}
		else {
			var.push_back(stod(equation[i]));
		}
	}
	if (var.size() == 1) {
		return var[0];
	}
}

double Equation::dX(double x, double y) {
	return ((f(x + threshold, y) - f(x - threshold, y)) / (2 * threshold));
}

double Equation::dY(double x, double y) {
	return ((f(x, y + threshold) - f(x, y - threshold)) / (2 * threshold));
}

Matrix Gradient(double x, double y, Equation F)
{
	Matrix gradient;

	if (F.dim == 3) {	// XY
		Vector dX, dY;
		dX.Data.push_back(F.dX(x, y));
		dY.Data.push_back(F.dY(x, y));
		gradient.Data.push_back(dX);
		gradient.Data.push_back(dY);
	}
	else if (F.dim == 2) {	// Y
		Vector dY;
		dY.Data.push_back(F.dY(x, y));
		gradient.Data.push_back(dY);
	}
	else if (F.dim == 1) {	// X
		Vector dX;
		dX.Data.push_back(F.dX(x, y));
		gradient.Data.push_back(dX);
	}
	else {	// No X Y
		Vector Zero;
		Zero.Data.push_back(0);
		gradient.Data.push_back(Zero);
	}

	return gradient;
}

Matrix Hessian(double x, double y, Equation F)
{
	Matrix hessian;

	if (F.dim == 3) {	// XY
		double dXX = 0, dYX = 0, dXY = 0, dYY = 0;
		Vector row1, row2;
		dXX = (F.dX(x + threshold, y) - F.dX(x - threshold, y)) / (2 * threshold);
		dYX = (F.dY(x + threshold, y) - F.dY(x - threshold, y)) / (2 * threshold);
		dXY = (F.dX(x, y + threshold) - F.dX(x, y - threshold)) / (2 * threshold);
		dYY = (F.dX(x, y + threshold) - F.dX(x, y - threshold)) / (2 * threshold);
		row1.Data.push_back(dXX);
		row1.Data.push_back(dYX);
		row2.Data.push_back(dXY);
		row2.Data.push_back(dYY);
		hessian.Data.push_back(row1);
		hessian.Data.push_back(row2);
	}
	else if (F.dim == 2) {	// Y
		Vector row1;
		double dYY = 0;
		dYY = (F.dX(x, y + threshold) - F.dX(x, y - threshold)) / (2 * threshold);
		row1.Data.push_back(dYY);
		hessian.Data.push_back(row1);
	}
	else if (F.dim == 1) {	// X
		Vector row1;
		double dXX = 0;
		dXX = (F.dX(x + threshold, y) - F.dX(x - threshold, y)) / (2 * threshold);
		row1.Data.push_back(dXX);
		hessian.Data.push_back(row1);
	}
	else {
		Vector Zero;
		Zero.Data.push_back(0);
		hessian.Data.push_back(Zero);
	}

	return hessian;
}

void Equation::Steepest_Descent(double x, double y, double xMin, double xMax, double yMin, double yMax)
{



}
