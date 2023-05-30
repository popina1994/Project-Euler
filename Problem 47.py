__author__ = 'popina'


MAX_NUM = 1000000

prime = {1 : False}
for idx in range(2, MAX_NUM) :
    prime[idx] = True

for idx in range(2, MAX_NUM) :
    for idxDiv in range(2 * idx, MAX_NUM, idx) :
        prime[idxDiv] = False

def Divisors(n, primeList) :
    divList = []
    for it in primeList :
        if (n % it == 0) :
            divList.append(it)
        while (n % it == 0) :
            n /= it
        if (n == 1) :
            return divList


primeList = []
for idx in prime :
    if prime[idx] :
        primeList.append(idx)

CON_NUM = 4

listCon = []

for it in range(2, CON_NUM + 2) :
    listCon.append(len(Divisors(it, primeList)))

for it in range(CON_NUM + 2, MAX_NUM) :
    del listCon[0]
    listCon.append(len(Divisors(it, primeList)))
    val = listCon[0]
    found = True
    for itCon in listCon :
        if val != itCon  or val != CON_NUM:
            found = False
            break
    if found :
        for itIn in range(it - CON_NUM + 1, it + 1) :
            print Divisors(itIn, primeList)
        print it  - CON_NUM + 1
        break

