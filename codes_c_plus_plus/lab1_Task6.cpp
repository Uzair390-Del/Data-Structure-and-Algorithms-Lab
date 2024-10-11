// #include <iostream>
// using namespace std;

// int main() {
//     int n;

//     // Input the number of elements in the array
//     cout << "Enter the number of elements: ";
//     cin >> n;

//     int arr[n];

//     // Input the array elements
//     cout << "Enter the elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     // Reverse the array using the swap function
//     for (int i = 0; i < n / 2; i++) {
//         swap(arr[i], arr[n - i - 1]); // Swap elements at both ends
//     }

//     // Output the reversed array
//     cout << "Reversed array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
#include <iostream>
using namespace std;

int main() {
    int n;

    // Input the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Input the array elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize start and end pointers
    int start = 0;
    int end = n - 1;

    // Reverse the array using start and end variables
    while (start < end) {
        // Swap the elements at start and end
        swap(arr[start], arr[end]);
        start++;  // Move the start pointer forward
        end--;    // Move the end pointer backward
    }

    // Output the reversed array
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
