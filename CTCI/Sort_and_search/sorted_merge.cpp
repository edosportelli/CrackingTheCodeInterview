#include <iostream>

#define N 10
#define M 8

class SortedMerge
{
  public:
    SortedMerge() {}

    void sort(int* v1, int* v2, int size1, int size2)
    {
        int* aux = new int[size1 + size2];

        merge(v1, v2, size1, size2, aux);
        // sort(v1, aux, 0, size - 1);
    }

  private:
    void merge(int* v1, int* v2, int size1, int size2, int* aux)
    {
        for (int i = 0; i < size1; i++)
        {
            aux[i] = v1[i];
        }

        for (int i = 0; i < size2; i++)
        {
            aux[i + size1] = v2[i];
        }

        int i = 0;
        int j = size1;

        for (int k = 0; k < size1 + size2; k++)
        {
            if (i >= size1)
                v1[k] = aux[j++];
            else if (j >= size1 + size2)
                v1[k] = aux[i++];
            else if (aux[i] < aux[j])
                v1[k] = aux[i++];
            else
                v1[k] = aux[j++];
        }
    }

};



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

    // SortedMerge sort;
    // sort.sort(&v1[0], &v2[0], N, M);

    sort(&v1[0], &v2[0], N, M);

    for (int i = 0; i < M + N; i++)
    {
        std::cout << v1[i] << " " << v2[i] << std::endl;
    }
}
