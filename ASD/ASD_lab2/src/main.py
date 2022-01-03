import input_matrix
import merge

if __name__ == '__main__':
    arr_sum = merge.merge(input_matrix.input_matrix())
    try:
        if len(arr_sum[0]) == 0:
            print("No data to print")
        for i in range(len(arr_sum[0])):
            print(arr_sum[0][i], end=" ")
    except (TypeError, ValueError):
        print("No data to sort")
