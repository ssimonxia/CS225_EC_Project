#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>
#include "grid.h"

int main() {
    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> randint(0, 1);
    //int number =  randint(gen)

    /*
    * 0: road can pass
    * 1: barrier
    * 2: source
    * 3: destination
    */
    for(int k = 0; k < 5; k++) {
        for (int n = 5; n <= 50; n++) {
            for (int m = 5; m <= 50; m++) {

                // generate random grid with size n, m
                std::vector<std::vector<int>> grid;
                for (int i = 0; i < n; i++) {
                    std::vector<int> tmp;
                    for (int j = 0; j < m; j++) {
                        int number = randint(gen);
                        tmp.push_back(number);
                    }
                    grid.push_back(tmp);
                }

                //generate random source and destination
                std::random_device rdsx;  // a seed source for the random number engine
                std::mt19937 gensx(rdsx()); // mersenne_twister_engine seeded with rd()
                std::uniform_int_distribution<> randintsx(0, n-1);
                std::random_device rdsy;  // a seed source for the random number engine
                std::mt19937 gensy(rdsy()); // mersenne_twister_engine seeded with rd()
                std::uniform_int_distribution<> randintsy(0, m-1);
                int sourcex = randintsx(gensx);
                int sourcey = randintsy(gensy);
                grid[sourcex][sourcey] = 2;

                std::random_device rddx;  // a seed source for the random number engine
                std::mt19937 gendx(rddx()); // mersenne_twister_engine seeded with rd()
                std::uniform_int_distribution<> randintdx(0, n-1);
                std::random_device rddy;  // a seed source for the random number engine
                std::mt19937 gendy(rddy()); // mersenne_twister_engine seeded with rd()
                std::uniform_int_distribution<> randintdy(0, m-1);
                int destinationx = randintdx(gendx);
                int destinationy = randintdy(gendy);
                grid[destinationx][destinationy] = 3;

                int minDis = minDistance(grid, n, m);

                std::string filename="../TestData/Fail/test_grid_width"+ std::to_string(n) +"_height"+std::to_string(m)+"("+std::to_string(k)+")"".txt";
                if (minDis == -1) {
                    std::ofstream os(filename);
                    os<<n<<" "<<m<<" "<<minDis<<std::endl;
                    for(int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            os<<grid[i][j]<<" ";
                        }
                        os<<std::endl;
                    }
                    os.close();
                }
            }
        }
    }
    return 0;
}