#include <iostream>

int main()
{
    long int k = 0;
    long int res = 0;
    std::cin >> k;

    for (long int i = 1; i <= k; i++)
    {   
        if (i < 10)
        {
            res++;
            continue;
        }
        else if ((i >= 10) && (i < 100))
        {
            if (i / 10 == i % 10)
            {
                res++;
                continue;
            }
        }
        else if ((i >= 100) && (i < 1000))
        {
            if (i / 100 == i % 10)
            {
                res++;
                continue;
            }
        }
        else if ((i >= 1000) && (i < 10000))
        {
            if ((i / 1000 * 10 + i / 100 % 10) == (i % 10 * 10 + i / 10 % 10))
            {
                res++;
                continue;
            }
        }
        else
        {
            if ((i / 10000 * 10 + i / 1000 % 10) == (i % 10 * 10 + i / 10 % 10))
            {
                res++;
                continue;
            }
        }
    }
    std::cout << res;
    return EXIT_SUCCESS;
}