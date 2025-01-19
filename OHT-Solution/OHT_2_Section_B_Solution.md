# **OHT Exam Solutions**

**Class Name:** BSCS 3B  
**Subject Name:** Data Structures  
**Lab Instructor:** Uzair Hassan  
**OHT Number:** OHT-II  

---

## **Question No. 01**  
**(CLO 3, PLO-05)**  
**(Points = 10+10)**

### **Problem Statement**

1. Write a C++ program to implement a queue using a linked list and perform:
   - Enqueue an element.
   - Dequeue an element.
   - Display the elements in the list.

2. Write a C++ program to implement a stack using a linked list and perform the following operations:
   - Push an element.
   - Pop an element.
   - Display all elements.

---

### **Solution Overview**

**Part 1: Queue Implementation**  
We will create a queue using a linked list with the following operations:
- Enqueue (inserts an element at the rear).
- Dequeue (removes an element from the front).
- Display all elements in the queue.

**Part 2: Stack Implementation**  
We will create a stack using a linked list with operations to:
- Push (insert an element at the top).
- Pop (remove an element from the top).
- Display all elements in the stack.

---

### **Code Implementation**

#### **Queue Implementation Using Linked List**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // Enqueue operation
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << val << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }

    // Display elements
    void display() {
        if (front == NULL) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue Elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}
```

---

#### **Stack Implementation Using Linked List**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << val << endl;
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped: " << temp->data << endl;
        delete temp;
    }

    // Display elements
    void display() {
        if (top == NULL) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack Elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(5);
    s.push(10);
    s.push(15);

    s.display();

    s.pop();
    s.display();

    return 0;
}
```

---

## **Question No. 02**  
**(CLO 1, PLO-02)**  
**(Points = 10)**

### **Problem Statement**
Write a C++ program to implement a singly linked list. Perform the following operations:
- Insert a node at the beginning.
- Delete a node from the end.
- Display all nodes in the list.

---

### **Solution Overview**
We will create a singly linked list with operations to:
- Insert a node at the beginning.
- Delete a node from the end.
- Display all nodes in the list.

---

### **Code Implementation**

#### **Singly Linked List Implementation**
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    // Insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at the beginning." << endl;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Deleted the last node." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        cout << "Deleted the last node." << endl;
    }

    // Display all nodes
    void display() {
        if (head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "List Elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.display();

    list.deleteFromEnd();
    list.display();

    return 0;
}
```

---
