///lab 12
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

template <class T>
T amax (T arr[] ,int size ,int n)
{
    sort(arr, arr+size, greater <T> ());
    return arr[n-1];
}
int main()
{
    int arr[10]  = {10, 70, 88, 17, 29 ,4, 8 ,6 ,12,5,};
    cout << "The value of the 5th largest element of the array: "  << amax(arr, 10, 5) << endl;
}
