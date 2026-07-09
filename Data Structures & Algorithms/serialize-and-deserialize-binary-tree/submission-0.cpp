/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    void preorder(TreeNode* root, string &ans) {
        if (root == nullptr) {
            ans += "N,";
            return;
        }
        ans += to_string(root->val) + ",";
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    string serialize(TreeNode* root) {
        string ans;
        preorder(root, ans);
        return ans;
    }

    TreeNode* build(queue<string> &q) {
        string curr = q.front();
        q.pop();
        if (curr == "N")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(curr));
        root->left = build(q);
        root->right = build(q);
        return root;
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp;
        for (char ch : data) {
            if (ch == ',') {
                q.push(temp);
                temp.clear();
            }
            else {

                temp += ch;
            }
        }
        return build(q);
    }
};