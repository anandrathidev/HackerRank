from sys import stdin

class railTrack:
    def __init__(self,c1,c2):
        self.c1=c1
        self.c2=c2

def countCells(tracks):
    return sum([ (k.c2 - k.c1)+1  for k in tracks.values()])

def main():
    lines = list()
    tracksHash = {}
    for line in stdin:
        lines.append(line.strip())
    r,c,k = lines[0].split(' ')
    r = int(r)
    c = int(c)
    k = int(k)
    #print(r,c,k)
    for i in range(1, k):
        trR,c1,c2 = lines[i].split()
        trR = int(trR)
        c1 = int(c1)
        c2 = int(c2)
        node = tracksHash.get(trR)
        if node == None:
            tracksHash[trR] = railTrack(c1,c2)
        else:
            tracksHash[trR].c1 = min( (c1,tracksHash[trR].c1 )  )
            tracksHash[trR].c2 = max( (c2,tracksHash[trR].c2 )  )
    occupied = countCells(tracksHash)
    total = r*c 
    freec = total - occupied
    print(freec)

if __name__ == '__main__':
	main()
