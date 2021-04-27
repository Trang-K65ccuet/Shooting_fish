# Shooting Fish
- Thực hiện: Nguyễn Hà Trang - 20020482
- Mã LHP: INT 2215-2, N3

# Hướng dẫn cài đặt
- Link tải: https://drive.google.com/drive/folders/1D2Vka0Si9BvL1EX4PXYJI5DTEK3tsEm0?usp=sharing
- Chọn Shooting Fish -> Tải xuống
![image](https://user-images.githubusercontent.com/79615121/116037181-eeb15580-a691-11eb-9f96-53a0aad1ba76.png)
![image](https://user-images.githubusercontent.com/79615121/116037295-14d6f580-a692-11eb-9fa0-765c5faa83c6.png)
- Tại mục vừa download xuống, nhấn chuột phải chọn tệp và giải nén( Extract Here)
![image](https://user-images.githubusercontent.com/79615121/116037742-b65e4700-a692-11eb-8bdd-5bbe50291aff.png)
- Vào thư mục vừa được giải nén
![image](https://user-images.githubusercontent.com/79615121/116037890-eb6a9980-a692-11eb-8da9-7dedffc8e17f.png)
- Chọn Debug
![image](https://user-images.githubusercontent.com/79615121/116038001-1359fd00-a693-11eb-8334-82ca967969aa.png)
- Chọn ShootingFish.exe và bắt đầu chơi game
![image](https://user-images.githubusercontent.com/79615121/116038089-308ecb80-a693-11eb-8bf4-02a900cdefeb.png)
![image](https://user-images.githubusercontent.com/79615121/116038157-469c8c00-a693-11eb-9b5d-5d42aaae5165.png)

# Mô tả luồng hoạt động của game
1. Thành phần
* *Phần mở đầu
- Lựa chọn Play(chơi).
- Lựa chọn Exit(thoát game).
* *Phần game chính
- Con tàu(đối tượng chính) có khả năng bắn đạn.
- Cá di chuyển.
- Bom di chuyển.
- Trái tim( biểu thị mạng của người chơi)
- Điểm số( tăng và giảm tương ứng với vật bắn được).
- Nhạc nền game.
- Âm thanh khi đạn bắn và khi bắn trúng cá hoặc bom.
* *Phần kết thúc game(hiện ra sau khi game over)
- Lựa chọn Quit(thoát game).
- Lựa chọn Play Again(chơi lại). 
2. Thao tác chơi
- Với phần mở đầu, nhấn Play để chơi, nếu không nhấn Exit.
- Dùng các phím lên, xuống, trái, phải để di chuyển con tàu đến vị trí mong muốn.
- Sử dụng phím cách hoặc chuột trái để bắn đạn.
- Nếu đạn bắn vào cá, điểm số tăng và cá biến mất.
- Nếu đạn bắn vào bom, điểm số giảm, bom bị nổ và biến mất. Đồng thời, số tim(mạng) bị giảm.
- Khi bắn bom 3 lần( hết tim), game over.
- Sau khi game over, chọn Quit để thoát, nếu muốn chơi lại chọn Play Agian.

# Nguồn tham khảo
1. Tham khảo về lập trình 1 game C++ cơ bản trên web https://phattrienphanmem123az.com/lap-trinh-game-cpp
2. Các sửa đổi:
 - Tự thiết kế lại background, cùng việc thiết kế các nhân vật.
 - Ngoài việc sử dụng chuột để bắn, còn lập trình để sử dụng thêm phím cách.
 - Lập trình để có nhiều đối tượng bắn( cá, bom) thay vì chỉ một loại thread.
 - Sửa đổi linh hoạt vị trí đạn bắn ra, cũng như cự li mỗi lần di chuyển của con tàu sao cho phù hợp.
 - Lập trình để điểm số giảm, chứ không chỉ tăng nhưng game tham khảo.
 - Tạo âm thanh nền cho game.
 - Tạo được giao diện đẹp hơn cho phần Game Over thay vì  dùng Message Box.
 - Lập trình tạo được phần Play Again, giúp chơi lại mà không cần thoát trò chơi rồi mở lại.

# Link video demo:
- Drive: https://drive.google.com/file/d/16fmVqqQny4AV8GcLJ4A1ZtXp8KqLnV5N/view?fbclid=IwAR0a8Jz-sYoUsw0V4Gd8_chsmtHnfCRNvFyrW8FpyiTcgP_ZFejYRjX7S2M
- Youtube: https://www.youtube.com/watch?v=H_vG9TUyuMY
