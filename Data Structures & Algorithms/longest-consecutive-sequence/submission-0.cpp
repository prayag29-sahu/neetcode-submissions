class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxLen=0;
        unordered_set<int> st(nums.begin(), nums.end());
        for(int num :st){
            if(st.find(num-1)==st.end()){
                int curr=num;
                int currLen = 1;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    currLen++;
                }
                maxLen=max(maxLen,currLen);
            }
        }
        return maxLen;
    }
};
