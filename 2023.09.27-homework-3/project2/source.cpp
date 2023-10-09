#include <iostream>

int main(int argc, char *argv[])
{
    long int num = 0;
    long int res = 0;
    std::cin >> num;
    while (num != 0)
    {
        res += num % 10;
        res = res * 10;
        num = num / 10;
    }
    std::cout << res / 10;
    return EXIT_SUCCESS;
}