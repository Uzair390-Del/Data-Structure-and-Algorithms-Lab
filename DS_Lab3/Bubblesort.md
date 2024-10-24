# Bubble Sort Guidance

## 1. Introduction to Bubble Sort
- **Definition**: Bubble Sort is a simple comparison-based sorting algorithm where adjacent elements are compared, and if they are in the wrong order, they are swapped.
- **Use case**: Suitable for small datasets or when simplicity is more important than performance.

## 2. Example Array for Dry Run
Let’s take an example array with 5 elements:  
**Array**: `[5, 3, 8, 4, 2]`

## 3. Detailed Dry Run

### Step 1 (First Pass):
- Compare 1st and 2nd elements: `5 > 3`, so **swap** → `[3, 5, 8, 4, 2]`
- Compare 2nd and 3rd elements: `5 < 8`, no swap → `[3, 5, 8, 4, 2]`
- Compare 3rd and 4th elements: `8 > 4`, so **swap** → `[3, 5, 4, 8, 2]`
- Compare 4th and 5th elements: `8 > 2`, so **swap** → `[3, 5, 4, 2, 8]`
- End of the first pass, **largest element (8) is now in its correct position**.

### Step 2 (Second Pass):
- Compare 1st and 2nd elements: `3 < 5`, no swap → `[3, 5, 4, 2, 8]`
- Compare 2nd and 3rd elements: `5 > 4`, so **swap** → `[3, 4, 5, 2, 8]`
- Compare 3rd and 4th elements: `5 > 2`, so **swap** → `[3, 4, 2, 5, 8]`
- End of the second pass, **second-largest element (5) is now in its correct position**.

### Step 3 (Third Pass):
- Compare 1st and 2nd elements: `3 < 4`, no swap → `[3, 4, 2, 5, 8]`
- Compare 2nd and 3rd elements: `4 > 2`, so **swap** → `[3, 2, 4, 5, 8]`
- End of the third pass, **third-largest element (4) is now in its correct position**.

### Step 4 (Fourth Pass):
- Compare 1st and 2nd elements: `3 > 2`, so **swap** → `[2, 3, 4, 5, 8]`
- End of the fourth pass, **array is now sorted**.

At this point, no further swaps are needed, and the array is sorted: `[2, 3, 4, 5, 8]`.

## 4. Steps for Writing Pseudocode
Here’s a breakdown of how to write the pseudocode for Bubble Sort:

1. **Initialize Loop**: Create a loop that runs multiple times (outer loop).
2. **Comparison**: Inside the loop, compare adjacent elements (inner loop).
3. **Swap**: If the element on the left is greater than the element on the right, swap them.
4. **Repeat**: Repeat the process for each element except the last, as the largest elements will "bubble" to the correct position.
5. **Optimization** (optional): Stop the loop if no swaps are made in a pass (array is already sorted).

## 5. Pseudocode for Bubble Sort
```text
function bubbleSort(arr)
    n = length of arr
    for i = 0 to n-1
        for j = 0 to n-i-1
            if arr[j] > arr[j+1]
                swap(arr[j], arr[j+1])
    end for
end function
```

# 6. Time Complexity Derivation

## Basic Idea of Bubble Sort
Bubble Sort works by repeatedly comparing adjacent elements and swapping them if they are in the wrong order. This process is repeated for each element until the array is sorted.

## Number of Comparisons and Swaps

### Outer Loop (Passes):
Bubble Sort makes multiple "passes" through the array. Each pass moves the largest unsorted element to its correct position. The number of passes required is **n-1**, where **n** is the number of elements in the array.

### Inner Loop (Comparisons):
In each pass, Bubble Sort compares adjacent elements in the array. After each pass, the largest element is placed in its final position, so fewer comparisons are needed in subsequent passes. The inner loop (comparisons) runs **n-i-1** times during the i-th pass, where:

- **i** = current pass number (starting from 0).

## Total Number of Comparisons
To compute the total number of comparisons made by Bubble Sort, we sum the comparisons for each pass:

Total comparisons = (n-1) + (n-2) + (n-3) + ... + 1

This is the sum of the first (n-1) integers, which is a well-known formula for the sum of an arithmetic series:

S = [(n-1) * n] / 2

Simplifying the formula:

S = (n^2 - n) / 2
## Time Complexity Derivation
The dominant term in this expression is \(n^2\), because as **n** becomes large, \(n^2\) grows much faster than **n**. Therefore, the time complexity is primarily determined by \(n^2\).

- **Best case time complexity**: O(n) — In the best case, if the array is already sorted, Bubble Sort can be optimized to detect that no swaps are needed and exit after the first pass.
- **Worst case time complexity**: O(n²) — In the worst case (reverse sorted array), every element has to be compared and swapped, making the maximum number of comparisons and swaps.
- **Average case time complexity**: O(n²) — Even on random data, Bubble Sort tends to perform near its worst-case behavior because it makes comparisons in a similar pattern.

## Explanation of O(n²)
Since we are summing the number of comparisons in each pass and the number of comparisons is proportional to the square of the number of elements in the array, the overall time complexity is **O(n²)**.

In big-O notation:
- **O(n²)** represents the quadratic time complexity because the algorithm's running time grows roughly proportional to the square of the input size.
- This is due to the fact that for every element, we perform **n-i-1** comparisons, and summing those over all passes results in the quadratic growth.

## Why is it Inefficient?
Bubble Sort compares adjacent elements and repeats this process even for elements that are already sorted. The number of operations quickly grows with the size of the input array, making it inefficient for large datasets. More efficient algorithms like Merge Sort and Quick Sort are often preferred due to their **O(n log n)** time complexity, which grows more slowly than **O(n²)**.


