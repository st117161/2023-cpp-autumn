#include <iostream>

int main()
{
    long int a = 0;
    long int b = 0;
    long int n = 0;
    long int ls = 0;
    long int bs = 0;
    std::cin >> a;
    std::cin >> b;
    std::cin >> n;

    //обозначим переменные для вместимостей
    if (a > b)
    {
        ls = b;
        bs = a;
    }
    else 
    {
        ls = a;
        bs = b;
    }
    
    std::cout << b << std::endl;
    return EXIT_SUCCESS;
}
