#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Matrix {
	
	valarray<T> data;
	size_t rows;
	
	public:
	Matrix(size_t rows, size_t columns) : data(rows*columns), rows(rows) 	    {assert(rows>0 and columns>0);}

	T operator()(size_t row, size_t col) const
	{
		return data[rows*row + 1*col];
	}

	T& operator()(size_t row, size_t col)
	{
		return data[rows*row + 1*col];
	}
	
	~Matrix(){
		data.resize(0);
	}
	
};

int main()
{
	Matrix<int> m1(2,2);

	m1(0,0) = 1; m1(0,1) = 2;
	m1(1,0) = 3; m1(1,1) = 4;

	cout<<endl;

	cout<<m1(0,0)<<" "<<m1(0,1)<<endl;
	cout<<m1(1,0)<<" "<<m1(1,1)<<endl;
	
	cout<<endl;

	Matrix<long long int> m2(2,2);

	m2(0,0) = 1e+18; m2(0,1) = 2;
	m2(1,0) = 3e+16; m2(1,1) = -177e+15;
	
	cout<<m2(0,0)<<" "<<m2(0,1)<<endl;
	cout<<m2(1,0)<<" "<<m2(1,1)<<endl;

	cout<<endl;

	Matrix<float> m3(2,2);

	m3(0,0) = 1.5; m3(0,1) = 2.9;
	m3(1,0) = -3.2; m3(1,1) = 4;
	
	cout<<m3(0,0)<<" "<<m3(0,1)<<endl;
	cout<<m3(1,0)<<" "<<m3(1,1)<<endl;

	return 0;
}
