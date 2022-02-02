#include <iostream>
#include <stdlib.h>

#define N 16

class MergeSort
{
  public:
    MergeSort() {}

    void sort(int* v, int size)
    {
        copy = new int[size];
        v_ = v;

        sort(v, copy, 0, size - 1);
    }

    void print()
    {
        for (int i = 0; i < N; ++i)
        {
            std::cout << copy[i] << " ";
        }

        std::cout << std::endl;

        for (int i = 0; i < N; ++i)
        {
            std::cout << v_[i] << " ";
        }
    }

  private:
    int* copy;
    int* v_;

    void merge(int* v1, int* v2, int l, int r, int mid)
    {

        for (int i = l; i <= r; i++)
            v2[i] = v1[i];

        int i = l;
        int j = mid + 1;

        for (int k = l; k <= r; k++)
        {
            if (i > mid)
                v1[k] = v2[j++];
            else if (j > r)
                v1[k] = v2[i++];
            else if (v2[j] <= v2[i])
                v1[k] = v2[j++];
            else
                v1[k] = v2[i++];
        }
    }

    void sort(int* v1, int* v2, int l, int r)
    {
        if (r <= l)
            return;

        int mid = l + (r - l) / 2;
        sort(v1, v2, l, mid);
        sort(v1, v2, mid + 1, r);
        merge(v1, v2, l, r, mid);
    }
};

int main()
{
    MergeSort sort;

    int v[N];

    for (int i = 0; i < N; ++i)
    {
        v[i] = rand() % 10;
        std::cout << v[i] << " ";
    }

    std::cout << std::endl;

    sort.sort(&v[0], N);

    sort.print();
}