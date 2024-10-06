class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> v(n);

        for(int i = 0; i < n; i++)
        {
            v[i] = arr[i] % k;

            if(v[i] < 0)
            {
                v[i] += k;
            }
        }
        for(auto &x:v)
        {
            cout << x << " ";
        }
        cout << endl;
        map<int, int> mp;
        for(auto &x:v)
        {
            mp[x]++;
        }
        
        bool ans = true;

        for(auto &x:mp)
        {
            

            if(x.first == 0 && x.second % 2)
            {
               ans = false;
               break;
            }
            else if(x.first == 0) continue;

            cout << x.first << " -> " << x.second << " " << mp[k - x.first] << endl;
            if(x.second == mp[k - x.first])
            {
                x.second = 0;
                mp[k - x.first] = 0;
            }
            else{
                ans = false;
                break;
            }
        }
        return ans;
    }
};
