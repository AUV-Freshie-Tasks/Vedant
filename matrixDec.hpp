#include<iostream>
#include<vector>
#pragma once
using namespace std;
template<typename T> class matrix;
template<typename T>
matrix<T> add(const matrix<T>& a,const matrix<T>& b){
        matrix<T> c(a.mat.size(),a.mat[0].size());
        for(int i=0;i<a.mat.size();i++){
                for(int j=0;j<a.mat[0].size();j++){
                        c.mat[i][j]=a.mat[i][j]+b.mat[i][j];
                }
        }
        return c;
}
template<typename T>
matrix<T> sub(const matrix<T>& a,const matrix<T>& b){
        matrix<T> c(a.mat.size(),a.mat[0].size());
        for(int i=0;i<a.mat.size();i++){
                for(int j=0;j<a.mat[0].size();j++){
                        c.mat[i][j]=a.mat[i][j]-b.mat[i][j];
                }
        }
        return c;
}
template<typename T>
matrix<T> multiply(const matrix<T>& a,const matrix<T>& b){
        matrix<T> c(a.mat.size(),b.mat[0].size());
        for(int i=0;i<a.mat.size();i++){
                for(int j=0;j<b.mat[0].size();j++){
                        c.mat[i][j]=0;
                        for(int k=0;k<b.mat.size();k++){
                                c.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
                        }
                }
        }
        return c;
}
template<typename T>
matrix<T> multiply(const matrix<T>& a,T factor){
        matrix<T> c(a.rows,a.cols,0);
        for(int i=0;i<a.rows;i++){
                for(int j=0;j<a.cols;j++){
                        c.mat[i][j]+=a.mat[i][j]*factor;
                }
        }
        return c;
}

template <typename T>
class matrix {
	public:
        vector<vector<T>> mat;
	int rows;
	int cols;
	
	matrix(){mat={{0}};rows=1;cols=1;};
	matrix(int row,int columns){
		vector<vector<T>> tempmat(row,vector<T>(columns)); mat=tempmat;
		rows=row;
                cols=columns;
	};
	matrix(int row,int columns,T value){
		vector<vector<T>> tempmat(row,vector<T>(columns,value)); mat=tempmat;
		rows=row;
                cols=columns;
	};
	matrix(const vector<vector<T>>& input){
		mat = input;
		rows=mat.size();
        	cols=mat[0].size();
	};

	matrix<T> operator+(const matrix<T> &other) const{return add(*this,other);}
	matrix<T> operator*(const matrix<T> &other) const{return multiply(*this,other);}
	matrix<T> operator-(const matrix<T> &other) const{return sub(*this,other);}
	matrix<T> operator*(const T &other) const{return multiply(*this, other);}
	matrix<T> Trans(){
		matrix temp(rows,cols);
		for(int i=0;i<rows;i++){for(int j=0;j<cols;j++){temp.mat[j][i]=mat[i][j];}}
		return temp;
	}
};
/*template <typename U>
void printm(matrix<U> t){
	for(int i=0;i<t.mat.size();i++){for(int j=0;j<t.mat[0].size();j++){cout<<t.mat[i][j]<<" ";}}
};

template <typename T>
vector<vector<T>> getMatrix(int n,int k){
		vector<vector<T>> inputMat;
        for(int i=0;i<n;i++){
                vector<T> row;
                for(int j=0;j<k;j++){
                        T input;
                        cin>>input;
                        row.push_back(input);
                }
                inputMat.push_back(row);
        }
        return inputMat;
}*/
template<typename T>
matrix<T> inverse(matrix<T> A);
template<typename T>
void modifyMatrix(matrix<T>* a,int i,int j,float n);
template<typename T>
matrix<T> LMatrix(matrix<T> a);
template<typename T>
matrix<T> UMatrix(matrix<T> a);
template<typename T>
vector<T> solveMatrix(matrix<T> a,vector<T> b);
template<typename T>
matrix<T> lReg(matrix<T> x,matrix<T> y,T rate=0.01);
template<typename T>
matrix<T> transpose(matrix<T> original);
