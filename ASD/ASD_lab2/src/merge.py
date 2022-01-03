def merge(arr_sum):
    try:
        if len(arr_sum[1]) == 1:
            return arr_sum
        if len(arr_sum[1]) == 0:
            return arr_sum
        mid = len(arr_sum[1]) // 2
        l, r = [[0] * mid for _ in range(2)], [[0] * mid for _ in range(2)]
        l[0], r[0] = arr_sum[0][:mid], arr_sum[0][mid:]
        l[1], r[1] = arr_sum[1][:mid], arr_sum[1][mid:]
        merge(l)
        merge(r)
        index_l = index_r = index = 0
        res = [[0] * (len(l[1]) + len(r[1])) for _ in range(2)]
        while index_l < len(l[1]) and index_r < len(r[1]):
            if l[1][index_l] <= r[1][index_r]:
                res[0][index] = l[0][index_l]
                res[1][index] = l[1][index_l]
                index_l += 1
            else:
                res[0][index] = r[0][index_r]
                res[1][index] = r[1][index_r]
                index_r += 1
            index += 1
        while index_l < len(l[1]):
            res[0][index] = l[0][index_l]
            res[1][index] = l[1][index_l]
            index_l += 1
            index += 1
        while index_r < len(r[1]):
            res[0][index] = r[0][index_r]
            res[1][index] = r[1][index_r]
            index_r += 1
            index += 1
        for i in range(len(arr_sum[1])):
            arr_sum[0][i] = res[0][i]
            arr_sum[1][i] = res[1][i]
        for i in range(len(arr_sum[0])):
            print(arr_sum[0][i], end=" ")
        print()
        return arr_sum
    except (TypeError, ValueError):
        exit()
