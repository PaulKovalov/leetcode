class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> traversal;
        if (matrix.size() == 0) {
            return traversal;
        }
        int i = 0, j = 0, h = matrix.size(), w = matrix[0].size(), ts = h*w;
        vector<vector<int>> used(h, vector<int>(w, 0));
        bool move_right = true, move_bottom = false, move_left = false, move_top = false;
        while(traversal.size() != ts) {
            if (!used[i][j]) {
                traversal.push_back(matrix[i][j]);
                used[i][j] = true;
            }
            // check where to move
            if (move_right) {
                if (j + 1 >= w || used[i][j + 1]) {
                    move_right = false;
                    move_bottom = true;
                } else {
                    ++j;
                }
            }
            if (move_bottom) {
                if (i + 1 >= h || used[i + 1][j]) {
                    move_bottom = false;
                    move_left = true;
                } else {
                    ++i;
                }
            }
            if (move_left) {
                if (j < 1 || used[i][j - 1]) {
                    move_left = false;
                    move_top = true;
                } else {
                    --j;
                }
            }
            if (move_top) {
                if (i < 1 || used[i - 1][j]) {
                    move_top = false;
                    move_right = true;
                } else {
                    --i;
                }
            }
        }
        return traversal;
    }
};