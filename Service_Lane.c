#include <stdio.h>

int minimum(int a, int b)
{
    return a > b ? b : a;
}

int main()
{
    int N, T;
    scanf("%d %d", &N, &T);

    int width[N];

    for (int i=0; i<N; i++)
    {
        scanf("%d", &width[i]);
    }

    for (int i=0; i<T; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);

        int result = width[l];
        while (l <= r)
        {
            result = minimum(result, width[l]);
            l++;
        }
        printf("%d\n", result);
    }    
    return 0;
}