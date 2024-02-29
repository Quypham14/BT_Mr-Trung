#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // Chèn node vào đầu danh sách liên kết đơn
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Chèn node vào vị trí xác định trong danh sách liên kết đơn
    void insertAtPosition(int value, int position)
    {
        if (position < 0)
        {
            cout << "Vi tri khong hop le." << endl;
            return;
        }

        Node *newNode = new Node(value);

        if (position == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *current = head;
        for (int i = 0; i < position - 1 && current != nullptr; ++i)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Vi tri vuot qua kich thuoc danh sach." << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Loại bỏ node tại vị trí Pos trong danh sách liên kết đơn
    void deleteAtPosition(int position)
    {
        if (isEmpty() || position < 0)
        {
            cout << "Danh sach rong hoac vi tri khong hop le." << endl;
            return;
        }

        Node *temp = head;

        if (position == 0)
        {
            head = head->next;
            delete temp;
            return;
        }

        Node *current = head;
        for (int i = 0; i < position - 1 && current != nullptr; ++i)
        {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr)
        {
            cout << "Vi tri vuot qua kich thuoc danh sach." << endl;
            return;
        }

        temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Sửa đổi nội dung node trong danh sách liên kết đơn
    void modifyNode(int position, int newValue)
    {
        if (isEmpty() || position < 0)
        {
            cout << "Danh sach rong hoac vi tri khong hop le." << endl;
            return;
        }

        Node *current = head;
        for (int i = 0; i < position && current != nullptr; ++i)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Vi tri vuot qua kich thuoc danh sach." << endl;
            return;
        }

        current->data = newValue;
    }

    // Sắp xếp các node của danh sách liên kết đơn
    void sortList()
    {
        if (isEmpty())
        {
            cout << "Danh sach rong." << endl;
            return;
        }

        Node *current = head;
        Node *index = nullptr;
        int temp;

        while (current != nullptr)
        {
            index = current->next;

            while (index != nullptr)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }

                index = index->next;
            }

            current = current->next;
        }
    }

    // Đảo ngược các node trong danh sách liên kết đơn
    void reverseList()
    {
        Node *prev = nullptr, *current = head, *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // Tìm kiếm vị trí của node trong danh sách liên kết đơn
    int findPosition(int value)
    {
        Node *current = head;
        int position = 0;

        while (current != nullptr)
        {
            if (current->data == value)
            {
                return position;
            }

            current = current->next;
            position++;
        }

        return -1; // Không tìm thấy giá trị trong danh sách
    }

    // Hiển thị nội dung trong danh sách liên kết đơn
    void displayList()
    {
        Node *current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    // Kiểm tra danh sách liên kết đơn có r
    // ...

    // Kiểm tra danh sách liên kết đơn có rỗng không
    bool isEmpty()
    {
        return head == nullptr;
    }
};

int main()
{
    LinkedList myList;

    // Khởi tạo danh sách liên kết đơn
    myList.insertAtBeginning(30);
    myList.insertAtBeginning(20);
    myList.insertAtBeginning(10);

    // Hiển thị nội dung trong danh sách liên kết đơn
    cout << "Danh sach liên kết đơn: ";
    myList.displayList();

    // Chèn node vào vị trí xác định trong danh sách liên kết đơn
    myList.insertAtPosition(25, 2);
    cout << "Danh sach liên kết đơn sau khi chen node: ";
    myList.displayList();

    // Loại bỏ node tại vị trí xác định trong danh sách liên kết đơn
    myList.deleteAtPosition(1);
    cout << "Danh sach liên kết đơn sau khi loại bo node: ";
    myList.displayList();

    // Sửa đổi nội dung node trong danh sách liên kết đơn
    myList.modifyNode(2, 15);
    cout << "Danh sach liên kết đơn sau khi sua doi node: ";
    myList.displayList();

    // Sắp xếp các node của danh sách liên kết đơn
    myList.sortList();
    cout << "Danh sach liên kết đơn sau khi sap xep: ";
    myList.displayList();

    // Đảo ngược các node trong danh sách liên kết đơn
    myList.reverseList();
    cout << "Danh sach liên kết đơn sau khi dao nguoc: ";
    myList.displayList();

    // Tìm kiếm vị trí của node trong danh sách liên kết đơn
    int position = myList.findPosition(15);
    if (position != -1)
    {
        cout << "Vi tri cua node co gia tri 15 la: " << position << endl;
    }
    else
    {
        cout << "Khong tim thay node co gia tri 15 trong danh sach." << endl;
    }

    return 0;
}
