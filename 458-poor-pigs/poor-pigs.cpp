class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest){
        if(buckets == 1){
            return 0;
        }
        int kow = 1 + minutesToTest/minutesToDie;
        int x = kow;
        int ans = 1;
        while(kow < buckets){
            kow *= x;
            ans++;
        }
        return ans;
    }
};