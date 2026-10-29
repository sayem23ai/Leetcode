class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans=0,n=s.size();
        for (int i=0;i<n-2;i++){
            char a=s[i],b=s[i+1],c=s[i+2];
            if(a!=b && b!=c && a!=c)
                ans++;
        }
        return ans;
    }
};