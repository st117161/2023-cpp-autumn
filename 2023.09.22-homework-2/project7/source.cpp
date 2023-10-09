#include <iostream>

int main(int argc, char *argv[])
{
    int x = 0;
    std::cin >> x;
    int x_10 = x / 10;
    int x_1 = x - x_10 * 10;

    switch (x_10)
    {
    case (0):
        break;
    case (1):
        std::cout << "X";
        break;
    case (2):
        std::cout << "XX";
        break;
    case (3):
        std::cout << "XXX";
        break;
    case (4):
        std::cout << "XL";
        break;
    case (5):
        std::cout << "L";
        break;
    case (6):
        std::cout << "LX";
        break;
    case (7):
        std::cout << "LXX";
        break;
    case (8):
        std::cout << "LXXX";
        break;
    case (9):
        std::cout << "XC";
        break;
    case (10):
        std::cout << "C";
        break;
    }

    switch (x_1)
    {
    case (0):
        break;
    case (1):
        std::cout << "I";
        break;
    case (2):
        std::cout << "II";
        break;
    case (3):
        std::cout << "III";
        break;
    case (4):
        std::cout << "IV";
        break;
    case (5):
        std::cout << "V";
        break;
    case (6):
        std::cout << "VI";
        break;
    case (7):
        std::cout << "VII";
        break;
    case (8):
        std::cout << "VIII";
        break;
    case (9):
        std::cout << "IX";
        break;
    }

    return EXIT_SUCCESS;
}