
# Data Structures Lab: Implementation of Stacks in C++

## Objectives
By the end of this lab, students will be able to:
- Understand the concept of a stack and its operations.
- Implement a stack using an array in C++.
- Identify and explain the practical applications of stacks.
- Write and analyze programs using stacks.

---

## What is a Stack?
A **stack** is a linear data structure that works on the **LIFO (Last In, First Out)** principle. This means that the last element added to the stack is the first one to be removed.

### Real-Life Analogies:
- A stack of plates: The plate added last is removed first.
- Undo operations in text editors: The last action performed is undone first.

### Stack Operations:
1. **Push**: Add an element to the stack.
2. **Pop**: Remove the top element from the stack.
3. **Peek/Top**: Retrieve the top element without removing it.
4. **isEmpty**: Check if the stack is empty.
5. **isFull**: Check if the stack is full (in fixed-size implementations).

### Properties of a Stack:
- The stack has a **fixed capacity** when implemented using arrays.
- Elements are only added or removed from the **top of the stack**.

---

## Implementation of Stack Using Array

### Code Implementation:
Below is the step-by-step implementation of a stack using an array in C++. 

```cpp
#include <iostream>
#define MAX 100 // Define the maximum size of the stack

class Stack {
    int top; // To keep track of the top index
    int arr[MAX]; // Array to store stack elements

public:
    Stack() { top = -1; } // Constructor to initialize the stack

    // Push: Add an element to the stack
    bool push(int value) {
        if (top >= MAX - 1) {
            std::cout << "Stack Overflow\n";
            return false;
        } else {
            arr[++top] = value;
            std::cout << value << " pushed into stack\n";
            return true;
        }
    }

    // Pop: Remove the top element from the stack
    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow\n";
            return -1;
        } else {
            int value = arr[top--];
            return value;
        }
    }

    // Peek: Retrieve the top element without removing it
    int peek() {
        if (top < 0) {
            std::cout << "Stack is Empty\n";
            return -1;
        } else {
            return arr[top];
        }
    }

    // isEmpty: Check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }

    // Display all elements in the stack
    void display() {
        if (top < 0) {
            std::cout << "Stack is Empty\n";
        } else {
            std::cout << "Stack elements are: ";
            for (int i = 0; i <= top; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << stack.pop() << " popped from stack\n";
    stack.display();

    std::cout << "Top element is: " << stack.peek() << "\n";

    std::cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
```

### Explanation of the Code:
1. **Push Operation**:
   - Check if the stack is full (`top >= MAX - 1`).
   - If not full, increment `top` and add the element to `arr[top]`.

2. **Pop Operation**:
   - Check if the stack is empty (`top < 0`).
   - If not empty, return the element at `arr[top]` and decrement `top`.

3. **Peek Operation**:
   - Simply return the element at `arr[top]` without modifying `top`.

4. **Display Function**:
   - Traverse from the base of the stack to the top to print all elements.

---

## **Dry Run of the Code**

Here’s a dry run of the main function step by step:

### Code for Dry Run
```cpp
int main() {
    Stack stack;

    stack.push(10);   // Step 1
    stack.push(20);   // Step 2
    stack.push(30);   // Step 3

    std::cout << stack.pop() << " popped from stack\n";   // Step 4
    stack.display();  // Step 5

    std::cout << "Top element is: " << stack.peek() << "\n";  // Step 6

    std::cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << "\n"; // Step 7
    return 0;
}
```

### **Initial Conditions**
- The stack is implemented using an array `arr` of size `MAX = 100`.
- The `top` pointer is initialized to `-1` (indicating an empty stack).

### **Step-by-Step Execution**

#### **Step 1: `stack.push(10)`**
- `top` becomes `0`.
- Stack: `[10]`

#### **Step 2: `stack.push(20)`**
- `top` becomes `1`.
- Stack: `[10, 20]`

#### **Step 3: `stack.push(30)`**
- `top` becomes `2`.
- Stack: `[10, 20, 30]`

#### **Step 4: `stack.pop()`**
- Value popped: `30`.
- `top` becomes `1`.
- Stack: `[10, 20]`

#### **Step 5: `stack.display()`**
- Output: `Stack elements are: 10 20`

#### **Step 6: `stack.peek()`**
- Top element: `20`.

#### **Step 7: `stack.isEmpty()`**
- Output: `No`.

---

## Applications of Stacks
1. **Backtracking**:
   - Used in algorithms for solving mazes or navigating browser history.

2. **Undo/Redo Operations**:
   - In text editors, operations are stored in stacks to undo/redo them.

3. **Balanced Parentheses**:
   - A stack can check whether a given expression has balanced parentheses.

4. **Reverse a String**:
   - Push each character of a string onto a stack, then pop them to reverse it.

---


