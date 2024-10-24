# Bubble Sort
```cpp
#include <iostream>
using namespace std;

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    // Input the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input the array elements
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform bubble sort
    bubbleSort(arr, n);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

```
## Dry Run: Bubble Sort in C++

### Problem:
We are performing a bubble sort on an array of integers to arrange them in ascending order.

---

### Input:
- Suppose the user inputs an array of 6 integers: **{64, 34, 25, 12, 22, 11}**.

---

### Dry Run:

#### **Step 1: Initialization**
- The program prompts the user to enter the number of elements, say `n = 6`.
- An array `arr[]` of size 6 is created.

**State after initialization:**
- `arr[] = {64, 34, 25, 12, 22, 11}`

---

#### **Step 2: Perform Bubble Sort**

Bubble sort works by repeatedly swapping adjacent elements if they are in the wrong order. Each pass through the array "bubbles" the largest element to the end.

---

#### **Pass 1:**
- The array before the first pass: `arr[] = {64, 34, 25, 12, 22, 11}`
  
##### **Iteration 1 (j = 0):**
- Compare `arr[0] = 64` with `arr[1] = 34`. 
- Since `64 > 34`, swap them.
- Array after the swap: `arr[] = {34, 64, 25, 12, 22, 11}`

##### **Iteration 2 (j = 1):**
- Compare `arr[1] = 64` with `arr[2] = 25`. 
- Since `64 > 25`, swap them.
- Array after the swap: `arr[] = {34, 25, 64, 12, 22, 11}`

##### **Iteration 3 (j = 2):**
- Compare `arr[2] = 64` with `arr[3] = 12`. 
- Since `64 > 12`, swap them.
- Array after the swap: `arr[] = {34, 25, 12, 64, 22, 11}`

##### **Iteration 4 (j = 3):**
- Compare `arr[3] = 64` with `arr[4] = 22`. 
- Since `64 > 22`, swap them.
- Array after the swap: `arr[] = {34, 25, 12, 22, 64, 11}`

##### **Iteration 5 (j = 4):**
- Compare `arr[4] = 64` with `arr[5] = 11`. 
- Since `64 > 11`, swap them.
- Array after the swap: `arr[] = {34, 25, 12, 22, 11, 64}`

**State after pass 1:**
- `arr[] = {34, 25, 12, 22, 11, 64}`

---

#### **Pass 2:**
- The array before the second pass: `arr[] = {34, 25, 12, 22, 11, 64}`
  
##### **Iteration 1 (j = 0):**
- Compare `arr[0] = 34` with `arr[1] = 25`. 
- Since `34 > 25`, swap them.
- Array after the swap: `arr[] = {25, 34, 12, 22, 11, 64}`

##### **Iteration 2 (j = 1):**
- Compare `arr[1] = 34` with `arr[2] = 12`. 
- Since `34 > 12`, swap them.
- Array after the swap: `arr[] = {25, 12, 34, 22, 11, 64}`

##### **Iteration 3 (j = 2):**
- Compare `arr[2] = 34` with `arr[3] = 22`. 
- Since `34 > 22`, swap them.
- Array after the swap: `arr[] = {25, 12, 22, 34, 11, 64}`

##### **Iteration 4 (j = 3):**
- Compare `arr[3] = 34` with `arr[4] = 11`. 
- Since `34 > 11`, swap them.
- Array after the swap: `arr[] = {25, 12, 22, 11, 34, 64}`

**State after pass 2:**
- `arr[] = {25, 12, 22, 11, 34, 64}`

---

#### **Pass 3:**
- The array before the third pass: `arr[] = {25, 12, 22, 11, 34, 64}`
  
##### **Iteration 1 (j = 0):**
- Compare `arr[0] = 25` with `arr[1] = 12`. 
- Since `25 > 12`, swap them.
- Array after the swap: `arr[] = {12, 25, 22, 11, 34, 64}`

##### **Iteration 2 (j = 1):**
- Compare `arr[1] = 25` with `arr[2] = 22`. 
- Since `25 > 22`, swap them.
- Array after the swap: `arr[] = {12, 22, 25, 11, 34, 64}`

##### **Iteration 3 (j = 2):**
- Compare `arr[2] = 25` with `arr[3] = 11`. 
- Since `25 > 11`, swap them.
- Array after the swap: `arr[] = {12, 22, 11, 25, 34, 64}`

**State after pass 3:**
- `arr[] = {12, 22, 11, 25, 34, 64}`

---

#### **Pass 4:**
- The array before the fourth pass: `arr[] = {12, 22, 11, 25, 34, 64}`
  
##### **Iteration 1 (j = 0):**
- Compare `arr[0] = 12` with `arr[1] = 22`. 
- No swap needed.

##### **Iteration 2 (j = 1):**
- Compare `arr[1] = 22` with `arr[2] = 11`. 
- Since `22 > 11`, swap them.
- Array after the swap: `arr[] = {12, 11, 22, 25, 34, 64}`

