# Insertion Sort Guidance

---

## 1. Introduction to Insertion Sort
**Definition**: Insertion Sort is a comparison-based sorting algorithm where each element is inserted into its correct position within a sorted portion of the array. The array is divided into a sorted and an unsorted part, with the sorted part expanding one element at a time.

**Use case**: Suitable for small datasets or when a nearly sorted array requires minimal additional sorting.

---

## 2. Example Array for Dry Run
Let’s use an example array with 5 elements:

**Array**: `[12, 11, 13, 5, 6]`

---

## 3. Detailed Dry Run

**Step-by-Step Process**:

### Step 1 (First Iteration)
- **Array**: `[12, 11, 13, 5, 6]`
- **Current Key**: 11 (second element)
- Compare 11 with the previous element 12. Since 11 < 12, shift 12 one position to the right.
- Insert 11 at the start.
- **Array after first iteration**: `[11, 12, 13, 5, 6]`

### Step 2 (Second Iteration)
- **Array**: `[11, 12, 13, 5, 6]`
- **Current Key**: 13 (third element)
- Compare 13 with previous elements. Since 13 > 12, no shifting needed.
- **Array after second iteration**: `[11, 12, 13, 5, 6]`

### Step 3 (Third Iteration)
- **Array**: `[11, 12, 13, 5, 6]`
- **Current Key**: 5 (fourth element)
- Compare 5 with previous elements. Since 5 < 13, 12, and 11, shift all these to the right.
- Insert 5 at the start.
- **Array after third iteration**: `[5, 11, 12, 13, 6]`

### Step 4 (Fourth Iteration)
- **Array**: `[5, 11, 12, 13, 6]`
- **Current Key**: 6 (fifth element)
- Compare 6 with previous elements. Shift 13, 12, and 11 one position to the right.
- Insert 6 at index 1.
- **Array after fourth iteration**: `[5, 6, 11, 12, 13]`

---

## 4. Time Complexity Analysis in Detail

Insertion Sort has different complexities for best, average, and worst cases:

- **Best case**: \( O(n) \) - when the array is already sorted
- **Worst and Average case**: \( O(n^2) \) - when the array is in reverse order or random order

Let’s analyze the complexity with a dry run.

### Example Array: `[5, 2, 4, 6, 1, 3]`

#### Detailed Dry Run with Time Complexity

| Pass | Key | Comparisons | Shifts | Array State                    |
|------|-----|-------------|--------|--------------------------------|
| 1    | 2   | 1           | 1      | `[2, 5, 4, 6, 1, 3]`           |
| 2    | 4   | 1           | 0      | `[2, 4, 5, 6, 1, 3]`           |
| 3    | 6   | 1           | 0      | `[2, 4, 5, 6, 1, 3]`           |
| 4    | 1   | 4           | 4      | `[1, 2, 4, 5, 6, 3]`           |
| 5    | 3   | 3           | 3      | `[1, 2, 3, 4, 5, 6]`           |

#### Total Comparisons and Shifts
The total number of comparisons and shifts depends on how unsorted the array is:

- **Comparisons**: Sum of comparisons across all passes.
- **Shifts**: Each comparison that finds an out-of-place element results in a shift.

#### Formula for Total Comparisons
- Best case: \( O(n) \) - one comparison per element.
- Average/Worst case: \( O(n^2) \) - each pass compares more elements, summing to \( (n^2 - n) / 2 \).

---

## 5. Steps for Writing Pseudocode

1. **Loop**: Iterate over each element, treating it as the current key.
2. **Compare and Shift**: Compare the current key with sorted elements on its left and shift elements to make space.
3. **Insert**: Place the key in its correct position.
4. **Repeat**: Continue for each element until the array is sorted.

---

## 6. Pseudocode for Insertion Sort

```plaintext
function insertionSort(arr)
    n = length of arr
    for i = 1 to n-1
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key
            arr[j + 1] = arr[j]
            j = j - 1
        arr[j + 1] = key
    end for
end function
