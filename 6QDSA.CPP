#include <iostream>
using namespace std;

int main() {
    int rows, cols, depth;
    cout << "Enter number of rows, columns, and depth: ";
    cin >> rows >> cols >> depth;

    int baseAddress;
    cout << "Enter base address: ";
    cin >> baseAddress;

    int i, j, k;
    cout << "Enter the indices (i, j, k): ";
    cin >> i >> j >> k;

    char order;
    cout << "Enter memory arrangement (R for Row Major, C for Column Major): ";
    cin >> order;

    int size = sizeof(int);

    int address;
    if (order == 'R') {
        address = baseAddress + (i * cols * depth + j * depth + k) * size;
    } else {
        address = baseAddress + (k * rows * cols + i * cols + j) * size;
    }

    cout << "Address of element at (" << i << ", " << j << ", " << k << ") is: " << address << endl;
    return 0;
}
