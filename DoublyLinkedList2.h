// This implementation ensures that memory management is handled automatically by shared pointers, and it allows multiple instances of the list to share ownership of the nodes while still preventing dangling pointers and memory leaks.
// In this version, `NodePtr` is an alias for `std::shared_ptr<Node>` and `WeakNodePtr` is an alias for `std::weak_ptr<Node>`.
// The `prev` pointer in each node is a `std::shared_ptr`, and the `tail` pointer is a `std::weak_ptr` to prevent cyclic dependencies and potential memory leaks.

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <memory>

template <typename T>
class DoublyLinkedList {
   private:
    struct Node;
    using NodePtr = std::shared_ptr<Node>;
    using WeakNodePtr = std::weak_ptr<Node>;

   public:
    DoublyLinkedList() : size(0) {}
    ~DoublyLinkedList() = default;

    void add(const T& data);
    bool remove(const T& data);
    int getSize() const;
    bool isEmpty() const;
    NodePtr getHead() const;

   private:
    struct Node {
        Node(const T& data) : data(data) {}

        T data;
        NodePtr prev;
        NodePtr next;
    };

    NodePtr head;
    WeakNodePtr tail;
    int size;
};

template <typename T>
void DoublyLinkedList<T>::add(const T& data) {
    NodePtr newNode = std::make_shared<Node>(data);
    if (!head) {
        head = newNode;
        tail = head;
    } else {
        newNode->prev = tail.lock();
        tail.lock()->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
bool DoublyLinkedList<T>::remove(const T& data) {
    NodePtr current = head;
    while (current) {
        if (current->data == data) {
            if (current == head) {
                head = current->next;
                if (head)
                    head->prev.reset();
            } else if (current == tail.lock()) {
                tail = current->prev;
                tail.lock()->next.reset();
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
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

template <typename T>
typename DoublyLinkedList<T>::NodePtr DoublyLinkedList<T>::getHead() const {
    return head;
}

#endif // DOUBLY_LINKED_LIST_H
