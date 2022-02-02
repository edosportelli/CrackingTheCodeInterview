#include <iostream>

class QuickUnionUF
{
  public:
    QuickUnionUF(int N_) : N(N_)
    {
        elements = new int[N];
        id = new int[N];
        z = new int[N];

        for (int i = 0; i < N; ++i)
        {
            elements[i] = i;
            id[i] = i;
            z[i] = 1;
        }
    }

    void print()
    {
        for (int i = 0; i < N; ++i)
            std::cout << elements[i] << " ";

        std::cout << std::endl;

        for (int i = 0; i < N; ++i)
            std::cout << id[i] << " ";

        std::cout << std::endl;
    }

    int root(int i)
    {
        while(i != id[i])
            i = id[i];

        return i;
    }

    bool connected(int p, int q)
    {
        return (root(p) == root(q));
    }

    void add_union(int p, int q)
    {
        int i = root(p);
        int j = root(q);

        if (i == j) return;

        if (z[i] < z[j])
        {
            id[i] = j;
            z[j] += z[i];

            std::cout << z[j] << std::endl;
        }
        else
        {
            id[j] = i;
            z[i] += z[j];

            std::cout << z[i] << std::endl;
        }
    }

  private:
    int N;
    int* elements;
    int* id;
    int* z;
};

int main()
{
    QuickUnionUF q(10);
    q.print();
    std::cout << std::endl;

    q.add_union(4, 3);
    q.add_union(3, 8);
    q.add_union(6, 5);
    q.add_union(9, 4);
    q.add_union(2, 1);
    q.add_union(5, 0);
    q.add_union(7, 2);
    q.add_union(6, 1);
    q.add_union(7, 3);

    q.print();
}
