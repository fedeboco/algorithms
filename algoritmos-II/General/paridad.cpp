#include <iostream>
using namespace std;

int main()
{
    int x[] = {1,2,3,4,5,6,7,8,9,10,11};
    int aux = 0;
    for(int i = 0; i <= 10; i++)
    {
        aux = x[i] & (0x01);
        cout << aux << endl;
    }
}