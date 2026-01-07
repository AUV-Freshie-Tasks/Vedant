#include "linearReg.h"
#include<iostream>
template <typename T>
matrix<T> linearRegressor<T>::predict(matrix<T> input){
	matrix<T> temp(input.rows,input.cols+1,1);
        for(int i=0;i<input.rows;i++){
                for(int j=0;j<input.cols;j++){
                        temp.mat[i][j+1]=input.mat[i][j];
                }
        }
	matrix<T> c=temp*parameters;
	return c;
}
template <typename T>
void linearRegressor<T>::fit(matrix<T> Coords,matrix<T> output){
        matrix<T> p(Coords.cols+1,1,1);
	parameters=p;
        matrix<T> change(Coords.cols+1,1);
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
                matrix<T> d=(c*((output-(temp*parameters))));
                for(int i=0;i<change.rows;i++){
                        change.mat[i][0]=(-2.0/Coords.rows)*d.mat[i][0];
                }
                parameters=parameters-change*learnRate;
                for(int i=0;i<change.rows;i++){
                        if(abs(change.mat[i][0])>0.01){MinimaAcheived*=0;}
                }

        }
}
template class linearRegressor<double>;
template class linearRegressor<float>;
