//Queue bằng list
/*
#include <iostream>
using namespace std;

struct ListQueue {
    int arr[1000];
    int headIndex;
    int tailIndex;

    ListQueue() {
        headIndex = 0;
        tailIndex = 0;
    }

    bool isEmpty() {
        return headIndex == tailIndex;
    }

    int size() {
        return tailIndex - headIndex;
    }

    void enqueue(int item) {
        arr[tailIndex] = item;
        tailIndex++;
    }

    int front() {
        if (isEmpty()) return -1;
        return arr[headIndex];
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int popItem = arr[headIndex];
        headIndex++;
        return popItem;
    }
};

int main() {
    ListQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Kich thuoc: " << q.size() << endl;
    cout << "Gia tri dau: " << q.front() << endl;

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;
}
*/


//Queue bằng linklist (queue sẽ dùng linklist thay vì list như bên stack)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* themcuoi(Node* head, int data) {
    Node* p = new Node(data);
    if (head == nullptr) return p;
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = p;
    return head;
}

Node* xoadau(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

struct Queue {
    Node* head;
    int n;

    Queue() {
        head = nullptr;
        n = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int size() {
        return n;
    }

    int front() {
        if (isEmpty()) return -1;
        return head->data;
    }

    void enqueue(int item) {
        head = themcuoi(head, item);
        n++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int popItem = head->data;
        head = xoadau(head);
        n--;
        return popItem;
    }
};

int main() {
    Queue q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    cout << "Kich thuoc: " << q.size() << endl;
    cout << "Gia tri dau: " << q.front() << endl;

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;
}