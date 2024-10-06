class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n=skill.size();
        sort(skill.begin(),skill.end());
        
        // vector<pair<int,int>> v;
        int req=skill[0]+skill[n-1];
        long long ans=0;
        for(int i=0;i<n/2;i++)
        {
            if((skill[i]+skill[n-i-1])!=req)
            {
                return -1;
            }
            else{
                // v.push_back({skill[i],skill[n-i-1]});
                ans+=(skill[i]*skill[n-i-1]);
            }
        }
        
        
        // for(auto &x:v)
        // {
        //     ans+=(x.first*x.second);
        // }
        return ans;
    }
};
