#include <iostream>

#define A

#ifdef A
void sort(int arr[], int n) {
    bool unsorted = true;
    int times = 1;
    while (unsorted) {
        unsorted = false;
        for (int i = 0; i < n - times; ++i) {
            if (arr[i] > arr[i + 1]) {
                auto tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                unsorted = true;
            }
        }
        ++times;
    }
}

int main() {
    int n;
    std::cin >> n;
    auto arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    sort(arr, n);
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
#endif

#ifdef B
void sort(int arr[], int n) {
    bool unsorted = true;
    int times = 1;
    while (unsorted) {
        unsorted = false;
        for (int i = 0; i < n - times; ++i) {
            if (arr[i] > arr[i + 1]) {
                auto tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                unsorted = true;
            }
        }
        ++times;
    }
}
void sort(double arr[], int n) {
    bool unsorted = true;
    int times = 1;
    while (unsorted) {
        unsorted = false;
        for (int i = 0; i < n - times; ++i) {
            if (arr[i] > arr[i + 1]) {
                auto tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                unsorted = true;
            }
        }
        ++times;
    }
}

int main() {
    int n, choice;
    std::cin >> n;
    std::cout << "enter 0 for array of integers, 1 for array of real numbers\n";
    std::cin >> choice;

    int *arr0; double *arr1;

    if (choice) {
        arr1 = new double[n];
        for (int i = 0; i < n; ++i) {
            std::cin >> arr1[i];
        }
        sort(arr1, n);
        for (int i = 0; i < n; ++i) {
            std::cout << arr1[i] << " ";
        }
    } else {
        arr0 = new int[n];
        for (int i = 0; i < n; ++i) {
            std::cin >> arr0[i];
        }
        sort(arr0, n);
        for (int i = 0; i < n; ++i) {
            std::cout << arr0[i] << " ";
        }
    }
    std::cout << "\n";
}
#endif

#ifdef C
template <typename T>
void sort(T arr[], int n) {
    bool unsorted = true;
    int times = 1;
    while (unsorted) {
        unsorted = false;
        for (int i = 0; i < n - times; ++i) {
            if (arr[i] > arr[i + 1]) {
                auto tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                unsorted = true;
            }
        }
        ++times;
    }
}
bool isLetter(char c) {
    return 'A' <= c and c <= 'Z' or 'a' <= c and c <= 'z';
}
template <>
void sort<char>(char arr[], int n) {
    for (int i = 0; i < n; ++i) {
        if (!isLetter(arr[i]))
            arr[i] = ' ';
    }

    for (int k = n; k > 1; --k) {
        int max_i = 0;
        for (int i = 0; i < k; ++i) {
            if(arr[i] == ' ' or arr[max_i] != ' ' and tolower(arr[i]) >= tolower(arr[max_i])) {
                max_i = i;
            }
        }
        auto tmp = arr[k - 1];
        arr[k - 1] = arr[max_i];
        arr[max_i] = tmp;
    }
}
template <typename T>
void input(T* &arr, int n) {
    arr = new T[n];
    std::cin.clear();
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
}

template <typename T>
void print(T*arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

template <typename T>
void isp(T* &arr, int n) {
    input(arr, n);
    sort(arr, n);
    print(arr, n);
}

int main() {
    int n, choice;
    std::cin >> n;
    std::cout << "enter 0 for array of integers, 1 for array of real numbers, 2 for chars\n";
    std::cin >> choice;
    int *arr_int = nullptr;
    double *arr_double = nullptr;
    char *arr_char = nullptr;
    switch (choice) {
        case 0:
            isp(arr_int, n);
            break;
        case 1:
            isp(arr_double, n);
            break;
        case 2:
            isp(arr_char, n);
            break;
        default:
            std::cout << "no such type\n";
            break;
    }
}
#endif