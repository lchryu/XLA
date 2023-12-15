import pygame
import numpy as np
from math import log
import os

os.system("cls")

print("Enter your matrix!")
n, m = map(int, input().split())
a = np.zeros((n, m), dtype=float)
max_matrix = 7
for i in range(n):
    row_data = list(map(int, input().split()))
    for j in range(m):
        a[i][j] = row_data[j] / max_matrix * 1.0

expression = input("Enter the expression (e.g., 2 * log(1 + r)): ")

print("I1 =")
for i in range(n):
    for j in range(m):
        print(f"{a[i][j]:.4f}", end=" ")
    print()

print("\nI2 =")
for i in range(n):
    for j in range(m):
        s = eval(expression.replace("r", str(a[i][j])))
        print(f"{s:.4f}", end=" ")
        a[i][j] = s
    print()

print("\nI4 =")
for i in range(n):
    for j in range(m):
        if a[i][j] > 1:
            print(max_matrix, end=" ")
        else:
            print(round(a[i][j] * max_matrix), end=" ")
    print()
