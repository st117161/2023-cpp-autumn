#include <iostream>

int main(int argc, char *argv[])
{
    int n = 0;
    std::cin >> n;

    if (n >= 0)
    {
        for (int i = 0; n - i >= 0; ++i)
        {
            std::cout << n - i << " ";
        }
    }
    else
    {
        for (int i = 0; n + i <= 0; ++i)
        {
            std::cout << n + i << " ";
        }
    }

    return EXIT_SUCCESS;
}
