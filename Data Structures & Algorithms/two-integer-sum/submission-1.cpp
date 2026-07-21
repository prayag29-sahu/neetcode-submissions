class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            int n = target - nums[i];
            if(m.find(n)!=m.end()){
                return {m[n],i};
            }
            m[nums[i]]=i;
        }
        return {};
    }
    
};
