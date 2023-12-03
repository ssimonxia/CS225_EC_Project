#include <vector>
#include "Astar.h"
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <functional>
#include <queue>
#include <string>
using namespace std;


void Astar::converttogrid(string infile) {
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
}

/*
template <typename Heuristic>
vector<pair<int, int>> Astar::aStar(pair<int, int> start, pair<int, int> target, vector<vector<int>> grid, Heuristic h){
    map<pair<int, int>, pair<int, int>> parentcell;
    parentcell[start] = make_pair(-1, -1);
    vector<pair<int, int>> empty;
    queue<pair<int, int>> astarqueue;
    astarqueue.push(start);

    while (!astarqueue.empty()) {
        pair<int, int> current = astarqueue.front();
        astarqueue.pop();
        if (current == target) { 
            vector<pair<int, int>> path;
            while (current.first != -1 && current.second != -1){ 
                path.push_back(make_pair(current.first, current.second));
                cout<<current.first<<" "<<current.second<<endl;
                current = parentcell[current];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        vector<pair<int, int>> neighbors = getNeighbor(current, grid);
        double minn = 999999;
        for(auto it = neighbors.begin(); it != neighbors.end(); ++it){
            if(h(it->first, it->second) < minn){
                parentcell[make_pair(it->first, it->second)] = current;
                astarqueue.push(make_pair(it->first, it->second));
                minn = h(it->first, it->second);
            }
        }
    }
    return empty;
}
*/

vector<pair<int, int>> Astar::getNeighbor(pair<int, int> curr, vector<vector<int>> grid) {
    vector<pair<int, int>> neighbors;
    neighbors.push_back(make_pair(curr.first - 1, curr.second)); // left
    neighbors.push_back(make_pair(curr.first, curr.second - 1)); // up
    neighbors.push_back(make_pair(curr.first + 1, curr.second)); // right
    neighbors.push_back(make_pair(curr.first, curr.second + 1)); // down
    neighbors.push_back(make_pair(curr.first - 1, curr.second - 1)); // upper left
    neighbors.push_back(make_pair(curr.first - 1, curr.second + 1)); // lower left
    neighbors.push_back(make_pair(curr.first + 1, curr.second - 1)); // upper right
    neighbors.push_back(make_pair(curr.first + 1, curr.second + 1)); // lower right

    unsigned i = 0;
    while (i < neighbors.size()) {
        pair<int, int> neighbor = neighbors[i];
        int x = neighbor.first;
        int y = neighbor.second;
        if (x < 0 || x >= width || y < 0 || y >= height
        || grid[x][y] == 1){
            neighbors.erase(neighbors.begin() + i);
        } else {
            i++;
        }
    }

    return neighbors;
}

vector<pair<int, int>> Astar::BFS(pair<int, int> start, pair<int, int> target, vector<vector<int>> grid) {
    map<pair<int, int>, pair<int, int>> parentcell;
    parentcell[start] = make_pair(-1, -1);
    auto visited = grid;
    visited[target.first][target.second] = 0;
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        //cout<<"check: "<<p.first<<" "<<p.second<<endl;
        if (p == target) { 
            vector<pair<int, int>> path;
            while (p.first != -1 && p.second != -1){ 
                path.push_back(make_pair(p.first, p.second));
                p = parentcell[p];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        // move left
        if (p.first - 1 >= 0 && visited[p.first - 1][p.second] == 0) {
            parentcell[make_pair(p.first-1, p.second)] = p;
            q.push(make_pair(p.first-1, p.second));
            visited[p.first - 1][p.second] = 1;
        }
 
        // moving up
        if (p.second - 1 >= 0 && visited[p.first][p.second - 1] == 0) {
            parentcell[make_pair(p.first, p.second-1)] = p;
            q.push(make_pair(p.first, p.second - 1));
            visited[p.first][p.second - 1] = 1;
        }

        // move right
        if (p.first + 1 < width && visited[p.first + 1][p.second] == 0) {
            parentcell[make_pair(p.first+1, p.second)] = p;
            q.push(make_pair(p.first + 1, p.second));
            visited[p.first + 1][p.second] = 1;
        }
 
 
         // moving down
        if (p.second + 1 < height && visited[p.first][p.second + 1] == 0) {
            parentcell[make_pair(p.first, p.second + 1)] = p;
            q.push(make_pair(p.first, p.second + 1));
            visited[p.first][p.second + 1] = 1;
        }
        
        // moving upper left
        if (p.first - 1 >= 0 && p.second - 1 >= 0 && visited[p.first - 1][p.second - 1] == 0) {
            parentcell[make_pair(p.first-1, p.second-1)] = p;
            q.push(make_pair(p.first - 1, p.second - 1));
            visited[p.first - 1][p.second - 1] = 1;
        }
 
        // moving lower left
        if (p.second + 1 < height && p.first - 1 >= 0 && visited[p.first-1][p.second + 1] == 0) {
            parentcell[make_pair(p.first - 1, p.second + 1)] = p;
            q.push(make_pair(p.first - 1, p.second + 1));
            visited[p.first - 1][p.second + 1] = 1;
        }

        // moving upper right
        if (p.first + 1 < width && p.second - 1 >= 0 && visited[p.first + 1][p.second - 1] == 0) {
            parentcell[make_pair(p.first + 1, p.second - 1)] = p;
            q.push(make_pair(p.first + 1, p.second - 1));
            visited[p.first + 1][p.second - 1] = 1;
        }
        
 
         // moving lower right
        if (p.first + 1 < width && p.second + 1 < height && visited[p.first + 1][p.second + 1] == 0) {
            parentcell[make_pair(p.first+1, p.second+1)] = p;
            q.push(make_pair(p.first+1, p.second+1));
            visited[p.first + 1][p.second + 1] = 1;
        }
        
    }
    vector<pair<int, int>> empty;
    return empty;
}