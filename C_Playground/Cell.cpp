#include <cstdio>

int main()
{
    int a[2][2][2];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                a[i][j][k] = i * 100 + j * 10 + k;

    for (int i = 0; i < 8; i++)
        printf("%d ", ((int*)a)[i]);

    printf("\n");
}
