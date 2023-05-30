__author__ = 'popina'

def sumDigitSquare(n) :
    sum = 0
    for it in str(n) :
        sum += int(it) ** 2
    return sum

digitSquareSum = {}

digitSquareSum[1] = 1
digitSquareSum[89] = 89


MAX = 10000000
cnt = 0
for it in range(1, MAX) :
    if (digitSquareSum.get(it, 0) == 0) :
        sum = sumDigitSquare(it)
        digitSquareSum[it] = sum
    else :
        sum = digitSquareSum.get(it, 0)
    while (sum != 1) and (sum != 89) :
        if (digitSquareSum.get(sum, 0) == 0) :
            oldSum = sum
            sum = sumDigitSquare(oldSum)
            digitSquareSum[oldSum] = sum
        else :
            sum = digitSquareSum.get(sum, 0)

    if (sum == 89) :
        cnt += 1
print cnt