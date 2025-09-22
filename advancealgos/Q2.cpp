#include <iostream>
#include <vector>
#include <cstdlib>    // for rand() and srand()
#include <ctime>      // for time()

using namespace std;

long long comparisons = 0; 


void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


int randomizedPartition(vector<int> &arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swapElements(arr[randomIndex], arr[high]); 

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swapElements(arr[i], arr[j]);
        }
    }
    swapElements(arr[i + 1], arr[high]);
    return i + 1; // final pivot index
}


int randomizedSelect(vector<int> &arr, int low, int high, int i) {
    if (low == high)
        return arr[low]; 

    
    int q = randomizedPartition(arr, low, high);
    int k = q - low + 1;

    if (i == k)
        return arr[q]; 
    else if (i < k)
        return randomizedSelect(arr, low, q - 1, i); 
    else
        return randomizedSelect(arr, q + 1, high, i - k);
}

int main() {
    srand(time(0));

    int n, i;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int j = 0; j < n; j++)
        cin >> arr[j];

    cout << "Enter i (to find the i-th smallest element): ";
    cin >> i;

    if (i < 1 || i > n) {
        cout << "Invalid i. It should be between 1 and " << n << endl;
        return 0;
    }

    int ithSmallest = randomizedSelect(arr, 0, n - 1, i);

    cout << "\nThe " << i << "-th smallest element is: " << ithSmallest << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
