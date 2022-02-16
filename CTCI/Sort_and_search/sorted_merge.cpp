#include <iostream>

#define N 10
#define M 8

void sort(int* v1, int* v2, int size1, int size2)
{
    int i = size1 - 1;
    int j = size2 - 1;

    for (int k = size1 + size2 - 1; k >= 0; k--)
    {
        if (j == 0)
            return;
        else if (i == 0)
            v1[k] = v2[j--];
        else if (v1[i] >= v2[j])
            v1[k] = v1[i--];
        else
            v1[k] = v1[j--];
    }
}

int main()
{
    int v1[N + M];
    int v2[M];

    for (int i = 0; i < N; i++)
        v1[i] = i;

    for (int i = 0; i < M; i++)
        v2[i] = i;

    for (int i = 0; i < M + N; i++)
    {
        std::cout << v1[i] << " " << v2[i] << std::endl;
    }

    std::cout << std::endl;

    sort(&v1[0], &v2[0], N, M);

    for (int i = 0; i < M + N; i++)
    {
        std::cout << v1[i] << " " << v2[i] << std::endl;
    }
}
