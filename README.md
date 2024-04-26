# Ultimate Dinasour
- Bài tập lớn môn học Lập trình nâng cao sử dụng ngôn ngữ C++ và thư viện SDL2
- Video giới thiệu game:<https://www.youtube.com/watch?v=RiUNwMcwlOA> <https://www.youtube.com/watch?v=9kUNWRCB--E> <https://www.youtube.com/watch?v=__-uUjxY1FE>
# Giới thiệu game
- Trong UltimateDinasour, bạn sẽ điều khiển nhân vật khung long tránh chướng ngại vật để giành được điểm số cao nhất có thế
#Cách tải game
 Vào link gitub trên <https://github.com/vietsosad/ultimate-dinosaur> và dowload các folder về máy, cài đặt visual code theo hướng dẫn <https://www.youtube.com/watch?v=UgJadfInqyo> và chơi

## 1.Cách chơi
- Khi bắt đầu vào game, bạn sẽ thấy môt màn hình chờ ![menu](https://github.com/vietsosad/ultimate-dinosaur/blob/master/DINASOUR/Turtorial/Screenshot%202024-04-26%20230304.png)
+ Nút Play: bắt đầu game
+ Nút Exit: kết thúc game
- Khi vào trong màn chơi:
+ Bạn sẽ thấy có các con quái:
   + Tên lửa: ![Rocket](https://github.com/vietsosad/ultimate-dinosaur/blob/master/DINASOUR/imgs/enemy/rocket_.png) 
   + Rơi:![Bat](https://github.com/vietsosad/ultimate-dinosaur/blob/master/DINASOUR/imgs/enemy/bat.png)
   + Xương Rồng: ![catus](https://github.com/vietsosad/ultimate-dinosaur/blob/master/DINASOUR/imgs/enemy/cactus.png) 
+ Khi bạn va chạm quái, bạn sẽ thua và game kết thúc, màn hình hiện ra cửa số GameOver, nhấn ok sẽ thoát ra khỏi màn hình. ![Over](https://github.com/vietsosad/ultimate-dinosaur/blob/master/DINASOUR/Turtorial/Screenshot%202024-04-26%20230345.png)
+ Khi đã né được quái, điểm của bạn sẽ tăng lên
## Cách chơi
- Bạn điều khiển nhân vật để nén các trở ngại ở trên, cố gắng dành điểm cao nhất có thể
- Thất bại: Khi bạn va chạm vào trở ngại
- Điều khiển: Giữ nút space để khủng long của thể bay, sử dụng phím mũi tên để di chuyển khủng long sang trái và phải
# Mã nguồn tham khảo 
- Từ trang lazyfoo và youtuber Lập trình game az
# Đồ họa đã sử dụng
- Lấy từ github của <https://github.com/thai-nm/dino-in-zungle/tree/master/imgs> và design cải tiến thêm
# Soucre code game
+ Folder CommonFunc: Chứa các thư viện thông dụng, struct tọa độ và hàm kiểm tra xử lí va chạm
+ Folder BaseObject: Chứa constructor và destructor, cũng như các hàm để load ảnh, để render lên một đối tượng với các thông số chỉ định cụ thể và hàm giải phóng
+ Folder MainObject: chính là hàm khởi tạo nhân vật khủng long để xác định tọa độ vị trí, di chuyển, tạo animation
+ Folder ThreatObjects: Tạo các vật cản , tương tự hàm MainObject
+ Folder LTexture:  Giống BaseObject nhưng phục vụ cho việc tạo Menu 
+ Folder Button: tạo hình để start và exit game, nhấn vào sẽ chơi và thoát
+ Folder TextObject: Hiện thị số điểm của người chơi lên trên màn hình
+ main.cpp: hàm main của chương trình, để xử lí các hàm được gọi và cũng chính là để code có thể chạy được hoàn thiện
## Thiếu sót
+Game vẫn còn nhiều hàm thô sơ, chưa tối ưu
+Hàm xử lí va chạm vẫn chưa tối ưu
+Thanh menu còn sơ sài, chưa đủ tính năng
  # Lời cảm ơn
  +Cuối cùng, kết thúc môn học, em muốn cảm ơn thầy Trọng và thầy Thủy đã tâm huyết truyền đạt kiến thức và giảng dạy những bài học hay, thú vị cho bọn em, giúp bọn em có kiến thức về SDL2 và C++ cũng như tạo một nền tảng vững chắc về sau!!!
