#define N 5

#include <iostream>
#include <random>
#include <vector>

struct Point
{
    int x;
    int y;
};

float calc_dist_origin(const Point& p1)
{
    Point origin{0, 0};
    return sqrt(pow(p1.x - origin.x, 2) + pow(p1.y - origin.y, 2));
}

void swap(Point& p1, Point& p2)
{
    Point temp;

    temp.x = p1.x;
    temp.y = p1.y;

    p1.x = p2.x;
    p1.y = p2.y;

    p2.x = temp.x;
    p2.y = temp.y;
}

int parition(std::vector<Point>& v, int l, int r)
{
    int p_i = l;
    Point p = v[p_i];

    l += 1;

    while (r >= l)
    {
        while (calc_dist_origin(v[l]) < calc_dist_origin(p) && l <= r)
            l++;

        while (calc_dist_origin(v[r]) > calc_dist_origin(p) && r >= l)
            r--;

        if (r >= l)
        {
            swap(v[l], v[r]);
            l++;
            r--;
        }
    }

    swap(v[p_i], v[r]);

    return r;
}

Point find_k_close_to_origin(std::vector<Point>& v, int l, int r, int k)
{
    int p = parition(v, l, r);

    if (p == k)
        return v[k];
    else if (p < k)
        find_k_close_to_origin(v, p + 1, r, k);
    else
        find_k_close_to_origin(v, l, p - 1, k);
}

int main()
{
    std::vector<Point> v;

    for (int i = 0; i < N; i++)
    {
        Point p = {rand() % 10, rand() % 10};
        v.push_back(p);
    }

    for (auto item : v)
        std::cout << item.x << " " << item.y << " " << calc_dist_origin(item) << std::endl;

    Point res = find_k_close_to_origin(v, 0, v.size() - 1, 0);

    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << res.x << " " << res.y << std::endl;
}