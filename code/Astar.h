#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <functional>
#include <queue>
#include <fstream>
using namespace std;


class Astar {
    public:
        void converttogrid(std::string infile);
        template <typename Heuristic>
        vector<pair<int, int>> aStar(pair<int, int> start, pair<int, int> target, vector<vector<int>> grid, Heuristic h);

        vector<pair<int, int>> getNeighbor(pair<int, int> curr, vector<vector<int>> grid);
        vector<vector<int>> grid;
        int height;
        int width;
        pair<int, int> start;
        pair<int, int> end;
        vector<pair<int, int>> sol; 
        int bestDis;
};

#include "Astar.hpp"
