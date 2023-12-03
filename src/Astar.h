#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <functional>
#include <queue>
#include <fstream>
using namespace std;

struct cell {
    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
};

class Astar {
    public:
        void converttogrid(std::string infile);
        template <typename Heuristic>
        vector<pair<int, int>> aStar(pair<int, int> start, pair<int, int> target, vector<vector<int>> grid, Heuristic h);
        vector<pair<int, int>> getNeighbor(pair<int, int> curr, vector<vector<int>> grid);
        vector<pair<int, int>> BFS(pair<int, int> start, pair<int, int> target, vector<vector<int>> grid);
        template <typename Heuristic>
        vector<pair<int, int>> aStarSearch(vector<vector<int>> grid, pair<int, int> start, pair<int, int> target, Heuristic h);
        vector<vector<int>> grid;
        int height;
        int width;
        pair<int, int> start;
        pair<int, int> end;
        vector<pair<int, int>> sol; 
        int bestDis = 0;
};

#include "Astar.hpp"
