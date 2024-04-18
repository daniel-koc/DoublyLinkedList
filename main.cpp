#include <iostream>
#include "DoublyLinkedList2.h"

int main() {
    DoublyLinkedList<int> list;

    // Adding elements to the list
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);

    // Displaying the size of the list
    std::cout << "Size of the list: " << list.getSize() << std::endl;

    // Removing an element from the list
    int elementToRemove = 20;
    if (list.remove(elementToRemove)) {
        std::cout << "Removed " << elementToRemove << " from the list." << std::endl;
    } else {
        std::cout << "Element " << elementToRemove << " not found in the list." << std::endl;
    }

    // Displaying the remaining elements in the list
    std::cout << "Remaining elements in the list: ";
    auto currentNode = list.getHead();
    while (currentNode) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;

    return 0;
}
