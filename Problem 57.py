__author__ = 'popina'

from fractions import Fraction

NUM_MAX = 1000
meme = {}

meme[0] = Fraction(1, 1)
for idx in range(1, NUM_MAX + 1):
    meme[idx] = Fraction(1 + 1 / (1 + meme[idx  - 1]))

cnt = 0
for it in meme :
    print meme[it]
    if (len(str(meme[it].numerator)) > len(str(meme[it].denominator))) :
        print meme[it]
        cnt += 1

print cnt