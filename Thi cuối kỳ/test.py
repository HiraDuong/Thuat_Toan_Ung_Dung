
   
def sovle(m,n):
    Mat = []
    for i in range(m):
        A = [int(j) for j in input().split()]
        Mat.append(A)
    #print(Mat)
    linh = []
    for i in range(m):
        for j in range(n):
            if(Mat[i][j] == 1):
                linh.append([i,j])

    for linhs in linh:
        x = linhs[0]
        y = linhs[1]
        for i in range(m):
            Mat[i][y] = 1
        for j in range(n):
            Mat[x][j] = 1

        
    vang = 0
    for i in range(m):
        for j in range(n):
            if(Mat[i][j] == 0):
                vang = vang+1
    return vang

T = int(input())

for i in range (T):
    mn = input().split()
    m = int(mn[0])
    n = int(mn[1])
    result = sovle(m,n)
    print("#"+str(i+1),end=" ")
    print(result)
