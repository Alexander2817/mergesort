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
 * The main function is the entry point of the program.
 * It asks the user for the size of the vector and fills it with random numbers.
 * It then calls the mergeSort function and measures the time it takes to sort the vector.
 * Finally, it prints out the duration of the sorting process.
 */
int main() {
    int size;
    vector<int> arr;
    
    cout << "Enter the size of the vector: ";
    cin >> size;
    cout << "Input Value: " << size <<endl;

    srand(time(0));
    for (int i = 0; i < size; i++) {
        int value = rand() % 1000;
        arr.push_back(value);
    }

    clock_t start = clock();
    mergeSort(arr, 0, arr.size() - 1);
    clock_t end = clock();

    double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
    cout << "Duration: " << duration << " s" << endl;

    return 0;
}