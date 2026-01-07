import matrix_lib as m
import math
class logistic_Regressor:
    def __init__(self,lR=0.01,maxTry=100000,tol=1e-6):
        self.parameters=m.matrix([[1]])
        self.learnRate=lR
        self.maxTries=maxTry
        self.tolerance=tol
    def fit(self,Input: m.matrix,Output: m.matrix):
        norm=1
        tempMat=m.matrix(Input.cols,1,1)
        self.parameters=tempMat
        tries=0;
        while(norm>self.tolerance and tries<self.maxTries):
            z=Input*self.parameters
            tempSigmoidedOutput=[]
            for i in range (0,z.rows):
                element=[1/(1+math.exp(-1*(z.data[i][0])))]
                tempSigmoidedOutput.append(element)
            p=m.matrix(tempSigmoidedOutput)
            grad=(m.transpose(Input)*(p-Output))*(1/Input.rows)
            self.parameters=self.parameters-grad*self.learnRate
            norm=(m.transpose(grad)*grad).data[0][0]
            """print(norm)
            print(tries)"""
            tries=tries+1
    def getParameters(self):
        return self.parameters
    def predict(self,Input: m.matrix):
        return 1/(1+math.exp(-1*((Input*self.parameters).data[0][0])))



