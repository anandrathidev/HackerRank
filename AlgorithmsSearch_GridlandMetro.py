from collections import Counter
from sys import stdin

class railTrack:
    def __init__(self,c1,c2):
        self.c1=c1
        self.c2=c2

def countCells(r,c1,c2):
    

def main():
    lines = list()
    tracksHash = {}
    for line in stdin:
        lines.append(line.strip())
    r,c,k = lines[0].split(' ')
    print(r,c,k)
    for i in range(1, k):
        trR,c1,c2 = lines[i].split()
        tracksHash[trR] 

if __name__ == '__main__':
	main()
