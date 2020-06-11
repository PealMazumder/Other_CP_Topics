class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        deque<char> dq;
        int ls = s.size(), lp = p.size();
        map<char, int> mp,ms;
        for(int i = 0; i<lp; i++)
        {
            mp[p[i]]++;
        }
        int l = 0, r = 0;
        while(r<ls)
        {
            if(mp[s[r]] != 0 && ms[s[r]] < mp[s[r]])
            {
                ms[s[r]]++; 
                dq.push_back(s[r]);
                r++;
            }
            else if(!dq.empty())
            {
                char tm = dq.front();
                dq.pop_front();
                ms[tm]--;
                l++;
            }
            else
            {
                r++;
                l++;
            }
            if(dq.size() == lp)
            {
                ans.push_back(l);
                char tm = dq.front();
                dq.pop_front();
                ms[tm]--;
                l++;
            }
        }
        
        return ans;
    }
};