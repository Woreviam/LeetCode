class Solution {
public:
    /*
    #define INF (1<<30)

    int DP(int taken, int l, int r, string &s, vector<vector<vector<int> > > &memo){

        if(l > r)return 0;
        if(l == r)return 1;
        
        int &ret = memo[taken][l][r];

        if(ret != -1)return ret;
        int ans = -INF;

        if(taken){

            if(s[l] == s[r])return ret = 2 + DP(taken, l + 1, r - 1, s, memo);
            else return ret = -INF;
        }
        else{

            ans = max(DP(taken, l + 1, r, s, memo), DP(taken, l, r - 1, s, memo));
            if(s[l] == s[r])ans = max(ans, 2 + DP(1, l + 1, r - 1, s, memo));
        }

        return ret = ans;
    }

    string longestPalindrome(string s) {
        
        int n = s.size();
        vector< vector < vector<int> > >memo(2, vector<vector<int> > (n, vector<int>(n, -1)));

        int ans = 0, l, r;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && ans < 1 + (i != j) + DP(1, i + 1, j - 1, s, memo)){
                    
                    ans = 1 + DP(1, i + 1, j - 1, s, memo) + (i != j);
                    l = i; r = j;
                }
            }   
        }

        return s.substr(l, r - l + 1);

    }
*/

    string longestPalindrome(string s) {

        string t = "";
        for(int i = 0; i < s.size(); i++)t += '#', t += s[i];
        t += '#';

        t = "$" + t + "^";
        int n = t.size(), center = 1;
        vector<int>manacher(n);

        for(int i = 1, l = 1, r = 1; i < n; i++){
            
            manacher[i] = min(r - i, manacher[l + r - i]);
            while(t[i - manacher[i]] == t[i + manacher[i]])manacher[i]++;
            if(i + manacher[i] > r){
                l = i - manacher[i];
                r = i + manacher[i];
            }

            if(manacher[center] < manacher[i])center = i;
        }   

        string ans = "";
        for(int i = center - manacher[center] + 2; i < center + manacher[center]; i += 2)ans += t[i];
        return ans;
    }
};
