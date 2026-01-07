#include<iostream>
#include "matrixDec.hpp"
#include<vector>
int main(){
	int n;
	std::cin>>n;
	matrix<double> a(getMatrix<double>(2,n));
	matrix<double> b(getMatrix<double>(1,n));
	printm(lReg(a,b));
	//vector<float> b(n);
	//for(int i=0;i<n;i++){std::cin>>b[i];}
	//matrix b(getMatrix(n));
	//printm(a+b);
	//printm(a*b);
	//printm(inverse(a));
	//vector<float> c =solveMatrix(a,b);
	//for(int i=0;i<c.size();i++){std::cout << c[i];}
}
