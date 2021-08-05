def multiply (a, b, base):
    #print(a,b);
    if (a<=10 or b<=10):
        return a*b;
    # res1 , res2 = base-a, base-b;
    p2=multiply(base-a, base-b, base);
    #print(p2);
    #normal_base=base//10;
    p1= multiply((a+b-base),base//10,base);
    p1=p1 + p2//10;
    p2=p2%10;
    #return (p1);
    #print(p2);
    return (p1*10+p2);

def to_integer (n):
    count=0;
    neg=0;
    if (n<0):
        neg=1;
    while(int(n)!=n):
        n=n*10;
        count+=1;
    return (int(abs(n)), count, neg);

def give_base (n1, n2):
    max_ = max(n1, n2);
    return (max_//10+1)*10;
 
a, b=map(float, input("\nEnter the operands by a space (only 2 digits allowed at max) : ").split());
(n1,c1, neg1)=to_integer(a);
n2,c2, neg2=to_integer(b);
base=give_base(n1, n2);

sign=1;
if (neg1^neg2):
    sign=-1;

ans=sign*multiply(n1, n2, base)/10**(c1+c2);
print("\nThe result of multiplication of %g and %g is: %g\n" %(a,b,ans));