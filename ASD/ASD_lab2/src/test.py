def solve(l, x):
    if len(l) == 1:
        if l[len(l)-1] == x:
            return 0 #

def test_list(l):
    mid = len(l) // 2
    if len(l) == 0:
        return
    for i in range(len(l)):
        print(i, end=" ")
    print()
    l1 = l[::mid]
    l2 = l[mid::]
    test_list(l1)
    test_list(l2)

test_list([0,1,2,3,4,5])

k = input()
res = 0
for i in range(len(k)):
    res += int(k[i])
print(res)
sum = res
while res % 10 != 0:
    s = str(sum)
    res = 0
    for i in range(len(s)):
        res += int(s[i])
    sum += 1
print(sum - 1)