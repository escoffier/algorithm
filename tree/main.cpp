#include "iostream"
#include "list.h"

//5-1 阶乘函数
int factorial(int n )
{
    if(0 == n)
	{
	    return 1;
	}
	return n * factorial(n - 1);
}

//5-3 欧几里得算法
int gcd(int m, int n)
{
    if(n == 0)
	{
	    return m;
	}
	return gcd(n, m%n);
}

int max( int *a, int size )
{
    if(size == 1)
	{
	    return a[0];
	}
	int m = max(a + 1, size - 1 );
	int maxn = a[0] > m ? a[0] : m;
	std::cout<<maxn<<std::endl;
	return maxn;
}

int main( int argc, char **argv)
{
     std::cout<<gcd(100, 80)<<std::endl;
	 std::cout<<factorial(10)<<std::endl;
	 int a[] = {9, 6, 7, 2, 4, 8, 1, 3, 5, 19};
	 std::cout<<"max number is: "<<max(a, sizeof(a)/sizeof(int) )<<std::endl;
	 return 0;
}