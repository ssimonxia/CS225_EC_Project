#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

struct cell {
    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
};
 
double h(pair<int, int> curr,  pair<int, int> target){
    return ((double)sqrt((curr.first - target.first) * (curr.first - target.first)
        + (curr.second - target.second) * (curr.second - target.second)));
}
 
void tracePath(vector<vector<cell>> cellDetails, pair<int, int> target){
    printf("\nThe Path is ");
    int x = target.first;
    int y = target.second;
 
    stack<pair<int, int>> Path;
    int countt = 0;
    while (!(cellDetails[x][y].parent_i == x && cellDetails[x][y].parent_j == y)) {
        Path.push(make_pair(x, y));
        int tmpx = x;
        int tmpy = y;
        x = cellDetails[tmpx][tmpy].parent_i;
        y = cellDetails[tmpx][tmpy].parent_j;
        countt++;
    }
    countt++;
    Path.push(make_pair(x, y));
    while (!Path.empty()) {
        pair<int, int> p = Path.top();
        Path.pop();
        printf("-> (%d,%d) ", p.first, p.second);
    }
    cout<<endl;
    cout<<countt<<endl;
}
 
void aStarSearch(vector<vector<int>> grid, pair<int, int> start, pair<int, int> target)
{
    int height = grid[0].size();
    int width = grid.size();
    cout<<height<<" "<<width<<endl;
    vector<bool> tmp(height, false);
    vector<vector<bool>> closedList(width, tmp);

    vector<cell> tmpc(height);
    vector<vector<cell>> cellDetails(width, tmpc);
    
    int i,j;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }
    i = start.first, j = start.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;
 
    set<pair<double, pair<int, int>>> openList;

    openList.insert(make_pair(0.0, make_pair(i, j)));
 
    bool foundDest = false;
    int c=0;
    while (!openList.empty()) {
        pair<double, pair<int, int>> p = *openList.begin();
        openList.erase(openList.begin());
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;
        double gNew, hNew, fNew;
        //cout<<i<<" "<<j<<endl;
        c+=8;
        cout<<c<<endl;
        //left
        if (i-1>=0 && j>=0 && i-1<width && j<height) {
            if ((i-1) == target.first && j == target.second) {
                cellDetails[i - 1][j].parent_i = i;
                cellDetails[i - 1][j].parent_j = j;
                tracePath(cellDetails, target);
                foundDest = true;
                return;
            } else if (closedList[i - 1][j] == false && grid[i-1][j] == 0) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = h(make_pair(i-1, j), target);
                fNew = gNew + hNew;
 
                if (cellDetails[i - 1][j].f == FLT_MAX || cellDetails[i - 1][j].f > fNew) {
                    openList.insert(make_pair(fNew, make_pair(i - 1, j)));
                    cellDetails[i - 1][j].f = fNew;
                    cellDetails[i - 1][j].g = gNew;
                    cellDetails[i - 1][j].h = hNew;
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                }
            }
        }
        
        //up
        if (i>=0&&j-1>=0&&i<width&&j-1<height) {
            if (i == target.first && j-1 == target.second) {
                cellDetails[i][j - 1].parent_i = i;
                cellDetails[i][j - 1].parent_j = j;
                tracePath(cellDetails, target);
                foundDest = true;
                return;
            } else if (closedList[i][j - 1] == false && grid[i][j-1]==0) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = h(make_pair(i, j - 1), target);
                fNew = gNew + hNew;
                if (cellDetails[i][j - 1].f == FLT_MAX|| cellDetails[i][j - 1].f > fNew) {
                    openList.insert(make_pair(fNew, make_pair(i, j - 1)));
                    cellDetails[i][j - 1].f = fNew;
                    cellDetails[i][j - 1].g = gNew;
                    cellDetails[i][j - 1].h = hNew;
                    cellDetails[i][j - 1].parent_i = i;
                    cellDetails[i][j - 1].parent_j = j;
                }
            }
        }

        //right
        if (i+1>=0 && j>=0 && i+1<width && j<height) {
            if ((i+1) == target.first && j == target.second) {
                cellDetails[i + 1][j].parent_i = i;
                cellDetails[i + 1][j].parent_j = j;
                tracePath(cellDetails, target);
                foundDest = true;
                return;
            } else if (closedList[i + 1][j] == false && grid[i+1][j] == 0) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = h(make_pair(i + 1, j), target);
                fNew = gNew + hNew;
                if (cellDetails[i + 1][j].f == FLT_MAX || cellDetails[i + 1][j].f > fNew) {
                    openList.insert(make_pair(fNew, make_pair(i + 1, j)));
                    cellDetails[i + 1][j].f = fNew;
                    cellDetails[i + 1][j].g = gNew;
                    cellDetails[i + 1][j].h = hNew;
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                }
            }
        }
        

        // down
        if (i>=0&&j+1>=0&&i<width&&j+1<height) {
            if (i == target.first && j+1 == target.second) {
                cellDetails[i][j + 1].parent_i = i;
                cellDetails[i][j + 1].parent_j = j;
                tracePath(cellDetails, target);
                foundDest = true;
                return;
            } else if (closedList[i][j + 1] == false && grid[i][j+1]==0) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = h(make_pair(i, j + 1), target);
                fNew = gNew + hNew;
                if (cellDetails[i][j + 1].f == FLT_MAX || cellDetails[i][j + 1].f > fNew) {
                    openList.insert(make_pair(fNew, make_pair(i, j + 1)));
                    cellDetails[i][j + 1].f = fNew;
                    cellDetails[i][j + 1].g = gNew;
                    cellDetails[i][j + 1].h = hNew;
                    cellDetails[i][j + 1].parent_i = i;
                    cellDetails[i][j + 1].parent_j = j;
                }
            }
        }
        
        // upper left
        if (i-1>=0&&j-1>=0&&i-1<width&&j-1<height) {
            if (i-1==target.first && j-1==target.second) {
                cellDetails[i - 1][j - 1].parent_i = i;
                cellDetails[i - 1][j - 1].parent_j = j;
                tracePath(cellDetails, target);
                foundDest = true;
                return;
            } else if (closedList[i - 1][j - 1] == false &&grid[i-1][j-1]==0) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = h(make_pair(i - 1, j - 1), target);
                fNew = gNew + hNew;
                if (cellDetails[i - 1][j - 1].f == FLT_MAX || cellDetails[i - 1][j - 1].f > fNew) {
                    openList.insert(make_pair(fNew, make_pair(i - 1, j - 1)));
                    cellDetails[i - 1][j - 1].f = fNew;
                    cellDetails[i - 1][j - 1].g = gNew;
                    cellDetails[i - 1][j - 1].h = hNew;
                    cellDetails[i - 1][j - 1].parent_i = i;
                    cellDetails[i - 1][j - 1].parent_j = j;
                }
            }
        }

        //lower left
        if (i-1>=0&&j+1>=0&&i-1<width&&j+1<height) {
            if (i-1==target.first && j+1==target.second) {
                cellDetails[i - 1][j + 1].parent_i = i;
                cellDetails[i - 1][j + 1].parent_j = j;
                tracePath(cellDetails, target);
                foundDest = true;
                return;
            }else if (closedList[i - 1][j + 1] == false && grid[i-1][j+1]==0) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = h(make_pair(i - 1, j + 1), target);
                fNew = gNew + hNew;
                if (cellDetails[i - 1][j + 1].f == FLT_MAX || cellDetails[i - 1][j + 1].f > fNew) {
                    openList.insert(make_pair(fNew, make_pair(i - 1, j + 1)));
                    cellDetails[i - 1][j + 1].f = fNew;
                    cellDetails[i - 1][j + 1].g = gNew;
                    cellDetails[i - 1][j + 1].h = hNew;
                    cellDetails[i - 1][j + 1].parent_i = i;
                    cellDetails[i - 1][j + 1].parent_j = j;
                }
            }
        }

        // upper right
        if (i+1>=0&&j-1>=0&&i+1<width&&j-1<height) {
            if (i+1==target.first && j-1==target.second) {
                // Set the Parent of the destination cell
                cellDetails[i + 1][j - 1].parent_i = i;
                cellDetails[i + 1][j - 1].parent_j = j;
                tracePath(cellDetails, target);
                foundDest = true;
                return;
            }
            else if (closedList[i + 1][j - 1] == false && grid[i+1][j-1]==0) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = h(make_pair(i + 1, j - 1), target);
                fNew = gNew + hNew;
                if (cellDetails[i + 1][j - 1].f == FLT_MAX || cellDetails[i + 1][j - 1].f > fNew) {
                    openList.insert(make_pair(fNew, make_pair(i + 1, j - 1)));
                    cellDetails[i + 1][j - 1].f = fNew;
                    cellDetails[i + 1][j - 1].g = gNew;
                    cellDetails[i + 1][j - 1].h = hNew;
                    cellDetails[i + 1][j - 1].parent_i = i;
                    cellDetails[i + 1][j - 1].parent_j = j;
                }
            }
        }
    
 
        // lower right
        if (i+1>=0&&j+1>=0&&i+1<width&&j+1<height) {
            if (i+1==target.first&&j+1==target.second) {
                cellDetails[i + 1][j + 1].parent_i = i;
                cellDetails[i + 1][j + 1].parent_j = j;
                tracePath(cellDetails, target);
                foundDest = true;
                return;
            } else if (closedList[i + 1][j + 1] == false && grid[i+1][j+1] == 0) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = h(make_pair(i + 1, j + 1), target);
                fNew = gNew + hNew;
                if (cellDetails[i + 1][j + 1].f == FLT_MAX|| cellDetails[i + 1][j + 1].f > fNew) {
                    openList.insert(make_pair(fNew, make_pair(i + 1, j + 1)));
                    cellDetails[i + 1][j + 1].f = fNew;
                    cellDetails[i + 1][j + 1].g = gNew;
                    cellDetails[i + 1][j + 1].h = hNew;
                    cellDetails[i + 1][j + 1].parent_i = i;
                    cellDetails[i + 1][j + 1].parent_j = j;
                }
            }
        }
    }    
    if (foundDest == false)
        printf("Failed to find the Destination Cell\n");
 
    return;
}

