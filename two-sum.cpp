class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int>numbers;
        vector<int>answer(2);

        for(int i = 0; i < nums.size(); i++){
            if(numbers.find(target - nums[i]) != numbers.end()){
                answer[0] = i; answer[1] = numbers[target - nums[i]];
                return answer; 
            }
            numbers[nums[i]] = i;
        }

        return answer;
    }
};
