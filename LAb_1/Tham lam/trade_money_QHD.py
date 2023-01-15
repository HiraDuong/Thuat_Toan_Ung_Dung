# Give 5 types of coin 1, 5, 10, 25, 100 cent
# find the way to give X cent which the number of coins 
# is minimun using QHD   Solution

infi = 99999

# USING     Quy hoạch động  
mem = [[-1 for i in range(10)] for j in range(1000)]
d = []
def otp (i,X):
    if(i == -1 ): return infi
    if (X == 0): return 0
    if (X<0): return infi
    if (mem[i][X] != -1): return mem[i][X]
    ans = infi
    ans = min(ans,1+otp(i,X-d[i]))
    ans = min(ans,otp(i-1,X))
    mem[i][X] = ans
    return ans

def trade(i, X):
    if ( i == -1): return
    if (X<=0): return
    if (mem[i][X] == 1+otp(i,X-d[i])):
        print(d[i])
        trade(i,X-d[i])
    else: trade (i-1,X)

