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

	if (meetX && meetY) {
		dim = 3;
	}
	else if (meetY) {
		dim = 2;
	}
	else if (meetX) {
		dim = 1;
	}
	else { // No meet
		dim = 0;
	}
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
	double f1 = f(x + threshold, y);
	double f2 = f(x - threshold, y);
	double d = (f1 - f2) / (2 * threshold);

	return d;
	// return ((f(x + threshold, y) - f(x - threshold, y)) / (2 * threshold));
}

double Equation::dY(double x, double y) {
	return ((f(x, y + threshold) - f(x, y - threshold)) / (2 * threshold));
}

Matrix Equation::Gradient(const Vector& X)
{
	Matrix gradient;
	Vector d;

	if (dim == 3) {	// XY
		d.Data.push_back(this->dX(X.Data[0], X.Data[1]));
		d.Data.push_back(this->dY(X.Data[0], X.Data[1]));
	}
	else if (dim == 2) {	// Y
		d.Data.push_back(this->dY(0, X.Data[0]));
	}
	else if (dim == 1) {	// X
		d.Data.push_back(this->dX(X.Data[0], 0));
	}

	gradient.Data.push_back(d);
	return gradient;
}

Matrix Equation::Hessian(const Vector& X)
{
	Matrix hessian;

	if (dim == 3) {	// XY
		double dXX = 0, dYX = 0, dXY = 0, dYY = 0;
		Vector row1, row2;
		dXX = (dX(X.Data[0] + threshold, X.Data[1]) - dX(X.Data[0] - threshold, X.Data[1])) / (2 * threshold);
		dYX = (dY(X.Data[0] + threshold, X.Data[1]) - dY(X.Data[0] - threshold, X.Data[1])) / (2 * threshold);
		dXY = (dX(X.Data[0], X.Data[1] + threshold) - dX(X.Data[0], X.Data[1] - threshold)) / (2 * threshold);
		dYY = (dY(X.Data[0], X.Data[1] + threshold) - dY(X.Data[0], X.Data[1] - threshold)) / (2 * threshold);
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
		dYY = (dY(0, X.Data[0] + threshold) - dY(0, X.Data[0] - threshold)) / (2 * threshold);
		row1.Data.push_back(dYY);
		hessian.Data.push_back(row1);
	}
	else if (dim == 1) {	// X
		Vector row1;
		double dXX = 0;
		dXX = (dX(X.Data[0] + threshold, 0) - dX(X.Data[0] - threshold, 0)) / (2 * threshold);
		row1.Data.push_back(dXX);
		hessian.Data.push_back(row1);
	}

	return hessian;
}

void Equation::Steepest_Descent(double x, double y, double xMin, double xMax, double yMin, double yMax, System::Windows::Forms::TextBox^ Output)
{
	double Precision = 0.001;
	int Max_iter = 500;

	// Initial X Vector and Internal Vector
	Vector Max_X, Min_X;
	if (dim == 3) {
		X.initial(x, y);
		Max_X.initial(xMax, yMax);
		Min_X.initial(xMin, yMin);
	}
	else if (dim == 2) {
		X.initial(y);
		Max_X.initial(yMax);
		Min_X.initial(yMin);
	}
	else if (dim == 1) {
		X.initial(x);
		Max_X.initial(xMax);
		Min_X.initial(xMin);
	}

	Vector pre_x = X, now_x = X;
	Vector step;

	// step 0
	int k = 0;
	while (Max_iter-- > 0) {

		// step 1
		Matrix G = Gradient(now_x);
		Vector gradient = G.Data[0];	// Matrix to Vector

		if (Norm(gradient) == 0) {
			break;
		}
		gradient = -1 * gradient;

		// Not A Number Happened
		while (isnan(gradient.Data[0])) {
			std::cout << " Test ----------------------" << std::endl;
			std::cout << "G = " << gradient.Data[0] << std::endl;
			std::cout << "step = " << step.Data[0] << std::endl;
			step = 0.9 * step;
			std::cout << "step = " << step.Data[0] << std::endl;
			now_x = pre_x + step;
			std::cout << "x = " << now_x.Data[0] << std::endl;

			G = Gradient(now_x);
			gradient = G.Data[0];
			gradient = -1 * gradient;
		}
		pre_x = now_x;
		
		// step 2 : compute step-size lambda
		Matrix L = G * Transpose(G) * Inverse(G * Hessian(pre_x) * Transpose(G));

		Vector lambda = L.Data[0];
		step = lambda * gradient;

		// step 3
		now_x = pre_x + step;

		// step 1: Stopping criteria
		if (Norm(gradient) <= Precision || abs(Norm(pre_x - now_x)) <= Precision || f(pre_x) <= f(now_x) ) {
			break;
		}

		// Edge Dealing
		for (int i = 0; i < now_x.getDim(); i++) {
			while (now_x.Data[i] > Max_X.Data[i] || now_x.Data[i] < Min_X.Data[i]) {
				step = 0.9 * step;
				now_x = pre_x + step;
			}
		}


		// step 4 : output
		k++;
		//pre_x = now_x;

		// print
		std::cout << k << std::endl;
		// print
		for (int i = 0; i < gradient.getDim(); i++) {
			std::cout << "h = " << gradient.Data[i] << std::endl;
		}
		// print
		for (int i = 0; i < lambda.getDim(); i++) {
			std::cout << "Lambda = " << lambda.Data[i] << std::endl;
		}
		// print
		for (int i = 0; i < now_x.getDim(); i++) {
			std::cout << "X = " << now_x.Data[i] << std::endl;
		}

	}

	Output->Text += k.ToString() + System::Environment::NewLine;
	for (int i = 0; i < pre_x.getDim(); i++) {
		Output->Text += pre_x.Data[i].ToString() + ",";
	}
	Output->Text += System::Environment::NewLine + "min = " + f(pre_x).ToString() + System::Environment::NewLine;

}
