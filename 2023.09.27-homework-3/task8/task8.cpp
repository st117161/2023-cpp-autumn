#include <iostream>

int main()
{
    int a = 0;
    int b = 0;
    int n = 0;
    int s1 = 0;
    int s2 = 0;
    int i = 0;

    std::cin >> a;
    std::cin >> b;
    std::cin >> n;

    int a_nod = a;
    int b_nod = b;
    int nod = 0;

    while ((a_nod != 0) && (b_nod != 0))
    {
        if (a_nod > b_nod)
        {
            a_nod = a_nod % b_nod;
        }
        else
        {
            b_nod = b_nod % a_nod;
        }
    }
    nod = a_nod + b_nod;
    // std::cout << nod << " " << a << " " << b << " " << std::endl;

    if (((n > a) && (n > b)) || (n % nod != 0))
    {   
        std::cout << "Impossible" << std::endl;
    }
    else if (b > a)
    {
        while ((s1 != n) && (s2 != n) && (i < 100000))
        {
            i++;
            s1 += a;
            std::cout << ">A" << std::endl;
            s2 += s1;
            s1 = 0;
            std::cout << "A>B" << std::endl;
            if (s2 >= b)
            {
                s1 += s2 - b;
                s2 = b;
                if ((s1 == n) || (s2 == n)) 
                {
                    break;
                }
                s2 = 0;
                std::cout << "B<" << std::endl;
            }
        
        }
    }
    else 
    {
        while ((s1 != n) && (s2 != n) && (i < 100000))
        {   
            i++;
            s1 += b;
            std::cout << ">B" << std::endl;
            s2 += s1;
            s1 = 0;
            std::cout << "B>A" << std::endl;
            if (s2 >= a)
            {
                s1 += s2 - a;
                s2 = a;
                if ((s1 == n) || (s2 == n)) 
                {
                    break;
                }
                s2 = 0;
                std::cout << "A<" << std::endl;
            }  
        }
    }
    // std::cout << i;
    return EXIT_SUCCESS;
}