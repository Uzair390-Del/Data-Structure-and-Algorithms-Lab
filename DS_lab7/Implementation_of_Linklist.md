# Lab: Comprehensive Implementation of Singly Linked List in C++

## 1. Introduction to Singly Linked List
A **Singly Linked List** is a dynamic data structure where each node contains:
- **Data**: Stores the value.
- **Next Pointer**: Points to the next node in the list.
- The last node's `next` pointer points to `NULL`.

---

## 2. Benefits of Linked Lists
1. **Dynamic Size**: Memory allocation is dynamic and can grow/shrink as needed.
2. **Efficient Insertions/Deletions**: Inserting or deleting a node is efficient as there is no need to shift elements.
3. **No Memory Wastage**: Utilizes memory efficiently, unlike arrays, which may have unused reserved space.

---

## 3. Applications of Linked Lists
1. Implementation of **Stacks, Queues, and Graphs**.
2. **Dynamic Memory Allocation** in operating systems.
3. Efficient data manipulation where frequent insertions/deletions are needed.
4. **Symbol Table Management** in compilers.

---

## 4. Comparison: Linked List vs. Array

| **Feature**           | **Linked List**                | **Array**                     |
|-----------------------|---------------------------------|-------------------------------|
| **Size**              | Dynamic (grows/shrinks)        | Fixed at initialization.      |
| **Insertion/Deletion**| Efficient                      | Requires shifting elements.   |
| **Random Access**     | Not possible                   | Possible via indexing.        |
| **Memory Allocation** | Scattered in memory            | Contiguous in memory.         |

---

## 5. Time Complexity Analysis

| **Operation**         | **Time Complexity**            |
|-----------------------|---------------------------------|
| **Insertion**         | O(1) at beginning, O(n) at end/position |
| **Deletion**          | O(1) at beginning, O(n) at position |
| **Traversal**         | O(n)                           |
| **Search**            | O(n)                           |
| **Sorting**           | O(n²) (bubble sort)            |

---

## 6. Universally Used Structure for Linked Lists

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;        // Stores data
    Node* next;      // Pointer to the next node
};

// Functions for various operations
void insertAtBeginning(Node*& head, int value);
void insertAtEnd(Node*& head, int value);
void insertAtPosition(Node*& head, int position, int value);
void deleteNode(Node*& head, int value);
void traverseList(Node* head);
void sortList(Node*& head);