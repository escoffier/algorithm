#ifndef _HEAP_H_
#define _HEAP_H_

template<class T>void exchange(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
};

template<class T> void maxheapify(T a[], int n, int k)
{
    int j = 0;
    while((2*(k+ 1) <= n))
    {
        j = 2*k + 1;
        if(j+1 <= n -1)
        {
            if(a[j+1]> a[j])
            {
                ++j;
            }
        }
        if(a[k] < a[j])
        {
            exchange(a[k], a[j]);
        }
        k = j;
    }   
};

template<class T> void buildheap(T a[], int size)
{
    for(int i = size/2 - 1; i >=0; --i)
    {
        maxheapify(a, size, i);
    }
};

template<class T> void heapsort(T a[], int size)
{
    while(size > 1)  
    {
	exchange(a[0], a[size -1]);
        maxheapify(a, --size, 0);
    }  
};
#endif
