#include "matrixDec.hpp"
//#include "LruCache.h"
#include <iostream>
#include <vector>
template<typename T>
matrix<T> inverse(matrix<T> a){
	if(a.rows!=a.cols){
		throw invalid_argument("please use a square matrix");
	}
	matrix<T> c(a.rows,a.cols);
	for(int i=0;i<a.mat.size();i++){c.mat[i][i]=1;}
	for(int i=0;i<a.mat.size();i++){
		float p=a.mat[i][i];
		for(int j=0;j<a.mat.size();j++){c.mat[i][j] = c.mat[i][j]/p ;}
		for(int j=0;j<a.mat.size();j++){a.mat[i][j] = a.mat[i][j]/p ;}
		for(int k=0;k<a.mat.size();k++){
			if(i!=k){
				modifyMatrix(&c,i,k,-1*a.mat[k][i]);
				modifyMatrix(&a,i,k,-1*a.mat[k][i]);
			}
		}
	}
	return c;
}
template<typename T>
void modifyMatrix(matrix<T>* a,int i,int j,float n){
	for(int b=0;b<a->mat.size();b++){
		a->mat[j][b] = a->mat[j][b]+n*a->mat[i][b];
	}
}
template<typename T>
matrix<T> LMatrix(matrix<T> a){
	matrix<T> c(a.mat.size(),a.mat.size());
        for(int i=0;i<a.mat.size();i++){c.mat[i][i]=1;}
        for(int i=0;i<a.mat.size();i++){
                for(int k=i+1;k<a.mat.size();k++){
                        T factor=a.mat[k][i]/a.mat[i][i];
			c.mat[k][i]=factor;
                        modifyMatrix(&a,i,k,-1*factor);
                }
        }
        return c;
}
template<typename T>
matrix<T> UMatrix(matrix<T> a){
	for(int i=0;i<a.mat.size();i++){
                for(int k=i+1;k<a.mat.size();k++){
                        T factor=a.mat[k][i]/a.mat[i][i];
                        modifyMatrix(&a,i,k,-1*factor);
                }
        }
	return a;
}
template<typename T>
vector<T> solveMatrix(matrix<T> a,vector<T> b){
	vector<T> answer(a.mat.size(),0);
	matrix<T> L=LMatrix(a);
	matrix<T> U=UMatrix(a);
	vector<T> Y;
	for(int i=0;i<a.mat.size();i++){
		T element=0;
		for(int j=0;j<i;j++){
			element+=L.mat[i][j]*Y[j];
		}
		Y.push_back(b[i]-element);
	}
	for(int i=a.mat.size()-1;i>=0;i--){
		T element=0;
                for(int j=i+1.;j<a.mat.size();j++){
                        element+=U.mat[i][j]*answer[j];
                }
		answer[i]=(Y[i]-element)/U.mat[i][i];
	}
	return answer;

}
template<typename T>
matrix<T> lReg(matrix<T> Coords, matrix<T> Output,T rate){
        matrix<T> parameters(Coords.cols+1,1,1);
	matrix<T> change(Coords.cols+1,1);
        T learnRate=rate;
	matrix<T> temp(Coords.rows,Coords.cols+1,1);
	for(int i=0;i<Coords.rows;i++){
               	for(int j=0;j<Coords.cols;j++){
           		temp.mat[i][j+1]=Coords.mat[i][j];
               	}
        }
        matrix<T> c(temp.cols,temp.rows);
        for(int i=0;i<temp.cols;i++){
                for(int j=0;j<temp.rows;j++){
                        c.mat[i][j]=temp.mat[j][i];
               }
        }
	int MinimaAcheived = 0;
       	int max=5000;	
        while(!MinimaAcheived&&max>0){
		max--;
		MinimaAcheived=1;
		matrix<T> d=(c*((Output-(temp*parameters))));
		for(int i=0;i<change.rows;i++){
			change.mat[i][0]=(-2.0/Coords.rows)*d.mat[i][0];
		}
                parameters=parameters-change*learnRate;
		for(int i=0;i<change.rows;i++){
			if(abs(change.mat[i][0])>0.01){MinimaAcheived*=0;}
		}

        }
        return parameters;
}
template<typename T>
matrix<T> transpose(matrix<T> original){
        matrix<T> temp(original.cols,original.rows);
        for(int i=0;i<original.rows;i++){for(int j=0;j<original.cols;j++){temp.mat[j][i]=original.mat[i][j];}}
        return temp;
}
template void modifyMatrix<float>(
    matrix<float>*, int, int, float
);
template void modifyMatrix<double>(
    matrix<double>*, int, int, float
);
template matrix<float> LMatrix<float>(
    matrix<float>
);
template matrix<double> LMatrix<double>(
    matrix<double>
);
template matrix<float> UMatrix<float>(
    matrix<float>
);
template matrix<double> UMatrix<double>(
    matrix<double>
);
template vector<float> solveMatrix<float>(
    matrix<float>, vector<float>
);
template vector<double> solveMatrix<double>(
    matrix<double>, vector<double>
);
template matrix<float> lReg<float>(
    matrix<float>, matrix<float>, float
);
template matrix<double> lReg<double>(
    matrix<double>, matrix<double>, double
);
template matrix<float> transpose<float>(
    matrix<float>
);
template matrix<double> transpose<double>(
    matrix<double>
);
template matrix<double> inverse(matrix<double>);
template matrix<float> inverse(matrix<float>);
template class matrix<double>;
template class matrix<float>;
