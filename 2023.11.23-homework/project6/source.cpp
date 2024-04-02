#include <iostream>

void hanoi(int count, int from = 1, int to = 3)
{
    if (count <= 0)
    {
        return;
    }

    int res = 6 - from - to;

    if (count == 1)
    {
        printf("1 %d %d\n", from, to);
    }
    else
    {
        hanoi(count - 1, from, to);
        hanoi(count - 2, to, res);
        printf("0 %d %d\n", from, to);
        hanoi(count - 2, res, from);
        hanoi(count - 1, from, to);
    }
}

int main(int argc, char *argv[])
{
    int n = 0;
    std::cin >> n;
    hanoi(n);

    return EXIT_SUCCESS;
}