#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

/**
 * Merge two sorted subarrays into a single sorted array.
 *
 * @param arr the array that contains the two sorted subarrays
 * @param l(left) the starting index of the first subarray
 * @param m(mid) the ending index of the first subarray
 * @param r(right) the ending index of the second subarray
 */
void merge(vector<int>& arr, int l, int m, int r) {
    int leftSubArray = m - l + 1;
    int rightSubArray = r - m;

    vector<int> leftArr(leftSubArray), rightArr(rightSubArray);

    for (int i = 0; i < leftSubArray; i++) {
        leftArr[i] = arr[l + i];
    }
    for (int j = 0; j < rightSubArray; j++) {
        rightArr[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < leftSubArray && j < rightSubArray) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {  
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < leftSubArray) {
        arr[k] = leftArr[i];
        i++; k++;
    }

    while (j < rightSubArray) {
        arr[k] = rightArr[j];
        j++; k++;
    }
}   

/**
 * Recursively divide the array into two halves until the subarray has only one element (base case),
 * then merge the two halves in sorted order.
 * @param arr the array to be sorted
 * @param left the starting index of the subarray
 * @param right the ending index of the subarray
 */
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/**
 * Generates a vector of the given size with random elements between 0 and 1,000,000,000.
 * @param size the size of the vector to be generated
 * @return a vector of the given size with random elements
 */
vector<int> random(int size) {
    vector<int> arr(size);
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000000000; 
    }
    return arr;
}

/**
 * Prints the first ten elements or fewer of the given vector, separated by commas.
 * If the vector has fewer than ten elements, only those elements are printed.
 * @param arr the vector of integers to be printed
 */
void coutVector(const vector<int>& arr) {
    int lim = min(10, (int)arr.size());
    cout << "[";
    for (int i = 0; i < lim; i++) {
        cout << arr[i];
        if (i < lim - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}


/**
 * Main function that generates a random vector of integers, sorts it using merge sort, 
 * and prints the time taken for sorting ten elements of the sorted vector.
 * It measures the time taken to execute the merge sort and outputs the duration in milliseconds.
 * It also prints the unsorted and sorted vectors.
 */
int main() {
    int size;
    cout << "Enter the size of the vector: " << endl;
    cin >> size;

    vector<int> arr = random(size);

    cout << "Unsorted Elements: ";
    coutVector(arr);

    clock_t start_time = clock();
    mergeSort(arr, 0, arr.size() - 1);
    clock_t end_time = clock();

    double duration = (end_time - start_time) / (double)CLOCKS_PER_SEC * 1000.0;
    cout << "Time taken: " << duration << " milliseconds" << endl;
    cout << "Sorted Elements: ";
    coutVector(arr);

    return 0;
}