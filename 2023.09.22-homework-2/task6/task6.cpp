#include <iostream>

int main()
{
    int k = 0;
    int m = 0;
    int n = 0;
    int time = 0;
    std::cin >> k;
    std::cin >> m;
    std::cin >> n;

    if (k >= n)
    {
        time = 2 * m;
    }
    else 
    {
        time = (2 * n / k) * m;
        if ((n % k != 0) && (n % k != k / 2))
        {
            time += m;
        }
    }
    
    std::cout << time;
    return EXIT_SUCCESS;
}