vector<vector<int>> converttogrid(string infile) {
    int width = 0;
    int height = 0;
    pair<int,int> start;
    pair<int,int> end;
    int bestDis = 0;
    vector<vector<int>> grid;
    ifstream input(infile);
    if (!input.is_open()) {
        throw std::runtime_error("the file fails to open");
        std::cout<<"the file fails to open"<<std::endl;
    }
    string s = "";
    int flag = 0;
    while (getline(input, s)) {
        if (flag == 0) {
            int countt = 0;
            string tmp = "";
            for(auto i = s.begin(); i != s.end(); i++) {
                if (*i != ' '){
                    tmp += *i;
                }
                if (*i == ' ' && countt == 0){
                    width = stoi(tmp);
                    tmp = "";
                    countt++;
                } else if (*i == ' ' && countt == 1) {
                    height = stoi(tmp);
                    tmp="";
                    countt++;
                } else if (i == (s.end()-1) && countt == 2){
                    //cout<<"check: "<<tmp<<endl;
                    bestDis = stoi(tmp); 
                    countt++;
                }
                
            }
        } else {
            vector<int> vec;
            string tmp = "";
            int countt = 0;
            for (char i : s) {
                if (i == ' ') {
                    continue;
                } else {
                    vec.push_back(i-48);
                }
                if (i == '2') {
                    start = pair<int, int>(countt,flag-1);
                } else if (i == '3') {
                    end = pair<int, int>(countt, flag-1);
                }
                countt++;
            }
            grid.push_back(vec);
        }
        flag++;
    }
    input.close();
    vector<vector<int>> temp;
    for(int i = 0; i < width; i++) {
        vector<int> aa(height);
        temp.push_back(aa);
    }
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            temp[j][i] = grid[i][j];
        }
    }
    grid = temp;
    return grid;
}
 
int main()
{
    string s = "../data/Medium(10-50)/test_grid_width30_height35(0).txt";
    vector<vector<int>> grid = converttogrid(s);
    pair<int, int> start = make_pair(24, 15);
    pair<int, int> target = make_pair(9, 4);
    aStarSearch(grid, start, target);
    return 0;
}

