#include<bits/stdc++.h>
#include"Matrix.h"

int n=3;

int main(){
	Matrix<double> m1(n,n), m2(n,n), m3(n,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) {
			m1(i,j) = i + j + 0.3;m2(i,j) = i + j + 0.3;
		}
	}

	m1 *=  m2 + m1; 

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout << i << " " << j << " " << m1(i,j) << endl;
		}
	}
	return 0;
}

