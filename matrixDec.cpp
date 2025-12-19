#include "matrixDec.hpp"
#include "LruCache.h"
#include <iostream>
#include <vector>
template<typename T>
matrix<T> inverse(matrix<T> a){
	matrix<T> c(a.mat.size(),a.mat.size());
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
	matrix<double> c(a.mat.size(),a.mat.size());
        for(int i=0;i<a.mat.size();i++){c.mat[i][i]=1;}
        for(int i=0;i<a.mat.size();i++){
                for(int k=i+1;k<a.mat.size();k++){
                        float factor=a.mat[k][i]/a.mat[i][i];
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
                        float factor=a.mat[k][i]/a.mat[i][i];
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
matrix<T> lReg(matrix<T> a,matrix<T> b){
        matrix<T> ans(1,2);
        ans.mat[0][0]=1;ans.mat[0][1]=0;
        T Xd=1;
        T Yd=1;
        T lRate=0.09;
        matrix<T> c(a.mat[0].size(),a.mat.size());
        for(int i=0;i<a.mat[0].size();i++){
                for(int j=0;j<a.mat.size();j++){
                        c.mat[i][j]=a.mat[j][i];
               }
        }
        while(Xd*Xd+Yd*Yd >=0.00000001){
		matrix<T> temp=(((b-(ans*a))*c));
                Xd=(-2.0/a.mat[0].size())*temp.mat[0][0];
                Yd=(-2.0/a.mat[0].size())*temp.mat[0][1];
                ans.mat[0][0]-=lRate*Xd;
                ans.mat[0][1]-=lRate*Yd;
        }
        return ans;
}

template class matrix<double>;
template class matrix<float>;
