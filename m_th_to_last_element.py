
# https://www.hackerrank.com/contests/programming-interview-questions/challenges/m-th-to-last-element/problem
import sys
M1 = -1 * int(sys.stdin.readline().rstrip())
L1 = sys.stdin.readlines()
L1 = list(map(lambda x: x.rstrip(), L1))[0].split()
def return_ele(x, i):
    if i<0 and len(x) >= abs(i): return x[i]
    if i>=0 and len(x) > abs(i): return x[i]
    return "NIL" 

print(return_ele(L1, M1))
