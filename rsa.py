import random
def gcd(a,b):
    while b!=0:
        a,b=b,a%b
    return a

def coprime(phi):
    while True:
        e=random.randrange(2,phi)
        if gcd(e,phi) == 1:
            print("e=",e)
            return e

def modular(b,e,m):
    res=1
    b=b%m
    while e>0:
        if e%2 == 1:
            res=(res*b)%m
        e=e>>1
        b=(b*b)%m
    return res

def privatekey(e,phi):
    d=0
    k=1
    while True:
        d=(phi*k+1)/e
        if d.is_integer():
            print("d=",d)
            return int(d)
        k+=1

def encrypt(pt,e,n):
    ct=[]
    for i in pt:
        ct.append(modular(ord(i),e,n))
    return ct


def decrypt(ct,d,n):
    pt=[]
    for i in ct:
        pt.append(chr(modular(i,d,n)))
    return ''.join(pt)

p=11
q=13
n=p*q
phi=(p-1)*(q-1)

e=coprime(phi)
d=privatekey(e,phi)

pt=input("Enter the plaintext:")
ct=encrypt(pt,e,n)

print("plaintext:",pt)
print("ciphertext:",ct)
print("decrypted message:",decrypt(ct,d,n))