class Solution {
public:
    int getWinner(vector<int>& arr, int k){
        int n = arr.size();
        int max_ele = *max_element(arr.begin(), arr.end());
        if(max_ele == arr[0] or k >= n){
            return max_ele;
        }
        int player = arr[0], count = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] > player){
                player = arr[i];
                count = 1;
            }else{
                count++;
            }
            if(count == k or player == max_ele){
                return player;
            }
        }
        return player;
    }
};