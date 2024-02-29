#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Cấp phát miền nhớ cho 1 node
    Node *createNode(int value)
    {
        return new Node(value);
    }

    // Thêm node vào đầu bên trái danh sách liên kết kép
    void insertLeftFront(Node *newNode)
    {
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Thêm node vào đầu bên phải danh sách liên kết kép
    void insertRightFront(Node *newNode)
    {
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Thêm node vào node giữa danh sách liên kết kép
    void insertAfter(Node *prevNode, Node *newNode)
    {
        if (prevNode == nullptr)
        {
            cout << "Node truoc do khong ton tai." << endl;
            return;
        }

        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (prevNode->next != nullptr)
        {
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
    }

    // Loại node cuối bên trái danh sách liên kết kép
    void deleteLeftRear()
    {
        if (head == nullptr)
        {
            cout << "Danh sach rong." << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }

        delete temp;
    }

    // Loại node cuối bên phải danh sách liên kết kép
    void deleteRightRear()
    {
        if (head == nullptr)
        {
            cout << "Danh sach rong." << endl;
            return;
        }

        Node *temp = tail;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }

        delete temp;
    }

    // Loại node ở giữa danh sách liên kết kép
    void deleteMiddle(Node *deleteNode)
    {
        if (deleteNode == nullptr)
        {
            cout << "Node can xoa khong ton tai." << endl;
            return;
        }

        if (deleteNode->prev != nullptr)
        {
            deleteNode->prev->next = deleteNode->next;
        }
        if (deleteNode->next != nullptr)
        {
            deleteNode->next->prev = deleteNode->prev;
        }

        delete deleteNode;
    }

    // Duyệt trái danh sách liên kết kép
    void traverseLeft()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Duyệt phải danh sách liên kết kép
    void traverseRight()
    {
        Node *current = tail;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // Tìm node trên danh sách liên kết kép
    Node *searchNode(int value)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

int main()
{
    DoublyLinkedList myDoublyList;

    // Khởi tạo danh sách liên kết kép
    Node *node1 = myDoublyList.createNode(10);
    Node *node2 = myDoublyList.createNode(20);
    Node *node3 = myDoublyList.createNode(30);

    // Thêm node vào đầu bên trái danh sách liên kết kép
    myDoublyList.insertLeftFront(node1);
    myDoublyList.insertLeftFront(node2);

    // Thêm node vào đầu bên phải danh sách liên kết kép
    myDoublyList.insertRightFront(node3);

    // Thêm node vào node giữa danh sách liên kết kép
    Node *node4 = myDoublyList.createNode(25);
    myDoublyList.insertAfter(node2, node4);

    // Hiển thị danh sách liên kết kép
    cout << "Danh sach liên kết kép: ";
    myDoublyList.traverseLeft();

    // Loại node cuối bên trái danh sách liên kết kép
    myDoublyList.deleteLeftRear();

    // Loại node cuối bên phải danh sách liên kết kép
    myDoublyList.deleteRightRear();

    // Loại node ở giữa danh sách liên kết kép
    Node *nodeToDelete = myDoublyList.searchNode(20);
    myDoublyList.deleteMiddle(nodeToDelete);

    // Hiển thị danh sách liên kết kép sau khi thay đổi
    cout << "Danh sach liên kết kép sau khi xoa: ";
    myDoublyList.traverseLeft();

    // Duyệt phải danh sách liên kết kép
    cout << "Duyet phai danh sach liên kết kép: ";
    myDoublyList.traverseRight();

    return 0;
}
