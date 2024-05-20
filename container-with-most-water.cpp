class Solution {
public:

    int solve(vector<int>& height){

        int max_area = 0;
        vector<int>maxh(height.size(), -1);

        maxh[0] = height[0];
        for(int i = 1, j; i < height.size(); i++)maxh[i] = max(maxh[i - 1], height[i]);
        
        for(int i = 1; i < height.size(); i++){

            int lo = 0, hi = i - 1, me;
            while(lo < hi){
                me = lo + (hi - lo)/2;
                if(maxh[me] >= height[i])hi = me;
                else lo = me + 1;
            }

            if(height[lo] >= height[i])max_area = max(max_area, height[i] * (i - lo));
        }
        return max_area;
    }

    int maxArea(vector<int>& height) {
        
        int answer = solve(height);
        reverse(height.begin(), height.end());

        answer = max(answer, solve(height));    
        return answer;
    }
};
