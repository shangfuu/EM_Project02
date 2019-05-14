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

double Equation::f(const Vector& xy)
{
	std::vector<double> var;
	double buff = 0;
	std::string temp = "";
	for (unsigned int i = 0; i < equation.size(); i++) {
		if (equation[i] == "x") {
			var.push_back(xy.Data[0]);
		}
		else if (equation[i] == "y") {
			var.push_back(xy.Data[1]);
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

Matrix Equation::Gradient(double x, double y)
{
	Matrix gradient;

	if (dim == 3) {	// XY
		Vector dX, dY;
		dX.Data.push_back(this->dX(x, y));
		dY.Data.push_back(this->dY(x, y));
		gradient.Data.push_back(dX);
		gradient.Data.push_back(dY);
	}
	else if (dim == 2) {	// Y
		Vector dY;
		dY.Data.push_back(this->dY(x, y));
		gradient.Data.push_back(dY);
	}
	else if (dim == 1) {	// X
		Vector dX;
		dX.Data.push_back(this->dX(x, y));
		gradient.Data.push_back(dX);
	}
	else {	// No X Y
		Vector Zero;
		Zero.Data.push_back(0);
		gradient.Data.push_back(Zero);
	}

	return gradient;
}

Matrix Equation::Hessian(double x, double y)
{
	Matrix hessian;

	if (dim == 3) {	// XY
		double dXX = 0, dYX = 0, dXY = 0, dYY = 0;
		Vector row1, row2;
		dXX = (dX(x + threshold, y) - dX(x - threshold, y)) / (2 * threshold);
		dYX = (dY(x + threshold, y) - dY(x - threshold, y)) / (2 * threshold);
		dXY = (dX(x, y + threshold) - dX(x, y - threshold)) / (2 * threshold);
		dYY = (dX(x, y + threshold) - dX(x, y - threshold)) / (2 * threshold);
		row1.Data.push_back(dXX);
		row1.Data.push_back(dYX);
		row2.Data.push_back(dXY);
		row2.Data.push_back(dYY);
		hessian.Data.push_back(row1);
		hessian.Data.push_back(row2);
	}
	else if (dim == 2) {	// Y
		Vector row1;
		double dYY = 0;
		dYY = (dX(x, y + threshold) - dX(x, y - threshold)) / (2 * threshold);
		row1.Data.push_back(dYY);
		hessian.Data.push_back(row1);
	}
	else if (dim == 1) {	// X
		Vector row1;
		double dXX = 0;
		dXX = (dX(x + threshold, y) - dX(x - threshold, y)) / (2 * threshold);
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

void Equation::Steepest_Descent(double x, double y, double xMin, double xMax, double yMin, double yMax, System::Windows::Forms::TextBox^ Output)
{
	double Precision = 0.0001;
	int Max_iter = 500;

	// double next_x = x, now_x = x;
	Vector next_x(x), now_x(x);
	next_x.Data.push_back(y);
	now_x.Data.push_back(y);

	// step 0
	int k = 0;
	

	while (Max_iter-- < 0) {
		Vector gradient = Gradient(x, y).Data[0];	// Matrix to Vector

		// step 1: Stopping criteria
		if (Norm(gradient) <= Precision || abs(Norm(next_x - now_x)) <= Precision || f(next_x) > f(now_x) ) {
			break;
		}

		// step 2 : compute step-size lambda: using backtracking
		Vector lambda(1);	// size always 1 equals double
		double c = 0.001;
		while (f(now_x - lambda*gradient) > f(now_x) - c * lambda.Data[0] * pow(Norm(gradient),2)) {
			lambda.Data[0] = lambda.Data[0] * 0.5;
		}
		now_x = next_x;
		// step 3
		next_x = now_x - lambda * gradient;
		k++;
	}


}
