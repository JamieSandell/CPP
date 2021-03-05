#include <iostream>

using namespace std;
int * apply_all(const int array1[], int array1_size, const int array2[], int array2_size);
void print(const int array[], int array_size);

int main() {
    int array1[] {1, 2, 3, 4, 5};
    int array2[] {10, 20, 30};
    int *result = apply_all(array1, 5, array2, 3);
    print(result, 15);
    
    return 0;
}

int * apply_all(const int array1[], int array1_size, const int array2[], int array2_size) {
    int *result = new int[array1_size * array2_size]{};
    int result_index {0};
    
    if (array1_size < array2_size) {
        for (int array1_index {0}; array1_index < array1_size; ++array1_index) {
            for (int array2_index {0}; array2_index < array2_size; ++array2_index) {
                result[result_index] = array1[array1_index] * array2[array2_index];
                ++result_index;
            }
        }
    }
    else {
        for (int array2_index {0}; array2_index < array2_size; ++array2_index) {
            for (int array1_index {0}; array1_index < array1_size; ++array1_index) {
                result[result_index] = array1[array1_index] * array2[array2_index];
                ++result_index;
            }
        }
    }
    
    
    
    return result;
}

void print(const int array[], int array_size) {
    cout << "[ ";
    for (int array_index{0}; array_index < array_size; ++array_index) {
        cout << array[array_index] << " ";
    }
    cout << "]" << endl;
}