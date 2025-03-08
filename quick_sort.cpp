#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// first i will right the half part of quick sort which is to write Partition function
int partition(vector<int> &arr, int st, int end)
{ // basically this partition function returns the index of pivot in an array
    int idx = st - 1;
    int pivot = arr[end];
    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}
void quicksort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int piv = partition(arr, st, end);
        quicksort(arr, st, piv - 1);
        quicksort(arr, piv + 1, end);
    }
}
int main()
{
    vector<int> arr = {5, 2, 6, 4, 1, 3};
    int n = arr.size();
    quicksort(arr, 0, n - 1);
    cout << "Below is the sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    return 0;
}