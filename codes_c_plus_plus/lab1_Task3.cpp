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
