


def in_Maze(Mat,r,c):
    if 0<=r<len(Mat) and 0<=c<len(Mat[0]):
        return True
    else: return False

def BFS(Mat,r,c):
    # Tạo before để truy vết
    Before = [(0,0)]*len(Mat)
    for j in range(len(Mat)):
        Before[j] = [(0,0)]*len(Mat[0])

    Queue = [(r,c)]
    #print(Queue)
    # up,down,right,left
    move = [(-1,0),(1,0),(0,1),(0,-1)]
    count = 0
    while Queue:
    #  duyet tung dinh(start BFS)
        x,y = Queue[0][0],Queue[0][1]
        
        #print (str(x)+" "+str(y))
        #count +=1

        if in_Maze(Mat,x,y) :
            for i in (move):
                if in_Maze(Mat,x + i[0],y+i[1])and Mat[x+i[0]][y+i[1]]==0:
                    if (x + i[0],y+i[1]) not in Queue:
                        Before[x + i[0]][y+i[1]] = (x,y)
                        Queue.append((x + i[0],y+i[1]))
            Mat[x][y] = 2 # 2 mean visited
            Queue.pop(0)
            '''
            check thứ tự duyệt 
            print(Queue)'''
            if x== 0 or x == len(Mat)-1 or y == 0 or y == len(Mat[0])-1:        
                #in ra điểm cuối của đường ngắn nhất
                #print(count)
                break
            # tức là nếu vẫn đang trong mê kyuu mà hết đỉnh duyệt (hết đường đi)
            # - >  không còn đường chạy -> chúc mừng bạn quay vào -1
            if len(Queue) == 0 and 0<x<len(Mat)-1 and 0<y<len(Mat) - 1:
                print("-1")
                print("There is no way to nigerou outside of Matrix :))")
                return 0

    #print("done "+str(x+1)+" "+str(y+1))
    '''for i in range(len(Before)):
        print(Before[i])
        '''
    # Truy vết :
    #print("The shortest path is: ")
    while (x,y) != (r,c):
        #print(str((x+1,y+1)),end="<-")
        (x,y) = Before[x][y]
        count+=1
    '''print(str((r+1,c+1)))
    print("with "+str(count+1)+" steps ")'''
    print(count+1)

    '''for i in range(len(Mat)):
        
        print(Mat[i])'''


N,M,row,col = map(int,input().split())

A = []
Path = []
for i in range(N):		 
    list = input().split()
    A.append([eval(j) for j in list])


BFS(A,row-1,col-1)




