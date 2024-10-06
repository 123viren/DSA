#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // Compute the total sum modulo p
        long long sum = 0;
        for(auto &x : nums) {
            sum += x;
            sum %= p;
        }
        
        // If the sum is already divisible by p, no need to remove any subarray
        if(sum == 0) return 0;
        
        // We need to find a subarray with sum % p == sum
        // Initialize a map to store (prefix_sum % p) -> index
        unordered_map<long long, int> modMap;
        modMap[0] = -1; // Handle the case when subarray starts from index 0
        
        long long prefix = 0;
        int minLength = nums.size();
        
        for(int i = 0; i < nums.size(); ++i){
            prefix = (prefix + nums[i] % p) % p;
            
            // The target is (prefix - sum + p) % p
            long long target = (prefix - sum + p) % p;
            
            if(modMap.find(target) != modMap.end()){
                int prevIndex = modMap[target];
                minLength = min(minLength, i - prevIndex);
            }
            
            // Store the latest index for this prefix sum
            modMap[prefix] = i;
        }
        
        // If minLength is equal to the size of nums, it's not possible to remove a valid subarray
        return minLength < nums.size() ? minLength : -1;
    }
};
