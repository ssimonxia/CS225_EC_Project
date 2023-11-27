#include <iostream>
#include <vector>
#include <string>
#include "../src/Astar.h"
using namespace std;
int main() {
    string s = "../data/Small(5-10)/test_grid_width10_height9(3).txt";
    Astar a;
    a.converttogrid(s);
    std::cout<<"width: "<<a.width<<" "<<"height: "<<a.height<<std::endl;
    std::cout<<"start: "<<a.start.first<<" "<<a.start.second<<std::endl;
    std::cout<<"end: "<<a.end.first<<" "<<a.end.second<<std::endl;
    for(int i = 0; i < a.height; i++) {
        for(int j = 0; j < a.width; j++) {
            std::cout<<a.grid[j][i]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"start: "<<a.grid[a.start.first][a.start.second]<<std::endl; // "2"
    std::cout<<"end: "<<a.grid[a.end.first][a.end.second]<<std::endl; // "3"
    return 0;
}