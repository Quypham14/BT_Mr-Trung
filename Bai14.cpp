#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

class Queue
{
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    // Hàm khởi tạo
    Queue()
    {
        front = -1;
        rear = -1;
    }

    // Hàm kiểm tra hàng đợi có rỗng không
    bool isEmpty()
    {
        return front == -1;
    }

    // Hàm kiểm tra hàng đợi có đầy không
    bool isFull()
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Hàm thêm phần tử vào hàng đợi
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Hang doi day. Khong the them phan tu." << endl;
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = value;
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

        cout << "Phan tu " << arr[front] << " da duoc lay ra khoi hang doi." << endl;

        if (front == rear)
        {
            // Nếu chỉ còn một phần tử, reset front và rear
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
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

        return arr[front];
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
