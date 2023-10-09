#include <iostream>

int main(int argc, char *argv[])
{
    long int n = 0;
    long int ans = 0;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i * i >= n)
        {
            if (i * i == n)
                ans++;
            break;
        }
        if (n % i == 0)
        {
            ans += 2;
        }
    }

    std::cout << ans;

    return EXIT_SUCCESS;
}