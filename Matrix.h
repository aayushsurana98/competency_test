#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Matrix {
	
	valarray<T> data;
	size_t rows;
	size_t columns;
	
	public:
	Matrix(size_t rows, size_t columns) : data(rows*columns), rows(rows), columns(columns) 	    {assert(rows>0 and columns>0);}

	T operator()(size_t row, size_t col) const
	{
		return data[rows*row + 1*col];
	}

	T& operator()(size_t row, size_t col)
	{
		return data[rows*row + 1*col];
	}

	Matrix& operator+=(const Matrix &rest)
	{
		assert((rows == rest.rows) and (columns == rest.columns));
		data+=rest.data;
		return *this;
	}

	Matrix& operator*=(const Matrix &rest)
	{
		assert(columns == rest.rows);
		data*=rest.data;
		return *this;
	}
		
	~Matrix()
	{
		data.resize(0);
	}

};
	
template<typename T>
Matrix<T> operator+(Matrix<T> a, const Matrix<T>& b)
{
	return a += b;
}

template<typename T>
Matrix<T> operator*(Matrix<T> a, const Matrix<T>& b)
{
	return a *= b;
}
