# Enter your code here. Read input from STDIN. Print output to STDOUT

N = int(str(input()).strip())
clouds = list(map(int, (str(input()).strip()).split()))
#print(clouds)
jumps = 0
#for i in range(N):
index = 0
while True:
    if index+2<=N-1 and clouds[index+2]==0:
        jumps += 1
        index += 2
    elif index+1<=N-1 and clouds[index+1]==0:
        jumps += 1
        index += 1
    if index>=N-1:
        break
print(jumps)
