
namespace qunfeng
{
template<class T> struct link
{
    link(): date(), link(NULL) {}
    T date;
	link* next;
};

template<class T> class List
{
public:
    List() {};
	~List() {};
	void push_back( T );
private:
   link<T> * node;	
   unsigned int size_;
};

template<class T> void List<T>::push_back(T val)
{
    if(0 == size_)
	{
	    node = new link<T>;
		node->data = val;
		node.next = NULL;
	}
	else
	{
	    node->next = new link<T>;
		node->next.data = val;
		node->next->next = NULL;
		
	}
	size_++;
}

}