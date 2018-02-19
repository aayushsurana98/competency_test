#include <bits/stdc++.h>

using namespace std;

template <typename T>
class MatrixExp {

	public:

		double operator[](size_t i) const { return static_cast<T const&>(*this)[i]; }

		size_t size()               const { return static_cast<T const&>(*this).size(); }

		operator T& () { return static_cast<T&>(*this); }

		operator const T& () const { return static_cast<const T&>(*this); }

};

class Matrix : public MatrixExp<Matrix> {
	valarray<double> data;
	public:
	double operator[](size_t i) const { return data[i]; }
	double &operator[](size_t i)      { return data[i]; }
	size_t size() const               { return data.size(); }
	
	//data[] contains the matrix elements in the form of 1-D vector
	//data[0] stores the number of rows
	
	double operator()(size_t row, size_t col) const{
		return data[data[0]*row + col + 1];
	}

	double& operator()(size_t row, size_t col){
		return data[data[0]*row + col + 1];
	}

	Matrix(size_t n, size_t m) : data(n*m + 1){assert(n>0 and m>0);data[0] = n;}


	//the addition operation occurs only at the destination when in is reached hence, no memory overhead cost

	template <typename T>
	inline Matrix &operator+=(const MatrixExp<T> &X) {
		this->data[0] = X[0];
		for(int i = 1; i < X.size(); i++) {
			this->data[i] = this->data[i] + X[i];
			cout<<i<<" "<<data[i]<<endl;
		}
		return *this;
	}

	template <typename T>
	inline Matrix &operator=(const MatrixExp<T> &X) {
		this->data[0] = X[0];
		for(int i = 1; i < X.size(); i++) {
			this->data[i] = X[i];
		}
		return *this;
	}

		
	~Matrix()
	{
		data.resize(0);
	}

};

template <typename E1, typename E2>
class MatrixSum : public MatrixExp<MatrixSum<E1, E2> > {

	E1 const& _u;
	E2 const& _v;

	public:
	MatrixSum(E1 const& u, E2 const& v) : _u(u), _v(v) {		
		assert(u[0] == v[0] and (u.size()-1) == (v.size() - 1));
	}

	double operator[](size_t i) const { 
		if(i!=0) {
			return _u[i] + _v[i];
		}
		else return _v[i];
	}
	size_t size()               const { 
		return _v.size(); 
	}
};

template <typename E1, typename E2>
MatrixSum<E1,E2> const
operator+(E1 const& u, E2 const& v) {
	return MatrixSum<E1, E2>(u, v);
}

const int n=3;

int main(){
	Matrix m1(n,n), m2(n,n), m3(n,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) {
			m1(i,j) = i + j;m2(i,j) = i + j;
		}
	}

	m1 += m1 + m2;
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout << i << " " << j << " " << m1(i,j) << endl;
		}
	}
	return 0;
}
