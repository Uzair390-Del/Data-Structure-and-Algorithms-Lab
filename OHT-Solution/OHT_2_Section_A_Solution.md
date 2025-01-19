# **OHT Exam Solutions**

**Class Name:** BSCS 3A  
**Subject Name:** Data Structures  
**Lab Instructor:** Uzair Hassan  
**OHT Number:** OHT-1  

---

## **Question No. 01**

### **Problem Statement**
1. Implement a circular queue using an array in C++ and perform the following operations:
   - Enqueue an element.
   - Dequeue an element.
   - Check if the queue is full or empty after every operation.

2. Write a C++ program to implement a stack using an array with the following operations:
   - Push operation.
   - Pop operation.
   - Display the elements.

---

### **Solution Overview**
**Part 1: Circular Queue**  
We will create a circular queue implementation using an array. The operations include:
1. Enqueuing an element.
2. Dequeuing an element.
3. Checking if the queue is full or empty.

**Part 2: Stack**  
We will implement a stack using an array with operations to:
1. Push an element onto the stack.
2. Pop an element from the stack.
3. Display all elements currently in the stack.

---

### **Code Implementation**

#### **Circular Queue Implementation**
```cpp
#include <iostream>
using namespace std;

#define SIZE 5 // Maximum size of the queue

class CircularQueue {
private:
    int queue[SIZE];
    int front, rear, count;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        count = 0;
    }

    // Enqueue operation
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is Full! Cannot enqueue " << element << endl;
            return;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = element;
        if (front == -1) front = 0;
        count++;
        cout << "Enqueued: " << element << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << queue[front] << endl;
        front = (front + 1) % SIZE;
        count--;
        if (count == 0) {
            front = rear = -1; // Reset queue
        }
    }

    // Check if the queue is full
    bool isFull() {
        return count == SIZE;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60); // Queue is Full

    cq.dequeue();
    cq.dequeue();
    cq.enqueue(70);
    cq.enqueue(80); // Circular behavior

    return 0;
}
```

---

#### **Stack Implementation**
```cpp
#include <iostream>
using namespace std;

#define SIZE 5 // Maximum size of the stack

class Stack {
private:
    int stack[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Push operation
    void push(int element) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << element << endl;
            return;
        }
        stack[++top] = element;
        cout << "Pushed: " << element << endl;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << "Popped: " << stack[top--] << endl;
    }

    // Display the elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack Elements: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

    // Check if the stack is full
    bool isFull() {
        return top == SIZE - 1;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;

    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);
    s.push(30); // Stack Overflow

    s.display();

    s.pop();
    s.pop();
    s.display();

    return 0;
}
```

---

## **Question No. 02**

### **Problem Statement**
Write a C++ program to implement a doubly linked list and perform the following operations:
1. Insert a node at the beginning.
2. Insert a node at the end.
3. Delete a node from a given position.

---

### **Solution Overview**
We will implement a doubly linked list with operations for:
1. Inserting a node at the beginning.
2. Inserting a node at the end.
3. Deleting a node from a specified position.

---

### **Code Implementation**

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
        cout << "Inserted " << val << " at the beginning." << endl;
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            cout << "Inserted " << val << " at the end." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        cout << "Inserted " << val << " at the end." << endl;
    }

    // Delete from a given position
    void deleteFromPosition(int position) {
        if (head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        Node* temp = head;
        for (int i = 1; temp != NULL && i < position; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Invalid Position!" << endl;
            return;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        cout << "Deleted node at position " << position << "." << endl;
        delete temp;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtBeginning(10);
    dll.insertAtBeginning(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);

    dll.deleteFromPosition(2);
    dll.deleteFromPosition(5); // Invalid Position

    return 0;
}
```

---

### **Discussion**
- **Circular Queue**:
  - Efficient for applications requiring a fixed-size queue, such as buffering.
  - Circular behavior avoids unnecessary shifting of elements.

- **Stack**:
  - Useful for LIFO operations like function calls and undo mechanisms.
  - Array implementation provides fixed size but can lead to overflow.

- **Doubly Linked List**:
  - Allows efficient insertion and deletion from both ends.
  - More memory-intensive than singly linked lists due to extra pointers.

---
