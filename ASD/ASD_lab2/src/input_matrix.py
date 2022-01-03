def input_matrix():
    try:
        n = int(input())
        arr_sum = [[], []]
        for i in range(n):
            len_matrix = int(input())
            diagonal_sum = 0
            for j in range(len_matrix):
                buf_list = [int(i) for i in input().split()]
                diagonal_sum += buf_list[j]
            arr_sum[0].append(i)
            arr_sum[1].append(diagonal_sum)
        return arr_sum
    except (TypeError, ValueError):
        print("Incorrect data entry")
        exit()
