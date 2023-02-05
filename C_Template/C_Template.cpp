#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

template <typename T>
T FindMax(T arr[5])
{
    int max = arr[0];

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
T FindMin(T arr[5])
{
    int min = arr[0];

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

template <typename T>
T Sort(T (&arr)[5])
{
    int temp = 0;

    for (int i = 0; i < 5; i++) 
    {
        for (int j = (5 - 1); j >= (i + 1); j--) 
        {
            if (arr[j] < arr[j - 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}

template <typename T>
T BinarySearch(T arr[], T num, T first, T last)
{
    while (last > first)
    {
        int mid = (first + last) / 2;

        if (arr[mid] < num)
        {
            first = mid + 1;
        }
        else if (arr[mid] > num)
        {
            first = mid - 1;
        }
        else 
        {
            return mid;
        }
    }

    if (arr[first] == num)
    {
        return first;
    }
    else
    {
        return -1;
    }
}

template<typename T>
T Replace(T(&arr)[5], T old_value, T new_value)
{
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == old_value)
        {
            arr[i] = new_value;
        }
    }

    for (int i : arr)
    {
        cout << i << ' ';
    }
    return 0;
}

int main()
{
    srand(time(0));
    int arr[5];

    cout << "Ur array: ";

    for (int i = 0; i < 5; i++)
    {
        arr[i] = rand() % 10; 
        cout << arr[i] << ' ';
    }

    cout << "\nMax: " << FindMax(arr);
    cout << "\nMin: " << FindMin(arr);
    cout << "\nSort: ";
    Sort(arr);
    cout << "\nSearching element: 3";
    cout << "\nSearch element under index: " << BinarySearch(arr, 3, 0, 4);
    cout << "\nReplace array (3 -> 9): ";
    Replace(arr, 3, 9);
}
