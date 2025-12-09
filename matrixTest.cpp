#include<iostream>
#include "matrixDec.h"
#include<vector>
int main(){
	int n;
	matrix a(getMatrix(2,2));
	matrix b(getMatrix(1,2));
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
