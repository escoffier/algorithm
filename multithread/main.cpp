#include "iostream"

int  add(int a , int b)
{
    return __sync_fetch_and_add(&a, b); 
}

int main( int argc, char **argv)
{
    int a = 10;
	int b = 1;
    std::cout<<__sync_fetch_and_add(&a, b)<<std::endl;
	std::cout<<a<<std::endl;
	 return 0;
}