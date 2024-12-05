# Lab on Queue Application and Implementation Using Arrays

---

## Objective
1. Understand the concept of a queue and its real-life applications.
2. Implement a **simple queue** using arrays in C++.
3. Perform operations like enqueue, dequeue, peek, and check if the queue is empty or full.
4. Analyze a real-world problem and solve it using queue operations.

---

## Introduction to Queue

A queue is a linear data structure that follows the **First In, First Out (FIFO)** principle. The element inserted first is the first to be removed.

### Real-life Examples of Queue:
1. **Customer Service**: Calls handled in the order they are received.
2. **Print Queue**: Printing tasks are handled in the order they are sent.
3. **Task Scheduling**: Processes in an operating system.

---

## Queue Operations

1. **Enqueue**: Add an element to the end of the queue.
2. **Dequeue**: Remove an element from the front of the queue.
3. **Peek/Front**: Retrieve the element at the front without removing it.
4. **IsEmpty**: Check if the queue is empty.
5. **IsFull**: Check if the queue is full.

---

## Simple Queue Implementation Using Array

### Key Points:
- Use a fixed-size array.
- Two variables: 
  - **Front**: Tracks the first element.
  - **Rear**: Tracks the last element.

---

## Algorithm

### 1. Enqueue Operation
1. Check if the queue is full:
   - `rear == size - 1`
2. If not full:
   - If `front == -1`, set `front = 0`.
   - Increment `rear`.
   - Insert the new element at `arr[rear]`.

### 2. Dequeue Operation
1. Check if the queue is empty:
   - `front == -1` or `front > rear`
2. If not empty:
   - Retrieve the value at `arr[front]`.
   - Increment `front`.
   - If `front > rear`, reset `front` and `rear` to `-1`.

### 3. Peek Operation
- Return the element at `arr[front]` if the queue is not empty.

### 4. Check Empty/Full
- Empty: `front == -1`
- Full: `rear == size - 1`

---

## Detailed Dry Run for Simple Queue Operations

### Initial State
- `front = -1`, `rear = -1`, `size = 5`
- Queue = `[ _, _, _, _, _ ]` (all slots are initially empty)

---

### Operation 1: Enqueue(10)

1. **Check if the queue is full:**
   - `rear == size - 1`
   - `-1 == 4` → False (Queue is not full)

2. **Proceed to enqueue:**
   - `front = 0` (as the queue was empty initially)
   - Increment `rear`: `rear = rear + 1 = 0`
   - Insert `10` at index `rear`: `Queue[0] = 10`

**Updated State:**
- `front = 0`, `rear = 0`
- Queue = `[ 10, _, _, _, _ ]`

---

### Operation 2: Enqueue(20)

1. **Check if the queue is full:**
   - `rear == size - 1`
   - `0 == 4` → False (Queue is not full)

2. **Proceed to enqueue:**
   - Increment `rear`: `rear = rear + 1 = 1`
   - Insert `20` at index `rear`: `Queue[1] = 20`

**Updated State:**
- `front = 0`, `rear = 1`
- Queue = `[ 10, 20, _, _, _ ]`

---

### Operation 3: Enqueue(30)

1. **Check if the queue is full:**
   - `rear == size - 1`
   - `1 == 4` → False (Queue is not full)

2. **Proceed to enqueue:**
   - Increment `rear`: `rear = rear + 1 = 2`
   - Insert `30` at index `rear`: `Queue[2] = 30`

**Updated State:**
- `front = 0`, `rear = 2`
- Queue = `[ 10, 20, 30, _, _ ]`

---

### Operation 4: Dequeue()

1. **Check if the queue is empty:**
   - `front == -1 or front > rear`
   - `0 == -1 or 0 > 2` → False (Queue is not empty)

2. **Proceed to dequeue:**
   - Retrieve the value at `front`: `Dequeued = Queue[0] = 10`
   - Increment `front`: `front = front + 1 = 1`

3. **Special case (check if the queue is now empty):**
   - `front > rear` → `1 > 2` → False

**Updated State:**
- `front = 1`, `rear = 2`
- Queue = `[ _, 20, 30, _, _ ]`

---

### Operation 5: Enqueue(40)

1. **Check if the queue is full:**
   - `rear == size - 1`
   - `2 == 4` → False (Queue is not full)

2. **Proceed to enqueue:**
   - Increment `rear`: `rear = rear + 1 = 3`
   - Insert `40` at index `rear`: `Queue[3] = 40`

**Updated State:**
- `front = 1`, `rear = 3`
- Queue = `[ _, 20, 30, 40, _ ]`

---

### Operation 6: Dequeue()

1. **Check if the queue is empty:**
   - `front == -1 or front > rear`
   - `1 == -1 or 1 > 3` → False (Queue is not empty)

2. **Proceed to dequeue:**
   - Retrieve the value at `front`: `Dequeued = Queue[1] = 20`
   - Increment `front`: `front = front + 1 = 2`

3. **Special case (check if the queue is now empty):**
   - `front > rear` → `2 > 3` → False

**Updated State:**
- `front = 2`, `rear = 3`
- Queue = `[ _, _, 30, 40, _ ]`

---

## Final State
- `front = 2`, `rear = 3`
- Queue = `[ _, _, 30, 40, _ ]`

---

## C++ Implementation

```cpp
#include <iostream>
#define SIZE 5

using namespace std;

class SimpleQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    SimpleQueue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
        if (front > rear) front = rear = -1;
    }

    // Peek operation
    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty. Nothing to peek." << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Display the queue
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SimpleQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.peek();

    return 0;
}
```
## Circular Queue
Circular nature to optimize space.

