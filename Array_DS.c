// Array DS
# include <stdio.h>

int main()
{
    int n, temp=0;

    scanf("%d", &n);

    int arr[n];

    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    temp = n-1;
    for (int i=0; i<n; i++)
    {
        printf("%d ", arr[temp]);
        temp -= 1;
    }

    return 0;

}