class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size(); 
        int diff = INT_MAX, sum;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            for(int j = i + 1, k = n - 1; j < k; j++){
                
                while(j < k && nums[i] + nums [j] + nums[k] >= target){
                    
                    if(diff > nums[i] + nums [j] + nums[k] - target){

                        diff = nums[i] + nums [j] + nums[k] - target;
                        sum = nums[i] + nums [j] + nums[k];
                    }
                    k--;
                }
            }
        }

        reverse(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            for(int j = i + 1, k = n - 1; j < k; j++){
                
                while(j < k && nums[i] + nums [j] + nums[k] <= target){

                    if(diff > target - (nums[i] + nums [j] + nums[k])){

                        diff = target - (nums[i] + nums [j] + nums[k]);
                        sum = nums[i] + nums [j] + nums[k];
                    }
                    k--;
                }
            }
        }

        return sum;
    }
};
