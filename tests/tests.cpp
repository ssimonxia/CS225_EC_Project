#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "../src/Astar.h"

TEST_CASE("converttogrid_1", "[width = 5][height = 5]"){
    std::string file = "../data/Small(5-10)/test_grid_width5_height5(0).txt";
    std::vector<std::vector<int>> expected{{0, 0, 0, 0, 0},{3, 0, 0, 0, 0},{0, 0, 2, 1 ,1},{1, 0, 1, 1, 0},{1, 0, 1, 1, 0}};
    Astar astar;
    astar.converttogrid(file);
    REQUIRE(astar.grid.size() == 5);
    REQUIRE(astar.grid[0].size() == 5);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            REQUIRE(astar.grid[i][j] == expected[i][j]);
        }
    }
    REQUIRE(astar.grid[2][2] == 2);
    REQUIRE(astar.grid[1][0] == 3);
}

TEST_CASE("converttogrid_2", "[width = 6][height = 5]"){
    std::string file = "../data/Small(5-10)/test_grid_width6_height5(1).txt";
    std::vector<std::vector<int>> expected{{3, 0, 0, 1, 1},{1, 0, 1, 0, 0},{1, 2, 1, 1, 0},{0, 0, 0, 0, 1},{1, 1, 0, 0, 0}, {0, 1, 1, 1, 0}};
    Astar astar;
    astar.converttogrid(file);
    REQUIRE(astar.grid.size() == 6);
    REQUIRE(astar.grid[0].size() == 5);
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            REQUIRE(astar.grid[i][j] == expected[i][j]);
        }
    }
    REQUIRE(astar.grid[2][1] == 2);
    REQUIRE(astar.grid[0][0] == 3);
}
/*
TEST_CASE("aStar_Small") {
    for (int i = 0; i < 5; i++) {
        for(int j = 5; j <= 10; j++) {
            for(int k = 5; k <= 10; k++) {
                std::string file = "../data/Small(5-10)/test_grid_width"+std::to_string(j)+"_height"+std::to_string(k)+"("+std::to_string(i)+").txt";
                std::ifstream f(file);
                if (!f.is_open()){
                    continue;
                } else {
                    Astar astar;
                    astar.converttogrid(file);
                    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
                        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
                    };
                    std::vector<std::pair<int, int>> actual = astar.aStar(astar.start, astar.end, astar.grid, h);
                    std::vector<std::pair<int, int>> bfs = astar.BFS(astar.start, astar.end, astar.grid);
                    std::cout<<file<<": "<<astar.bestDis+1<<std::endl;
                    REQUIRE(int(actual.size()) == int(bfs.size()));
                }
            }
        }
    }
}

TEST_CASE("aStar_Medium") {
    for (int i = 0; i < 3; i++) {
        for(int j = 10; j <= 50; j+=5) {
            for(int k = 10; k <= 50; k+=5) {
                std::string file = "../data/Medium(10-50)/test_grid_width"+std::to_string(j)+"_height"+std::to_string(k)+"("+std::to_string(i)+").txt";
                std::ifstream f(file);
                if (!f.is_open()){
                    continue;
                } else {
                    Astar astar;
                    astar.converttogrid(file);
                    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
                        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
                    };
                    std::vector<std::pair<int, int>> actual = astar.aStar(astar.start, astar.end, astar.grid, h);
                    std::cout<<file<<": "<<astar.bestDis+1<<std::endl;
                    REQUIRE(int(actual.size()) == (astar.bestDis + 1));
                }
            }
        }
    }
}

TEST_CASE("aStar_Large") {
    for(int i = 0; i < 5; i++){
        for(int j = 50; j <= 200; j+=10) {
            for(int k = 50; k <= 200; k+=10) {
                std::string file = "../data/Large(50-200)/test_grid_width"+std::to_string(j)+"_height"+std::to_string(k)+"("+std::to_string(i)+").txt";
                std::ifstream f(file);
                if (!f.is_open()){
                    continue;
                } else {
                    Astar astar;
                    astar.converttogrid(file);
                    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
                        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
                    };
                    std::vector<std::pair<int, int>> actual = astar.aStar(astar.start, astar.end, astar.grid, h);
                    std::cout<<file<<": "<<astar.bestDis+1<<std::endl;
                    REQUIRE(int(actual.size()) == (astar.bestDis + 1));
                }
            }
        }
        }
    
}

TEST_CASE("aStar_Super") {
    for(int i = 0; i < 1; i++){
        for(int j = 200; j <= 2000; j+=100) {
            for(int k = 200; k <= 2000; k+=100) {
                std::string file = "../data/Super(200-2000)/test_grid_width"+std::to_string(j)+"_height"+std::to_string(k)+"("+std::to_string(i)+").txt";
                std::ifstream f(file);
                if (!f.is_open()){
                    continue;
                } else {
                    Astar astar;
                    astar.converttogrid(file);
                    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
                        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
                    };
                    std::vector<std::pair<int, int>> actual = astar.aStar(astar.start, astar.end, astar.grid, h);
                    std::cout<<file<<": "<<astar.bestDis+1<<std::endl;
                    REQUIRE(int(actual.size()) == (astar.bestDis + 1));
                }
            }
        }
        }

    
}

TEST_CASE("aStar_Extreme") {
    for(int i = 0; i < 5; i++){
        for(int j = 2000; j <= 20000; j+=2000) {
            for(int k = 2000; k <= 20000; k+=2000) {
                std::string file = "../data/Extreme(2000+)/test_grid_width"+std::to_string(j)+"_height"+std::to_string(k)+"("+std::to_string(i)+").txt";
                std::ifstream f(file);
                if (!f.is_open()){
                    continue;
                } else {
                    Astar astar;
                    astar.converttogrid(file);
                    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
                        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
                    };
                    std::vector<std::pair<int, int>> actual = astar.aStar(astar.start, astar.end, astar.grid, h);
                    std::cout<<file<<": "<<astar.bestDis+1<<std::endl;
                    REQUIRE(int(actual.size()) == (astar.bestDis + 1));
                }
            }
        }
        }

    
}

*/

