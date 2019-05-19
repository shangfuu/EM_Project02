#include "Matrix.h"

Matrix::Matrix()
{
}

Matrix::Matrix(std::vector<Vector>matrix)
{
	this->Data = matrix;
}

Matrix::Matrix(const Vector &v)
{
	this->Data.push_back(v);
}

void Matrix::identity(const Vector &v)
{
	if (v.getDim() == 2) {
		Vector row1(1, 0), row2(0, 1);
		Data.push_back(row1);
		Data.push_back(row2);
	}
	else if (v.getDim() == 1) {
		Vector tmp(1);
		Data.push_back(tmp);
	}
}

Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	Matrix mat;
	for (int i = 0; i < m1.getRow(); i++) {
		mat.Data.push_back(m1.Data[i] + m2.Data[i]);
	}
	return mat;
}

Matrix operator-(const Matrix & m1, const Matrix & m2)
{
	Matrix mat;
	for (int i = 0; i < m1.getRow(); i++) {
		mat.Data.push_back(m1.Data[i] - m2.Data[i]);
	}
	return mat;
}

Matrix operator*(const Matrix & m1, const Matrix & m2)
{
	Matrix mat;
	if (m1.getCol() == 1 && m1.getRow() == 1) {
		mat = m2;
		for (int i = 0; i < mat.Data.size(); i++) {
			for (int j = 0; j < mat.Data[i].Data.size(); j++) {
				mat.Data[i] = Scalar(mat.Data[i], m1.Data[0]);
			}
		}
	}
	else if (m2.getCol() == 1 && m2.getRow() == 1) {
		mat = m1;
		for (int i = 0; i < mat.Data.size(); i++) {
			for (int j = 0; j < mat.Data[i].Data.size(); j++) {
				mat.Data[i] = Scalar(mat.Data[i], m1.Data[0]);
			}
		}
	}
	else {
		mat.Data.resize(m1.getRow());
		for (int i = 0; i < m1.getRow(); i++) {
			mat.Data[i].Data.resize(m2.getCol());
			for (int j = 0; j < m2.getCol(); j++) {
				for (int k = 0; k < m1.getCol(); k++) {
					mat.Data[i].Data[j] += m1.Data[i].Data[k] * m2.Data[k].Data[j];
				}
			}
		}
	}

	return mat;
}

Matrix operator*(const double & num, const Matrix & m)
{
	Matrix mat = m;
	for (int i = 0; i < mat.getRow(); i++) {
		for (int j = 0; j < mat.getCol(); j++) {
			mat.Data[i].Data[j] = num * mat.Data[i].Data[j];
		}
	}
	return mat;
}

Matrix Scalar(const Matrix& m, const Matrix& m1) {
	Matrix mat = m;
	for (int i = 0; i < m.Data.size(); i++) {
		for (int j = 0; j < m.Data[i].Data.size(); j++) {
			mat.Data[i] = Scalar(mat.Data[i], m1.Data[0]);
		}
	}
	return mat;
}

int Matrix::Rank() const
{
	Matrix mat = U_Triangle(*this);
	int cnt = 0;
	for (int i = 0; i < mat.getRow(); i++) {
		for (int j = 0; j < mat.getCol(); j++) {
			if (mat.Data[i].Data[j] != 0) {
				cnt++;
				break;
			}
		}
	}
	return cnt;
}

Matrix Transpose(const Matrix& m) {
	Matrix mat;
	mat.Data.resize(m.getCol());
	for (int i = 0; i < m.getCol(); i++) {
		mat.Data[i].Data.resize(m.getRow());
		for (int j = 0; j < m.getRow(); j++) {
			mat.Data[i].Data[j] = m.Data[j].Data[i];
		}
	}
	return mat;
}

Matrix U_Triangle(const Matrix& m) {
	Matrix mat = m;
	for (int i = 0; i < mat.getRow(); i++) {
		if (i + 1 <= mat.getCol()) {
			if (mat.Data[i].Data[i] != 0) {
				for (int j = i + 1; j < mat.getRow(); j++) {
					double scalar = mat.Data[j].Data[i] / mat.Data[i].Data[i];
					for (int k = 0; k < mat.Data[j].Data.size(); k++) {
						mat.Data[j].Data[k] -= mat.Data[i].Data[k] * scalar;
						if (abs(mat.Data[j].Data[k]) < 0.00000001) {
							mat.Data[j].Data[k] = 0;
						}
					}
				}
			}
			else {
				bool nfind = true;
				for (int j = i + 1; j < mat.getRow(); j++) {
					if (mat.Data[j].Data[i] != 0) {
						Vector flag = mat.Data[j];
						mat.Data[j] = mat.Data[i];
						mat.Data[i] = flag;
						nfind = false;
						break;
					}
				}
				if (nfind) {
				}
				else {
					for (int j = i + 1; j < mat.getRow(); j++) {
						double scalar = mat.Data[j].Data[i] / mat.Data[i].Data[i];
						for (int k = 0; k < mat.Data[j].Data.size(); k++) {
							mat.Data[j].Data[k] -= mat.Data[i].Data[k] * scalar;
							if (abs(mat.Data[j].Data[k]) < 0.00000001) {
								mat.Data[j].Data[k] = 0;
							}
						}
					}
				}
			}
		}
	}
	return mat;
}

