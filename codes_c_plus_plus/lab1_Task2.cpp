// simple C++ program that uses loops, conditionals, and functions.
#include <iostream> // Include the input-output stream library
using namespace std; // Use the standard namespace to avoid prefixing standard elements

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

