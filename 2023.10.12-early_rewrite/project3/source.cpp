#include <iostream>

int main(int argc, char *argv[])
{
    int n = 0;
    int ans = 1;
    std::cin >> n;

    while (n > 0)
    {
        ans = ans * (n % 10);
        n = n / 10;
    }
    std::cout << ans;

    return EXIT_SUCCESS;
}