TEST_CASE("aStarSearch_Small") {
    for (int i = 0; i < 5; i++) {
        for(int j = 5; j <= 10; j++) {
            for(int k = 5; k <= 10; k++) {
                std::string file = "../data/Small(5-10)/test_grid_width"+std::to_string(j)+"_height"+std::to_string(k)+"("+std::to_string(i)+").txt";
                std::ifstream f(file);
                if (!f.is_open()){
                    continue;
                } else {
                    Astar astar;
                    astar.converttogrid(file);
                    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
                        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
                    };
                    std::vector<std::pair<int, int>> actual = astar.aStarSearch(astar.grid ,astar.start, astar.end, h);
                    std::cout<<file<<": "<<astar.bestDis+1<<std::endl;
                    std::vector<std::pair<int, int>> bfs = astar.BFS(astar.start, astar.end, astar.grid);
                    REQUIRE(int(actual.size()) == int(bfs.size()));
                }
            }
        }
    }
}

TEST_CASE("aStarSearch_Medium") {
    for (int i = 0; i < 3; i++) {
        for(int j = 10; j <= 50; j+=5) {
            for(int k = 10; k <= 50; k+=5) {
                std::string file = "../data/Medium(10-50)/test_grid_width"+std::to_string(j)+"_height"+std::to_string(k)+"("+std::to_string(i)+").txt";
                std::ifstream f(file);
                if (!f.is_open()){
                    continue;
                } else {
                    Astar astar;
                    astar.converttogrid(file);
                    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
                        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
                    };
                    std::vector<std::pair<int, int>> actual = astar.aStarSearch(astar.grid, astar.start, astar.end, h);
                    std::vector<std::pair<int, int>> bfs = astar.BFS(astar.start, astar.end, astar.grid);
                    std::cout<<file<<": "<<astar.bestDis+1<<std::endl;
                    REQUIRE(int(actual.size()) == int(bfs.size()));
                    //REQUIRE(int(actual.size()) == (astar.bestDis + 1));
                }
            }
        }
    }
}

TEST_CASE("aStarSearch_Large") {
    for (int i = 0; i < 5; i++) {
        for(int j = 50; j <= 200; j+=10) {
            for(int k = 50; k <= 200; k+=10) {
                std::string file = "../data/Large(50-200)/test_grid_width"+std::to_string(j)+"_height"+std::to_string(k)+"("+std::to_string(i)+").txt";
                std::ifstream f(file);
                if (!f.is_open()){
                    continue;
                } else {
                    Astar astar;
                    astar.converttogrid(file);
                    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
                        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
                    };
                    std::vector<std::pair<int, int>> actual = astar.aStarSearch(astar.grid, astar.start, astar.end, h);
                    std::vector<std::pair<int, int>> bfs = astar.BFS(astar.start, astar.end, astar.grid);
                    std::cout<<file<<": "<<astar.bestDis+1<<std::endl;
                    REQUIRE(int(actual.size()) == int(bfs.size()));
                    //REQUIRE(int(actual.size()) == (astar.bestDis + 1));
                }
            }
        }
    }
}

TEST_CASE("aStarSearch_Super") {
    for (int i = 0; i < 1; i++) {
        for(int j = 200; j <= 2000; j+=100) {
            for(int k = 200; k <= 2000; k+=100) {
                std::string file = "../data/Super(200-2000)/test_grid_width"+std::to_string(j)+"_height"+std::to_string(k)+"("+std::to_string(i)+").txt";
                std::ifstream f(file);
                if (!f.is_open()){
                    continue;
                } else {
                    Astar astar;
                    astar.converttogrid(file);
                    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
                        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
                    };
                    std::vector<std::pair<int, int>> actual = astar.aStarSearch(astar.grid, astar.start, astar.end, h);
                    std::vector<std::pair<int, int>> bfs = astar.BFS(astar.start, astar.end, astar.grid);
                    std::cout<<file<<": "<<astar.bestDis+1<<std::endl;
                    REQUIRE(int(actual.size()) == int(bfs.size()));
                    //REQUIRE(int(actual.size()) == (astar.bestDis + 1));
                }
            }
        }
    }
}

TEST_CASE("aStarSearch_Extreme") {
    for (int i = 0; i < 1; i++) {
        for(int j = 2000; j <= 20000; j+=2000) {
            for(int k = 2000; k <= 20000; k+=2000) {
                std::string file = "../data/Extreme(2000+)/test_grid_width"+std::to_string(j)+"_height"+std::to_string(k)+"("+std::to_string(i)+").txt";
                std::ifstream f(file);
                if (!f.is_open()){
                    continue;
                } else {
                    Astar astar;
                    astar.converttogrid(file);
                    auto h = [](std::pair<int,int> curr, std::pair<int,int> destination) -> double {
                        return std::sqrt(std::pow(destination.first - curr.first, 2) + std::pow(destination.second - curr.second, 2));
                    };
                    std::vector<std::pair<int, int>> actual = astar.aStarSearch(astar.grid, astar.start, astar.end, h);
                    std::vector<std::pair<int, int>> bfs = astar.BFS(astar.start, astar.end, astar.grid);
                    std::cout<<file<<": "<<astar.bestDis+1<<std::endl;
                    REQUIRE(int(actual.size()) == int(bfs.size()));
                    //REQUIRE(int(actual.size()) == (astar.bestDis + 1));
                }
            }
        }
    }
}




/*
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
*/