#include <iostream>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    int intermediate = 0;

    if ((a >= b) && (b >= c) && (a >= c))
    {
        std::cout << c << " " << b << " " << a;
    }

    else if ((a <= b) && (b >= c) && (a >= c))
    {
        std::cout << c << " " << a << " " << b;
    }

    else if ((a <= b) && (a <= c) && (b <= c))
    {
        std::cout << a << " " << b << " " << c;
    }

    else if ((a >= b) && (a >= c) && (b <= c))
    {
        std::cout << b << " " << c << " " << a;
    }

    else if ((a >= b) && (a <= c) && (b <= c))
    {
        std::cout << b << " " << a << " " << c;
    }

    else 
    {
        std::cout <<  a << " " << c << " " << b;
    }
    return EXIT_SUCCESS;
}
