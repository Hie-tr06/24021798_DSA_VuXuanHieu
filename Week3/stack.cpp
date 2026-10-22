#include <iostream>
using namespace std;
//Stack dùng list (Nên dùng hơn linklist ở dưới)
struct ListStack {
    int arr[1000];
    int n;

    ListStack() {
        n = 0;
    }

    bool isEmpty() {
        return n == 0;
    }

    int size() {
        return n;
    }

    void push(int item) {
        arr[n] = item;
        n++;
    }

    int top() {
        if (isEmpty()) return -1;
        return arr[n - 1];
    }

    int pop() {
        if (isEmpty()) return -1;
        int popItem = arr[n - 1];
        n--;
        return popItem;
    }
};

int main() {
    ListStack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Kich thuoc: " << s.size() << endl;
    cout << "Gia tri dinh: " << s.top() << endl;

    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    cout << endl;

    return 0;
}

//Stack dùng linklist
/*
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

Node* themdau(Node* head, int data) {
    Node* p = new Node(data);
    p->next = head;
    return p;
}

Node* xoadau(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

struct Stack {
    Node* head;
    int n;

    Stack() {
        head = nullptr;
        n = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int size() {
        return n;
    }

    int top() {
        if (isEmpty()) return -1;
        return head->data;
    }

    void push(int item) {
        head = themdau(head, item);
        n++;
    }

    int pop() {
        if (isEmpty()) return -1;
        int popItem = head->data;
        head = xoadau(head);
        n--;
        return popItem;
    }
};

int main() {
    Stack s;
    s.push(4);
    s.push(5);
    s.push(6);

    cout << "Kich thuoc: " << s.size() << endl;
    cout << "Gia tri dinh: " << s.top() << endl;

    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    cout << endl;

    return 0;
}

*/