#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recursiveBinarySearch(const vector<int>& vec, int target, int left, int right);
int iterativeBinarySearch(const vector<int>& vec, int target);
int sequentialSearch(const vector<int>& vec, int target);

int main() {
    vector<int> numbers = { 10, 25, 30, 35, 40, 45, 50, 55, 60, 65 };
    sort(numbers.begin(), numbers.end());

    int target1 = 40;  // An item that is in the list
    int target2 = 70;  // An item that is not in the list

    // Recursive Binary Search
    int index = recursiveBinarySearch(numbers, target1, 0, numbers.size() - 1);
    cout << "Contents of vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    cout << target1 << " found at location " << index << endl;

    index = recursiveBinarySearch(numbers, target2, 0, numbers.size() - 1);
    cout << target2 << " was not found, return value is " << index << endl;

    // Iterative Binary Search
    index = iterativeBinarySearch(numbers, target1);
    cout << target1 << " found at location " << index << endl;

    index = iterativeBinarySearch(numbers, target2);
    cout << target2 << " was not found, return value is " << index << endl;

    // Sequential Search
    index = sequentialSearch(numbers, target1);
    cout << target1 << " found at location " << index << endl;

    index = sequentialSearch(numbers, target2);
    cout << target2 << " was not found, return value is " << index << endl;

    return 0;
}

int recursiveBinarySearch(const vector<int>& vec, int target, int left, int right) {
    if (left > right) {
        return -1;  // Target not found
    }

    int mid = left + (right - left) / 2;

    if (vec[mid] == target) {
        return mid;  // Target found
    }
    else if (vec[mid] > target) {
        return recursiveBinarySearch(vec, target, left, mid - 1);
    }
    else {
        return recursiveBinarySearch(vec, target, mid + 1, right);
    }
}

int iterativeBinarySearch(const vector<int>& vec, int target) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (vec[mid] == target) {
            return mid;  // Target found
        }
        else if (vec[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return -1;  // Target not found
}

int sequentialSearch(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            return i;  // Target found
        }
    }
    return -1;  // Target not found
}