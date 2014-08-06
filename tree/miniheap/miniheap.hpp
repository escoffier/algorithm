#include <iostream>
#include <ostream>
#include <istream>

using namespace std;

static void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MiniHeap
{
public:
    MiniHeap();
    explicit MiniHeap(int len);
    ~MiniHeap();
    
    void Insert(int value);
    int PopUp();
    friend ostream & operator << (ostream & os, MiniHeap &heap);
    //friend istream & operator << (istream & is, MiniHeap &heap);
private:
    int length_;
    int totallen_;
    int* array_;
};

MiniHeap::MiniHeap()
{
    totallen_ = 1;
    length_ = 0;
    array_ = new int[1];
}

MiniHeap::~MiniHeap()
{
    length_ = 0;
    totallen_ = 0;
    delete [] array_;
}

MiniHeap::MiniHeap(int len)
{
    length_ = 0;
    totallen_ = len;
    array_ = new int[totallen_];
}

void MiniHeap::Insert(int value)
{
    if((++length_) > totallen_)
    {
        int *newarray = new int[totallen_ * 2];
        memcpy(newarray, array_, sizeof(int) * length_);
        delete [] array_;
        array_ = 0;
        array_ = newarray;
        totallen_ = totallen_ * 2;
    }
    
    int index = length_- 1;
    array_[index] = value;

    cout<<"length_ = "<<length_<<std::endl;
    while(index && array_[(index - 1)/2] > array_[index])
    {
        int temp = array_[(index - 1)/2];
        array_[(index - 1)/2] = array_[index];
        array_[index] = temp;
        index = (index - 1)/2;
    }
    cout<<"Insert"<<std::endl;
    cout<<*this;
}

ostream & operator << (ostream & os, MiniHeap &heap)
{  
    for(int i = 0; i < heap.length_; ++i)
    {
        os << heap.array_[i] << " "; 
    }
    os<<std::endl;
    return os;  
} 

int MiniHeap::PopUp()
{
    exchange(array_, array_+ (length_ - 1));
	length_--;
    int index = 0;
    while( (2*(index+1) -1) <= (length_ -1) )
    {
        int j = 2*(index + 1) -1;
        if((j < (length_ -1)) && array_[j] > array_[j+1])
        {
            ++j;
        }
        if(array_[index] > array_[j])
        {
            exchange(array_ + j, array_ + index);
            index = j;
        }
        else
        {
            break;
        }
    }
	cout<<*this;
    return array_[length_];
}
// istream & operator << (istream & is, MiniHeap &heap)
// {  
    // std::cout<<"请输入插入的值"<<std::endl;
    // int value;
    // is >> value; 
    // heap.Insert(value);
    // cout<<heap;
    // return is;  
// } 


