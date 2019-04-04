#include <iostream>

int sum_of_squares1(int n)
{
    if(!n)
        return 0;
    return n * n + sum_of_squares1(n-1);
}


int main()
{
    std::cout << sum_of_squares1(3) << std::endl;
}