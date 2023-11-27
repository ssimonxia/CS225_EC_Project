#include <vector>
#include <queue>
#include <string>
using namespace std;

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
            int flag = 0;
            while (current.first != -1 && current.second != -1){ 
                if (flag > 40) {
                    break;
                }
                path.push_back(make_pair(current.first, current.second));
                //cout<<current.first<<" "<<current.second<<endl;
                current = parentcell[current];
                flag++;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        vector<pair<int, int>> neighbors = getNeighbor(current, grid);
        double minn = 999999;
        pair<int, int> tt;
        for(auto it = neighbors.begin(); it != neighbors.end(); ++it){
            if((parentcell.find(*it) == parentcell.end()) 
            &&(h(*it, target) <= minn)){
                parentcell[*it] = current;
                tt = *it;
                minn = h(*it, target);
                astarqueue.push(tt);
            }
        }
        
        //cout<<"check: "<<tt.first<<" "<<tt.second<<endl;
    }
    return empty;
}