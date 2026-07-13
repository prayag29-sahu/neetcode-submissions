class TrieNode {
public:
    TrieNode* children[26];
    string word;

    TrieNode() {
        for(int i=0;i<26;i++)
            children[i]=nullptr;

        word="";
    }
};

class Solution {
public:

    TrieNode* root=new TrieNode();

    void insert(string word){

        TrieNode* curr=root;

        for(char ch:word){

            int index=ch-'a';

            if(curr->children[index]==nullptr)
                curr->children[index]=new TrieNode();

            curr=curr->children[index];
        }

        curr->word=word;
    }

    void dfs(vector<vector<char>>& board,int i,int j,
             TrieNode* node,vector<string>& ans){

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
            return;

        char ch=board[i][j];

        if(ch=='#')
            return;

        if(node->children[ch-'a']==nullptr)
            return;

        node=node->children[ch-'a'];

        if(node->word!=""){

            ans.push_back(node->word);

            node->word="";
        }

        board[i][j]='#';

        dfs(board,i+1,j,node,ans);
        dfs(board,i-1,j,node,ans);
        dfs(board,i,j+1,node,ans);
        dfs(board,i,j-1,node,ans);

        board[i][j]=ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for(string word:words)
            insert(word);

        vector<string> ans;

        int m=board.size();

        int n=board[0].size();

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                dfs(board,i,j,root,ans);
            }
        }

        return ans;
    }
};