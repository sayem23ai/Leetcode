class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // Add '(' only if it is NOT the outermost
                if (depth > 0)
                    ans += s[i];
                depth++;
            }
            else {
                depth--;
                // Add ')' only if it is NOT the outermost
                if (depth > 0)
                    ans += s[i];
            }
        }
        return ans;
    }
};