#include <iostream>
#include <cstdlib>

int main(int argc, char **)
{
    int element = 0;
    int count = 0;
    int n = 0;
    std::cin >> n;
    int *a = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> element;
        if (element >= 0)
        {
            count += 1;
        }
        *(a + i) = element;
    }

    int *b = (int *)malloc(sizeof(int) * count);

    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (*(a + i) >= 0)
        {
            *(b + j) = *(a + i);
            ++j;
        }
    }
    free(a);

    for (int j = 0; j < count; ++j)
    {
        std::cout << *(b + j) << " ";
    }
    std::cout << std::endl;
    free(b);
}
