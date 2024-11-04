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
# Time Complexity Derivation for Insertion Sort

---

### Basic Idea of Insertion Sort
Insertion Sort builds a sorted portion of the array one element at a time by shifting elements as necessary to insert the current element in the correct position within the sorted portion.

---

### Number of Comparisons and Shifts

#### Outer Loop (Passes):
Insertion Sort requires `n - 1` passes through the array, where `n` is the number of elements in the array. This is because it starts from the second element (`i = 1`) and goes up to the last element (`i = n - 1`).

#### Inner Loop (Comparisons and Shifts):
For each pass, Insertion Sort may need to shift elements to make space for the current element (`key`). The worst-case number of shifts happens when each element is greater than the `key`, requiring every element to be moved.

The number of comparisons in each pass depends on the sorted portion. In the worst case, each pass performs up to `i` comparisons and shifts, where `i` is the index of the current element.

---

### Total Number of Comparisons and Shifts (Worst Case)

In the worst-case scenario, where the array is sorted in reverse order, each element must be shifted `i` times to reach the correct position. Therefore, the total number of comparisons and shifts can be calculated as:


\text{Total comparisons (worst case)} = 1 + 2 + 3 + \dots + (n - 1)

Using the formula for the sum of an arithmetic series:

S = (n-1)n/2

Simplifying the formula:

S = n^2 - n/2


Thus, the worst-case time complexity is determined by the dominant term, which is \( O(n^2) \).

---

### Time Complexity Analysis

- **Best Case Time Complexity: \( O(n) \)**  
  If the array is already sorted, Insertion Sort only makes one comparison per pass and no shifts, resulting in a linear time complexity.

- **Worst Case Time Complexity: \( O(n^2) \)**  
  When the array is in reverse order, each element must be compared and shifted for each pass, leading to quadratic time complexity.

- **Average Case Time Complexity: \( O(n^2) \)**  
  On average, half of the elements need to be shifted in each pass, resulting in a time complexity close to \( O(n^2) \).

### Explanation of \( O(n^2) \)

The quadratic time complexity of Insertion Sort arises from the nested structure of the algorithm: for each element, the algorithm may need to make up to \( i \) comparisons, resulting in a number of operations proportional to \( n^2 \).

---

### Advantages of Insertion Sort

Unlike Selection Sort, Insertion Sort is adaptive. It performs well for nearly sorted or small datasets, making it a good choice in specific cases. The number of shifts is minimized compared to other quadratic algorithms, which can be useful when data is close to sorted.

### Why Insertion Sort is Inefficient for Large Datasets

Despite its benefits for small or nearly sorted arrays, Insertion Sort becomes inefficient for large datasets due to its \( O(n^2) \) time complexity. More efficient algorithms, such as Merge Sort and Quick Sort, achieve \( O(n \log n) \) complexity, making them preferable for larger datasets.


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
