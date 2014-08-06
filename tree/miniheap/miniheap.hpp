#include <iostream>
#include <ostream>
#include <istream>

using namespace std;

class MiniHeap
{
public:
    MiniHeap();
	explicit MiniHeap(int len);
	~MiniHeap();
	
	void Insert(int value);
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
	
    int parent = (length_ - 1)/2;
	int index = length_;
	array_[length_ - 1] = value;
	cout<<"length_ = "<<length_<<std::endl;
	while(parent && array_[parent] > value)
	{
	    int temp = array_[parent];
		array_[parent] = value;
		array_[index] = temp;
		index = parent;
		parent = (parent - 1)/2;
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

// istream & operator << (istream & is, MiniHeap &heap)
// {  
    // std::cout<<"请输入插入的值"<<std::endl;
	// int value;
	// is >> value; 
    // heap.Insert(value);
	// cout<<heap;
	// return is;  
// } 


