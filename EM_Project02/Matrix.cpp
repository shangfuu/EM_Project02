#include "Matrix.h"

Matrix::Matrix()
{
}

Matrix::Matrix(std::vector<Vector>matrix)
{
	this->Data = matrix;
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
	mat.Data.resize(m1.getRow());
	for (int i = 0; i < m1.getRow(); i++) {
		mat.Data[i].Data.resize(m2.getCol());
		for (int j = 0; j < m2.getCol(); j++) {
			for (int k = 0; k < m1.getCol(); k++) {
				mat.Data[i].Data[j] += m1.Data[i].Data[k] * m2.Data[k].Data[j];
			}
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

Matrix Copy(const Matrix& m) {
	Matrix mat;
	int flag = 0;
	for (int i = 0; i < m.getRow(); i++) {
		if (m.Data[i].Data[0] == 1) {
			flag = i;
			break;
		}
		if (m.Data[i].Data[0] == 0 && i != m.getRow() - 1) {
			flag++;
		}
	}
	mat.Data.push_back(m.Data[flag]);
	for (int i = 0; i < m.getRow(); i++) {
		if (i != flag) {
			mat.Data.push_back(m.Data[i]);
		}
	}
	return mat;
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
	Matrix mat = Copy(m);
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

Matrix Solve_Linear_System(const Matrix& m1, const Matrix& m2) {
	Matrix mat = (Inverse(m1)*m2);
	return mat;
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

Vector FindK(const Matrix& m, int n) {
	Matrix mat = m;
	Vector v;
	v.Data.resize(n);
	for (int i = mat.Data.size() - 1; i >= 0; i--) {
		if (mat.Data[i].Data[i] == 0) {
			v.Data[i] = 1;
			if (i != mat.Data.size() - 1) {
				for (int j = i + 1; j < mat.Data[i].Data.size(); j++) {
					if (mat.Data[i].Data[j] != 0) {
						v.Data[j] = 0;
					}
				}
			}
		}
		else {
			v.Data[i] = 0;
			if (i != mat.Data.size() - 1) {
				double sum = 0;
				for (int j = mat.Data.size() - 1; j >= i; j--) {
					if (j == i) {
						v.Data[j] = sum / mat.Data[i].Data[i] * -1;
					}
					else {
						sum += v.Data[j] * mat.Data[i].Data[j];
					}
				}
			}
		}
	}
	return v;
}

Matrix Eigen(const Matrix& m) {
	Matrix mat = m;
	Matrix buff;
	Vector v;
	double rrr = 0, rr = 0, r = 0, con = 0;
	if (mat.getRow() == 2) {
		con += (mat.Data[0].Data[0] * mat.Data[1].Data[1] - mat.Data[1].Data[0] * mat.Data[0].Data[1]);
		r += (mat.Data[0].Data[0] * -1 + mat.Data[1].Data[1] * -1);
		rr = 1;
		double x1, x2;
		x1 = (-1 * r + sqrt(pow(r, 2) - rr * con * 4)) / (2 * rr);
		x2 = (-1 * r - sqrt(pow(r, 2) - rr * con * 4)) / (2 * rr);
		v.Data.resize(2);
		v.Data[0] = x1;
		v.Data[1] = 0;
		buff.Data.push_back(v);
		v.Data[0] = 0;
		v.Data[1] = x2;
		buff.Data.push_back(v);
		Matrix m1 = mat, m2 = mat;
		for (int i = 0; i < 2; i++) {
			m1.Data[i].Data[i] -= x1;
			m2.Data[i].Data[i] -= x2;
		}
		m1 = U_Triangle(m1);
		if (m1.Data[0].Data[0] == 0) {
			v.Data[0] = 1;
			v.Data[1] = v.Data[0] * m1.Data[0].Data[0] / m1.Data[0].Data[1] * -1;
			if (m1.Data[0].Data[1] == 0) {
				v.Data[1] = 0;
			}
		}
		else {
			if (m1.Data[0].Data[1] != 0) {
				v.Data[0] = 1;
				v.Data[1] = v.Data[0] * m1.Data[0].Data[0] / m1.Data[0].Data[1] * -1;
			}
			else {
				v.Data[0] = 0;
				v.Data[1] = 1;
			}
		}
		v = Normal(v);
		buff.Data.push_back(v);
		if (x1 == x2) {
			return Transpose(buff);
		}
		m2 = U_Triangle(m2);
		if (m2.Data[0].Data[0] == 0) {
			v.Data[0] = 1;
			v.Data[1] = v.Data[0] * m2.Data[0].Data[0] / m2.Data[0].Data[1] * -1;
			if (m2.Data[0].Data[1] == 0) {
				v.Data[1] = 0;
			}
		}
		else {
			if (m2.Data[0].Data[1] != 0) {
				v.Data[0] = 1;
				v.Data[1] = v.Data[0] * m2.Data[0].Data[0] / m2.Data[0].Data[1] * -1;
			}
			else {
				v.Data[0] = 0;
				v.Data[1] = 1;
			}
		}
		v = Normal(v);
		buff.Data.push_back(v);
		return Transpose(buff);
	}
	else if (mat.getRow() == 3) {
		con = -1 * Determinant(mat);
		r = -1 * ((mat.Data[0].Data[0] * mat.Data[1].Data[1] * -1) + ((mat.Data[0].Data[0] + mat.Data[1].Data[1]) * -1 * mat.Data[2].Data[2]) - (mat.Data[0].Data[2] * mat.Data[2].Data[0] * -1) - (mat.Data[0].Data[1] * mat.Data[1].Data[0] * -1) - (mat.Data[1].Data[2] * mat.Data[2].Data[1] * -1));
		rr = -1 * (mat.Data[2].Data[2] + mat.Data[0].Data[0] + mat.Data[1].Data[1]);
		rrr = 1;
		double x1, x2, x3, q, w, ang;
		q = (pow(rr, 2) - 3 * r) / 9;
		w = (2 * pow(rr, 3) - 9 * rr*r + 27 * con) / 54;
		if (pow(w, 2) >= pow(q, 3)) {
			Matrix err;
			return err;
		}
		ang = acos(w / sqrt(pow(q, 3)));
		x1 = -2 * sqrt(q)*cos(ang / 3) - rr / 3;
		if (abs(x1) < 0.00000001) {
			x1 = 0;
		}
		x2 = -2 * sqrt(q)*cos((ang + 2 * PI) / 3) - rr / 3;
		if (abs(x2) < 0.00000001) {
			x2 = 0;
		}
		x3 = -2 * sqrt(q)*cos((ang - 2 * PI) / 3) - rr / 3;
		if (abs(x3) < 0.00000001) {
			x3 = 0;
		}
		v.Data.resize(3);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j == i) {
					if (i == 0) {
						v.Data[i] = x1;
					}
					else if (i == 1) {
						v.Data[i] = x2;
					}
					else {
						v.Data[i] = x3;
					}
				}
				else {
					v.Data[j] = 0;
				}
			}
			buff.Data.push_back(v);
		}
		Matrix m1 = mat, m2 = mat, m3 = mat;
		for (int i = 0; i < mat.getRow(); i++) {
			for (int j = 0; j < mat.getCol(); j++) {
				if (i == j) {
					m1.Data[i].Data[j] -= x1;
					m2.Data[i].Data[j] -= x2;
					m3.Data[i].Data[j] -= x3;
				}
			}
		}
		m1 = U_Triangle(m1);
		buff.Data.push_back(Normal(FindK(m1, 3)));
		if (x1 != x2) {
			if (x2 != x3) {
				m2 = U_Triangle(m2);
				buff.Data.push_back(Normal(FindK(m2, 3)));
			}
		}
		if (x2 != x3) {
			if (x3 != x1) {
				m3 = U_Triangle(m3);
				buff.Data.push_back(Normal(FindK(m3, 3)));
			}
		}
		return (Transpose(buff));
	}
}

Matrix LeastSquare(const Matrix& m1, const Matrix & m2) {
	return (Inverse(Transpose(m1)*m1)*Transpose(m1)*m2);
}

std::vector<Vector> Power_Method(const Matrix& m) {
	Matrix mat;
	Matrix X;
	X.Data.resize(m.Data.size());
	for (int i = 0; i < m.Data.size(); i++) {
		X.Data[i].Data.resize(1);
		X.Data[i].Data[0] = 1;
	}
	mat = m;
	for (int r = 0; r < 2000; r++) {
		X = mat * X;
		double scalar = X.Data[0].Data[0];
		int loc = 0;
		for (int i = 1; i < X.Data.size(); i++) {
			if (abs(X.Data[i].Data[0]) > abs(scalar)) {
				loc = i;
				scalar = X.Data[i].Data[0];
			}
		}
		for (int i = 0; i < X.Data.size(); i++) {
			if (i == loc) {
				X.Data[i].Data[0] = 1;
			}
			else {
				X.Data[i].Data[0] /= scalar;
			}
		}
	}
	mat = mat * X;
	double d = 0, s = 0;
	for (int i = 0; i < mat.Data.size(); i++) {
		d += mat.Data[i].Data[0] * X.Data[i].Data[0];
		s += X.Data[i].Data[0] * X.Data[i].Data[0];
	}
	Vector eigenvalue;
	double val = d / s;
	eigenvalue.Data.push_back(val);
	mat = m;
	for (int i = 0; i < mat.Data.size(); i++) {
		mat.Data[i].Data[i] -= val;
	}
	mat = U_Triangle(mat);
	Vector v;
	v.Data.resize(mat.Data.size());
	for (int i = mat.Data.size() - 1; i >= 0; i--) {
		if (mat.Data[i].Data[i] == 0) {
			v.Data[i] = 1;
			if (i != mat.Data.size() - 1) {
				for (int j = i + 1; j < mat.Data[i].Data.size(); j++) {
					if (mat.Data[i].Data[j] != 0) {
						v.Data[j] = 0;
					}
				}
			}
		}
		else {
			v.Data[i] = 0;
			if (i != mat.Data.size() - 1) {
				double sum = 0;
				for (int j = mat.Data.size() - 1; j >= i; j--) {
					if (j == i) {
						v.Data[j] = sum / mat.Data[i].Data[i] * -1;
					}
					else {
						sum += v.Data[j] * mat.Data[i].Data[j];
					}
				}
			}
		}
	}
	v = Normal(v);
	std::vector<Vector>eig;
	eig.push_back(eigenvalue);
	eig.push_back(v);
	return eig;
}


bool IsLI(const Matrix& m) {
	// 應該要Call Matrix做
	if (m.Rank() != m.getRow()) {
		return false;
	}
	else {
		return true;
	}
}