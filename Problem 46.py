__author__ = 'popina'

MAX_NUM = 10000

prime = {}
for idx in range(2, MAX_NUM) :
    prime[idx] = True

for idx in range(2, MAX_NUM) :
    for idxDiv in range(2 * idx, MAX_NUM, idx) :
        prime[idxDiv] = False

primeList = []
for idx in prime :
    if prime[idx] :
        primeList.append(idx)
del primeList[0]

import math

for idx in prime :
    can = False
    if (not prime[idx]) :
        for it in primeList :
            if (it < idx) :
                dif = (idx - it) / 2
                if (round(math.sqrt(dif)) ** 2 == dif):
                    can = True
                    break
            else : break
    else :
        can = True
    if not can :
        print idx
        break

