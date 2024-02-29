#include <iostream>
#define MAX_SIZE 100

using namespace std;

class Stack
{
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    // Kiểm tra ngăn xếp có rỗng không
    bool isEmpty()
    {
        return top == -1;
    }

    // Kiểm tra ngăn xếp có đầy không
    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    // Thêm phần tử vào đỉnh ngăn xếp
    void push(int value)
    {
        if (isFull())
        {
            cout << "Ngan xep day. Khong the them phan tu." << endl;
            return;
        }
        arr[++top] = value;
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
        cout << "Da lay " << arr[top--] << " tu ngan xep." << endl;
    }

    // Xem phần tử ở đỉnh ngăn xếp
    void peek()
    {
        if (isEmpty())
        {
            cout << "Ngan xep rong. Khong co phan tu nao." << endl;
            return;
        }
        cout << "Phan tu o dinh ngan xep la: " << arr[top] << endl;
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
        for (int i = 0; i <= top; ++i)
        {
            cout << arr[i] << " ";
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
