__author__ = 'popina'



POW_NUM = 7830457

pow = 1
base = 2
modulo = 10000000000
for idx in range(POW_NUM) :
    pow *= base
    pow %= modulo
pow *=  28433
pow += 1
pow %= modulo
print pow
