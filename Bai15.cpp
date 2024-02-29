#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    // Hàm khởi tạo
    Queue() : front(nullptr), rear(nullptr) {}

    // Hàm kiểm tra hàng đợi có rỗng không
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Hàm thêm phần tử vào hàng đợi
    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Da them phan tu " << value << " vao hang doi." << endl;
    }

    // Hàm lấy phần tử khỏi hàng đợi
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Hang doi rong. Khong the lay phan tu." << endl;
            return;
        }

        Node *temp = front;
        front = front->next;

        cout << "Phan tu " << temp->data << " da duoc lay ra khoi hang doi." << endl;

        delete temp;

        // Nếu hàng đợi trở thành rỗng sau khi lấy đi một phần tử
        if (front == nullptr)
        {
            rear = nullptr;
        }
    }

    // Hàm lấy giá trị ở đầu hàng đợi
    int peek()
    {
        if (isEmpty())
        {
            cout << "Hang doi rong. Khong co phan tu de xem." << endl;
            return -1; // Giá trị mặc đặt khi hàng đợi rỗng
        }

        return front->data;
    }
};

int main()
{
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Gia tri tai dau hang doi: " << myQueue.peek() << endl;

    myQueue.dequeue();
    myQueue.dequeue();

    cout << "Gia tri tai dau hang doi sau khi lay di 2 phan tu: " << myQueue.peek() << endl;

    return 0;
}
