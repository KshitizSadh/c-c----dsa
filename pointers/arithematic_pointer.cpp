#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    int marks[n]; // Define the marks array after getting the number of students

    for (int i = 0; i < n; i++) {
        cout << "Enter marks for student " << i + 1 << ": ";
        cin >> marks[i];
    }

    cout << "Marks for student 5: " << marks[4] << endl;
    //pointer and arrays
    
    return 0;
}
