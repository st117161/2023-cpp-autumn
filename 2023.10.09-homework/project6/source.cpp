#include <iostream>
#include <cstdlib>

int main(int argc, char **)
{
    int element = 0;
    int n = 0;
    std::cin >> n;
    int *a = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> element;
        *(a + i) = element;
    }

    int max_element = -100000;
    int min_element = 100000;
    int max_ind = 0;
    int min_ind = 0;
    for (int i = 0; i < n; ++i)
    {
        if (max_element <= *(a + i))
        {
            max_element = *(a + i);
            max_ind = i;
        }
        if (min_element > *(a + i))
        {
            min_element = *(a + i);
            min_ind = i;
        }
    }

    int ind = 0;
    *(a + max_ind) = min_element;
    *(a + min_ind) = max_element;

    for (int i = 0; i < n; ++i)
    {
        std::cout << *(a + i) << " ";
    }
    std::cout << std::endl;
    free(a);
}
