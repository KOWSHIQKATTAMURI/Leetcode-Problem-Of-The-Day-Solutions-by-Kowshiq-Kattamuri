class Solution {
public:
    int partition(vector<int>& nums, int pivot, int low, int high){
        int i = low, j = low;
        while(i <= high){
            if(nums[i] <= pivot){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j - 1;
    }
    int quickselect(vector<int>& nums, int k, int low, int high){
        int pivot = nums[high];
        int idx = partition(nums, pivot, low, high);
        if(idx < k){
            return quickselect(nums, k, idx + 1, high);
        }else if(idx > k){
            return quickselect(nums, k, low, idx - 1);
        }
        return nums[idx];
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickselect(nums, n - k, 0, n - 1);
    }
};