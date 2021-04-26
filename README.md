# Shooting Fish
Thực hiện: Nguyễn Hà Trang - 20020482
Mã LHP: INT 2215-2, N3

1. Hướng dẫn cài đặt
- Link tải: https://drive.google.com/drive/folders/1VV3-_r49s7apKs6lWocaHqAF3SyqeM8j?fbclid=IwAR2Lim4Xds12u82czDnJ61HMp7kXbS49bjClr9tWENDxRlzYnbhn_js6inw
![image](https://user-images.githubusercontent.com/79615121/116036868-8498b080-a691-11eb-9bbf-68ad7e74d6d6.png)

2. Mô tả luồng hoạt động của game
2.1. Thành phần
2.1.1. Phần mở đầu
- Lựa chọn Play(chơi).
- Lựa chọn Exit(thoát game).
2.1.2. Phần game chính
- Con tàu(đối tượng chính) có khả năng bắn đạn.
- Cá di chuyển.
- Bom di chuyển.
- Trái tim( biểu thị mạng của người chơi).
- Điểm số( tăng và giảm tương ứng với vật bắn được).
- Nhạc nền game.
- Âm thanh khi đạn bắn và khi bắn trúng cá hoặc bom.
2.1.3. Phần kết thúc game(hiện ra sau khi game over)
- Lựa chọn Quit(thoát game).
- Lựa chọn Play Again(chơi lại). 
2.2. Thao tác chơi
- Với phần mở đầu, nhấn Play để chơi, nếu không nhấn Exit.
- Dùng các phím lên, xuống, trái, phải để di chuyển con tàu đến vị trí mong muốn.
- Sử dụng phím cách hoặc chuột trái để bắn đạn.
- Nếu đạn bắn vào cá, điểm số tăng và cá biến mất.
- Nếu đạn bắn vào bom, điểm số giảm, bom bị nổ và biến mất. Đồng thời, số tim(mạng) bị giảm.
- Khi bắn bom 3 lần( hết tim), game over.
- Sau khi game over, chọn Quit để thoát, nếu muốn chơi lại chọn Play Agian.

3. Nguồn tham khảo
 Tham khảo về lập trình 1 game C++ cơ bản trên web https://phattrienphanmem123az.com/lap-trinh-game-cpp
 Các sửa đổi:
 - Tự thiết kế lại background, cùng việc thiết kế các nhân vật.
 - Ngoài việc sử dụng chuột để bắn, còn lập trình để sử dụng thêm phím cách.
 - Lập trình để có nhiều đối tượng bắn( cá, bom) thay vì chỉ một loại thread.
 - Sửa đổi linh hoạt vị trí đạn bắn ra, cũng như cự li mỗi lần di chuyển của con tàu sao cho phù hợp.
 - Lập trình để điểm số giảm, chứ không chỉ tăng nhưng game tham khảo.
 - Tạo âm thanh nền cho game.
 - Tạo được giao diện đẹp hơn cho phần Game Over thay vì  dùng Message Box.
 - Lập trình tạo được phần Play Again, giúp chơi lại mà không cần thoát trò chơi rồi mở lại.

3. Link video demo:
 
