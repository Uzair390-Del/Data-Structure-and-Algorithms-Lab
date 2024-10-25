
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
    \[T(n) = O(1)\]

- **Worst Case**: The target element is at the last position (or not present in the array).
  - We need to compare each element in the array, resulting in `n` comparisons:  
    \[T(n) = c_1 + c_2 + \dots + c_n = O(n)\]

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
    \[T(n) = O(1)\]

- **Worst Case**: Inserting at the beginning or middle of the array.
  - You need to shift elements from index `k` to `n-1` to the right.
  - In the worst case (insertion at index 0), you shift all `n` elements:  
    \[T(n) = c_1 + c_2 + \dots + c_n = O(n)\]

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
    \[T(n) = O(1)\]

- **Worst Case**: Deleting from the beginning or middle of the array.
  - You need to shift all elements to the left after the deleted element.
  - In the worst case (delete at index 0), you shift `n-1` elements:  
    \[T(n) = c_1 + c_2 + \dots + c_{n-1} = O(n)\]

Thus, the time complexity for the worst case is **O(n)**.
