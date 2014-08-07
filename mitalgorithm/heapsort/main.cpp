#include <iostream>
#include"heap.h"

void printarray(int a[], int size)
{ 
    for(int i =0; i < size; ++i)
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;

}


int main(int argc, char** argv)
{
    int a[10] = {4,1,3,2,16,9,10,14,8,7};
    buildheap(a, sizeof(a)/sizeof(int));
    printarray(a, sizeof(a)/sizeof(int));
    heapsort(a, sizeof(a)/sizeof(int));
    printarray(a, sizeof(a)/sizeof(int));
    return 0;
}

