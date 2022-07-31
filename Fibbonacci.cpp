#include <bits/stdc++.h>

int fibonnacci(int n)
{
    if (n == 0) return 0;
    
    if (n == 1) return 1;

    return fibonnacci(n - 1) + fibonnacci(n - 2);
}

int main()
{
    std::cout << fibonnacci(4) << std::endl;
    std::cout << fibonnacci(10) << std::endl;
    return 0;
}