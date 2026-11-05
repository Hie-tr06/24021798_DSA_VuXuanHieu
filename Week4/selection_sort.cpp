//4th
#include <iostream>
#include <algorithm> //swap
using namespace std;

void selection_sort(int a[], int n)
{
    for (int j = 0; j < n - 1; j++) 
    {
        int min_index = j;
        
        for (int i = j + 1; i < n; i++) 
        {
            if (a[i] < a[min_index])
                min_index = i;
        }
        
        if (min_index != j)
            swap(a[min_index], a[j]);
    }
}

int main()
{
    int a[5] = {7, -5, -10, 99, 5};
    int n = 5;

    selection_sort(a, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}