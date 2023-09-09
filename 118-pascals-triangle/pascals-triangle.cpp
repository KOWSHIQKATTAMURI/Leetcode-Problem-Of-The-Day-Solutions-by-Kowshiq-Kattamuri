class Solution {
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> kow(numRows);
        for(int i = 0; i < numRows; i++){
            kow[i].resize(i + 1);
            kow[i][0] = kow[i][i] = 1;
            for(int j = 1; j < i; j++){
                kow[i][j] = kow[i - 1][j - 1] + kow[i - 1][j];
            }
        }
        return kow;
    }
};