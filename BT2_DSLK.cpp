#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> myList; // Khởi tạo danh sách liên kết đơn

    // Chèn node vào đầu danh sách liên kết đơn
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);

    // Hiển thị nội dung trong danh sách liên kết đơn
    cout << "Danh sach liên kết đơn: ";
    for (const auto &element : myList)
    {
        cout << element << " ";
    }
    cout << endl;

    // Chèn node vào vị trí xác định trong danh sách liên kết đơn
    auto it = myList.begin();
    advance(it, 2);
    myList.insert(it, 25);
    cout << "Danh sach liên kết đơn sau khi chen node: ";
    for (const auto &element : myList)
    {
        cout << element << " ";
    }
    cout << endl;

    // Loại bỏ node tại vị trí xác định trong danh sách liên kết đơn
    it = myList.begin();
    advance(it, 1);
    myList.erase(it);
    cout << "Danh sach liên kết đơn sau khi loại bo node: ";
    for (const auto &element : myList)
    {
        cout << element << " ";
    }
    cout << endl;

    // Sửa đổi nội dung node trong danh sách liên kết đơn
    it = myList.begin();
    advance(it, 2);
    *it = 15;
    cout << "Danh sach liên kết đơn sau khi sua doi node: ";
    for (const auto &element : myList)
    {
        cout << element << " ";
    }
    cout << endl;

    // Sắp xếp các node của danh sách liên kết đơn
    myList.sort();
    cout << "Danh sach liên kết đơn sau khi sap xep: ";
    for (const auto &element : myList)
    {
        cout << element << " ";
    }
    cout << endl;

    // Đảo ngược các node trong danh sách liên kết đơn
    myList.reverse();
    cout << "Danh sach liên kết đơn sau khi dao nguoc: ";
    for (const auto &element : myList)
    {
        cout << element << " ";
    }
    cout << endl;

    // Tìm kiếm vị trí của node trong danh sách liên kết đơn
    it = find(myList.begin(), myList.end(), 15);
    if (it != myList.end())
    {
        int position = distance(myList.begin(), it);
        cout << "Vi tri cua node co gia tri 15 la: " << position << endl;
    }
    else
    {
        cout << "Khong tim thay node co gia tri 15 trong danh sach." << endl;
    }

    return 0;
}
