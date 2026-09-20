#include <iostream>     // Arie Ardinata Kusuma
using namespace std;    // 251401046

struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void printList() {
    Node *temp = head;
    cout << "Isi Linked List: ";
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insertFirst(int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertLast(int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfter(int n, int check) {
    if(head == NULL) {
        cout << "List kosong, silahkan insert di depan \n";
        return;
    }

    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    Node *p = head;
    while(p != NULL && p->value != check) {
        p = p-> next;
    }

    if(p == NULL) {
        cout << "Node dengan nilai " << check << "tidak ketemu\n";
        delete newNode;
    } else {
        newNode -> next = p->next;
        p->next = newNode;
        if(p == tail) {
            tail = newNode;
        }
    }
    
}

void deleteFirst() {
    if(head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    Node *temp = head;
    head = head->next;
    if(head == NULL) tail = NULL;
    delete temp;
}

void deleteMiddle(int value) {
    if(head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    if(head->value == value) {
        deleteFirst();
        return;
    }

    Node *p = head;
    while(p->next != NULL && p ->next -> value != value) {
        p = p ->next;
    }

    if (p->next == NULL) {
        cout << "Node dengan nilai " << value << " tidak ketemu\n";
    } else {
        Node *temp = p ->next;
        p ->next = temp ->next;
        if(temp == tail) tail = p;
        delete temp;
    }
}



int main() {
    int pil, val, valCari;
    
    do {
    cout << "=== MENU SINGLE LINKED LIST ===" << endl;
    cout << "1. Tambah di awal" << endl;
    cout << "2. Tambah di akhir" << endl;
    cout << "3. Tambah setelah nilai tertentu" << endl;
    cout << "4. Hapus berdasarkan nilai" << endl;
    cout << "5. Tampilkan linked list" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan: "; 
    cin >> pil;

        switch(pil) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> val;
                insertFirst(val);
                printList();
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> val;
                insertLast(val);
                printList();
                break;
            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> val;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> valCari;
                insertAfter(val, valCari);
                printList();
                break;
            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> val;
                deleteMiddle(val);
                printList();
                break;
            case 5:
                printList();
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n\n";
        }

    } while(pil != 0);

    return 0;
}