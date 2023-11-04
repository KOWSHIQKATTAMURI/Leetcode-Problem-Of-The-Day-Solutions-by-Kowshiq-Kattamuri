class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right){
        int left_max = left.size() == 0 ? 0 : *max_element(left.begin(), left.end());
        int right_max = right.size() == 0 ? 0 : max(left_max, n - *min_element(right.begin(), right.end()));
        return max(left_max, right_max);
    }
};