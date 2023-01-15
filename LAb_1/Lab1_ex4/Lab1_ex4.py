'''
    
      ________________________________
                        |*******************************|
                        |*******************************|
                        |***       Vũ Huy Hoàng      ***|
                        |***         20204981        ***|
                        |***         IT_E6-05        ***|
                        |*******************************|
                        |*******************************|                
    
    '''

def cac_max_rect(Mat):
    """
    Lý do phải thêm 1 hàng 0 ở đây là do mình lấy số 0 làm mốc để tính chiều
    cao của hình chữ nhật nên mới thế( vì có th hàng đầu tiên là số 1 thì nó 
    bị ngu nên không tính được height)
    """
    list = []
    for i in range (len(Mat[0])):
        list.append(0)
    #print(list)
    Mat.insert(0,list)
    H = Mat
    '''  ____________c
        |
        |
        |
        r
        
    '''
    # caculate the height of rect
    '''# đoạn này do duyệt từ trên xuống nên là daijoubu, nó sẽ ghi đè nếu gặp 
    ô số 0 gần hơn '''
    for i in range (len(H)):
        for j in range(len(H[i])):
            if H[i][j] == 0:
                for k in range(i,len(H)):
                    if H[k][j] != 0:
                        H[k][j] = k - i
    H.pop(0)
    return H
    #print(H)

def largest_rect_solve2(Mat):
    Max_area = 0

    for k in range(len(Mat)):
        for i in range(len(Mat[k])-1):
            for j in range(i+1,len(Mat[k])):
                Max_area =max(Max_area, (j-i+1)*min(Mat[k][i:j+1]))
 
    return Max_area
    

def largest_rect(Mat):
    Max_area = 0
    #  Duyệt thuật toán từ từng hàng của ma trận bổ sung
    
    for k in range(len(Mat)):
        stack = []
        
        for i,h in enumerate(Mat[k]):
            start = i
            while stack and stack[-1][1] > h:
                index,height = stack.pop()
                Max_area = max(Max_area,height*(i-index))
                start = index
            stack.append((start,h))
        for i ,h in stack:
            Max_area = max(Max_area,h*(len(Mat[k])-i))
       

        '''for i in range(len(Mat[k])-1):
            for j in range(i+1,len(Mat[k])):
                Max_area =max(Max_area, (j-i+1)*min(Mat[k][i:j+1]))'''
 
    return Max_area


A = []
n,m = map(int,input().split())
for i in range(n):
    list = input().split()
    
    A.append([eval(j) for j in list])

'''
for i in range(len(A)):
    print(A[i])'''
#cac_max_rect(A)
B = cac_max_rect(A)
'''for i in range(len(B)):
    print(B[i])'''
for i in range(len(B)):
    print(B[i])
print(largest_rect(B))

#largest_rect(B)