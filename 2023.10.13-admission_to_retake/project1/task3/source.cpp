#include <iostream>

typedef unsigned int uint;

int main(int argc, char *argv[])
{
    const int BITS = sizeof(uint) * 8;

    uint a = 0;
    std::cin >> a;
    uint b = 0;
    std::cin >> b;
    uint sum = 0;
    bool up = 0;

    for (int i = 0; i < BITS; ++i)
    {
        bool bitA = ((a >> i) & 1);
        bool bitB = ((b >> i) & 1);
        bool current = bitA ^ bitB ^ up;
        up = (bitA & bitB) | (bitA & up) | (bitB & up);
        sum = sum | ((int)current << i);
    }
    std::cout << a << " + " << b << " = " << sum << std::endl;

    return EXIT_SUCCESS;
}