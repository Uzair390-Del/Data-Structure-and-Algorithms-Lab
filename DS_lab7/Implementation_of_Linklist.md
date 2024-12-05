# Lab: Comprehensive Implementation of Singly Linked List in C++

## 1. Introduction to Singly Linked List
A **Singly Linked List** is a linear data structure where each node contains::
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

## 7. Detailed Implementation

### 7.1 Insert at Beginning

#### Algorithm
1. Create a new node.
2. Assign the value to the node's `data`.
3. Set `newNode->next` to the current `head`.
4. Update the `head` to point to `newNode`.

#### Code with Line-by-Line Explanation
```cpp
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();   // Step 1: Create a new node
    newNode->data = value;        // Step 2: Assign value to the node
    newNode->next = head;         // Step 3: Link new node to the current list
    head = newNode;               // Step 4: Update head to point to new node
}
```

#### Detailed Dry Run
- **Initial List**: `NULL`
- **Input**: `insertAtBeginning(head, 10)`
- **Steps**:
  1. Create a new node with `data = 10`.
  2. Point `newNode->next` to `head` (currently `NULL`).
  3. Update `head` to point to `newNode`.
- **Result**: `10 -> NULL`

---

### 7.2 Insert at End

#### Algorithm
1. Create a new node.
2. Assign the value to the node's `data`.
3. Set `newNode->next` to `NULL`.
4. If the list is empty, set `head` to `newNode`.
5. Otherwise, traverse to the last node.
6. Update the last node’s `next` to point to `newNode`.

#### Code with Line-by-Line Explanation
```cpp
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();   // Step 1: Create a new node
    newNode->data = value;        // Step 2: Assign value to the node
    newNode->next = NULL;         // Step 3: Point new node to NULL
    if (head == NULL) {           // Step 4: Check if the list is empty
        head = newNode;           // Step 5: Update head if list is empty
    } else {
        Node* temp = head;        // Step 6: Start at the head
        while (temp->next != NULL) { // Step 7: Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;     // Step 8: Link the last node to the new node
    }
}
```

#### Detailed Dry Run
- **Initial List**: `10 -> NULL`
- **Input**: `insertAtEnd(head, 20)`
- **Steps**:
  1. Create a new node with `data = 20`.
  2. Traverse to the last node (`10`).
  3. Set `lastNode->next` to the new node.
- **Result**: `10 -> 20 -> NULL`

---

### 7.3 Delete a Node

#### Algorithm
1. If the list is empty, print a message and exit.
2. If the first node contains the value:
   - Update `head` to `head->next`.
   - Delete the first node.
3. Traverse to the node before the one to delete.
4. Update `temp->next` to skip the node to delete.
5. Delete the unwanted node.

#### Code with Line-by-Line Explanation
```cpp
void deleteNode(Node*& head, int value) {
    if (head == NULL) {             // Step 1: Check if the list is empty
        cout << "List is empty!
"; // Print message if empty
        return;
    }
    if (head->data == value) {      // Step 2: Check if the first node has the value
        Node* temp = head;          // Step 3: Store head in a temporary variable
        head = head->next;          // Step 4: Update head to the next node
        delete temp;                // Step 5: Delete the old head
        return;
    }
    Node* temp = head;              // Step 6: Start at the head
    while (temp->next != NULL && temp->next->data != value) { // Step 7: Traverse to find the value
        temp = temp->next;
    }
    if (temp->next == NULL) {       // Step 8: If value is not found
        cout << "Value not found!
";
    } else {
        Node* delNode = temp->next; // Step 9: Store the node to delete
        temp->next = delNode->next; // Step 10: Skip the node to delete
        delete delNode;             // Step 11: Delete the unwanted node
    }
}
```

#### Detailed Dry Run
- **Initial List**: `10 -> 20 -> NULL`
- **Input**: `deleteNode(head, 20)`
- **Steps**:
  1. Traverse to the node before `20` (`10`).
  2. Update `temp->next` to skip `20` and point to `NULL`.
  3. Delete the node `20`.
- **Result**: `10 -> NULL`
