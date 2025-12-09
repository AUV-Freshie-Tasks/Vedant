#include "matrixDec.h"
#include <iostream>
#include <vector>
matrix matrix::add(matrix a,matrix b){
	matrix c(a.mat.size(),a.mat[0].size());
	for(int i=0;i<a.mat.size();i++){
		for(int j=0;j<a.mat[0].size();j++){
			c.mat[i][j]=a.mat[i][j]+b.mat[i][j];
		}
	}
	return c;
}
matrix matrix::sub(matrix a,matrix b){
        matrix c(a.mat.size(),a.mat[0].size());
        for(int i=0;i<a.mat.size();i++){
                for(int j=0;j<a.mat[0].size();j++){
                        c.mat[i][j]=a.mat[i][j]-b.mat[i][j];
                }
        }
        return c;
}
matrix matrix::multiply(matrix a, matrix b){
	matrix c(a.mat.size(),b.mat[0].size());
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

void printm(matrix a){for(int i=0;i<a.mat.size();i++){for(int j=0;j<a.mat[0].size();j++){cout<<a.mat[i][j]<<" ";}}}

vector<vector<float>> getMatrix(int n,int k){
	vector<vector<float>> inputMat;
        for(int i=0;i<n;i++){
                vector<float> row;
                for(int j=0;j<k;j++){
                        float input;
                        cin>>input;
                        row.push_back(input);
                }
                inputMat.push_back(row);
        }
        return inputMat;
}

matrix inverse(matrix a){
	matrix c(a.mat.size(),a.mat.size());
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
void modifyMatrix(matrix* a,int i,int j,float n){
	for(int b=0;b<a->mat.size();b++){
		a->mat[j][b] = a->mat[j][b]+n*a->mat[i][b];
	}
}
matrix LMatrix(matrix a){
	matrix c(a.mat.size(),a.mat.size());
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
matrix UMatrix(matrix a){
	for(int i=0;i<a.mat.size();i++){
                for(int k=i+1;k<a.mat.size();k++){
                        float factor=a.mat[k][i]/a.mat[i][i];
                        modifyMatrix(&a,i,k,-1*factor);
                }
        }
	return a;
}
vector<float> solveMatrix(matrix a,vector<float> b){
	vector<float> answer(a.mat.size(),0);
	matrix L=LMatrix(a);
	matrix U=UMatrix(a);
	vector<float> Y;
	for(int i=0;i<a.mat.size();i++){
		float element=0;
		for(int j=0;j<i;j++){
			element+=L.mat[i][j]*Y[j];
		}
		Y.push_back(b[i]-element);
	}
	for(int i=a.mat.size()-1;i>=0;i--){
		float element=0;
                for(int j=i+1.;j<a.mat.size();j++){
                        element+=U.mat[i][j]*answer[j];
                }
		answer[i]=(Y[i]-element)/U.mat[i][i];
	}
	return answer;

}
matrix lReg(matrix a,matrix b){
        matrix ans(1,2);
        ans.mat[0][0]=1;ans.mat[0][1]=0;
        float Xd=1;
        float Yd=1;
        float lRate=0.09;
        matrix c(a.mat[0].size(),a.mat.size());
        for(int i=0;i<a.mat[0].size();i++){
                for(int j=0;j<a.mat.size();j++){
                        c.mat[i][j]=a.mat[j][i];
               }
        }
        while(Xd*Xd+Yd*Yd >=0.00000001){
		matrix temp=(((b-(ans*a))*c));
                Xd=(-2.0/a.mat[0].size())*temp.mat[0][0];
                Yd=(-2.0/a.mat[0].size())*temp.mat[0][1];
                ans.mat[0][0]-=lRate*Xd;
                ans.mat[0][1]-=lRate*Yd;
        }
        return ans;
}

