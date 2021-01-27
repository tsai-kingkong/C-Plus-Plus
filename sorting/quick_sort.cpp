/**
 * @file
 * @brief Quick sort algorithm
 *
 * Implementation Details -
 *      Quick Sort is a divide and conquer algorithm. It picks and element as
 *      pivot and partition the given array around the picked pivot. There
 *      are many different versions of quickSort that pick pivot in different
 *      ways.
 *
 *      1. Always pick the first element as pivot
 *      2. Always pick the last element as pivot (implemented below)
 *      3. Pick a random element as pivot
 *      4. Pick median as pivot
 *
 *      The key process in quickSort is partition(). Target of partition is,
 *      given an array and an element x(say) of array as pivot, put x at it's
 *      correct position in sorted array and put all smaller elements (samller
 *      than x) before x, and put all greater elements (greater than x) after
 *      x. All this should be done in linear time
 *
 */

#include <cstdlib>
#include <iostream>


// prints the array after sorting
void show(int arr[], int size) {
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}
void show(int arr[], int low, int high) {
    for (; low<=high ; low++) std::cout<< arr[low] << " ";
    std::cout << "\n";
}

namespace sorting {
/**
 *      This function takes last element as pivot, places
 *      the pivot element at its correct position in sorted
 *      array, and places all smaller (smaller than pivot)
 *      to left of pivot and all greater elements to right
 *      of pivot
 *
 */

int partition2(int arr[], int low, int high) {
    int pivot = arr[high];  // taking the last element as pivot
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            i++;  // increment index of smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

int partition3(int arr[], int l, int r){
    int pivot = arr[l];
    int i = l;
    for(int j=l+1; j<=r;j++){
        if(arr[j] < pivot){
            int temp = arr[j];
            arr[j] = arr[++i];
            arr[i] = temp;
        }
    }
    arr[l] = arr[i];
    arr[i] = pivot; 
    return i;
}

int partition_(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<high; j++){
        if(arr[j]>pivot){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    arr[high] = arr[++i];
    arr[i] = pivot;
    return i;
    

}

int partition(int arr[], int low, int high){
    printf("low=%d, high=%d\n", low, high);
    int pivot = arr[high];
    int i = low, j = high-1;
    while(i<=j){ //=的情況發生在只有兩個元素, ex:3 2
        while(i < high && arr[i] <= pivot) i++;
        while(j >= low && arr[j] > pivot) j--; //j>=low , arr[j] <= pivot
        if(i<j){
            printf("swap %d,%d\n",i,j);
            std::swap(arr[i], arr[j]);
        }
    }
    printf("j=%d\n",j);
    std::swap(arr[j+1], arr[high]);
    return j+1;
}


/**
 *      The main function that implements QuickSort
 *      arr[] --> Array to be sorted,
 *      low --> Starting index,
 *      high --> Ending index
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        show(arr, low, high);
        printf("partition done\n");
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void quickSort2(int arr[], int low, int high){
    std::cout<<"quickSort2"<<std::endl;
    show(arr, low, high);
    if(low >= high)
        return ;
    int pivot = arr[low];
    int i = low+1, j = high;
    while(i <= j){
        while(i<high && arr[i] <= pivot) i++;
        while(j>low && arr[j] > pivot) j--;
        if (i < j){
            std::swap(arr[i], arr[j]);
        }
    }
    if(j != low){
        std::swap(arr[low], arr[j]);
    }
    show(arr, low, high);
    quickSort2(arr, low, j-1);
    quickSort2(arr, j+1, high);

}

}  // namespace sorting
using sorting::quickSort;
using sorting::quickSort2;


/** Driver program to test above functions */
int main() {
    int size;
    std::cout << "\nEnter the number of elements : ";

    std::cin >> size;

    int *arr = new int[size];

    std::cout << "\nEnter the unsorted elements : ";

    for (int i = 0; i < size; ++i) {
        std::cout << "\n";
        std::cin >> arr[i];
    }
    std::cout << "Sorted array\n";
    show(arr, size);
    quickSort(arr, 0, size-1);
    std::cout << "Sorted array\n";
    show(arr, size);
    delete[] arr;
    return 0;
}
