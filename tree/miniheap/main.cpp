#include <iostream>
#include "miniheap.hpp"

int min_heap_reserve(int* heap, int size)
{
return 0;
}

int min_heap_shift_up(int* heap, int value)
{
return 0;

}

int main(int argc, char** argv)
{
    MiniHeap heap;
    std::string value;
    while(1)
    {
        cin>>value;
        if(value == "pop")
        {
            std::cout<<"pop: "<<heap.PopUp()<<std::endl;
        }
        else if(value == "q" || value == "quit")
        {
            break;
        }
        else
        {
            heap.Insert(atoi(value.c_str()));
        }
    }
    return 0;
}