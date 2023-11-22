#include <iostream>

void hanoi(int n, int from, int to)
{
    if (n <= 0)
    {
        return;
    }

    int res = 6 - from - to;
    if (n % 2 == 0)
    { // пока не получается осилить
    }
    else
    {
    }
}

int main(int argc, char *argv[])
{
    int n = 0;
    std::cin >> n;
    hanoi(n, 1, 3);

    return EXIT_SUCCESS;
}