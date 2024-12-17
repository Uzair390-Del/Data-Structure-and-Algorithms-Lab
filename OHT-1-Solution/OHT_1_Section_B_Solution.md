# **OHT Exam Solutions (Section B)**

**Class Name:**  BSCS 3B
**Subject Name:** Data Structures & Algorithms  
**Lab Instructor:** Uzair Hassan  
**OHT Number:** 02  

---

## **Question No. 01**

### **Problem Statement**
A company's sensor system monitors employee check-in times in seconds from the start of each hour and stores them in an array of size 20. The system stops accepting check-in times when the array is full or when the user stops inputting values. The program must:

1. Find and display the earliest and latest check-in times.
2. Print the indexes of these times.
3. Remove the earliest check-in time and shift the remaining elements left.
4. Discuss the efficiency of each operation.

---

### **Solution Overview**
We will implement the following in C++:
1. **Initialization** of an array with up to 20 integer elements.
2. A function to **insert check-in times** into the array.
3. Functions to **find the smallest and largest check-in times** along with their indexes.
4. A function to **remove the earliest check-in time** and shift the remaining elements.
5. Time complexity analysis for the operations.

---

### **Code Implementation**

```cpp
#include <iostream>
using namespace std;

class CheckInSystem {
private:
    static const int SIZE = 20; // Maximum size of the array
    int checkIns[SIZE];         // Array to store check-in times
    int count;                  // Number of current check-ins

public:
    // Constructor: Initialize the array and count
    CheckInSystem() {
        count = 0;
    }

    // Function to insert check-in times
    void insertCheckIn(int time) {
        if (count < SIZE) {
            checkIns[count++] = time;
        } else {
            cout << "Array is full. Cannot insert more check-in times." << endl;
        }
    }

    // Function to find and display the smallest and largest check-in times
    void findMinMax() {
        if (count == 0) {
            cout << "No check-in times available." << endl;
            return;
        }
        int minTime = checkIns[0], maxTime = checkIns[0];
        int minIndex = 0, maxIndex = 0;

        for (int i = 1; i < count; i++) {
            if (checkIns[i] < minTime) {
                minTime = checkIns[i];
                minIndex = i;
            }
            if (checkIns[i] > maxTime) {
                maxTime = checkIns[i];
                maxIndex = i;
            }
        }

        cout << "Earliest Check-In Time: " << minTime << " at Index: " << minIndex << endl;
        cout << "Latest Check-In Time: " << maxTime << " at Index: " << maxIndex << endl;
    }

    // Function to remove the earliest check-in time
    void removeEarliest() {
        if (count == 0) {
            cout << "No check-in times to remove." << endl;
            return;
        }

        int minIndex = 0;
        for (int i = 1; i < count; i++) {
            if (checkIns[i] < checkIns[minIndex]) {
                minIndex = i;
            }
        }

        // Shift elements to the left
        for (int i = minIndex; i < count - 1; i++) {
            checkIns[i] = checkIns[i + 1];
        }
        count--;
        cout << "Earliest check-in time removed." << endl;
    }

    // Function to display all check-in times
    void displayCheckIns() {
        if (count == 0) {
            cout << "No check-in times to display." << endl;
            return;
        }
        cout << "Current Check-In Times: ";
        for (int i = 0; i < count; i++) {
            cout << checkIns[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CheckInSystem system;
    int time;
    char choice;

    cout << "Enter check-in times (in seconds). Type 'N' to stop entering values." << endl;
    while (true) {
        cout << "Enter time: ";
        cin >> time;
        system.insertCheckIn(time);
        cout << "Do you want to add more? (Y/N): ";
        cin >> choice;
        if (choice == 'N' || choice == 'n') break;
    }

    system.displayCheckIns();
    system.findMinMax();
    system.removeEarliest();
    system.displayCheckIns();

    return 0;
}
```

---

### **Time Complexity Analysis**
1. **Insertion**: \( O(1) \).
2. **Finding Min and Max**: \( O(n) \) as the array is traversed once.
3. **Removing the Earliest Time**:
   - Finding the earliest time: \( O(n) \).
   - Shifting elements: \( O(n) \).
4. **Overall**: Operations involve linear traversal, making them \( O(n) \).

---

## **Question No. 02**

### **Problem Statement**
Create a C++ program to:
1. Initialize an array with 20 random integers.
2. Sort the array using **Insertion Sort**, displaying progress after each iteration.
3. Perform **Linear Search** and **Binary Search** for a target value.
4. Compare the time complexities of both search algorithms.
5. Analyze the time complexity of Insertion Sort.

---

### **Code Implementation**

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to display an array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        cout << "After Iteration " << i << ": ";
        displayArray(arr, n);
    }
}

// Linear Search
bool linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return true;
    }
    return false;
}

// Binary Search
bool binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main() {
    srand(time(0));
    const int n = 20;
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 100;

    cout << "Original Array: ";
    displayArray(arr, n);

    int target = arr[5]; // Choose a random target
    cout << "\nTarget Value: " << target << endl;

    // Linear Search
    cout << "\nLinear Search: ";
    cout << (linearSearch(arr, n, target) ? "Found" : "Not Found") << endl;

    // Sorting
    cout << "\nSorting Array using Insertion Sort...\n";
    insertionSort(arr, n);

    // Binary Search
    cout << "\nBinary Search: ";
    cout << (binarySearch(arr, n, target) ? "Found" : "Not Found") << endl;

    return 0;
}
```

---

### **Time Complexity Analysis**
1. **Linear Search**: \( O(n) \).
2. **Binary Search**: \( O(log n) \) on sorted data.
3. **Insertion Sort**:
   - Best Case: \( O(n) \) (already sorted).
   - Worst Case: \( O(n^2) \) (reverse order).

### **Comparison**
- **Linear Search**: Suitable for unsorted or small datasets.
- **Binary Search**: Efficient for sorted datasets.

---

**End of Document**
