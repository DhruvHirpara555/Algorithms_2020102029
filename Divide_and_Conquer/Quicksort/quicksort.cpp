
#include<bits/stdc++.h>
#include<iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


class quick_sort
{
private:
    int n;
    int *A;
public:
    quick_sort(int k, int* B){
        n = k;
        A = B;
    };
    void swap(int* a, int* b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    };
    int* quicksort(int arr[], int low ,int high,int flag_random);
    int Rand_partition(int arr[], int low, int high);
    int helper(int arr[], int low, int high);
};

// this will partition the array into two parts such that all elements less than the pivot are to the left of the pivot and all elements greater than the pivot are to the right of the pivot.



int quick_sort::helper(int arr[], int low, int high){
    int pivot = arr[high]; // pivot
    int i = low; // Index of smaller element
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than pivot wap current element with index i and do i++
        if (arr[j] < pivot)
        {

            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}
int quick_sort::Rand_partition(int arr[],int low, int high){

    srand(time(NULL));
    int rand_pivot = low + rand() % (high - low); //random pivot
    swap(&arr[rand_pivot], &arr[high]); //  swap pivot with last element

    return helper(arr, low, high); // return the index of the pivot by calling helper function

}

int* quick_sort::quicksort(int arr[],int low, int high, int flag_random)
{
    if (low < high)
    {
        int pi;
        if (flag_random == 1)
        {
            pi = Rand_partition(arr, low, high); // random pivot
        }
        else
        {
            pi = helper(arr, low, high); //last element as pivot
        }
        quicksort(arr, low, pi - 1, flag_random); // sort left subarray
        quicksort(arr, pi + 1, high, flag_random); // sort right subarray
    }

    return arr;

}

int main(){
    int flag;
    cout << "Do you want randdom?";
    cin >> flag;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort q(n, arr);
    q.quicksort(arr, 0, n - 1, flag);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}