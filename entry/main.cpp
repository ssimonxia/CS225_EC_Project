#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <chrono>
#include "../src/Astar.h"
using namespace std;
int main() {
    string s = "../data/Super/test_grid_width1500_height2000(0).txt";
    Astar a;
    auto start{std::chrono::steady_clock::now()};
    auto end{std::chrono::steady_clock::now()};
    a.converttogrid(s);
    std::cout<<"width: "<<a.width<<" "<<"height: "<<a.height<<std::endl;
    std::cout<<"start: "<<a.start.first<<" "<<a.start.second<<std::endl;
    std::cout<<"end: "<<a.end.first<<" "<<a.end.second<<std::endl;
    /*for(int i = 0; i < a.height; i++) {
        for(int j = 0; j < a.width; j++) {
            std::cout<<a.grid[j][i]<<" ";
        }
        std::cout<<std::endl;
    }*/
    std::cout<<"start: "<<a.grid[a.start.first][a.start.second]<<std::endl; // "2"
    std::cout<<"end: "<<a.grid[a.end.first][a.end.second]<<std::endl; // "3"
    std::cout<<"best distance: "<<a.bestDis<<std::endl;
    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
    };
    start = std::chrono::steady_clock::now();
    std::vector<std::pair<int, int>> actual = a.aStar(a.start, a.end, a.grid, h);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> astar_second{end - start};

    std::cout<<"path: "<<actual.size()<<std::endl;
    /*for(unsigned i = 0; i < actual.size(); i++) {
        std::cout<<actual[i].first<<" "<<actual[i].second<<std::endl;
    }*/
    
    start = std::chrono::steady_clock::now();
    std::vector<std::pair<int, int>> bfs = a.BFS(a.start, a.end, a.grid);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> bfs_second{end - start};

    std::cout<<"bfs: "<<bfs.size()<<std::endl;
    /*for(unsigned i = 0; i < bfs.size(); i++) {
        std::cout<<bfs[i].first<<" "<<bfs[i].second<<std::endl;
    }*/

    start = std::chrono::steady_clock::now();
    std::vector<std::pair<int, int>> a2 = a.aStarSearch(a.grid, a.start, a.end, h);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> a2_second{end - start};

    std::cout<<"a2: "<<a2.size()<<std::endl;
    /*for(unsigned i = 0; i < a2.size(); i++) {
        std::cout<<a2[i].first<<" "<<a2[i].second<<std::endl;
    }*/

    std::cout<<"astar sec: "<<astar_second.count()<<std::endl;
    std::cout<<"bfs sec: "<<bfs_second.count()<<std::endl;
    std::cout<<"a2 sec: "<<a2_second.count()<<std::endl;
    return 0;
}