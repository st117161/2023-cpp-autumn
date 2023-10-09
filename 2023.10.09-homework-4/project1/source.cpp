#include <iostream>
#include <cstdlib>

int main(int argc, char **)
{
    int count = 0;
    int element = 0;
    int n = 0;
    std::cin >> n;
    int *a = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> element;
        if (element > 0)
        {
            count += 1;
        }
        *(a + i) = element;
    }

    free(a);

    std::cout << count << std::endl;
}
