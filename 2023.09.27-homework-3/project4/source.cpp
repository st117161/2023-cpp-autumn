#include <iostream>

int main(int argc, char *argv[])
{
    long int a = 0;
    long int b = 0;
    long int c = 0;
    long int d = 0;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;

    for (int x = 0; x <= 1000; x++)
    {
        if ((a * x * x * x + b * x * x + c * x + d) == 0)
        {
            std::cout << x << " ";
        }
    }
    return EXIT_SUCCESS;
}
