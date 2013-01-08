'''
Created on Jan 7, 2013

@author: Rafael Angelo
'''
def binomial(N,p):
    aux = N
    no = 1;
    while aux > 0:
        no = no *(aux%p + 1)
        aux = aux/p
    return (N - no + 1)

number = int(raw_input())
for number in range(0,number):
    N = raw_input()
    lista = N.split();
    N = int(lista[0])
    p = int(lista[1])
    result = binomial(N,p)
    print result
