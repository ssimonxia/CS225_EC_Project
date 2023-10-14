#include <vector>
class QItem {
    public:
        int row;
        int col;
        int dist;
        QItem(int x, int y, int w)
            : row(x), col(y), dist(w)
        {
    }
};

int minDistance(const std::vector<std::vector<int>> grid, int n, int m);