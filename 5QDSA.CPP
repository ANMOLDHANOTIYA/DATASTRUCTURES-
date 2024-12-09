#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int baseAddress;
    cout << "Enter base address: ";
    cin >> baseAddress;

    int i, j;
    cout << "Enter the indices (i, j): ";
    cin >> i >> j;

    char order;
    cout << "Enter memory arrangement (R for Row Major, C for Column Major): ";
    cin >> order;

    int size = sizeof(int); // For int type array

    int address;
    if (order == 'R') {
        address = baseAddress + (i * cols + j) * size;
    } else {
        address = baseAddress + (j * rows + i) * size;
    }

    cout << "Address of element at (" << i << ", " << j << ") is: " << address << endl;
    return 0;
}
