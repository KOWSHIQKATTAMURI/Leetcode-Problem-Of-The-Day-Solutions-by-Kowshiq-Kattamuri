class Solution {
public:
    int uniquePaths(int m, int n){
        vector<vector<int>>kow(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    kow[i][j] = 1;
                }else{
                    kow[i][j] = kow[i][j - 1] + kow[i - 1][j];
                }
            }
        }
        return kow[m - 1][n - 1];
    }
};