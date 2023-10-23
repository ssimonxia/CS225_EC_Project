#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

TEST_CASE("converttogrid_1", "[width = 5][height = 5]"){
    std::string file = "test_grid_width5_height5(0).txt";
    std::vector<std::vector<int>> expected{{0, 0, 1, 3, 0},{0, 1, 0, 1, 0},{1, 0, 1, 0 ,0},{1, 0, 0, 0, 0},{0, 1, 1, 0, 2}};
    AStart astar;
    astar.converttogrid(file);
    REQUIRE(astar.grid.size() == 5);
    REQUIRE(astar.grid[0].size() == 5);
    int flag = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if (astar.grid[i][j] != expected[i][j]){
                flag = 1;
            }
        }
    }
    REQUIRE(flag == 0);
}

TEST_CASE("converttogrid_2", "[width = 6][height = 5]"){
    std::string file = "test_grid_width6_height5(1).txt";
    std::vector<std::vector<int>> expected{{0, 1, 0, 1, 0},{1, 0, 0, 1, 1},{0, 1, 0, 0 ,1},{1, 1, 1, 0, 1},{1, 0, 3, 2, 0},{0, 0, 0, 0, 0}};
    AStart astar;
    astar.converttogrid(file);
    REQUIRE(astar.grid.size() == 6);
    REQUIRE(astar.grid[0].size() == 5);
    int flag = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            if (astar.grid[i][j] != expected[i][j]){
                flag = 1;
            }
        }
    }
    REQUIRE(flag == 0);
}

TEST_CASE("aStar_1") {
    std::string file = "test_grid_width5_height5(0).txt";
    std::vector<std::vector<int>> expected{{0, 1, 0, 1, 0},{1, 0, 0, 1, 1},{0, 1, 0, 0 ,1},{1, 1, 1, 0, 1},{1, 0, 3, 2, 0},{0, 0, 0, 0, 0}};
    AStart astar;
    astar.converttogrid(file);
    double h = [](std::pair<int,int> curr, std::pair<int,int> destination){
        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
    }
    std::vector<std::pair<int, int>> actual = aStar(astar.start, astar.goal, astar.grid, h);
    REQUIRE(actual.size()==5);
    REQUIRE(actual[0].first == 4 && actual[0].second == 4);
    REQUIRE(actual[1].first == 3 && actual[1].second == 4);
    REQUIRE(actual[2].first == 2 && actual[2].second == 4);
    REQUIRE(actual[3].first == 1 && actual[3].second == 4);
    REQUIRE(actual[4].first == 0 && actual[4].second == 3);
}

TEST_CASE("aStar_2") {
    std::string file = "test_grid_width6_height5(1).txt";
    std::vector<std::vector<int>> expected{{0, 0, 1, 3, 0},{0, 1, 0, 1, 0},{1, 0, 1, 0 ,0},{1, 0, 0, 0, 0},{0, 1, 1, 0, 2}};
    AStart astar;
    astar.converttogrid(file);
    double h = [](std::pair<int,int> curr, std::pair<int,int> destination){
        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
    }
    std::vector<std::pair<int, int>> actual = aStar(astar.start, astar.goal, astar.grid, h);
    REQUIRE(actual.size()==2);
    REQUIRE(actual[0].first == 4 && actual[0].second == 3);
    REQUIRE(actual[1].first == 4 && actual[1].second == 2);
    
}

TEST_CASE("aStar_3") {
    std::string file = "test_grid_width150_height170(0).txt";
    AStart astar;
    astar.converttogrid(file);
    double h = [](std::pair<int,int> curr, std::pair<int,int> destination){
        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
    }
    std::vector<std::pair<int, int>> actual = aStar(astar.start, astar.goal, astar.grid, h);
    REQUIRE(actual.size() <= 1.25*173);
    REQUIRE(actual[0].first == 134 && actual[0].second == 8);
    REQUIRE(actual.back().first == 91 && actual.back().second == 157);
}

TEST_CASE("getNeighbor_1") {
    std::string file = "test_grid_width5_height5(0).txt";
    std::vector<std::vector<int>> expected{{0, 0, 1, 3, 0},{0, 1, 0, 1, 0},{1, 0, 1, 0 ,0},{1, 0, 0, 0, 0},{0, 1, 1, 0, 2}};
    AStart astar;
    astar.converttogrid(file);
    std::pair<int, int> curr(3,4);
    std::vector<std::pair<int, int>> actual = getNeighbor(curr, astar.grid);
    REQUIRE(actual.size() == 4);
    REQUIRE(actual[0].first == 3 && actual[0].second == 3);
    REQUIRE(actual[1].first == 2 && actual[1].second == 4);
    REQUIRE(actual[2].first == 2 && actual[2].second == 3);
    REQUIRE(actual[3].first == 4 && actual[3].second == 3);
}

TEST_CASE("getNeighbor_2") {
    std::string file = "test_grid_width6_height5(1).txt";
    std::vector<std::vector<int>> expected{{0, 1, 0, 1, 0},{1, 0, 0, 1, 1},{0, 1, 0, 0 ,1},{1, 1, 1, 0, 1},{1, 0, 3, 2, 0},{0, 0, 0, 0, 0}};
    AStart astar;
    astar.converttogrid(file);
    std::pair<int, int> curr(3,2);
    std::vector<std::pair<int, int>> actual = getNeighbor(curr, astar.grid);
    REQUIRE(actual.size() == 5);
    REQUIRE(actual[0].first == 3 && actual[0].second == 1);
    REQUIRE(actual[1].first == 2 && actual[1].second == 2);
    REQUIRE(actual[2].first == 3 && actual[2].second == 3);
    REQUIRE(actual[3].first == 4 && actual[3].second == 3);
    REQUIRE(actual[4].first == 4 && actual[0].second == 1);
    
}
