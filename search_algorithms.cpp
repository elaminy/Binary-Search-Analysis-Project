#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int recursiveBinarySearch(const vector<int>& vec, int target, int left, int right);
int iterativeBinarySearch(const vector<int>& vec, int target);
int sequentialSearch(const vector<int>& vec, int target);

int main() {
    const int RANGE = 100;
    const int SIZE = 20;

    vector<int> numbers(SIZE);
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = rand() % RANGE + 1;
    }
    sort(numbers.begin(), numbers.end());

    int target = rand() % RANGE + 1;

    cout << "Contents of vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Recursive Binary Search
    int index = recursiveBinarySearch(numbers, target, 0, numbers.size() - 1);
    if (index != -1) {
        cout << target << " found at location " << index << " using Recursive Binary Search" << endl;
    }
    else {
        cout << target << " was not found using Recursive Binary Search" << endl;
    }

    // Iterative Binary Search
    index = iterativeBinarySearch(numbers, target);
    if (index != -1) {
        cout << target << " found at location " << index << " using Iterative Binary Search" << endl;
    }
    else {
        cout << target << " was not found using Iterative Binary Search" << endl;
    }

    // Sequential Search
    index = sequentialSearch(numbers, target);
    if (index != -1) {
        cout << target << " found at location " << index << " using Sequential Search" << endl;
    }
    else {
        cout << target << " was not found using Sequential Search" << endl;
    }

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