vector<bool> tmp(height, false);
    vector<vector<bool>> closedList(width, tmp);

    vector<cell> tmpc(height);
    vector<vector<cell>> cellDetails(width, tmpc);
    
    vector<pair<int, int>> out;
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
    while (!openList.empty()) {
        pair<double, pair<int, int>> p = *openList.begin();
        openList.erase(openList.begin());
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;
        double gNew, hNew, fNew;
        //left
        if (i-1>=0 && j>=0 && i-1<width && j<height) {
            if ((i-1) == target.first && j == target.second) {
                cellDetails[i - 1][j].parent_i = i;
                cellDetails[i - 1][j].parent_j = j;
                int x = target.first;
                int y = target.second;
                while (!(cellDetails[x][y].parent_i == x && cellDetails[x][y].parent_j == y)) {
                    out.push_back(make_pair(x, y));
                    int tmpx = x;
                    int tmpy = y;
                    x = cellDetails[tmpx][tmpy].parent_i;
                    y = cellDetails[tmpx][tmpy].parent_j;
                }
                out.push_back(make_pair(x, y));
                reverse(out.begin(), out.end());
                return out;
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
                int x = target.first;
                int y = target.second;
                while (!(cellDetails[x][y].parent_i == x && cellDetails[x][y].parent_j == y)) {
                    out.push_back(make_pair(x, y));
                    int tmpx = x;
                    int tmpy = y;
                    x = cellDetails[tmpx][tmpy].parent_i;
                    y = cellDetails[tmpx][tmpy].parent_j;
                }
                out.push_back(make_pair(x, y));
                reverse(out.begin(), out.end());
                return out;
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
                int x = target.first;
                int y = target.second;
                while (!(cellDetails[x][y].parent_i == x && cellDetails[x][y].parent_j == y)) {
                    out.push_back(make_pair(x, y));
                    int tmpx = x;
                    int tmpy = y;
                    x = cellDetails[tmpx][tmpy].parent_i;
                    y = cellDetails[tmpx][tmpy].parent_j;
                }
                out.push_back(make_pair(x, y));
                reverse(out.begin(), out.end());
                return out;
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
                int x = target.first;
                int y = target.second;
                while (!(cellDetails[x][y].parent_i == x && cellDetails[x][y].parent_j == y)) {
                    out.push_back(make_pair(x, y));
                    int tmpx = x;
                    int tmpy = y;
                    x = cellDetails[tmpx][tmpy].parent_i;
                    y = cellDetails[tmpx][tmpy].parent_j;
                }
                out.push_back(make_pair(x, y));
                reverse(out.begin(), out.end());
                return out;
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
                int x = target.first;
                int y = target.second;
                while (!(cellDetails[x][y].parent_i == x && cellDetails[x][y].parent_j == y)) {
                    out.push_back(make_pair(x, y));
                    int tmpx = x;
                    int tmpy = y;
                    x = cellDetails[tmpx][tmpy].parent_i;
                    y = cellDetails[tmpx][tmpy].parent_j;
                }
                out.push_back(make_pair(x, y));
                reverse(out.begin(), out.end());
                return out;
            } else if (closedList[i - 1][j - 1] == false &&grid[i-1][j-1]==0) {
                gNew = cellDetails[i][j].g + 1.414;
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
                int x = target.first;
                int y = target.second;
                while (!(cellDetails[x][y].parent_i == x && cellDetails[x][y].parent_j == y)) {
                    out.push_back(make_pair(x, y));
                    int tmpx = x;
                    int tmpy = y;
                    x = cellDetails[tmpx][tmpy].parent_i;
                    y = cellDetails[tmpx][tmpy].parent_j;
                }
                out.push_back(make_pair(x, y));
                reverse(out.begin(), out.end());
                return out;
            }else if (closedList[i - 1][j + 1] == false && grid[i-1][j+1]==0) {
                gNew = cellDetails[i][j].g + 1.414;
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
                int x = target.first;
                int y = target.second;
                while (!(cellDetails[x][y].parent_i == x && cellDetails[x][y].parent_j == y)) {
                    out.push_back(make_pair(x, y));
                    int tmpx = x;
                    int tmpy = y;
                    x = cellDetails[tmpx][tmpy].parent_i;
                    y = cellDetails[tmpx][tmpy].parent_j;
                }
                out.push_back(make_pair(x, y));
                reverse(out.begin(), out.end());
                return out;
            }
            else if (closedList[i + 1][j - 1] == false && grid[i+1][j-1]==0) {
                gNew = cellDetails[i][j].g + 1.414;
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
                int x = target.first;
                int y = target.second;
                while (!(cellDetails[x][y].parent_i == x && cellDetails[x][y].parent_j == y)) {
                    out.push_back(make_pair(x, y));
                    int tmpx = x;
                    int tmpy = y;
                    x = cellDetails[tmpx][tmpy].parent_i;
                    y = cellDetails[tmpx][tmpy].parent_j;
                }
                out.push_back(make_pair(x, y));
                reverse(out.begin(), out.end());
                return out;
            } else if (closedList[i + 1][j + 1] == false && grid[i+1][j+1] == 0) {
                gNew = cellDetails[i][j].g + 1.414;
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
    vector<pair<int, int>> empty;
 
    return empty;