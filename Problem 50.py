__author__ = 'popina'


MAX_NUM = 1000000

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


sum = [0]
curSum = 0

for it in primeList :
    curSum += it
    sum.append(curSum)

maxNum = -1
bigIdx = -1
smallIdx = -1
maxDif = -1

for idx in reversed(range(len(primeList))) :
    inIdx = idx - 2
    while (inIdx >= 0)  :
        reverseIt = sum[idx]
        reverseItIn = sum[inIdx]
        if (reverseItIn < reverseIt) :
            num = reverseIt - reverseItIn
            if num >= MAX_NUM :
                break
            dif = idx - inIdx
            if (prime[num]) and (dif > maxDif) :
                bigIdx = idx
                smallIdx = inIdx
                maxNum = num
                maxDif = dif

        inIdx -= 1

print maxNum, smallIdx, bigIdx, dif