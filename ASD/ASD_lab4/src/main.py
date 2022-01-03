import RabinKarp
import hashlib

#pat = input()
#txt = input()

f_1 = open('1.txt','r')
f_2 = open('2.txt','r')
text_1 = f_1.read()
text_2 = f_2.read()
md5_hash_1 = hashlib.md5()
md5_hash_1.update(bytes(text_1, 'utf-8'))
md5_hash_2 = hashlib.md5()
md5_hash_2.update(bytes(text_2, 'utf-8'))

q = 1000000007
ans = RabinKarp.RabinKarp(text_1, text_2, q)
print("hash 1:", md5_hash_1.hexdigest())
print("hash 2:", md5_hash_2.hexdigest())

print("alg Rabin Karp:", True if ans == [0] else False)
print("alg md5:", True if md5_hash_1.hexdigest() == md5_hash_2.hexdigest() else False)
