class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int count = 1;
        int last_smaller = INT_MIN;
        int largest = 1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]-1 == last_smaller ){
                count = count+1;
                last_smaller = nums[i];
            }
            else if(nums[i]!=last_smaller){
                count = 1;
                last_smaller = nums[i];
            }
            largest = max(largest,count);
        }
        return largest;
    }
};
