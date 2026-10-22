#include <iostream>
using namespace std;

// Dinh nghia Struct Node
struct Node {
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Ham them vao dau danh sach
Node *insertAtBeginning(Node *head, int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    return head;
}

// Ham them vao cuoi danh sach
Node *insertAtEnd(Node *head, int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
        return newNode;
    }

    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Ham them vao 1 vi tri bat ky (pos bat dau tu 1)
Node *insertAtPos(Node *head, int pos, int value) {
    if (pos <= 0) {
        cout << "Vi tri khong hop le!" << endl;
        return head;
    }

    if (pos == 1) {
        return insertAtBeginning(head, value);
    }

    Node *newNode = new Node(value);
    Node *current = head;

    // Duyet den vi tri truoc pos (pos - 1)
    for (int i = 1; i < pos - 1 && current != nullptr; i++) {
        current = current->next;
    }

    // Neu pos vuot qua do dai danh sach
    if (current == nullptr) {
        cout << "Vi tri khong hop le!" << endl;
        delete newNode; // Giai phong bộ nho cap phat du
        return head;
    }

    // Thuc hien chen
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Ham xoa node dau danh sach
Node *deleteAtBeginning(Node *head) {
    if (head == nullptr) {
        return nullptr; // Danh sach rong
    }

    Node *temp = head;
    head = head->next;
    delete temp; // Giai phong bo nho node dau
    return head;
}

// Ham xoa node cuoi danh sach
Node *deleteAtEnd(Node *head) {
    if (head == nullptr) {
        return nullptr; // Danh sach rong
    }

    // Truong hop danh sach chi co 1 node
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    // Duyet den node ke cuoi
    Node *current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;   // Xoa node cuoi
    current->next = nullptr; // Ngat ket noi
    return head;
}

// Ham xoa tai vi tri bat ky (pos bat dau tu 1)
Node *deleteAtPos(Node *head, int pos) {
    if (head == nullptr || pos <= 0) {
        cout << "Vi tri khong hop le!" << endl;
        return head;
    }

    if (pos == 1) {
        return deleteAtBeginning(head);
    }

    Node *current = head;

    // Duyet den node truoc vi tri pos
    for (int i = 1; i < pos - 1 && current != nullptr; i++) {
        current = current->next;
    }

    // Neu pos vuot qua do dai danh sach
    if (current == nullptr || current->next == nullptr) {
        cout << "Vi tri khong hop le!" << endl;
        return head;
    }

    Node *temp = current->next; // Node can xoa
    current->next = temp->next; // Noi qua node can xoa
    delete temp;                // Giai phong bo nho

    return head;
}

// Ham duyet xuoi danh sach (Forward Traversal)
void printForward(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

// Ham duyet nguoc bang de quy (Reverse Traversal)
void printReverse(Node *head) {
    if (head == nullptr) {
        return;
    }

    // Goi de quy den node tiep theo
    printReverse(head->next);

    // In du lieu theo chieu nguoc lai
    cout << head->data << " -> ";
}

// Ham main kiem thu tat ca cac chuc nang
int main() {
    Node *head = nullptr;

    // 1. Khoi tao danh sach: 10 -> 20 -> 30
    cout << "--- THAO TAC THEM PHAN TU ---" << endl;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    cout << "Danh sach sau khi them cuoi (10, 20, 30): ";
    printForward(head);

    // 2. Them vao dau
    head = insertAtBeginning(head, 5);
    cout << "Sau khi insertAtBeginning(5): ";
    printForward(head);

    // 3. Them vao vi tri pos = 3 (chèn 15 vào giữa 10 và 20)
    head = insertAtPos(head, 3, 15);
    cout << "Sau khi insertAtPos(pos=3, val=15): ";
    printForward(head);

    // 4. Duyet nguoc danh sach
    cout << "\n--- DUYET NGUOC (DE QUY) ---" << endl;
    cout << "Duyet nguoc: ";
    printReverse(head);
    cout << "nullptr" << endl;

    // 5. Cac thao tac xoa
    cout << "\n--- THAO TAC XOA PHAN TU ---" << endl;
    head = deleteAtBeginning(head);
    cout << "Sau khi deleteAtBeginning(): ";
    printForward(head);

    head = deleteAtEnd(head);
    cout << "Sau khi deleteAtEnd(): ";
    printForward(head);

    head = deleteAtPos(head, 2);
    cout << "Sau khi deleteAtPos(pos=2): ";
    printForward(head);

    return 0;
}