class Solution {
public:
    bool valid(int x, int y, int m, int n, vector<vector<int>>& matrix) {
        if (x >= 0 && x < m && y >= 0 && y < n) return matrix[x][y] != 999;
        return false; 
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans; 
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        int x = 0;
        int y = 0;
        int i = 0; 
        pair<int, int> dir = dirs[i];
        ans.push_back(matrix[x][y]);
        matrix[x][y] = 999;
        while (true) {
            //check current direction
            if (valid(x + dir.first, y + dir.second, m, n, matrix)) {
                x += dir.first;
                y += dir.second; 
                ans.push_back(matrix[x][y]);
                matrix[x][y] = 999;
                continue; 
            } else {
                //try to turn
                i = (i + 1) % 4;
                dir = dirs[i];
                if (valid(x + dir.first, y + dir.second, m, n, matrix)) {
                    x += dir.first; 
                    y += dir.second; 
                    ans.push_back(matrix[x][y]);
                    matrix[x][y] = 999;
                    continue; 
                } else { //turn failed, we are done
                    break; 
                }
            }
        }
        return ans; 
        //if both directions are unavailable, we are done
        //if current direction unavailable, try to turn
    }
};

//right: {0, 1}
//down: {1, 0}
//left: {0, -1}
//up: {-1, 0}