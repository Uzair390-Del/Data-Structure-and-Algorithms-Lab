#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    // Traverse the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int n, target;

    // Input the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input the array elements
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input the target value to search for
    cout << "Enter the value to search: ";
    cin >> target;

    // Perform linear search
    int result = linearSearch(arr, n, target);

    // Output the result
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
