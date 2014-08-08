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
    qqf::buildheap(a, sizeof(a)/sizeof(int));
    printarray(a, sizeof(a)/sizeof(int));
    qqf::heapsort(a, sizeof(a)/sizeof(int));
    printarray(a, sizeof(a)/sizeof(int));

    int b[] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};
    qqf::buildheap(b, sizeof(b)/sizeof(int));
    printarray(b, sizeof(b)/sizeof(int));
    
    qqf::priority_queue<int> que;
    return 0;
}

