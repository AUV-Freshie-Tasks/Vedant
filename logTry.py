import Logistic as l
import matrix_lib as m
inp=[]
noOfInputs=int(input("Enter the number of inputs:"))
for i in range (0,noOfInputs):
    element=[1];
    temp=float(input())
    element.append(temp)
    inp.append(element)
out=[]
for i in range (0,noOfInputs):
    element=[]
    k=float(input("Enter the Outputs:"))
    element.append(k)
    out.append(element)
myLog=l.logistic_Regressor()
inpu=m.matrix(inp)
outpu=m.matrix(out)
myLog.fit(inpu,outpu)
pred=float(input("Enter the value to predict:"))
print(myLog.predict(pred))
