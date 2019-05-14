#include "Vector.h"
// #define ANNOTATION

Vector::Vector()
{
}

Vector operator + (const Vector& x, const Vector& y) {
	Vector buff;
	for (int i = 0; i < x.Data.size(); i++) {
		buff.Data.push_back(x.Data[i] + y.Data[i]);
	}
	return buff;
}

Vector operator - (const Vector& x, const Vector& y) {
	Vector buff;
	for (int i = 0; i < x.Data.size(); i++) {
		buff.Data.push_back(x.Data[i] - y.Data[i]);
	}
	return buff;
}

Vector operator *(const Vector& x, const Vector& y) {
	Vector tmp;
	double dot = 0;

	for (int i = 0; i < x.Data.size(); i++) {
		dot += (x.Data[i] * y.Data[i]);
	}
	tmp.Data.push_back(dot);
	return tmp;
}

Vector Scalar(const Vector& vec1, const Vector& vec2) {
	Vector vec, scal;
	if (vec1.getDim() == 1 && vec2.getDim() != 1) {
		vec = vec2;
		scal = vec1;
	}
	else {
		vec = vec1;
		scal = vec2;
	}
	for (int i = 0; i < vec.getDim(); i++) {
		vec.Data[i] = vec.Data[i] * scal.Data[0];
	}
	return vec;
}

double Norm(const Vector& x) {
	double sum = 0;
	for (int i = 0; i < x.getDim(); i++) {
		sum += pow(x.Data[i], 2);
	}
	sum = sqrt(sum);
	return sum;
}

Vector Normal(const Vector& x) {
	Vector buff;
	for (int i = 0; i < x.getDim(); i++) {
		buff.Data.push_back(x.Data[i] / Norm(x));
	}
	return buff;
}

Vector Cross(const Vector& u, const Vector& v) {
	Vector vec;
	double i = (u.Data[1] * v.Data[2]) - (u.Data[2] * v.Data[1]);
	vec.Data.push_back(i);
	double j = -(1.0) * ((u.Data[0] * v.Data[2]) - (u.Data[2] * v.Data[0]));
	vec.Data.push_back(j);
	double k = (u.Data[0] * v.Data[1]) - (u.Data[1] * v.Data[0]);
	vec.Data.push_back(k);

	return vec;
}

Vector Comp(const Vector& x, const Vector& y) {
	Vector vec = x * y;
	vec.Data[0] = vec.Data[0] / Norm(y);
	return vec;
}

Vector Proj(const Vector& x, const Vector& y) {
	Vector comp = Comp(x, y);
	Vector normal = Normal(y);
	Vector vec = Scalar(comp, normal);
	return vec;
}

double TrigArea(const Vector& x, const Vector& y) {
	Vector tmp = x * y;
	double XdotY = tmp.Data[0];
	double ans = (sqrt(pow(Norm(x)*Norm(y), 2) - pow(XdotY, 2))) / 2;
	return ans;
}

bool IsParal(const Vector& x, const Vector& y) {

	if (x.getDim() != y.getDim()) return false;
	if (Norm(x) == 0 || Norm(y) == 0) return false;

	double length = Norm(x)*Norm(y) * sin(Angle(x, y)*PI / 180);
	if (length == 0) {
		return true;
	}
	return false;
}

bool IsOrthog(const Vector& x, const Vector& y) {
	Vector tmp = x * y;
	if (tmp.Data[0] == 0) 	return true;
	else	return false;
}

double Angle(const Vector& x, const Vector& y) {
	Vector tmp = x * y;
	double XdotY = tmp.Data[0];
	double cosv = XdotY / (Norm(x) * Norm(y));
	return (acos(cosv) * 180 / PI);
}

std::vector<Vector> Ob(const std::vector<Vector>& x) {
	std::vector<Vector> buff;
	buff.push_back(Normal(x[0]));

	for (int i = 1; i < x.size(); i++) {
		Vector temp = x[i];
		for (int j = 0; j < i; j++) {
			temp = temp - Proj(temp, buff[j]);
		}
		buff.push_back(Normal(temp));
	}
	return buff;
}
