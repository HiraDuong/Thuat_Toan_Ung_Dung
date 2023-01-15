Written by Vu Huy Hoang (Hira) 20204981
SoICT 

- Cần để 3 file main,data,query trong cùng 1 folder
- Chỉ cần chạy mỗi file main

Test Case :
 
call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
#
?check_phone_number
?number_calls_from 0912345678
?number_total_calls
?count_time_calls_from 0912345678
?count_time_calls_from 0132465789
#

Output: 

1
2
4
398.0
120.0

Mô tả :
- Gồm 3 file data , query và main
+ data để lấy dữ liệu từ log
+ query chứa các câu lệnh truy vấn
+ main là file chính của chương trình,(file chạy)