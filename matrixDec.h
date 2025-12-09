#include<iostream>
#include<vector>
using namespace std;
class matrix {
	public:
        vector<vector<float>> mat;

	//matrix(){vector<float> k(0,0);vector<vector<float>> tempmat(0,k); mat=tempmat;};
	matrix(int n,int k){vector<vector<float>> tempmat(n,vector<float>(k)); mat=tempmat;};
	matrix(vector<vector<float>> input){mat = input;};
	
	matrix add(matrix A,matrix B);
        matrix multiply(matrix A,matrix B);
	matrix sub(matrix A,matrix B);

	matrix operator+(const matrix &other){return matrix(add(*this,other));}
	matrix operator*(const matrix &other){return matrix(multiply(*this,other));}
	matrix operator-(const matrix &other){return matrix(sub(*this,other));}
};

void printm(matrix a);
vector<vector<float>> getMatrix(int n,int k);
matrix inverse(matrix A);
void modifyMatrix(matrix* a,int i,int j,float n);
matrix LMatrix(matrix a);
matrix UMatrix(matrix a);
vector<float> solveMatrix(matrix a,vector<float> b);
matrix lReg(matrix a,matrix b);



