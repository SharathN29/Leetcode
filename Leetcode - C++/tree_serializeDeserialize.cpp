#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Codec {
// public:
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if (root == nullptr) return "#";
//         return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         return mydeserialize(data);
//     }
//     TreeNode* mydeserialize(string& data) {
//         if (data[0]=='#') {
//             if(data.size() > 1) data = data.substr(2);
//             return nullptr;
//         } else {
//             TreeNode* node = new TreeNode(helper(data));
//             node->left = mydeserialize(data);
//             node->right = mydeserialize(data);
//             return node;
//         }
//     }
// private:
//     int helper(string& data) {
//         int pos = data.find(',');
//         int val = stoi(data.substr(0,pos));
//         data = data.substr(pos+1);
//         return val;
//     }
// };

class Codec {
private:
    TreeNode* de(istringstream& iss) {
        TreeNode* root = NULL;
        string word;
        if (iss >> word && word != "N") {
            root = new TreeNode(stoi(word));
            root->left = de(iss);
            root->right = de(iss);
        }
        return root;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) { return "N "; }
        return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return de(iss);
    }
};













































