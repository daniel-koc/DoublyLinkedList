#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <typename T>
class DoublyLinkedList {
    private:
    struct Node;

   public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoublyLinkedList();

    void add(const T& data);
    bool remove(const T& data);
    int getSize() const;
    bool isEmpty() const;

    Node* getHead() const { return head; }

   private:
    struct Node {
        Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}

        T data;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;
    int size;
};

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::add(const T& data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename T>
bool DoublyLinkedList<T>::remove(const T& data) {
    Node* current = head;
    while (current) {
        if (current->data == data) {
            if (current == head) {
                head = current->next;
                if (head)
                    head->prev = nullptr;
            } else if (current == tail) {
                tail = current->prev;
                tail->next = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            size--;
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
int DoublyLinkedList<T>::getSize() const {
    return size;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return size == 0;
}

#endif // DOUBLY_LINKED_LIST_H
