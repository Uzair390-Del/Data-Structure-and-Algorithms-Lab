# Quick Sort Guidance

---

## 1. Introduction to Quick Sort
**Definition**: Quick Sort is a divide-and-conquer sorting algorithm that selects a pivot element and partitions the array into two sub-arrays, such that elements smaller than the pivot are on the left and elements greater than the pivot are on the right. The process is repeated recursively on the sub-arrays.

**Use case**: Quick Sort is efficient for large datasets and often used when in-place sorting is required.

---

## 2. Example Array for Dry Run
Let’s use an example array with 6 elements:

**Array**: `[10, 7, 8, 9, 1, 5]`

---

## 3. Detailed Dry Run

**Step-by-Step Process**:

### Initial Array
- **Array**: `[10, 7, 8, 9, 1, 5]`
- **Pivot**: The first element, `10`

### Step 1: Partition Process
**Variables**:
- `low` = index of first element = 0
- `high` = index of last element = 5
- `i` = `low + 1` = 1
- `j` = `high` = 5

**Initial Pivot Placement**: `pivot = arr[low] = 10`

#### Partition Iterations
1. Compare `arr[j]` (5) with `pivot` (10):
   - `arr[j] < pivot`, decrement `j` to 4.
2. Compare `arr[j]` (1) with `pivot` (10):
   - `arr[j] < pivot`, decrement `j` to 3.
3. Compare `arr[j]` (9) with `pivot` (10):
   - `arr[j] < pivot`, decrement `j` to 2.
4. Compare `arr[j]` (8) with `pivot` (10):
   - `arr[j] < pivot`, decrement `j` to 1.
5. Compare `arr[j]` (7) with `pivot` (10):
   - `arr[j] < pivot`, decrement `j` to 0.

At this point, `i > j`.

**Swap Pivot with `arr[j]`**:
- Swap `arr[low]` and `arr[j]`.
- **Array after partitioning**: `[5, 7, 8, 9, 1, 10]`

**Pivot's Final Position**: Index 5.

### Step 2: Recursive Calls

#### Left Sub-array: `[5, 7, 8, 9, 1]`
- Pivot = `5` (first element).
- Perform partitioning:
  1. Compare `arr[j]` (1) with `pivot` (5):
     - `arr[j] < pivot`, decrement `j` to 3.
  2. Compare `arr[j]` (9) with `pivot` (5):
     - `arr[j] > pivot`, increment `i` to 1.
  3. Swap `arr[i]` and `arr[j]`:
     - **Array**: `[1, 7, 8, 9, 5, 10]`.
- Pivot's Final Position: Index 0.

#### Right Sub-array: `[7, 8, 9]`
- Pivot = `7` (first element).
- Perform partitioning:
  1. Compare `arr[j]` (9) with `pivot` (7):
     - `arr[j] > pivot`, increment `i` to 2.
  2. Swap `arr[i]` and `arr[j]`:
     - **Array**: `[1, 5, 7, 8, 9, 10]`.
- Pivot's Final Position: Index 1.

---

## 4. Time Complexity Analysis in Detail

Quick Sort has different complexities for best, average, and worst cases:

- **Best case**: \( O(n \log n) \) - when the pivot divides the array into two nearly equal parts.
- **Worst case**: \( O(n^2) \) - when the pivot is always the smallest or largest element.
- **Average case**: \( O(n \log n) \).

Let’s analyze the complexity with a dry run.

### Basic Idea of Quick Sort
Quick Sort divides the array based on the pivot element and recursively sorts the sub-arrays. The partitioning step dominates the time complexity.

---

### Time Complexity Analysis

- **Best Case Time Complexity: \( O(n \log n) \)**  
  Dividing the array into equal halves results in logarithmic recursive depth.

- **Worst Case Time Complexity: \( O(n^2) \)**  
  When the pivot divides the array into highly unbalanced partitions.

- **Average Case Time Complexity: \( O(n \log n) \)**  
  On average, the array is divided into balanced partitions.

---

## 5. Steps for Writing Pseudocode

1. **Choose a Pivot**: Select the first element as the pivot.
2. **Partition the Array**: Rearrange elements such that smaller elements are on the left and larger elements are on the right.
3. **Recursive Sort**: Apply the same logic to the left and right sub-arrays.
4. **Repeat**: Continue until the base case is reached (sub-array of size 1 or 0).

---

## 6. Pseudocode for Quick Sort

```plaintext
function quickSort(arr, low, high)
    if low < high
        pivotIndex = partition(arr, low, high)
        quickSort(arr, low, pivotIndex - 1)
        quickSort(arr, pivotIndex + 1, high)
end function

function partition(arr, low, high)
    pivot = arr[low]
    i = low + 1
    j = high
    while i <= j
        while arr[i] <= pivot and i <= high
            i = i + 1
        while arr[j] > pivot and j >= low
            j = j - 1
        if i < j
            swap arr[i] and arr[j]
    swap arr[low] and arr[j]
    return j
end function
```

---

## 7. Conclusion
Quick Sort is a highly efficient sorting algorithm for large datasets, especially when in-place sorting is required. Proper pivot selection and partitioning ensure optimal performance. While its worst-case performance is \( O(n^2) \), average and best-case complexities make it a preferred choice for many practical applications.
