# Selection Sort Guidance

## 1. Introduction to Selection Sort
- **Definition**: Selection Sort is a comparison-based sorting algorithm where the smallest (or largest, depending on order) element is selected from the unsorted portion and placed at the beginning.
- **Use case**: Useful for small datasets or when minimal swaps are preferred over minimal comparisons.

## 2. Example Array for Dry Run
Let's take an example array with 5 elements:  
**Array**: `[5, 3, 8, 4, 2]`

## 3. Detailed Dry Run

### Step 1 (First Pass):
- Find the minimum element in the unsorted array `[5, 3, 8, 4, 2]`.
- The minimum element is `2`, so **swap** `2` with the first element `5` → `[2, 3, 8, 4, 5]`.
- End of the first pass, **smallest element (2) is now in its correct position**.

### Step 2 (Second Pass):
- Find the minimum element in the remaining unsorted array `[3, 8, 4, 5]`.
- The minimum element is `3`, no swap needed as it is already in the correct position → `[2, 3, 8, 4, 5]`.
- End of the second pass, **second-smallest element (3) is now in its correct position**.

### Step 3 (Third Pass):
- Find the minimum element in the remaining unsorted array `[8, 4, 5]`.
- The minimum element is `4`, so **swap** `4` with `8` → `[2, 3, 4, 8, 5]`.
- End of the third pass, **third-smallest element (4) is now in its correct position**.

### Step 4 (Fourth Pass):
- Find the minimum element in the remaining unsorted array `[8, 5]`.
- The minimum element is `5`, so **swap** `5` with `8` → `[2, 3, 4, 5, 8]`.
- End of the fourth pass, **array is now sorted**.

After this step, no further swaps are needed, and the array is sorted: `[2, 3, 4, 5, 8]`.

## 4. Steps for Writing Pseudocode
Here’s a breakdown of how to write the pseudocode for Selection Sort:

1. **Initialize Loop**: Create a loop that iterates through the array (outer loop).
2. **Find Minimum**: Inside the loop, find the minimum element in the unsorted portion (inner loop).
3. **Swap**: Swap the minimum element with the first element of the unsorted portion.
4. **Repeat**: Repeat this process until all elements are sorted.

## 5. Pseudocode for Selection Sort
```text
function selectionSort(arr)
    n = length of arr
    for i = 0 to n-1
        minIndex = i
        for j = i+1 to n-1
            if arr[j] < arr[minIndex]
                minIndex = j
        if minIndex != i
            swap(arr[i], arr[minIndex])
    end for
end function
```
# Time Complexity Derivation

## Basic Idea of Selection Sort
Selection Sort works by repeatedly finding the minimum element from the unsorted portion and moving it to the sorted portion. This requires searching for the minimum each time and placing it in the correct position.

## Number of Comparisons and Swaps

### Outer Loop (Passes):
Selection Sort requires **n-1** passes, where **n** is the number of elements in the array.

### Inner Loop (Comparisons):
In each pass, we need to find the minimum element in the unsorted portion. This requires **n-i-1** comparisons during the i-th pass.

## Total Number of Comparisons
To compute the total number of comparisons in Selection Sort, we sum the comparisons for each pass:

Total comparisons = (n-1) + (n-2) + (n-3) + ... + 1

Using the formula for the sum of an arithmetic series:

 S = ((n-1) * n)/2 

Simplifying the formula:

S = (n^2 - n)/2 

## Time Complexity Derivation
The dominant term in this expression is \( n^2 \), which determines the time complexity as **O(n²)**.

- **Best case time complexity**: O(n²) — Even if the array is already sorted, Selection Sort still makes all comparisons.
- **Worst case time complexity**: O(n²) — The algorithm always makes the same number of comparisons regardless of the input order.
- **Average case time complexity**: O(n²) — Since the algorithm makes the same number of comparisons regardless of the order, the average case also remains O(n²).

## Explanation of O(n²)
Since we are summing the number of comparisons in each pass and each pass compares a diminishing number of elements, the overall time complexity is **O(n²)**.

In big-O notation:

- **O(n²)** represents the quadratic time complexity due to the number of comparisons growing proportional to the square of the input size.
- Unlike Bubble Sort, the number of swaps is minimized to one per pass, which is an advantage in certain use cases.

## Why is it Inefficient?
Selection Sort’s inefficiency arises from the need to scan the unsorted portion of the array to find the minimum in every pass. More efficient algorithms like Merge Sort and Quick Sort achieve **O(n log n)** time complexity, which grows slower than **O(n²)**, making them better choices for large datasets.
