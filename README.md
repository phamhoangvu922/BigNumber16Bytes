# BigNumber16Bytes

# Ý tưởng thiết kế và thực hiện:

- Lưu QInt trong 1 mảng số nguyên kiểu __int64.
- Các phép tính được xây dựng theo cách thao tác trên 1 block 64 bit (8byte)
tức 1 số nguyên kiểu __int64.

- Do số nguyên lớn có độ dài lớn hơn kiểu dữ liệu mặc định đƣợc hỗ trợ bởi
ngôn ngữ lập trình, nên để đọc giá trị thập phân, dãy bit, nhóm sử cách đọc
theo chuỗi dạng string.

- Xây dựng các lớp phục vụ cho việc xử lí số nguyên 16 byte (QInt); việc
chuyển đổi các kiểu số (Convert); các lớp hỗ trợ cho các chức năng xử lí
trên các hệ cơ số nhị phân (CBin), thập phân (CDec), lục thập phân (Chex)
và một lớp cho việc đọc-ghi file trong đó:
Lớp số nguyên lớn (QInt) được xây dụng với dữ liệu được lưu theo Little
Endian.
Lớp chuyển đổi được xây dựng là lớp thuần tĩnh theo mẫu thiết kế
Singleton.

- Các phương thức được cài đặt dựa trên các phép toán thao tác trên bit mà
C++ có hỗ trợ.
- Ngoài ra cài đặt thêm một số hàm hỗ trợ trong quá trình thực hiện
(hàm kiếm tra bằng 0, hàm kiểm tra số âm, …)

# Thực hiện cài đặt:
Được cài đặt theo phương pháp hướng đối tƣợng
