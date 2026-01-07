#include<iostream>
#include"linearReg.h"
int main(){
	linearRegressor<double> trial(0.01,1000);
	vector<vector<double>> c={{1.0},{2.0},{3.0}};
	vector<vector<double>> d={{3.0},{2.0},{1.0}};
	matrix a(c);
	matrix b(d);
	trial.fit(a,b);
	trial.getParameters();
}
