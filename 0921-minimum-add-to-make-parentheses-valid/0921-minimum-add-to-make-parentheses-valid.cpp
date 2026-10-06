class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
            }
            if(s[i]==')'){
                if(open>0){
                    open--;
                }
                else{
                    ans++;
                }
            }
        }
        if(open>0){
            ans+=open;
        }
        return ans;
    }
};