---

## Algorithm

### 1. Enqueue Operation
1. Check if the queue is full:
   - (rear + 1) % size == front
2. If not full:
   - Increment rear using (rear + 1) % size.
   - Insert the new element at rear.

### 2. Dequeue Operation
1. Check if the queue is empty:
   - front == -1
2. If not empty:
   - Store the value at front.
   - Increment front using (front + 1) % size.
   - If front equals rear, reset front and rear to -1.

### 3. Peek Operation
- Return the element at front if the queue is not empty.

### 4. Check Empty/Full
- Empty: front == -1
- Full: (rear + 1) % size == front

---
# Detailed Dry Run for Queue Operations

## Initial State
- front = -1, rear = -1, size = 5
- Queue = [ _, _, _, _, _ ] (all slots are initially empty)

---

## Operation 1: Enqueue(10)

1. **Check if the queue is full:**
   - (rear + 1) % size == front
   - ( -1 + 1 ) % 5 == -1 → 0 == -1 → False (Queue is not full)

2. **Proceed to enqueue:**
   - front = 0 (as the queue was empty initially)
   - Increment rear: rear = (rear + 1) % size = ( -1 + 1 ) % 5 = 0
   - Insert 10 at index rear: Queue[0] = 10

**Updated State:**
- front = 0, rear = 0
- Queue = [ 10, _, _, _, _ ]

---

## Operation 2: Enqueue(20)

1. **Check if the queue is full:**
   - (rear + 1) % size == front
   - ( 0 + 1 ) % 5 == 0 → 1 == 0 → False (Queue is not full)

2. **Proceed to enqueue:**
   - Increment rear: rear = (rear + 1) % size = ( 0 + 1 ) % 5 = 1
   - Insert 20 at index rear: Queue[1] = 20

**Updated State:**
- front = 0, rear = 1
- Queue = [ 10, 20, _, _, _ ]

---

## Operation 3: Enqueue(30)

1. **Check if the queue is full:**
   - (rear + 1) % size == front
   - ( 1 + 1 ) % 5 == 0 → 2 == 0 → False (Queue is not full)

2. **Proceed to enqueue:**
   - Increment rear: rear = (rear + 1) % size = ( 1 + 1 ) % 5 = 2
   - Insert 30 at index rear: Queue[2] = 30

**Updated State:**
- front = 0, rear = 2
- Queue = [ 10, 20, 30, _, _ ]

---

## Operation 4: Dequeue()

1. **Check if the queue is empty:**
   - front == -1 → 0 == -1 → False (Queue is not empty)

2. **Proceed to dequeue:**
   - Retrieve the value at front: Dequeued = Queue[0] = 10
   - Increment front: front = (front + 1) % size = ( 0 + 1 ) % 5 = 1

3. **Special case (single element check):**
   - front == rear → 1 == 2 → False (queue is not empty)

**Updated State:**
- front = 1, rear = 2
- Queue = [ _, 20, 30, _, _ ]

---

## Operation 5: Enqueue(40)

1. **Check if the queue is full:**
   - (rear + 1) % size == front
   - ( 2 + 1 ) % 5 == 1 → 3 == 1 → False (Queue is not full)

2. **Proceed to enqueue:**
   - Increment rear: rear = (rear + 1) % size = ( 2 + 1 ) % 5 = 3
   - Insert 40 at index rear: Queue[3] = 40

**Updated State:**
- front = 1, rear = 3
- Queue = [ _, 20, 30, 40, _ ]

---

## Operation 6: Enqueue(50)

1. **Check if the queue is full:**
   - (rear + 1) % size == front
   - ( 3 + 1 ) % 5 == 1 → 4 == 1 → False (Queue is not full)

2. **Proceed to enqueue:**
   - Increment rear: rear = (rear + 1) % size = ( 3 + 1 ) % 5 = 4
   - Insert 50 at index rear: Queue[4] = 50

**Updated State:**
- front = 1, rear = 4
- Queue = [ _, 20, 30, 40, 50 ]

---

## Operation 7: Dequeue()

1. **Check if the queue is empty:**
   - front == -1 → 1 == -1 → False (Queue is not empty)

2. **Proceed to dequeue:**
   - Retrieve the value at front: Dequeued = Queue[1] = 20
   - Increment front: front = (front + 1) % size = ( 1 + 1 ) % 5 = 2

3. **Special case (single element check):**
   - front == rear → 2 == 4 → False (queue is not empty)

**Updated State:**
- front = 2, rear = 4
- Queue = [ _, _, 30, 40, 50 ]

---

## Operation 8: Enqueue(60)

1. **Check if the queue is full:**
   - (rear + 1) % size == front
   - ( 4 + 1 ) % 5 == 2 → 0 == 2 → False (Queue is not full)

2. **Proceed to enqueue:**
   - Increment rear: rear = (rear + 1) % size = ( 4 + 1 ) % 5 = 0
   - Insert 60 at index rear: Queue[0] = 60

**Updated State:**
- front = 2, rear = 0
- Queue = [ 60, _, 30, 40, 50 ]

---

## Final State
- front = 2, rear = 0
- Queue = [ 60, _, 30, 40, 50 ]

This dry run illustrates how the circular queue operates, demonstrating the effectiveness of the modular arithmetic in efficiently managing space.

## C++ Implementation

```cpp
#include <iostream>
#define SIZE 5

using namespace std;

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Peek operation
    void peek() {
        if (front == -1) {
            cout << "Queue is empty. Nothing to peek." << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    // Display the queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); // Queue is now full

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70); // Circular enqueue

    q.display();

    q.peek();
    return 0;
}
```