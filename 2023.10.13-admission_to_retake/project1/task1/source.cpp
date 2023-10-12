#include <iostream>

typedef unsigned int uint;

int main(int argc, char *argv[])
{
    const int BITS = sizeof(uint) * 8;

    uint n = 0;
    std::cin >> n;

    int sumbits = 0;
    for (int i = 0; i < BITS; ++i)
    {
        sumbits += (n >> i) & 1;
    }
    std::cout << sumbits << std::endl;

    return EXIT_SUCCESS;
}