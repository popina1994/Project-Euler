__author__ = 'popina'


f = open('p059_cipher.txt', 'r')
s = f.readline()
f.close()

x = s.split(',')

NUM_LETT = 26

key = "god"
s = []
for idx in range(len(x)) :
    val = ord(key[idx % len(key)]) ^ int(x[idx])
    s.append( chr(ord(key[idx % len(key)]) ^ int(x[idx])))
sum = 0
for it in s :
    sum += ord(it)
print sum
