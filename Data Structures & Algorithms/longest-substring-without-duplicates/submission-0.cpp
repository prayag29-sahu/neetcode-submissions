class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n = s.length();
      vector<int> v(128,-1);
      int left =0;
      int maxlen = 0;
      for(int right =0;right<n;++right){
        if(v[s[right]]>=left){
            left = v[s[right]]+1;
        }
        v[s[right]]=right;
        maxlen = max(maxlen,right-left+1); 
      }
      return maxlen;
    }
};
