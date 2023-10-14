#include <queue>
#include <iostream>
#include <vector>
#include "grid.h"
using namespace std;
 
int minDistance(const std::vector<std::vector<int>> grid, int n, int m){
    QItem source(0, 0, 0);
 
    // To keep track of visited QItems. Marking
    // blocked cells as visited.
    std::vector<bool> tmp(m, false);
    std::vector<std::vector<bool>> visited(n, tmp);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                visited[i][j] = true;
            else
                visited[i][j] = false;
 
            // Finding source
            if (grid[i][j] == 2)
            {
               source.row = i;
               source.col = j;
            }
        }
    }
 
    // applying BFS on matrix cells starting from source
    queue<QItem> q;
    q.push(source);
    visited[source.row][source.col] = true;
    while (!q.empty()) {
        QItem p = q.front();
        q.pop();
 
        // Destination found;
        if (grid[p.row][p.col] == 3)
            return p.dist;
 
        // moving up
        if (p.row - 1 >= 0 && visited[p.row - 1][p.col] == false) {
            q.push(QItem(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }
 
        // moving down
        if (p.row + 1 < n && visited[p.row + 1][p.col] == false) {
            q.push(QItem(p.row + 1, p.col, p.dist + 1));
            visited[p.row + 1][p.col] = true;
        }
 
        // moving left
        if (p.col - 1 >= 0 && visited[p.row][p.col - 1] == false) {
            q.push(QItem(p.row, p.col - 1, p.dist + 1));
            visited[p.row][p.col - 1] = true;
        }
 
         // moving right
        if (p.col + 1 < m && visited[p.row][p.col + 1] == false) {
            q.push(QItem(p.row, p.col + 1, p.dist + 1));
            visited[p.row][p.col + 1] = true;
        }

        // moving up left
        if (p.col - 1 >= 0 && p.row - 1 >= 0 && visited[p.row - 1][p.col - 1] == false) {
            q.push(QItem(p.row - 1, p.col - 1, p.dist + 1));
            visited[p.row - 1][p.col - 1] = true;
        }
 
        // moving up right
        if (p.col + 1 < m && p.row - 1 >= 0 && visited[p.row - 1][p.col + 1] == false) {
            q.push(QItem(p.row - 1, p.col + 1, p.dist + 1));
            visited[p.row - 1][p.col + 1] = true;
        }
 
        // moving down left
        if (p.row + 1 < n && p.col - 1 >= 0 && visited[p.row + 1][p.col - 1] == false) {
            q.push(QItem(p.row + 1, p.col - 1, p.dist + 1));
            visited[p.row + 1][p.col - 1] = true;
        }
 
         // moving down right
        if (p.row + 1 < n && p.col + 1 < m && visited[p.row + 1][p.col + 1] == false) {
            q.push(QItem(p.row + 1, p.col + 1, p.dist + 1));
            visited[p.row + 1][p.col + 1] = true;
        }
    }
    return -1;
}