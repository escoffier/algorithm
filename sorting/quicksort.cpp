#include<iostream>
#include<stdlib.h>
#include<time.h>

const int size = 100;

void printarray(int *a, int size)
{
    for(int i = 0; i < size; ++i)
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
}

void exchange(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *a, int l, int r)
{
    int i = l - 1;
    int pivot = a[r];
    for(int j = l; j <= r - 1;  ++j)
    {
        if(a[j] <=  pivot)
        {
            exchange(a[j], a[++i]);

        }
    }
    exchange(a[r], a[++i]);
    return i;
}

void quicksort(int *array, int left, int right)
{
    printarray(array, size);
    if(left < right)
    {
        int q = partition(array, left, right);
        quicksort(array, left, q - 1);
        quicksort(array, q + 1, right);
    }
}

void initarray(int *a, int size)
{
    srand(time(NULL));
    for(int i = 0; i < size; ++i)
    {
        a[i] = rand();
    }
}

int main(int argc, char** argv)
{
    int a[size] = {2, 18, 7, 11, 31, 5, 6, 45, 14, 
                   30, 100, 0, 11, 88, 19 };

    initarray(a, size);
    quicksort(a, 0, size - 1);
    std::cout<<"The sorted array: "<<std::endl;
    printarray(a, size);
    return 0;
}
