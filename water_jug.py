
parsed_values=[[0,0]]

class jug:
    def __init__(self):
        self.capacity=0
        self.value=0
    def isEmpty(self):
        if(self.value==0):
            return True
        else:
            False
    def isFull(self):
        if(self.capacity==self.value):
            return True
        else:
            False
def min(a,b):
    if a>b:
        return b
    else:
        return a
def show(a,b):
    print("A= "+str(a)+" B= "+str(b))
def check_repeat(a):
    
    for i in parsed_values:
        if i==a:
            return True
        
    return False
    
    

def main():
    A=jug()
    B=jug()
    
    A.capacity=int(input("Enter the capacity of the  jugA: "))
    B.capacity=int(input("Enter the capacity of the  jugB: "))
    print("-----------------------------------")
    goalA=int(input("Enter the goal state of the jugA: "))
    goalB=int(input("Enter the goal state of the jugB: "))
    print("Start State of jugs A=0  B=0\n\n")

    if(goalA==0 and goalB==0):
        print("! Done !")
        return 0
    try:
        while(A.value!=goalA or B.value!=goalB):
            if(A.isEmpty()):
                A.value=A.capacity
                print("Fill  ",end="")
                show(A.value,B.value)
            elif B.isFull():
                B.value=0
                print("Empty ",end="")
                show(A.value,B.value)
            else:
                temp=min(B.capacity-B.value,A.value)
                B.value=B.value+temp
                A.value=A.value-temp
                print("Pour  ",end="")
                show(A.value,B.value)
            if(check_repeat([A.value,B.value])):
                raise 0 
            parsed_values.append([A.value,B.value])
        print("[+]]Executed succsefully[+]")
    except:
        print("! Not Possible !")
if __name__=="__main__":
    main()