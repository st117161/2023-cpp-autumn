#include <iostream>

int main()
{
    long int n = 0;
    long int k = 0;
    long int i = 1;
    std::cin >> n;

    while(i < n)
    {
        i = i * 2;
        k++;
    }
    
    std::cout << k << std::endl;
    return EXIT_SUCCESS;
}