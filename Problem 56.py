__author__ = 'popina'

UP_LIMIT = 100

maxSum = -1

for a in range(1, UP_LIMIT + 1) :
    for b in range(1, UP_LIMIT + 1) :
        strNum = str(pow(a, b))
        sum = 0
        for char in strNum :
            sum += int(char)
        if (sum > maxSum):
            maxSum = sum
print maxSum