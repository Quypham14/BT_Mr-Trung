#include <iostream>

using namespace std;

// Định nghĩa một nút trong danh sách liên kết đơn
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Định nghĩa lớp ngăn xếp sử dụng danh sách liên kết đơn
class Stack
{
private:
    Node *top; // Con trỏ đến đỉnh ngăn xếp

public:
    Stack()
    {
        top = nullptr;
    }

    // Kiểm tra ngăn xếp có rỗng không
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Thêm phần tử vào đỉnh ngăn xếp
    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Da them " << value << " vao ngan xep." << endl;
    }

    // Lấy phần tử từ đỉnh ngăn xếp
    void pop()
    {
        if (isEmpty())
        {
            cout << "Ngan xep rong. Khong the lay phan tu." << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        cout << "Da lay " << temp->data << " tu ngan xep." << endl;
        delete temp;
    }

    // Xem phần tử ở đỉnh ngăn xếp
    void peek()
    {
        if (isEmpty())
        {
            cout << "Ngan xep rong. Khong co phan tu nao." << endl;
            return;
        }
        cout << "Phan tu o dinh ngan xep la: " << top->data << endl;
    }

    // Hiển thị toàn bộ ngăn xếp
    void display()
    {
        if (isEmpty())
        {
            cout << "Ngan xep rong. Khong co phan tu nao." << endl;
            return;
        }
        cout << "Cac phan tu trong ngan xep la:" << endl;
        Node *current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    myStack.display();

    myStack.pop();

    myStack.display();

    myStack.peek();

    return 0;
}
