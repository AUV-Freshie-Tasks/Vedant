#include<iostream>
#include"matrixDec.hpp"
#pragma once 
template <typename T>
class linearRegressor{
	private:
	matrix<T> parameters;
	T learnRate;
	int maxCycles;

	public:
	linearRegressor(T lR,int max){learnRate=lR;maxCycles=max;}
	matrix<T> predict(matrix<T> input);
	void fit(matrix<T> input,matrix<T> output);
	matrix<T> getParameters(){return parameters;}
};
