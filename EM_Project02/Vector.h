#pragma once
#include<vector>
#include<math.h>
#include<iostream>
#include<fstream>
#include<string>

#define PI 3.14159265358979323846

class Vector
{
public:
	Vector();
	Vector(double);	// initial data x
	Vector(double, double); // initial data x y

	std::vector<double> Data;
	int getDim() const {
		return Data.size();
	}

	void initial(double x, double y);	// initial data
	void initial(double x);		// initial data

	/* Operator Overloading */
	friend Vector operator+(const Vector&, const Vector&);
	friend Vector operator-(const Vector&, const Vector&);
	friend Vector operator*(const Vector&, const Vector&);  // Dot
	friend Vector operator*(const double&, const Vector&);  // Scalar

	/* Method */
	friend Vector Scalar(const Vector&, const Vector&);
	friend double Norm(const Vector&);		//�V�q����
	friend Vector Normal(const Vector&);	// Normalizatioin ����V�q

	friend Vector Cross(const Vector&, const Vector&);		// Cross Product �T���~�n
	friend Vector Comp(const Vector &, const Vector&);		// Component �V�qA�L�g��V�qB������
	friend Vector Proj(const Vector&, const Vector&);		// Projection ���g�v

	friend double TrigArea(const Vector&, const Vector&);	// Triangle Area
	friend bool IsParal(const Vector&, const Vector&);		// Parallrl Judge
	friend bool IsOrthog(const Vector&, const Vector&);		// Orthogonal Judge
	friend double Angle(const Vector&, const Vector&);
};

