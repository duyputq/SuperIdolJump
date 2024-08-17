# JumpIdol Game

Sinh viên: Nguyễn Gia Duy

MSV: 21021571

Video youtube demo game: https://youtu.be/a7PdL-aVrXw

# Giới thiệu Game

Mỗi người trong chúng ta đều phải tìm được công chúa của cuộc đời mình. Để tìm được công chúa, chúng ta phải trải qua rất nhiều thử thách khác nhau trong cuộc sống. Từ ý tưởng đó, game JumpIdol là game giải cứu công chúa ra đời với mục đích giúp người chơi giải trí sau những giờ học căng thẳng. Game điều khiển nhân vật nhảy qua các màn với các chướng ngại vật có độ khó tăng dần. Khi đến màn cuối và giải cứu được công chúa, bạn sẽ trở thành "Super Idol" và giành chiến thắng.

# Mục lục

- [1. Bắt đầu game](#1bắt-đầu-game)
- [2. Các thành phần trong game:](#2các-thành-phần-trong-game)
- [3. Cách chơi](#3cấu-trúc-code)
- [4. Hình ảnh trong game](#4cách-chơi--hình-ảnh-trong-game)
- [5. Các kĩ thuật sử dụng](#5các-kỹ-thuật-sử-dụng)
- [6. Nguồn tham khảo](#6nguồn-tham-khảo)
- [7. Hướng phát triển](#7hướng-phát-triển)
- [8. Nhật ký, quá trình phát triển](#8nhật-ký-quá-trình-phát-triển)
- [9. Lời kết](#9lời-kết)


# 1.Bắt đầu game

Người chơi sẽ bắt đầu tại màn 1. Game có 5 màn tất cả. Người chơi phải vượt qua các chướng ngại vật ở các màn. Công chúa sẽ xuất hiện ở màn 5.

# 2.Các thành phần trong game

- Nhân vật chính: ![Jump_king_32px](https://github.com/user-attachments/assets/2391edea-a73e-4901-b92d-e04a35b77619) nhân vật mà chúng ta điều khiển

- Công chúa: ![princess](https://github.com/user-attachments/assets/823c5086-21c8-4ada-b96a-79ab14ba3138) công chúa mà ta cần giải cứu

- Đất: ![dat](https://github.com/user-attachments/assets/b30aa76b-016a-4a9e-b233-e41e9184d98c) những vật thể mà ta có thể đứng lên được, va chạm

- Nền: ![nen](https://github.com/user-attachments/assets/b4c4fda1-3ccd-4d44-a421-8fa3d44be8de)  các vật thể nền

- Chướng ngại vật (gai): ![spikes](https://github.com/user-attachments/assets/4becad23-262a-46f9-8eee-2221a85f2f8f) những vật mà chạm vào sẽ chết

# 3.Cấu trúc code  

Thư mục assets để lưu các tài nguyên trong game: đồ họa, map, nhân vật,...
Thư mục Src gồm các source code:
- Thư mục ECS để quản lý các thực thể dựa trên nguyên tắc Enity Component System ([Link đọc về ECS](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwi65s61wfuHAxUM5DQHHXfkCsgQFnoECBgQAw&url=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FEntity_component_system&usg=AOvVaw02h3nWP6I8lGnv9KjrXXU3&opi=89978449))
    + SpriteComponent.h để xử lý hoạt ảnh nhân vật
    + TileComponent.h để xử lý các vật thể đất, nước
    + KeyboradController.h để xử lý các sự kiện bàn phím
    + Animation.h để xử lý setup animation
    + TransformComponent.h để xử lý dịch chuyển của nhân vật
- File main.cpp là file chính để khởi tạo, kết thúc game
- File Game.cpp là file để xử lý chinh các sự kiện trong game
- File Collision.cpp để xử lý các va chạm trong game
- File GameObject.cpp để set up object trong game
- File Map.cpp để vẽ màn chơi trong game
- File TextureManager.cpp để vẽ đồ họa trong game
- File Vector2D để xử lý tọa độ của nhân vật trong game theo hướng vector

# 4.Cách chơi & Hình ảnh trong game

- Cách chơi: Người chơi sẽ dùng hai phím mũi tên trái, phải để di chuyển sang trái phải, phím Space để nhảy. Khi chết và chiến thắng, người chơi có thể dùng phím "R" để chơi lại từ đầu hoặc phím "Q" để thoát trò chơi.

- Màn 1: 
![Image](https://github.com/user-attachments/assets/1269d4c2-605f-438d-892b-b4255c363c34)

- Màn 2: 
![man2](https://github.com/user-attachments/assets/a9579c9d-29dc-4ba4-8074-cf0b7579297c)

- Màn 3: Số lượng gai nhiều hơn
![man3](https://github.com/user-attachments/assets/af70cdf1-3c2b-4270-9843-9cf9dfb68ba0)

- Màn 4: Số lượng gai nhiều hơn và xuất hiện ở vị trí khó hơn
 ![man4](https://github.com/user-attachments/assets/79e7998b-bebc-4a83-a04f-353d7e43cdcd)

- Màn 5: Công chúa xuất hiện
 ![man5](https://github.com/user-attachments/assets/3189aec8-f709-4d22-adee-38786a20a4a8)


- Nhân vật rơi bởi trọng lực: 
![gravity](https://github.com/user-attachments/assets/5df19f34-a191-4fca-bea2-e5c9f763ebba)


- Notification khi chiến thắng: khi ta tìm được công chúa
![noti_win](https://github.com/user-attachments/assets/cd01a098-4d94-494b-bae0-0d3f25c2d0c2)



- Notification khi chết (nhảy vào gai): Nhấn R để chơi lại, hoặc Q để thoát
![noti_death1](https://github.com/user-attachments/assets/bcf06d3e-ada5-4755-8e74-cc91954c98dd)

- Notification khi chết (rơi xuống gai):
![noti_death2](https://github.com/user-attachments/assets/1f3539f2-2ce0-43dd-b833-21a1ed9456b4)



# 5.Các kỹ thuật sử dụng

- Sử dụng thư viện SDL2.0
- Sử dụng nhiều class, vector, tách file, nạp chồng toán tử,...
- Kỹ thuật xử lý va chạm ABAB: nếu va chạm với đất thì sống, nếu va chạm với gai thì chết, nếu gặp công chúa thì chiến thắng,...
- Kỹ thuật tạo ra trọng lực

# 6.Nguồn tham khảo

- Ý tưởng game lấy cảm hứng từ những game nổi tiếng như Getting Over It (Băng qua các màn lên đỉnh cao nhất) , Mario (cứu công chúa)

- Tham khảo cách dùng SDL trên trang lazyfoo https://lazyfoo.net/tutorials/SDL/

- Tham khảo các tổ chức file trên kênh youtube Let's Make Game

- Đồ họa nhân vật và công chúa lấy sprite từ [Nguồn Sprite trên trang Spriter-Resource](https://www.spriters-resource.com/fullview/121682/)

- Xử lý các tính năng em tự code 100%

# 7.Hướng phát triển
- Tối ưu hóa game hơn
- Thêm nhiều màn với độ khó tăng dần hơn
- Làm cho cú nhảy "vật lý" hơn
- Tạo ra nhiều vật cản gây chết hơn (ví dụ phun lửa, gai có thể di chuyển)
- Phần chuyển cảnh mượt mà hơn



# 8.Nhật ký, quá trình phát triển
Ý tưởng sơ khai ban đầu

![image](https://github.com/user-attachments/assets/70ef4679-051c-471a-9f80-e6600645b67f)

Thêm phần đồ họa, ý tưởng chạm tới đích đến
![image](https://github.com/user-attachments/assets/2ff6e4c7-ae8a-402b-88f6-bbdbb1315ae8)

Ý tưởng chuyển cảnh
![image](https://github.com/user-attachments/assets/65942a89-618e-4049-85cd-cf8c5080fb63)

# 9.Lời kết
Em làm game này từ khâu lên ý tưởng, viết mã, debug trong vòng 1 tháng. Nhìn chung, game đã thực hiện được những chức năng cơ bản và thực thi được đồ họa 2D. Game có thể được cải tiến nhiều hơn nếu em viết trong 1 kỳ chính. Em xin cảm ơn thầy Trọng đã dành thời gian giảng dạy, hướng dẫn chúng em trong kỳ hè này. 