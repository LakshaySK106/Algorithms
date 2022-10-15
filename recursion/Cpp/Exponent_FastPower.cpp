//M^n(M to the power n) in this method we use a better Recursive algorithm to find the power(Fast power method)
//Time Complexity: O(log n)
#include <stdio.h>
int power(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        if (n % 2 == 0)
        {
            return power(m * m, n / 2);
        }
        else
        {
            return power(m * m, n / 2) * m;
        }
    }
}
int main()
{
    // Write C code here
    printf("%d", power(2, 10));

    return 0;
}
