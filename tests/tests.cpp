#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "../src/Astar.h"

TEST_CASE("converttogrid_1", "[width = 5][height = 5]"){
    std::string file = "../data/Small(5-10)/test_grid_width5_height5(1).txt";
    std::vector<std::vector<int>> expected{{1, 1, 1, 1, 1},{1, 1, 0, 0, 0},{1, 1, 3, 1 ,0},{1, 1, 0, 1, 2},{0, 0, 1, 1, 1}};
    Astar astar;
    astar.converttogrid(file);
    REQUIRE(astar.grid.size() == 5);
    REQUIRE(astar.grid[0].size() == 5);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            REQUIRE(astar.grid[i][j] == expected[i][j]);
        }
    }
    REQUIRE(astar.grid[3][4] == 2);
    REQUIRE(astar.grid[2][2] == 3);
}

TEST_CASE("converttogrid_2", "[width = 6][height = 5]"){
    std::string file = "../data/Small(5-10)/test_grid_width6_height5(1).txt";
    std::vector<std::vector<int>> expected{{0, 1, 0, 1, 0},{0, 1, 0, 1, 3},{0, 1, 0, 1, 0},{0, 1, 1, 1, 0},{1, 0, 1, 2, 1}, {1, 0, 1, 1, 0}};
    Astar astar;
    astar.converttogrid(file);
    REQUIRE(astar.grid.size() == 6);
    REQUIRE(astar.grid[0].size() == 5);
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            REQUIRE(astar.grid[i][j] == expected[i][j]);
        }
    }
    REQUIRE(astar.grid[4][3] == 2);
    REQUIRE(astar.grid[1][4] == 3);
}

TEST_CASE("aStar_1") {
    std::string file = "../data/Small(5-10)/test_grid_width5_height5(4).txt";
    Astar astar;
    astar.converttogrid(file);
    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
    };
    std::vector<std::pair<int, int>> actual = astar.aStar(astar.start, astar.end, astar.grid, h);
    REQUIRE(actual.size()==2);
    REQUIRE(actual[0].first == 1);
    REQUIRE(actual[0].second == 3);
    REQUIRE(actual[1].first == 0);
    REQUIRE(actual[1].second == 3);
}

TEST_CASE("aStar_2") {
    std::string file = "../data/Small(5-10)/test_grid_width6_height5(1).txt";
    Astar astar;
    astar.converttogrid(file);
    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
    };
    std::vector<std::pair<int, int>> actual = astar.aStar(astar.start, astar.end, astar.grid, h);
    REQUIRE(actual.size()==4);
    REQUIRE(actual[0].first == 4);
    REQUIRE(actual[0].second == 3);
    REQUIRE(actual[1].first == 3);
    REQUIRE(actual[1].second == 4);
    REQUIRE(actual[2].first == 2);
    REQUIRE(actual[2].second == 4);
    REQUIRE(actual[3].first == 1);
    REQUIRE(actual[3].second == 4);
}

TEST_CASE("aStar_3") {
    std::string file = "../data/Small(5-10)/test_grid_width10_height9(3).txt";
    Astar astar;
    astar.converttogrid(file);
    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
    };
    cout<<"check: "<<astar.start.first<<" "<<astar.start.second<<endl;
    std::vector<std::pair<int, int>> actual = astar.aStar(astar.start, astar.end, astar.grid, h);
    REQUIRE(actual.size()==5);
    REQUIRE(actual[0].first == 1);
    REQUIRE(actual[0].second == 5);
    REQUIRE(actual[1].first == 1);
    REQUIRE(actual[1].second == 4);
    REQUIRE(actual[2].first == 1);
    REQUIRE(actual[2].second == 3);
    REQUIRE(actual[3].first == 2);
    REQUIRE(actual[3].second == 2);
    REQUIRE(actual[4].first == 3);
    REQUIRE(actual[4].second == 1);
}

TEST_CASE("aStar_4") {
    std::string file = "../data/Medium(10-50)/test_grid_width15_height35(0).txt";
    Astar astar;
    astar.converttogrid(file);
    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
    };
    std::vector<std::pair<int, int>> actual = astar.aStar(astar.start, astar.end, astar.grid, h);
    REQUIRE(actual.size() <= 1.25*28);
}


TEST_CASE("aStar_5") {
    std::string file = "../data/Medium(10-50)/test_grid_width10_height45(2).txt";
    Astar astar;
    astar.converttogrid(file);
    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
    };
    std::vector<std::pair<int, int>> actual = astar.aStar(astar.start, astar.end, astar.grid, h);
    REQUIRE(actual.size() <= 1.25*5);
}

TEST_CASE("aStar_6") {
    std::string file = "../data/Medium(10-50)/test_grid_width25_height30(1).txt";
    Astar astar;
    astar.converttogrid(file);
    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
    };
    std::vector<std::pair<int, int>> actual = astar.aStar(astar.start, astar.end, astar.grid, h);
    REQUIRE(actual.size() <= 1.25*18);
}

TEST_CASE("aStar_7") {
    std::string file = "../data/Large(50-200)/test_grid_width120_height30(0).txt";
    Astar astar;
    astar.converttogrid(file);
    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
    };
    std::vector<std::pair<int, int>> actual = astar.aStar(astar.start, astar.end, astar.grid, h);
    REQUIRE(actual.size() <= 1.25*35);
}

TEST_CASE("getNeighbor_1") {
    std::string file = "../data/Small(5-10)/test_grid_width5_height5(2).txt";
    std::vector<std::vector<int>> expected{{2, 1, 0, 0, 0},{1, 0, 1, 1, 1},{1, 0, 3, 1, 1},{0, 1, 1, 0, 0},{1, 1, 0, 0, 0}};
    Astar astar;
    astar.converttogrid(file);
    std::pair<int, int> curr(3,4);
    std::vector<std::pair<int, int>> actual = astar.getNeighbor(curr, astar.grid);
    REQUIRE(actual.size() == 3);
    REQUIRE(actual[0].first == 3);
    REQUIRE(actual[0].second == 3);
    REQUIRE(actual[1].first == 4);
    REQUIRE(actual[1].second == 4);
    REQUIRE(actual[2].first == 4);
    REQUIRE(actual[2].second == 3);
}

TEST_CASE("getNeighbor_2") {
    std::string file = "../data/Small(5-10)/test_grid_width6_height5(3).txt";
    std::vector<std::vector<int>> expected{{0, 0, 0, 0, 0},{0, 0, 0, 0, 1},{0, 1, 3, 0, 0},{1, 1, 0, 0, 1},{1, 0, 1, 0, 0},{2, 0, 0, 1, 0}};
    Astar astar;
    astar.converttogrid(file);
    std::pair<int, int> curr(3,2);
    std::vector<std::pair<int, int>> actual = astar.getNeighbor(curr, astar.grid);
    REQUIRE(actual.size() == 5);
    REQUIRE(actual[0].first == 2);
    REQUIRE(actual[0].second == 2);
    REQUIRE(actual[1].first == 3);
    REQUIRE(actual[1].second == 3);
    REQUIRE(actual[2].first == 2);
    REQUIRE(actual[2].second == 3);
    REQUIRE(actual[3].first == 4);
    REQUIRE(actual[3].second == 1);
    REQUIRE(actual[4].first == 4);
    REQUIRE(actual[4].second == 3);
}