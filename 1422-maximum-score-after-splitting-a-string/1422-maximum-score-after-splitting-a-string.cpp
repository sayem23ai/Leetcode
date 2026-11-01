class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ones = 0, zeros = 0;
        int maxscore = 0;
        for (int i=0;i<n;i++){
            if(s[i]=='1'){
                ones++;
            }
        }
        for (int i=0;i<n-1;i++){
            if(s[i]=='0'){
                zeros++; // One more zero on the left.
            } else {
                ones--; // One fewer one on the right.
            }
            maxscore=max(maxscore,zeros+ones);
        }
        return maxscore;
    }
};