

def sort_sdvig(arr, l, r):
    while l != r:
        mi = arr[l]
        ma = arr[r]
        for l in range(r):  # поиск мин и мах
            if mi > arr[l]:
                mi = arr[l]
            if ma < arr[l]:
                ma = arr[l]
        if mi == arr[l]:
            l += 1
        if ma == arr[r]:
            r -= 1
        i = l
        temp = arr[l]
        while True:  # смещение
            if mi == arr[l] or ma == arr[r]:
                break
            arr[i - 1] = arr[i]
            i += 1
            i %= r - l + 1
        arr[r] = temp
        print(arr)


arr = [3, 2, 4, 0]
sort_sdvig(arr, 0, 3)
print(arr)
