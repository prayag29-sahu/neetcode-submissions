class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string word : strs) {
            string shortWord = word;
            sort(shortWord.begin(), shortWord.end());
            map[shortWord].push_back(word);
        }
        vector<vector<string>> ans;

        for (auto& it : map) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
