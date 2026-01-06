import matrix_lib as m
import math
class logistic_Regressor:
    parameters=m.matrix()
    def __init__(self,lR=0.01,maxTry=1000,tol=1e-6):
        self.learnRate=lR
        self.maxTries=maxTry
        self.tolerance=tol
    def fit(Input,Output):
        norm=1
        tempMat=m.matrix(Input.cols,1,1)
        parameters=tempMat
        tries=0;
        while(norm>tolerance or tries<maxTries):
            z=Input*parameters
            p=[]
            for(i in range z.rows):
                element=[1/(1+math.exp(-(z.mat[i][0]))]
                p.append(element)
            grad=(Input.T()*(p-Output))*(-1/Input.rows)
            parameters=parameters-grad*learnRate
            norm=parameters.T()*parameters.T
            tries=tries+1