Matrix Inverse(const Matrix& m) {
	Matrix mat = m;
	Matrix idm = m;
	for (int i = 0; i < m.getRow(); i++) {
		for (int j = 0; j < m.getCol(); j++) {
			if (i == j) {
				idm.Data[i].Data[j] = 1;
			}
			else {
				idm.Data[i].Data[j] = 0;
			}
		}
	}
	for (int i = 0; i < mat.getRow(); i++) {
		if (mat.Data[i].Data[i] != 0) {
			for (int j = i + 1; j < mat.getRow(); j++) {
				double scalar = mat.Data[j].Data[i] / mat.Data[i].Data[i];
				for (int k = 0; k < mat.Data[j].Data.size(); k++) {
					mat.Data[j].Data[k] -= mat.Data[i].Data[k] * scalar;
					idm.Data[j].Data[k] -= idm.Data[i].Data[k] * scalar;
					if (abs(mat.Data[j].Data[k]) < 0.00000001) {
						mat.Data[j].Data[k] = 0;
					}
				}
			}
		}
		else {
			bool nfind = true;
			for (int j = i + 1; j < mat.getRow(); j++) {
				if (mat.Data[j].Data[i] != 0) {
					Vector flag = mat.Data[j];
					mat.Data[j] = mat.Data[i];
					mat.Data[i] = flag;
					flag = idm.Data[j];
					idm.Data[j] = idm.Data[i];
					idm.Data[i] = flag;
					nfind = false;
					break;
				}
			}
			if (nfind) {
				break;
			}
			for (int j = i + 1; j < mat.getRow(); j++) {
				double scalar = mat.Data[j].Data[i] / mat.Data[i].Data[i];
				for (int k = 0; k < mat.Data[j].Data.size(); k++) {
					mat.Data[j].Data[k] -= mat.Data[i].Data[k] * scalar;
					idm.Data[j].Data[k] -= idm.Data[i].Data[k] * scalar;
					if (abs(mat.Data[j].Data[k]) < 0.00000001) {
						mat.Data[j].Data[k] = 0;
					}
				}
			}
		}
	}
	for (int i = m.getRow() - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (mat.Data[i].Data[i] == 0) {
				for (int k = 0; k < m.getRow(); k++) {
					for (int l = 0; l < m.getCol(); l++) {
						idm.Data[k].Data[l] = INFINITY;
					}
				}
				return idm;
			}
			double scalar = mat.Data[j].Data[i] / mat.Data[i].Data[i];
			for (int k = 0; k < mat.Data[j].Data.size(); k++) {
				mat.Data[j].Data[k] -= mat.Data[i].Data[k] * scalar;
				idm.Data[j].Data[k] -= idm.Data[i].Data[k] * scalar;
				if (abs(mat.Data[j].Data[k]) < 0.00000001) {
					mat.Data[j].Data[k] = 0;
				}
			}
		}
	}
	for (int i = 0; i < m.getRow(); i++) {
		for (int j = 0; j < mat.Data[i].Data.size(); j++) {
			idm.Data[i].Data[j] = idm.Data[i].Data[j] / mat.Data[i].Data[i];
		}
	}
	return idm;
}

double Determinant(const Matrix& m)
{
	Matrix mat = m;
	for (int i = 0; i < mat.Data.size(); i++)
	{
		if (mat.Data[i].Data[i] == 0) {
			for (int j = i + 1; j < mat.Data.size(); j++) {
				if (mat.Data[j].Data[i] != 0)
				{
					Vector flag = mat.Data[j];
					mat.Data[j] = mat.Data[i];
					mat.Data[i] = flag;
					break;
				}
			}
		}
		for (int j = i + 1; j < mat.Data.size(); j++)
			if (mat.Data[j].Data[i] != 0)
			{
				double n = mat.Data[j].Data[i] / mat.Data[i].Data[i];
				for (int k = i; k < mat.Data[i].Data.size(); k++)
				{
					mat.Data[j].Data[k] -= mat.Data[i].Data[k] * n;
					if (abs(mat.Data[j].Data[k]) < 0.00000001) {
						mat.Data[j].Data[k] = 0;
					}
				}
			}
	}
	double det = 1;
	for (int i = 0; i < mat.Data.size(); i++)
	{
		det *= mat.Data[i].Data[i];
	}
	return det;
}

Matrix Adjoint(const Matrix& m) {
	Matrix mat = Inverse(m);
	if (Determinant(m) != 0) {
		double det = Determinant(m);
		for (int i = 0; i < mat.getRow(); i++) {
			for (int j = 0; j < mat.Data[i].Data.size(); j++) {
				mat.Data[i].Data[j] *= det;
			}
		}
	}
	return mat;
}
