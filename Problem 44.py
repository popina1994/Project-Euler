__author__ = 'popina'

MAX_NUM = 3000

list = []
for idx in range(1, MAX_NUM) :
    list.append(idx * (3 * idx - 1) / 2)

for it1 in list :
    for it2 in list :
        if ((it1 + it2) in list) and ( (it1 - it2) in list) :
            print it1, it2
