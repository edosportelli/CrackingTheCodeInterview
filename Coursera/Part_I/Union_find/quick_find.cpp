#include <iostream>

/*
    - Find is quick o(1)
    - Union is slow o(n2), one for loop for init the id
    and one to run add_union
*/

class QuickFindUF
{
  public:
    QuickFindUF(int N_) : N(N_)
    {
        elements = new int[N];
        id = new int[N];

        for (int i = 0; i < N; ++i)
        {
            elements[i] = i;
            id[i] = i;
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

    bool is_connected(int p, int q) const { return id[p] == id[q]; }

    /* Set id of q in p */
    void add_union(int p, int q)
    {
        int pid = id[p]; // Direclty use id[p] can be a problem
        int qid = id[q];

        for (int i = 0; i < N; ++i)
        {
            if (id[i] == pid)
            {
                id[i] = qid;
            }
        }
    }

    int* elements;
    int* id;
    int N;
};

int main()
{
    QuickFindUF q(20);
    q.print();
    std::cout << std::endl;

    q.add_union(10, 2);
    // q.add_union(7, 2);
    // q.add_union(1, 17);
    // q.add_union(17, 5);
    // q.add_union(10, 5);

    q.print();
}