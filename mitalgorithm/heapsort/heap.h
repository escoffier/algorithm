#ifndef _HEAP_H_
#define _HEAP_H_
namespace qqf
{
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



//heap_extract_max
template<class T> void heappop(T a[], int& size)
{
    if(size < 1)
    {
        std::cout<<"no date to pop "<<std::endl;
        return;
    }
    else if( 1== size)
    {
        size = 0;
    }

    exchange(a[0], a[size -1]);
    maxheapify(a, size -1);
}

//HEAP_INCREASE_KEY
template<class T> void heapshiftup(T a[], int size, int n, int key)
{
    if(size < 1 || n < 1 )
    {
        std::cout<<"size is 0"<<std::endl;
        return;
    }
    a[n] = key;
    while( n > 0)
    {
        if(a[n] <= a[(n+1)/2 -1])
        {
            break;
        }
        exchange(a[n], a[(n+1)/2 -1]);
        n = (n+1)/2 -1;
    }
}

template<class T> void heapinsert(T a[], int &size, int key)
{
    if(0 == size)
    {
        a[0] = key;
    }
    ++size;
    a[size] = key;
    heapshiftup(a, size, size - 1, key);
}

template<class T> class priority_queue
{
public:
    priority_queue();
    ~priority_queue();

    void pop();
    void push(const T &value);
    const T& top() const;
    size_t size() const;
    bool empty() const;
private:
    T * buf_;
    unsigned int size_;
    unsigned int length_;
};

template<class T> priority_queue<T>::priority_queue()
{
    length_ = 8;
    buf_ = new T[length_];
    size_ = 0;
}

template<class T> priority_queue<T>::~priority_queue()
{
    delete [] buf_;
    buf_ = 0;
    length_ = 0;
    size_ = 0;
}

template<class T> void priority_queue<T>::pop()
{
    if(size_ < 1)
    {
        std::cout<<"no date to pop "<<std::endl;
        return;
    }
    else if( 1== size_)
    {
        size_ = 0;
    }

    exchange(buf_[0], buf_[size_ -1]);
    maxheapify(buf_, size_ -1);
}

template<class T> void priority_queue<T>::push(const T &value)
{
    if(0 == size_)
    {
        buf_[0] = value;
    }
    ++size_;
    buf_[size_] = value;
    heapshiftup(buf_, size_, size_ - 1, value);
}

template<class T> const T& priority_queue<T>::top() const
{
    return buf_[0];
}

template<class T> size_t priority_queue<T>::size() const
{
    return size_;
}

template<class T> bool priority_queue<T>::empty() const
{
    return ((!size_) ? false:true);
}

}
#endif
