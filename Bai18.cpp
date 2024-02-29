#include <iostream>
using namespace std;
const int MAX_SIZE = 5;

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Hang doi vong day. Khong the them phan tu." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = value;
        cout << "Da them phan tu " << value << " vao hang doi vong." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Hang doi vong rong. Khong the lay phan tu." << endl;
            return;
        }

        cout << "Phan tu " << arr[front] << " da duoc lay ra khoi hang doi vong." << endl;

        if (front == rear) {
            // Nếu chỉ còn một phần tử, reset front và rear
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Hang doi vong rong. Khong co phan tu de xem." << endl;
            return -1;
        }

        return arr[front];
    }
};

int main() {
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
