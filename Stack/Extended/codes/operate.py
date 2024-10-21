class Stack:
    def __init__(self):
        self.items=[]

    def is_empty(self):
        return len(self.items)==0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()

        else:
            return 0

    def top(self):
        if(not self.is_empty()):
            return self.items[len(self.items)-1]


def relation(c1, c2):
    cha=["+", "-", "*", "/", "(", ")", "#", "^"]
    relation = [[1, 1, -1, -1, -1, 1, 1, -1], [1, 1, -1, -1, -1, 1, 1, -1],
                      [1, 1, 1, 1, -1, 1, 1, -1], [1, 1, 1, 1, -1, 1, 1, -1],
                      [-1, -1, -1, -1, -1, 0, 5, -1], [1, 1, 1, 1, 5, 1, 1, -1],
                      [-1, -1, -1, -1, -1, 5, 0, -1], [1, 1, 1, 1, -1, 1, 1, 1]]
    i=0
    i1=i2=0
    while i<8:
        if str(c1)==cha[i]: i1=i
        if str(c2)==cha[i]: i2=i
        i+=1

    return relation[i1][i2]

def solve(a,op,b):
    if op=='+':
        return a+b
    if op=='-':
        return a-b
    if op=='*':
        return a*b
    if op=='/':
        if b==0:
            print("0 can't be a denominator.")
            exit(0)
        return a/b
    if op=='^':
        return pow(a,b)

def evaluate_expression(str):
    OPND = Stack()
    OPTR = Stack()
    OPTR.push('#')
    i=0

    while str[i]!='#' or OPTR.top()!='#':
        if str[i]==' ':
            i+=1
            continue
        if str[i]>='0' and str[i]<='9':
           x=int(str[i])-0
           i+=1
           while str[i]>='0' and str[i]<='9':
               x*=10
               x+=int(str[i])-0
               i+=1
           OPND.push(x)

        else :
            rel=relation(OPTR.top(), str[i])
            if rel==-1:
                OPTR.push(str[i])
                i+=1
            if rel==0:
                OPTR.pop()
                i+=1
            if rel==1:
                op=OPTR.top()
                OPTR.pop()

                a=OPND.top()
                OPND.pop()
                b=OPND.top()
                OPND.pop()
                OPND.push(solve(b,op,a))

    return OPND.top()