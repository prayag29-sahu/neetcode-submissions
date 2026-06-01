class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int n = matrix[0].size() - 1;
        // bool ans = false;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (matrix[i][j] == target) {
        //             return true;
        //         }
        //     }
        // }

        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int right = row * col - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r = mid / col;
            int c = mid % col;
            int val = matrix[r][c];
            if (val == target) {
                return true;
            } else if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
