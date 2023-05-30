__author__ = 'popina'

MAX_NUM = 100000
PANDIGIT_NUM_OF_DIGIT = 9
curBiggest = -1

for it in range(1, MAX_NUM) :
    itNum = 0
    n = 1
    panDigit = ""
    map = {}
    for idx in range(1, 10) :
        map[idx] = 0
    double = False

    while itNum < PANDIGIT_NUM_OF_DIGIT :
        num = n * it
        n += 1
        itNum += len(str(num))
        listOfDigit = [ int(char) for char in str(num) ]
        panDigit += str(num)
        for digit in listOfDigit :
            if (digit == 0) or (map[digit] > 0) :
                double = True
                break
            else:
                map[digit] += 1
        if (double) : break

    for idx in range(1, 10) :
        if (map[idx] == 0) :
            double = True
    if (itNum == PANDIGIT_NUM_OF_DIGIT) and not double :
        if int(curBiggest) < int(panDigit) :
            curBiggest = panDigit
print curBiggest