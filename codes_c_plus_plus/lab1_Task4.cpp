// print the index of the smallest and largest value
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
    int largest = arr[0], smallest = arr[0];
    int largestIndex = 0, smallestIndex = 0;

    // Loop through the array to find the largest and smallest values with their indices
    for(int i = 1; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
            largestIndex = i; // Update the index of the largest element
        }
        if(arr[i] < smallest) {
            smallest = arr[i];
            smallestIndex = i; // Update the index of the smallest element
        }
    }

    // Output the largest and smallest values along with their indices
    cout << "Largest value: " << largest << " at index " << largestIndex << endl;
    cout << "Smallest value: " << smallest << " at index " << smallestIndex << endl;

    return 0;
}
