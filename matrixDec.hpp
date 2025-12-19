#include<iostream>
#include<vector>
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

template <typename T>
class matrix {
	public:
        vector<vector<T>> mat;

	matrix(int n,int k){vector<vector<T>> tempmat(n,vector<T>(k)); mat=tempmat;};
	matrix(const vector<vector<T>> input){mat = input;};

	matrix<T> operator+(const matrix<T> &other) const{return add(*this,other);}
	matrix<T> operator*(const matrix<T> &other) const{return matrix(multiply(*this,other));}
	matrix<T> operator-(const matrix<T> &other) const{return matrix(sub(*this,other));}
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
matrix<T> lReg(matrix<T> x,matrix<T> y);



