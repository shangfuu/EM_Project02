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
	std::vector<double> Data;
	int getDim() const {
		return Data.size();
	}

	/* Operator Overloading */
	friend Vector operator+(const Vector&, const Vector&);
	friend Vector operator-(const Vector&, const Vector&);
	friend Vector operator*(const Vector&, const Vector&);  // Dot

	/* Method */
	friend Vector Scalar(const Vector&, const Vector&);
	friend double Norm(const Vector&);		//向量長度
	friend Vector Normal(const Vector&);	// Normalizatioin 轉單位向量

	friend Vector Cross(const Vector&, const Vector&);		// Cross Product 三維外積
	friend Vector Comp(const Vector &, const Vector&);		// Component 向量A印射到向量B的長度
	friend Vector Proj(const Vector&, const Vector&);		// Projection 正射影

	friend double TrigArea(const Vector&, const Vector&);	// Triangle Area
	friend bool IsParal(const Vector&, const Vector&);		// Parallrl Judge
	friend bool IsOrthog(const Vector&, const Vector&);		// Orthogonal Judge
	friend double Angle(const Vector&, const Vector&);
	friend std::vector<Vector> Ob(const std::vector<Vector>&);		// Gram–Schmidt Orthogonalization Process
};

