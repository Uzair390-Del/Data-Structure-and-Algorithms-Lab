# Insertion Sort Algorithm

---

## Code Explanation

This program implements the insertion sort algorithm in C++. The `insertionSort` function sorts an array in ascending order by iteratively placing each element in its correct position within the sorted part of the array.

### Code
```cpp
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
```

# Line-by-Line Dry Run

---

### Initial Array:
`[12, 11, 13, 5, 6]`

### Function Call
The `insertionSort` function is called with `arr = [12, 11, 13, 5, 6]` and `n = 5`.

---

### Iteration 1 (`i = 1`):
- `key = arr[1] = 11`
- `j = i - 1 = 0`
- **Inner while loop**:
  - Check if `j >= 0 && arr[j] > key` → `0 >= 0 && 12 > 11` → true.
  - Shift `arr[j]` to `arr[j + 1]`: `arr[1] = arr[0]`, so the array becomes `[12, 12, 13, 5, 6]`.
  - Decrement `j`: `j = j - 1 = -1`.
- **Exit while loop** (since `j < 0`).
- Place `key` at `arr[j + 1]`: `arr[0] = 11`.
- **Array after placing key**: `[11, 12, 13, 5, 6]`

---

### Iteration 2 (`i = 2`):
- `key = arr[2] = 13`
- `j = i - 1 = 1`
- **Inner while loop**:
  - Check if `j >= 0 && arr[j] > key` → `1 >= 0 && 12 > 13` → false.
- **Exit while loop** (no shifting needed).
- Place `key` at `arr[j + 1]`: `arr[2] = 13`.
- **Array remains unchanged**: `[11, 12, 13, 5, 6]`

---

### Iteration 3 (`i = 3`):
- `key = arr[3] = 5`
- `j = i - 1 = 2`
- **Inner while loop**:
  - Check if `j >= 0 && arr[j] > key` → `2 >= 0 && 13 > 5` → true.
  - Shift `arr[j]` to `arr[j + 1]`: `arr[3] = arr[2]`, so the array becomes `[11, 12, 13, 13, 6]`.
  - Decrement `j`: `j = j - 1 = 1`.
  - Check if `j >= 0 && arr[j] > key` → `1 >= 0 && 12 > 5` → true.
  - Shift `arr[j]` to `arr[j + 1]`: `arr[2] = arr[1]`, so the array becomes `[11, 12, 12, 13, 6]`.
  - Decrement `j`: `j = j - 1 = 0`.
  - Check if `j >= 0 && arr[j] > key` → `0 >= 0 && 11 > 5` → true.
  - Shift `arr[j]` to `arr[j + 1]`: `arr[1] = arr[0]`, so the array becomes `[11, 11, 12, 13, 6]`.
  - Decrement `j`: `j = j - 1 = -1`.
- **Exit while loop** (since `j < 0`).
- Place `key` at `arr[j + 1]`: `arr[0] = 5`.
- **Array after placing key**: `[5, 11, 12, 13, 6]`

---

### Iteration 4 (`i = 4`):
- `key = arr[4] = 6`
- `j = i - 1 = 3`
- **Inner while loop**:
  - Check if `j >= 0 && arr[j] > key` → `3 >= 0 && 13 > 6` → true.
  - Shift `arr[j]` to `arr[j + 1]`: `arr[4] = arr[3]`, so the array becomes `[5, 11, 12, 13, 13]`.
  - Decrement `j`: `j = j - 1 = 2`.
  - Check if `j >= 0 && arr[j] > key` → `2 >= 0 && 12 > 6` → true.
  - Shift `arr[j]` to `arr[j + 1]`: `arr[3] = arr[2]`, so the array becomes `[5, 11, 12, 12, 13]`.
  - Decrement `j`: `j = j - 1 = 1`.
  - Check if `j >= 0 && arr[j] > key` → `1 >= 0 && 11 > 6` → true.
  - Shift `arr[j]` to `arr[j + 1]`: `arr[2] = arr[1]`, so the array becomes `[5, 11, 11, 12, 13]`.
  - Decrement `j`: `j = j - 1 = 0`.
- **Exit while loop** (since `j < 0`).
- Place `key` at `arr[j + 1]`: `arr[1] = 6`.
- **Array after placing key**: `[5, 6, 11, 12, 13]`

---

### Final Sorted Array:
`[5, 6, 11, 12, 13]`

