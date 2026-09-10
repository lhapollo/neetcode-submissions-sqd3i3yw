class NumMatrix {
public:
    vector<vector<int>> prefix_matrix; 
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        prefix_matrix = vector<vector<int>>(r+1, vector<int>(c+1, 0));
        prefix_matrix[1][1] = matrix[0][0];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0 && j == 0) continue;
                prefix_matrix[i+1][j+1] = matrix[i][j] + prefix_matrix[i+1][j] + prefix_matrix[i][j+1] - prefix_matrix[i][j];
            }
        }

        // for (int i = 0; i < r; i++) {
        //     for (int j = 0; j < c; j++) {
        //         cout << prefix_matrix[i][j] << " ";
        //     }
        //     cout << endl; 
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix_matrix[row2+1][col2+1] - prefix_matrix[row2+1][col1] - prefix_matrix[row1][col2+1] + prefix_matrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */