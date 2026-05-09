class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(string s : strs){
            str+=to_string(s.size())+"#"+s;
        }
        return str;
    }

    vector<string> decode(string s) {
        int i=0;
        int n = s.size();
        vector<string> res;
        while(i<n){
            int j=i;
            while(s[j]!='#'){
                ++j;
            }
            int len = stoi(s.substr(i, j-i));
            ++j;
            string str = s.substr(j,len);
            res.push_back(str);
            i=j+len;
        }
        return res;
    }
};
