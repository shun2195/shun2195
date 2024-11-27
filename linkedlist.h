#ifndef LINKLIST_H
#define LINKLIST_H

#include <memory> 
#include <stdexcept>

template <typename T>
class LinkedList {
private:
    struct Node {
        T* data;
        Node* next;
        Node(T* data) : data(data), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void push_back(T* data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }
    
    void insertAt(int index, T* data) {
    if (index < 0 || index > size) {  // Kiểm tra index hợp lệ
        throw out_of_range("Index out of range");
    }

    Node* newNode = new Node(data);

    // Chèn vào đầu danh sách
    if (index == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        // Duyệt đến vị trí cần chèn
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;  // Kết nối node mới với phần tiếp theo
        temp->next = newNode;        // Kết nối node trước với node mới
    }

    size++;  // Tăng kích thước danh sách
}


    int getSize() const {
        return size;
    }

    T* operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            temp->data->display();
            temp = temp->next;
        }
    }

    LinkedList<T>& operator=(const LinkedList<T>& other) {
        if (this == &other) return *this;
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        size = 0;
        Node* otherTemp = other.head;
        while (otherTemp) {
            push_back(otherTemp->data);
            otherTemp = otherTemp->next;
        }
        return *this;
    }

    void removeAt(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;

    if (index == 0) {
        head = head->next;
        delete temp;  // Giải phóng bộ nhớ
    } else {
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;  // Giải phóng bộ nhớ
    }

    size--;
}


    ~LinkedList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

#endif
