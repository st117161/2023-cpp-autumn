#include <iostream>

int main()
{
    int n = 0;
    int s1 = 15;
    int s5 = 70;
    int s10 = 125;
    int s20 = 230;
    int s60 = 440;
    int b1 = 0;
    int b5 = 0;
    int b10 = 0;
    int b20 = 0;
    int b60 = 0;
    std::cin >> n;

    b60 = n / 60;
    b20 = (n - 60 * b60) / 20;
    b10 = (n - 60 * b60 - 20 * b20) / 10;
    b5 = (n - 60 * b60 - 20 * b20 - 10 * b10) / 5;
    b1 = (n - 60 * b60 - 20 * b20 - 10 * b10 - 5 * b5);

    if (b1 * s1 + b5 * s5 >= 125)
    {
        b1 = 0;
        b5 = 0;
        b10 += 1;
    }
    if (b1 * s1 + b5 * s5 + b10 * s10 >= 230)
    {
        b1 = 0;
        b5 = 0;
        b10 = 0;
        b20 += 1;
    }
    if (b1 * s1 + b5 * s5 + b10 * s10 + b20 * s20 >= 440)
    {
        b1 = 0;
        b5 = 0;
        b10 = 0;
        b20 = 0;
        b60 += 1;
    }

    std::cout << b1 << " " << b5 << " " << b10 << " " << b20 << " " << b60;
    return EXIT_SUCCESS;
}