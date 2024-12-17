# **OHT Exam Solutions**

**Class Name:** BSCS 3A
**Subject Name:**  Data Structures  
**Lab Instructor:** Uzair Hassan  
**OHT Number:** 01  

## **Question No. 01**

### **Problem Statement**
A weather monitoring system stores hourly temperature recordings in an integer array of size 24. When new data arrives after 24 readings, the oldest reading is removed, and the array shifts left to make room for the new reading.

### **Solution Overview**
We will implement the following in C++:
1. **Initialization** of an array with space for 24 integer elements.
2. A function to **insert new temperature readings**.
3. A function to **delete the oldest reading** and shift the remaining elements left when the array is full.
4. A function to **display all current temperature readings**.

We will also:
- Discuss the behavior when the array receives more than 24 readings.
- Analyze the time complexities for insertion, deletion, and shifting operations.

---

### **Code Implementation**

```cpp
#include <iostream>
using namespace std;

// Class for Weather Monitoring System
class WeatherMonitor {
private:
    static const int SIZE = 24; // Max size of the array
    int readings[SIZE];         // Array to store temperature readings
    int count;                  // Number of current readings

public:
    // Constructor: Initialize the array and count
    WeatherMonitor() {
        count = 0;
    }

    // Function to insert a new temperature reading
    void insertReading(int newReading) {
        if (count < SIZE) {
            readings[count] = newReading; // Add reading if space is available
            count++;
        } else {
            // Remove the oldest reading and shift elements
            for (int i = 0; i < SIZE - 1; i++) {
                readings[i] = readings[i + 1];
            }
            readings[SIZE - 1] = newReading; // Insert new reading at the end
        }
    }

    // Function to display current temperature readings
    void displayReadings() {
        cout << "Current Temperature Readings:" << endl;
        for (int i = 0; i < count; i++) {
            cout << readings[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    WeatherMonitor monitor;
    int n;

    // Simulate 30 readings to demonstrate rolling behavior
    for (int i = 1; i <= 30; i++) {
        cout << "Inserting reading: " << i * 2 << endl;
        monitor.insertReading(i * 2);
        monitor.displayReadings();
    }

    return 0;
}
```

---

### **Discussion: Behavior of the Array**
- When the array receives more than 24 readings, the oldest reading is removed.
- The elements are shifted to the left, and the new reading is added at the end.
- For example, inserting the 25th reading removes the 1st reading, and so on.

**Output Sample (Abbreviated):**
```
Inserting reading: 2
Current Temperature Readings:
2 
...
Inserting reading: 50
Current Temperature Readings:
4 6 8 ... 48 50
```

---

### **Time Complexity Analysis**
1. **Insertion**:
   - If the array is not full: \( O(1) \).
   - If the array is full: \( O(n) \) due to shifting \( n-1 \) elements.

2. **Deletion (Oldest Reading)**:
   - Combined with shifting: \( O(n) \).

3. **Shifting**:
   - Requires moving \( n-1 \) elements: \( O(n) \).

**Overall Complexity**:
- Insertion in the full array is the most expensive operation due to shifting.

---

## **Question No. 02**

### **Problem Statement**
Implement sorting and searching techniques on an array of integers.
1. Sort the array using **Selection Sort** or **Bubble Sort**, showing progress after each pass.
2. Perform **Linear Search** on the unsorted array.
3. Perform **Binary Search** on the sorted array.
4. Compare the time complexities of linear and binary search.
5. Analyze the sorting algorithm's time complexity.

---

### **Solution Overview**
We will:
1. Create an array of 10 integers with random values.
2. Use **Bubble Sort** to sort the array and print it after each pass.
3. Perform **Linear Search** and **Binary Search** for a specific number.
4. Compare and discuss the time complexities.

---

### **Code Implementation**

```cpp
#include <iostream>
using namespace std;

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble Sort Algorithm
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << "Pass " << i + 1 << ": ";
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        displayArray(arr, n);
    }
}

// Linear Search Function
bool linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return true;
    }
    return false;
}

// Binary Search Function
bool binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return true;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main() {
    int arr[10] = {34, 7, 23, 32, 5, 62, 31, 12, 28, 15};
    int n = 10, target = 23;

    cout << "Original Array: ";
    displayArray(arr, n);

    // Linear Search
    cout << "\nPerforming Linear Search for " << target << "..." << endl;
    if (linearSearch(arr, n, target))
        cout << "Found using Linear Search!" << endl;
    else
        cout << "Not Found!" << endl;

    // Bubble Sort
    cout << "\nSorting the Array using Bubble Sort..." << endl;
    bubbleSort(arr, n);

    // Binary Search
    cout << "\nPerforming Binary Search for " << target << "..." << endl;
    if (binarySearch(arr, n, target))
        cout << "Found using Binary Search!" << endl;
    else
        cout << "Not Found!" << endl;

    return 0;
}
```

---

### **Time Complexity Analysis**
1. **Linear Search**:
   - Time Complexity: \( O(n) \).
2. **Binary Search**:
   - Time Complexity: \( O(log n) \) (only on sorted data).
3. **Bubble Sort**:
   - Best Case: \( O(n) \) (already sorted).
   - Worst Case: \( O(n^2) \) (reverse order).

---

### **Comparison of Linear Search and Binary Search**
- **Linear Search**: Useful for unsorted or small datasets.
- **Binary Search**: More efficient for sorted data, especially for large arrays due to its logarithmic complexity.

**Conclusion**:
- Sorting and searching algorithms significantly impact performance based on data size and structure.
