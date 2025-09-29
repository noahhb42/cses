from fractions import Fraction

def prob(a,b):
    if a<=b:
        return Fraction(a-1,2*b)
    else:
        return Fraction(1,1)-Fraction(b+1,2*a)

def round_half_to_even(x: Fraction):
    y = x * 1000000
    q = y.numerator // y.denominator
    r = y.numerator % y.denominator
    tr = 2 * r
    d = y.denominator

    if tr < d:
        k = q
    elif tr > d:
        k = q+1
    else:
        k = q if q%2==0 else q+1
    
    whole = k//1000000
    frac = k%1000000
    return f"{whole}.{frac:06d}"

n = int(input())
r = [*map(int,input().split())]

total = Fraction(0,1)

for a in range(n):
    for b in range(a+1,n):
        total += prob(r[a],r[b])
    
print(round_half_to_even(total))