#include <iostream>

int main(int argc, char *argv[])
{
    int n = 0;
    std::cin >> n;
    std::cout << n * 100 + 90 + 9 - n;
    return EXIT_SUCCESS;
}