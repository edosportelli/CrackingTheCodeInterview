/* You are given a square grid with some cells open (.) and some blocked (X).
Your playing piece can move along any row or column until it reaches the edge
of the grid or a blocked cell. Given a grid, a start and a goal, determine the
minmum number of moves to get to the goal. */

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> grid{".X.", ".X.", "..."};

std::pair<int, int> start;
std::pair<int, int> end;

// first = row
// second = col

void print_grid(std::vector<std::string>& s)
{
    for (auto item : s)
    {
        for (auto el : item)
            std::cout << el << " ";

        std::cout << std::endl;
    }
}

// start_i -> fin_i
// start_j -> fin_j

int calculate_min_steps(std::vector<std::string>& s, int start_i, int start_j, int fin_i, int fin_j)
{
    if (start_i != fin_i)
    {
        
    }

}

int main()
{
    print_grid(grid);

    start.first = 0;
    start.second = 0;
    end.first = 0;
    end.second = 2;
}