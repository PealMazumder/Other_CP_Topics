class Solution {
public:
    unordered_set<string> st;
    int maxUniqueSplit(string s) {
        return maxUniqSubsring(s, "", 0);
    }
    
    int maxUniqSubsring(string &s, string curr, int idx)
    {
        if(idx >= (int)s.size()) return 0;
        curr += s[idx];
        int a, b;
        a = b = -100000000; 
        if(st.find(curr) == st.end())
        {
            st.insert(curr);
            a = maxUniqSubsring(s, "", idx+1) + 1;
            st.erase(curr);
        }
        b = maxUniqSubsring(s, curr, idx+1);
        return max(a, b);
    }
};