class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans = "";
        stack<char> st;
        for(int i = 0; i<S.size(); i++)
        {
            if(S[i] == ')')
            {
                if(st.size() > 1)
                    ans += ")";
                st.pop();
            }
            else
            {
                if(st.size() > 0)
                    ans += "(";
                st.push(S[i]);
            }  
        }
        return ans;   
    }
};