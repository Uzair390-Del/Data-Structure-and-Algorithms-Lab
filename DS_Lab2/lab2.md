
# Task 1: Simple C++ Program that Uses Loops, Conditionals, and Functions

```cpp
#include <iostream>  // Include the input-output stream library
using namespace std;  // Use the standard namespace to avoid prefixing standard elements

// Function to calculate the sum and average of an array of integers
void calculateSumAndAverage(int arr[], int size) {
    int sum = 0; // Initialize sum to 0

    // Loop through each element in the array
    for (int i = 0; i < size; i++) {
        sum += arr[i];  // Add each number to the sum
    }

    // Calculate average by casting sum to double to avoid integer division
    double average = static_cast<double>(sum) / size; 

    // Output the sum and average to the console
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
}

int main() {
    const int size = 5; // Define the size of the array
    int numbers[size]; // Declare an array to hold the integers

    cout << "Enter 5 integers: "; // Prompt the user for input
    // Loop to read integers from user input
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];  // Input each number into the array
    }

    // Call the function to calculate sum and average, passing the array and its size
    calculateSumAndAverage(numbers, size);  

    return 0; // Indicate that the program ended successfully
}
```

# Task 2: Find Largest and Smallest in an Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;

    // Ask the user for the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Create an array to store the elements
    int arr[n];

    // Input elements
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize smallest and largest with the first element of the array
    int largest = arr[0];
    int smallest = arr[0];

    // Loop through the array to find the largest and smallest values
    for(int i = 1; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    // Output the largest and smallest values
    cout << "Largest value: " << largest << endl;
    cout << "Smallest value: " << smallest << endl;

    return 0;
}
```

## Dry Run: Finding the Largest and Smallest in an Array

Given Code:

The program asks the user to input a number of elements (n) and then stores the values in an array. It proceeds to find the largest and smallest elements in the array.

### Input:

Suppose the input array has 5 elements: `{5, 2, 9, 3, 7}`.

### Step-by-Step Dry Run:

#### Initialization:
The user is asked to input the number of elements, `n = 5`.
The array `arr[]` is declared to hold 5 integers.

#### Input Phase:
The user enters the 5 elements: 5, 2, 9, 3, 7.
The array now contains: `arr[] = {5, 2, 9, 3, 7}`.

#### Initialize largest and smallest:
The variables largest and smallest are both initialized to the first element of the array (`arr[0] = 5`).
State:
- largest = 5
- smallest = 5

#### Iteration 1 (i = 1):
The second element of the array, `arr[1] = 2`, is compared with largest and smallest.
- Since 2 is smaller than smallest, smallest is updated to 2.
- No change is made to largest because 2 is not greater than 5.

State:
- largest = 5
- smallest = 2

#### Iteration 2 (i = 2):
The third element of the array, `arr[2] = 9`, is compared.
- Since 9 is greater than largest, largest is updated to 9.
- No change is made to smallest because 9 is not smaller than 2.

State:
- largest = 9
- smallest = 2

#### Iteration 3 (i = 3):
The fourth element of the array, `arr[3] = 3`, is compared.
- No change is made to largest because 3 is not greater than 9.
- No change is made to smallest because 3 is not smaller than 2.

State:
- largest = 9
- smallest = 2

#### Iteration 4 (i = 4):
The fifth and final element of the array, `arr[4] = 7`, is compared.
- No change is made to largest because 7 is not greater than 9.
- No change is made to smallest because 7 is not smaller than 2.

State:
- largest = 9
- smallest = 2

### Final Output:

The loop completes, and the program outputs:
- Largest value: 9
- Smallest value: 2

### Summary:

- The largest number in the array `{5, 2, 9, 3, 7}` is 9.
- The smallest number in the array is 2.




### Code:

```cpp
// Find the largest and smallest in an array
#include <iostream>
using namespace std;

int main() {
    int n;

    // Ask the user for the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Create an array to store the elements
    int arr[n];

    // Input elements
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize smallest and largest with the first element of the array
    int largest = arr[0];
    int smallest = arr[0];

    // Loop through the array to find the largest and smallest values
    for(int i = 1; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    // Output the largest and smallest values
    cout << "Largest value: " << largest << endl;
    cout << "Smallest value: " << smallest << endl;

    return 0;
}
```