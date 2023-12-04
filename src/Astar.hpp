#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cfloat>
#include <set>
using namespace std;
/*
template <typename Heuristic>
vector<pair<int, int>> Astar::aStar(pair<int, int> start, pair<int, int> target, vector<vector<int>> grid, Heuristic h){
    map<pair<int, int>, pair<int, int>> parentcell;
    parentcell[start] = make_pair(-1, -1);
    vector<pair<int, int>> tmp;
    tmp.push_back(make_pair(-1, 0));
    tmp.push_back(make_pair(0, -1));
    tmp.push_back(make_pair(1, 0));
    tmp.push_back(make_pair(0, 1));
    tmp.push_back(make_pair(-1, -1));
    tmp.push_back(make_pair(-1, 1));
    tmp.push_back(make_pair(1, -1));
    tmp.push_back(make_pair(1, 1));
    auto visited = grid;
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
                //cout<<current.first<<" "<<current.second<<endl;
                current = parentcell[current];
            }
            reverse(path.begin(), path.end());
            return path;
        }
        //vector<pair<int, int>> neighbors = getNeighbor(current, grid);
        //cout<<"size: "<<neighbors.size()<<endl;
        //set<pair<double, pair<int, int>>> re;
        vector<pair<int, int>> tmp_record;
        //double minn = 999999;
        //cout<<current.first<<" "<<current.second<<endl;
        for(int i = 0; i < 4; i++){
            pair<int, int> it = make_pair(current.first + tmp[i].first, current.second + tmp[i].second);
            int x = it.first;
            int y = it.second;
            if(x >= 0 && x < width && y >= 0 && y < height
            && (visited[x][y] == 0 || visited[x][y] == 3)){
                //cout<<"check node inside: "<<it.first<<" "<<it.second<<endl;
                parentcell[it] = current;
                //re.insert(make_pair(h(it, start),it));
                //astarqueue.push(it);
                tmp_record.push_back(it);
                visited[it.first][it.second] = 1;
            }
        }
        for(auto i = re.begin(); i != re.end(); i++) {
            astarqueue.push(i->second);
        }
        if (tmp_record.size() >= 1) {
            for(unsigned i = 0; i < tmp_record.size()-1; i++) {
                for(unsigned j = i+1; j < tmp_record.size()-1; j++) {
                    double hcurr = h(tmp_record[i], start);
                    double hnext = h(tmp_record[i+1], start);
                    if (hnext < hcurr) {
                        swap(hnext, hcurr);
                    }
                }
            }
            for(pair<int, int> i : tmp_record) {
                astarqueue.push(i);
                //cout<<"check: "<<i.first<<" "<<i.second<<endl;
            }
        }
        //cout<<"check: "<<tt.first<<" "<<tt.second<<endl;
    }
    return empty;
}
*/
template <typename Heuristic>
vector<pair<int, int>> Astar::aStarSearch(vector<vector<int>> grid, pair<int, int> start, pair<int, int> target, Heuristic h) {
    vector<bool> tmpl(height, false);
    vector<vector<bool>> closedList(width, tmpl);

    vector<cell> tmpc(height);
    vector<vector<cell>> cellDetails(width, tmpc);
    
    vector<pair<int, int>> tmp;
    tmp.push_back(make_pair(-1, 0));
    tmp.push_back(make_pair(0, -1));
    tmp.push_back(make_pair(1, 0));
    tmp.push_back(make_pair(0, 1));
    tmp.push_back(make_pair(-1, -1));
    tmp.push_back(make_pair(-1, 1));
    tmp.push_back(make_pair(1, -1));
    tmp.push_back(make_pair(1, 1));

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
    
    vector<pair<int, int>> out;
    //cout<<width<<" "<<height<<endl;
    while (!openList.empty()) {
        pair<double, pair<int, int>> p = *openList.begin();
        openList.erase(openList.begin());
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;
        double gNew, hNew, fNew;
        for(unsigned k = 0; k < 4; k++) {
            int x = i+tmp[k].first;
            int y = j+tmp[k].second;
            //cout<<x<<" "<<y<<" "<<i<<" "<<j<<endl;
            if (x >= 0 && y >= 0 && x < width && y < height) {
                if (x == target.first && y == target.second) {
                    cellDetails[x][y].parent_i = i;
                    cellDetails[x][y].parent_j = j;
                    //cout<<"endd"<<endl;
                    x = target.first;
                    y = target.second;
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
                } else if (closedList[x][y] == false && grid[x][y] == 0) {
                    gNew = cellDetails[i][j].g + 1.0;
                    hNew = h(make_pair(x, y), target);
                    fNew = gNew + hNew;
                    if (cellDetails[x][y].f == FLT_MAX || cellDetails[x][y].f > fNew) {
                        openList.insert(make_pair(fNew, make_pair(x, y)));
                        cellDetails[x][y].f = fNew;
                        cellDetails[x][y].g = gNew;
                        cellDetails[x][y].h = hNew;
                        cellDetails[x][y].parent_i = i;
                        cellDetails[x][y].parent_j = j;
                    }
                }
            }
        }
    }    
    vector<pair<int, int>> empty;
    return empty;
}