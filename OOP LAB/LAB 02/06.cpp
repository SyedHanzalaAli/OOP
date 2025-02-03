#include <iostream>
using namespace std;

void resize(int*& arr, int& capacity, int newCapacity) {
    int* newArr = new int[newCapacity];
    for (int i = 0; i < capacity; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

int main() {
    int capacity = 5;
    int size = 0;
    int* arr = new int[capacity];
    int num;
    char choice;

    do {
        cout << "Enter a number to insert: ";
        cin >> num;
        if (size == capacity) {
            resize(arr, capacity, capacity * 2);
        }
        arr[size++] = num;
        
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Do you want to add more? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    resize(arr, capacity, size);
    cout << "Final compact array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    return 0;
}