**State after pass 4:**
- `arr[] = {12, 11, 22, 25, 34, 64}`

---

#### **Pass 5:**
- The array before the fifth pass: `arr[] = {12, 11, 22, 25, 34, 64}`
  
##### **Iteration 1 (j = 0):**
- Compare `arr[0] = 12` with `arr[1] = 11`. 
- Since `12 > 11`, swap them.
- Array after the swap: `arr[] = {11, 12, 22, 25, 34, 64}`

**State after pass 5:**
- `arr[] = {11, 12, 22, 25, 34, 64}`

---

### Final Output:
- The program outputs the sorted array: **11, 12, 22, 25, 34, 64**.

# Selection Sort 
```cpp
#include <iostream>
using namespace std;

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the current index has the smallest element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }
        // Swap the smallest element found with the first element of the unsorted part
        swap(arr[i], arr[minIndex]);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    // Input the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input the array elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform selection sort
    selectionSort(arr, n);

    // Output the sorted array
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

```
### Dry Run: Selection Sort

#### **Step 1: Initialization**
- The program prompts the user to enter the number of elements, say `n = 6`.
- An array `arr[]` of size 6 is created.

**State after initialization:**
- `arr[] = {64, 34, 25, 12, 22, 11}`

---

#### **Step 2: Perform Selection Sort**

Selection Sort works by repeatedly selecting the smallest (or largest, depending on the order) element from the unsorted part of the array and swapping it with the first unsorted element. The array is divided into a sorted and unsorted section.

---

#### **Pass 1:**
- The array before the first pass: `arr[] = {64, 34, 25, 12, 22, 11}`
- We find the smallest element from index 0 to index 5.

##### **Iteration 1 (i = 0):**
- Assume `arr[0] = 64` is the smallest.
- Compare `arr[1] = 34` with `64`. `34 < 64`, so update the smallest to `34`.
- Compare `arr[2] = 25` with `34`. `25 < 34`, so update the smallest to `25`.
- Compare `arr[3] = 12` with `25`. `12 < 25`, so update the smallest to `12`.
- Compare `arr[4] = 22` with `12`. No change.
- Compare `arr[5] = 11` with `12`. `11 < 12`, so update the smallest to `11`.
- Swap `arr[0]` with `arr[5]`. The array becomes: `arr[] = {11, 34, 25, 12, 22, 64}`

**State after pass 1:**
- `arr[] = {11, 34, 25, 12, 22, 64}`

---

#### **Pass 2:**
- The array before the second pass: `arr[] = {11, 34, 25, 12, 22, 64}`
- Find the smallest element from index 1 to index 5.

##### **Iteration 2 (i = 1):**
- Assume `arr[1] = 34` is the smallest.
- Compare `arr[2] = 25` with `34`. `25 < 34`, so update the smallest to `25`.
- Compare `arr[3] = 12` with `25`. `12 < 25`, so update the smallest to `12`.
- Compare `arr[4] = 22` with `12`. No change.
- Compare `arr[5] = 64`. No change.
- Swap `arr[1]` with `arr[3]`. The array becomes: `arr[] = {11, 12, 25, 34, 22, 64}`

**State after pass 2:**
- `arr[] = {11, 12, 25, 34, 22, 64}`

---

#### **Pass 3:**
- The array before the third pass: `arr[] = {11, 12, 25, 34, 22, 64}`
- Find the smallest element from index 2 to index 5.

##### **Iteration 3 (i = 2):**
- Assume `arr[2] = 25` is the smallest.
- Compare `arr[3] = 34`. No change.
- Compare `arr[4] = 22` with `25`. `22 < 25`, so update the smallest to `22`.
- Compare `arr[5] = 64`. No change.
- Swap `arr[2]` with `arr[4]`. The array becomes: `arr[] = {11, 12, 22, 34, 25, 64}`

**State after pass 3:**
- `arr[] = {11, 12, 22, 34, 25, 64}`

---

#### **Pass 4:**
- The array before the fourth pass: `arr[] = {11, 12, 22, 34, 25, 64}`
- Find the smallest element from index 3 to index 5.

##### **Iteration 4 (i = 3):**
- Assume `arr[3] = 34` is the smallest.
- Compare `arr[4] = 25` with `34`. `25 < 34`, so update the smallest to `25`.
- Compare `arr[5] = 64`. No change.
- Swap `arr[3]` with `arr[4]`. The array becomes: `arr[] = {11, 12, 22, 25, 34, 64}`

**State after pass 4:**
- `arr[] = {11, 12, 22, 25, 34, 64}`

---

#### **Pass 5:**
- The array before the fifth pass: `arr[] = {11, 12, 22, 25, 34, 64}`
- No need to swap, as the remaining part is already sorted.

---

### Final Output:
- The program outputs the sorted array: **11, 12, 22, 25, 34, 64**.
