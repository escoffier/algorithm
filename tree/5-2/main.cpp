#include <iostream>

template<class T> T max( T a[], int l, int r )
{
    std::cout<<"l = "<<l<<"  r = "<<r<<std::endl;
    if(l == r)
	{
	    return a[l];
	}
	int mid = (l + r)/2;
	
	int lmax = max(a, l, mid);
	int rmax = max(a, mid + 1, r);
	return lmax > rmax ? lmax : rmax;
}

void hanoi(int N, int d)
{
    if(N == 0)
	{
	    return;
	}
	hanoi( N- 1, -d );
	std::cout<<"shift: "<<N<<" : "<<d<<std::endl;
	hanoi( N- 1, -d );
	
	return;
}

int F(int i)
{
    if(i < 1) 
	{
	    return 0;
	}
	
	if(i == 1)
	{
	    return 1;
	}
	
	return F(i - 1) + F(i - 2);
}

int main(int arc, char **argv)
{
    int a[] = {9, 6, 7, 2, 4, 8, 1, 3, 5, 19};
	std::cout<<max(a, 0, sizeof(a)/sizeof(int) - 1)<<std::endl;
	hanoi(5, 1);
	
	std::cout<<F(45)<<std::endl;
}