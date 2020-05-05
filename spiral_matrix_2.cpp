class Solution {
public:
    typedef vector<vector<int> > vvi;
    typedef vector<int> vi;
    vector<vector<int>> generateMatrix(int n) {
        vvi m(n, vi(n));
        int r = 0, c = 0, border_up = 0, border_left = 0, border_right = n - 1, border_down = n - 1;
        bool right = true, down = false,left = false, up = false;
        for (int i = 0; i < n*n; ++i) {
            m[r][c] = i + 1;
            bool coord_changed = false;
            while (!coord_changed) {
                if (right) {
                    if (c < border_right) {
                        ++c;
                        coord_changed = true;
                    } else {
                        right = false;
                        down = true;
                        border_up++;
                    }
                }
                if (down) {
                    if (r < border_down) {
                        ++r;
                        coord_changed = true;
                    } else {
                        down = false;
                        left = true;
                        border_right--;
                    }
                }
                if (left) {
                    if (c > border_left) {
                        --c;
                        coord_changed = true;
                    } else {
                        left = false;
                        up = true;
                        border_down--;
                    }
                }
                if (up) {
                    if (r > border_up) {
                        --r;
                        coord_changed = true;
                    } else {
                        up = false;
                        right = true;
                        border_left++;
                    }
                }
                if (border_left > border_right || border_up > border_down) {
                    break;
                }
            }
        }
        return m;
    }
};