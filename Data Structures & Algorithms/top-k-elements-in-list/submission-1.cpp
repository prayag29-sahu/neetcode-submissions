class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>  freq;

        for(int num:nums){
            freq[num]++;
        }
        int n = nums.size();

        vector<vector<int>> bucket(n + 1);

        for (auto& it : freq) {
            int num = it.first;
            int frequency = it.second;

            bucket[frequency].push_back(num);
        }
        vector<int> result;

        for (int i = n; i >= 1; i--) {

            for (int num : bucket[i]) {
                result.push_back(num);

                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
