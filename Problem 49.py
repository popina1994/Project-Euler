__author__ = 'popina'

MAX_NUM = 10000

prime = {1 : False}
for idx in range(2, MAX_NUM) :
    prime[idx] = True

for idx in range(2, MAX_NUM) :
    for idxDiv in range(2 * idx, MAX_NUM, idx) :
        prime[idxDiv] = False

primeList = []
for idx in prime :
    if prime[idx] :
        primeList.append(idx)

CON_NUM = 3

for it in primeList :

    breakOuter = True
    digits = str(it)
    for div in range(2, MAX_NUM, 2) :
        found = True
        for cnt in range(1, CON_NUM) :

            if (it + div * cnt < MAX_NUM) and prime[it + div * cnt] :
                digitsNext = str(it + div * cnt)
                if  (sorted(digits) != sorted(digitsNext)) :
                    found = False
                    break
            else :
                found = False
                break
        if found :

            print "IT:", it
            for cnt in range(1, CON_NUM) :
                print it + div * cnt
            breakOuter = True
            break
        else :
            breakOuter = False

