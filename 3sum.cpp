class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int> >solutions;

        unordered_map<long long, bool>seen;
        unordered_map<int, bool>visited;

        for(int i = 0; i < nums.size(); i++)visited[nums[i]] = true;
        long long add = 100000, base = 200001, h;
        int x;

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){

                h = (nums[j] + add) * base + nums[i];
                x = -(nums[i] + nums[j]);

                if(x < nums[i] || visited.find(x) == visited.end() || seen.find(h) != seen.end())continue;

                if(x != nums[i] && x != nums[j])solutions.push_back({nums[j], nums[i], x}), seen[h] = true;
                else if(x == nums[i] && x == nums[j] && i - j + 1 == 3)solutions.push_back({x, x, x}), seen[h] = true;
                else if(x == nums[i] && x != nums[j] && nums[i - 1] == x)solutions.push_back({nums[j], nums[i], x}), seen[h] = true;
            }
        }
        return solutions;
    }
};
