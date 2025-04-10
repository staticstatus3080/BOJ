#include <stdio.h>

int main()
{
    int n, sum;
    while (1)
    {
        sum = 0;
        scanf("%d", &n);
        if (n == -1)
            break;
        for (int i=1; i<n; i++)
        {
            if (n % i == 0)
                sum += i;
        }
        if (sum == n)
        {
            printf("%d = ", n);
            for (int i=1; i<n; i++)
            {
                 if (n % i == 0)
                 {
                     if (i == 1)
                         printf("1 ");
                     else
                         printf("+ %d ", i);
                 }
            }
        }
        else
            printf("%d is NOT perfect.", n);
        printf("\n");
    }
    return 0;
}