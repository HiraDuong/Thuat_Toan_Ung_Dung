Written by Vũ Huy Hoàng 20204981 ( Hira )

Thực tế bài này là bản nâng cao của bài toán LARGEST RECTANGLE IN HISTOGRAM 
Thuật giải đơn giản sẽ là đưa về các bài toán LARGEST RECTANGLE IN HISTOGRAM con
bằng việc chuyển các hàng của ma trận A về dạng đầu vào của thuật giải kia

** 
Input: n,m, MatA(0 and 1 matrix)
Output: max area rect  
B1 : Chuyển MatA thành MatB lưu dữ liệu về độ cao cuả hình chữ nhật (Tính từ hàng 0)
     Giải pháp: Duyệt theo từng hàng, nếu phần tử [i] trong hàng bằng 0 thì coi đó là 
     mốc, từ đó tính được độ cao của các phần từ cùng cột nhưng ở các hàng dưới nếu 
     phần tử đó = 1

     Lưu ý :
        - Do duyệt từ trên xuống và bắt đầu từ hàng thấp nhất của trục tọa độ nên sẽ ghi 
        đè nếu có phần tử = 0 gần hơn ở cột trên
       vd : input:         Duyệt hàng 0      Duyệt hàng 1
        0    1 0 0 1     -> 1 0 0 1       ->  1 0 0 1
        1    1 0 0 0        1 0 0 0           1 0 0 0
        2    1 1 1 1        1 2 2 1           1 1 1 1
        - Chính vì duyệt từ trên xuống nên hàng đầu tiên sẽ không có mốc để tính độ cao,
        vì vậy nên phải thêm 1 cột phụ vào ngay trước đó và đẩy hàng 0 lên thành hàng 1.
        nên nó sẽ thành 
        vd : input:       Thêm hàng:        Duyệt hàng 1      Duyệt hàng 2
        0    1 0 0 1      0 0 0 0             0 0 0 0           0 0 0 0
        1    1 0 0 0      1 0 1 1          -> 1 0 0 1       ->  1 0 0 1
        2    1 1 1 1      1 0 0 0             2 0 0 0           2 0 0 0
        3                 1 1 1 1             3 2 2 1           3 1 1 1

B2 : Lúc này chúng ta đã có đầu vào cần thiết để chạy thuật toán largest rect
    duyệt từng hàng 1, sau này max sẽ ghi đè nên giá trị cuối vẫn là max
    
    Có 2 cách để giải quyết bài toán này: 
        Dùng stack hoặc cho chạy vòng lặp, 
        ở trong code hiện tại đang dùng cách stack
        Có thể thay hàm stack bằng vòng lặp sau
        
        for k in range(len(Mat)):
            
            for i in range(len(Mat[k])-1):
                for j in range(i+1,len(Mat[k])):
                    Max_area =max(Max_area, (j-i+1)*min(Mat[k][i:j+1]))