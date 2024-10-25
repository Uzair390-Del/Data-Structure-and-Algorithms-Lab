
# Time Complexities of Array Operations

## 1. Linear Search (Time Complexity: O(n))

**Example**:  
Array: `[3, 7, 9, 1, 5]`  
Search for: `5`

### Steps:
- Compare `3` with `5` → Not equal, continue.
- Compare `7` with `5` → Not equal, continue.
- Compare `9` with `5` → Not equal, continue.
- Compare `1` with `5` → Not equal, continue.
- Compare `5` with `5` → Found the element.

### Derivation:
- **Best Case**: The target element `5` is found at the first position.
  - Only one comparison is needed:  
    T(n) = O(1)

- **Worst Case**: The target element is at the last position (or not present in the array).
  - We need to compare each element in the array, resulting in `n` comparisons:  
    T(n) = c_1 + c_2 + ... + c_n = O(n)

Thus, in the worst case, the time complexity is **O(n)**.

---

## 2. Insertion in an Array (Time Complexity: O(n))

**Example**:  
Array: `[10, 20, 30, 40]`  
Insert `25` at index 2 (between `20` and `30`).

### Steps:
- Array before insertion: `[10, 20, 30, 40]`
- To insert `25` at index 2:
  - Shift `30` to index 3.
  - Shift `40` to index 4.
  - Insert `25` at index 2.
- Final array: `[10, 20, 25, 30, 40]`

### Derivation:
- **Best Case**: Inserting at the end of the array.
  - No shifting of elements is required; you simply place the element at index `n`:  
    T(n) = O(1)

- **Worst Case**: Inserting at the beginning or middle of the array.
  - You need to shift elements from index `k` to `n-1` to the right.
  - In the worst case (insertion at index 0), you shift all `n` elements:  
    T(n) = c_1 + c_2 + ... + c_n = O(n)

Thus, the time complexity for the worst case is **O(n)**.

---

## 3. Deletion in an Array (Time Complexity: O(n))

**Example**:  
Array: `[12, 14, 16, 18, 20]`  
Delete the element at index 2 (which is `16`).

### Steps:
- Array before deletion: `[12, 14, 16, 18, 20]`
- Delete the element `16` at index 2.
- Shift `18` to index 2.
- Shift `20` to index 3.
- Final array: `[12, 14, 18, 20]`

### Derivation:
- **Best Case**: Deleting the last element in the array.
  - No shifting of elements is needed, as only the size of the array is reduced:  
    T(n) = O(1)

- **Worst Case**: Deleting from the beginning or middle of the array.
  - You need to shift all elements to the left after the deleted element.
  - In the worst case (delete at index 0), you shift `n-1` elements:  
    T(n) = c_1 + c_2 + ... + c_{n-1} = O(n)

Thus, the time complexity for the worst case is **O(n)**.

# Binary Search Time Complexity Derivation

Binary Search is an efficient algorithm to search for a target value in a **sorted** array. It repeatedly divides the search interval in half. If the value of the search key is less than the item in the middle of the interval, the search continues in the lower half; otherwise, it continues in the upper half.

## Steps of Binary Search (Recap):

1. **Find the middle element** of the array.
2. **Compare** the middle element with the target:
   - If the middle element is equal to the target, return the index.
   - If the target is smaller, discard the right half and continue searching in the left half.
   - If the target is larger, discard the left half and continue searching in the right half.
3. **Repeat** this process until the target is found or the search space is reduced to zero (i.e., the target is not present in the array).

### Key Concept: Dividing the Array

At every step, Binary Search reduces the size of the array by half. This halving process is key to understanding its time complexity.

---

## Time Complexity Derivation:

### 1. **Best Case Time Complexity**: `O(1)`

- The best case occurs when the middle element is the target in the first comparison.
- In this case, Binary Search only makes **one comparison** to find the element.

For the best case:

`T(n) = O(1)`

### 2. **Worst Case Time Complexity**: `O(log n)`

- In the worst case, the target element is either at the extreme left or extreme right of the array, meaning the search continues until the search space is reduced to one element.
- At each step, the search space is divided by 2.

Let’s break down the steps:

1. **Initial array size**: `n`
2. After 1st step, the array size is reduced to `n/2`.
3. After 2nd step, the array size is reduced to `n/4` (i.e., `n/2^2`).
4. After 3rd step, the array size is `n/8` (i.e., `n/2^3`).
5. This process continues until the search space is reduced to a single element (i.e., array size = 1).

The general form for the size of the array after `k` steps is:

`n / 2^k`

In the worst case, we continue halving the array until:

`n / 2^k = 1`

Solving for `k`:

`n = 2^k`

Taking the logarithm (base 2) on both sides:

`k = log_2(n)`

Thus, in the worst case, the algorithm makes `log_2(n)` comparisons to find the target element. Therefore, the time complexity for the worst case is:

`T(n) = O(log n)`

---

## Intuitive Explanation:

The key reason Binary Search is efficient is that it eliminates half of the remaining elements at each step. This halving process is logarithmic in nature.

For example:

- **8 elements**: Binary Search takes at most `log_2(8) = 3` comparisons (because `2^3 = 8`).
- **16 elements**: It takes `log_2(16) = 4` comparisons (because `2^4 = 16`).
- **32 elements**: It takes `log_2(32) = 5` comparisons (because `2^5 = 32`).

So, as the number of elements increases, the number of comparisons increases logarithmically.

---

## Detailed Example:

Consider the array: `[1, 3, 5, 7, 9, 11, 13]`, and we are searching for 9.

1. **Initial array**: `[1, 3, 5, 7, 9, 11, 13]`, size `n = 7`
   - Middle element is 7. Since 9 > 7, search in the right half.
   
2. **Right half**: `[9, 11, 13]`, size `n = 3`
   - Middle element is 11. Since 9 < 11, search in the left half.
   
3. **Left half**: `[9]`, size `n = 1`
   - Middle element is 9. Found the element!

This took **3 comparisons**, and since `log_2(7) ≈ 3`, this aligns with the worst-case time complexity.

---

## Space Complexity:

Binary Search operates in place, meaning it only uses a small, constant amount of extra memory (to store the indices of the current search boundaries). Therefore, the space complexity is:

`O(1)`

---

## Final Summary:

- **Best Case Time Complexity**: `O(1)` (when the middle element is the target).
- **Worst Case Time Complexity**: `O(log n)` (when the array is halved repeatedly).
- **Space Complexity**: `O(1)` (since no additional space is used).

The logarithmic nature of Binary Search makes it highly efficient compared to linear search algorithms, especially for large datasets.


