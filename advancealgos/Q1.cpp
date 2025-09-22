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
    return i + 1;
}


void randomizedQuickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0)); 

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    randomizedQuickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\nNumber of comparisons: " << comparisons << endl;

    return 0;
}
