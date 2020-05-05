class Solution {
    typedef unsigned long long ull;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) {
            return 0;
        }
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            for (int j = 0; j < obstacleGrid[i].size(); ++j) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            if (obstacleGrid[i][0] != -1) {
                obstacleGrid[i][0] = 1;
            } else {
                for (int j = i; j < obstacleGrid.size(); ++j) {
                    obstacleGrid[j][0] = -1; 
                }
                break;
            }
        }
        for (int i = 0; i < obstacleGrid[0].size(); ++i) {
            if (obstacleGrid[0][i] != -1) {
                obstacleGrid[0][i] = 1;
            } else {
                for (int j = i; j < obstacleGrid[0].size(); ++j) {
                    obstacleGrid[0][j] = -1;
                }
                break;
            }
        }
        for (int i = 1; i < obstacleGrid.size(); ++i) {
            for (int j = 1; j < obstacleGrid[i].size(); ++j) {
                ull top = obstacleGrid[i - 1][j] == -1 ? 0 : obstacleGrid[i - 1][j];
                ull left = obstacleGrid[i][j - 1] == -1 ? 0 : obstacleGrid[i][j - 1];
                if (obstacleGrid[i][j] != -1) {
                    obstacleGrid[i][j] = top + left;
                }
            }
        }
        int answer = obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
        answer = answer == -1 ? 0: answer;
        return answer;
    }
};