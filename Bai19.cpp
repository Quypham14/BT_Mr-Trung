#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularQueue
{
private:
    Node *front;
    Node *rear;

public:
    CircularQueue() : front(nullptr), rear(nullptr) {}

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            front = rear = newNode;
            rear->next = front; // Liên kết vòng
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Liên kết vòng
        }

        cout << "Da them phan tu " << value << " vao hang doi vong." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Hang doi vong rong. Khong the lay phan tu." << endl;
            return;
        }

        Node *temp = front;

        if (front == rear)
        {
            // Nếu chỉ còn một phần tử, reset front và rear
            front = rear = nullptr;
        }
        else
        {
            front = front->next;
            rear->next = front; // Cập nhật liên kết vòng
        }

        cout << "Phan tu " << temp->data << " da duoc lay ra khoi hang doi vong." << endl;
        delete temp;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Hang doi vong rong. Khong co phan tu de xem." << endl;
            return -1;
        }

        return front->data;
    }
};

int main()
{
    CircularQueue myCircularQueue;

    myCircularQueue.enqueue(10);
    myCircularQueue.enqueue(20);
    myCircularQueue.enqueue(30);

    cout << "Gia tri tai dau hang doi vong: " << myCircularQueue.peek() << endl;

    myCircularQueue.dequeue();
    myCircularQueue.dequeue();

    cout << "Gia tri tai dau hang doi vong sau khi lay di 2 phan tu: " << myCircularQueue.peek() << endl;

    return 0;
}
