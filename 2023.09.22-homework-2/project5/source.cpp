#include <iostream>

int main(int argc, char *argv[])
{
    int n = 0;
    int ost100 = 0;
    std::cin >> n;
    ost100 = n % 100;

    if ((ost100 <= 10) || (ost100 >= 20))
    {
        if ((n % 10 == 0) || (n % 10 >= 5))
        {
            std::cout << n << " bochek";
        }
        else if (n % 10 == 1)
        {
            std::cout << n << " bochka";
        }
        else
        {
            std::cout << n << " bochki";
        }
    }
    else
    {
        std::cout << n << " bochek";
    }
    return EXIT_SUCCESS;
}