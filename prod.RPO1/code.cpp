#include <iostream>


int* memory_allocation(int size) {
    int* arr = new int[size];
    return arr;
}

void read(int* arr, int size) {
    std::cout << "Введите " << size << " чисел: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

void print(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void free_memory(int* arr) {
    delete[] arr;
}

int find_position(int* arr, int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i + 1;
        }
    }
    return -1;
}


bool is_sorted(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int count_peaks(int* arr, int size) {
    int count = 0;
    for (int i = 1; i < size - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            count++;
        }
    }
    return count;
}

int main() {
    const int n = 5;


    std::cout << "task 1:\n";
    int* arr1 = memory_allocation(n);
    read(arr1, n);
    print(arr1, n);

    int x;
    std::cout << "Введите X: ";
    std::cin >> x;

    int pos = find_position(arr1, n, x);
    if (pos == -1) {
        std::cout << "Not found\n";
    }
    else {
        std::cout << "Позиция: " << pos << "\n";
    }
    free_memory(arr1);


    std::cout << "\ntask 2:\n";
    int* arr2 = memory_allocation(n);
    read(arr2, n);
    print(arr2, n);

    if (is_sorted(arr2, n)) {
        std::cout << "Массив отсортирован по неубыванию\n";
    }
    else {
        std::cout << "Массив НЕ отсортирован\n";
    }
    free_memory(arr2);


    std::cout << "\ntask 3:\n";
    int* arr3 = memory_allocation(n);
    read(arr3, n);
    print(arr3, n);

    std::cout << "Количество элементов больше соседей: "
        << count_peaks(arr3, n) << "\n";
    free_memory(arr3);

    return 0;
}