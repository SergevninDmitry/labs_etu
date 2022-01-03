import random
import time
import math
import matplotlib.pyplot as plt
import tree
from tree import RBTree

Tree = RBTree()

for i in range(10):
    Tree.insert(i)
print(Tree.get_root().color)
while True:
    try:
        print("Какое действие вы хотите совершить?\nDelete - удалить элемент, "
              "Search - найти элемент, Exit - выйти из программы: ")
        command = input()
        if command == 'Exit':
            break
        elif command == 'Search':
            root_found = Tree.search(int(input("Какой элемент найти?\nВведите эелемент:")))
            if root_found:
                print("Такой элемент есть в дереве.\n")
            else:
                print("Элемент не найден.\n")
        elif command == 'Delete':
            print("Введите границы удаления:")
            a, b = [int(i) for i in input().split()]
            Tree.delete_section(min(a, b), max(a, b))
            # bool_flag = Tree.delete(int(input("Какой элемент удалить?\nВведите эелемент: ")))
            #if bool_flag == 0:
            #    print("Дерево не содержит этого элемента.\n")
            print("Все числа из диапазона от {} до {} были удалены.\n".format(a, b))
        else:
            print(1/0)
    except (TypeError, ValueError, AttributeError, ZeroDivisionError):
        print("Smth went wrong, plz try again!")
        print("Probably, you typed not a number.\n")
