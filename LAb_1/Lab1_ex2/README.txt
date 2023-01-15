Written by Vu Huy Hoang 20204981 ( Hira )

Bài Maze này có 2 hướng giải quyết là dùng dfs và bfs, tuy nhiên
dfs chưa chắc đã là thuật toán chạy nhanh nhất và tìm được con đường ngắt nhất,
ngược lại bfs thì lại đưa ra được con đường ngắn nhất, dù thời gian có thể chậm 
hơn dfs (tùy trường hợp) nên cách tối ưu bài này là dùng bfs

Lưu ý : Vì cột hàng trong đề bài tính từ số 1, trong khi index của list( array nếu 
xài ngôn ngữ khác) bắt đầu từ 0 nên khi đưa vào hoặc in đường đi phải + index với 1 
và trừ input đi 1

Sơ qua về thuật toán
Gồm 3 list:
Before : Lưu tọa độ đỉnh cha gần nhất của đỉnh đang xét ( theo duyệt bfs)
Queue : FIFO, first in first out, chứa các đỉnh cần duyệt bfs
move = [(-1,0),(1,0),(0,1),(0,-1)] : lên xuống phải trái để trỏ tới đỉnh cần duyệt 
tiếp theo

Khởi tạo Queue = [(r,c)]
Lặp : Chừng nào Queue còn phần tử thì tiếp tục()
Bắt đầu từ đỉnh (r,c), trỏ theo move đi tìm các đỉnh con (x,y) (có value = 0),
sau đó thêm vào Queue, lúc này tức là đỉnh (r,c) đã duyệt xong và đi ra, Queue.pop()
và đổi value = 2 (bằng gì cũng được miễn là khác 0 để phân biệt với đỉnh chưa duyệt)
lúc này cũng đồng thời cho Before(x,y) = (r,c) để sau này truy vết. Cứ tiếp tục duyệt
cho tới khi gặp đỉnh có tọa độ ở biên (tức là ở hàng 1, hàng cuối hoặc cột 1 hoặc cột cuối)
thì break, khi đó ta có ngay tọa độ của đỉnh ra gần nhất
Dựa vào tọa độ đỉnh ra, ta truy vết ngược lại, đồng thời mỗi lần truy vết count 
tăng thêm 1 đv cho tới khi gặp được đỉnh xuất phát thì dừng

Lưu ý : count chỉ là số bước ngắn nhất từ đỉnh ban đầu tới đỉnh biên của matrix,
vì vậy nên phải mất thêm 1 bước nữa để thoát ra khỏi mê kyuu nên tổng số bước phải 
là count +1


