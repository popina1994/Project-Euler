__author__ = 'popina'

MAX_NUM = 10000

def IsPalindrome(s) :
    for idx in range(0, len(s) / 2 + 1) :
        if (s[idx] != s[-1-idx]) :
            return False

    return True
def IsLychrel(s) :
    MAX_IT = 50
    for it in range(1, MAX_IT) :
        rev = s[::-1]
        if IsPalindrome(str( int(s) + int(rev) )) :
            print "Broj iteracija", it
            return True
        s = str(int(s) + int(rev))
    return False

cnt = 0
for it in range(1, MAX_NUM) :
    print it
    if (not IsLychrel(str(it))) :
        cnt += 1

print "BROJ JE" , cnt
