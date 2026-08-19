/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    vector<vector<int>> answer;

public:
    int floor(vector<int>& arr, int key) {
        int low = 0, high = arr.size() - 1;
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key) {
                return key;
            } else if (arr[mid] < key) {
                res = arr[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }

    int ceil(vector<int>& arr, int key) {
        int low = 0, high = arr.size() - 1;
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key) {
                return key;
            } else if (arr[mid] > key) {
                res = arr[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }

    void inOrder(TreeNode* root, vector<int>& arr) {
        if (!root)
            return;
        inOrder(root->left, arr);
        arr.emplace_back(root->val);
        inOrder(root->right, arr);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> arr;
        inOrder(root, arr);
        for (int val : queries) {
            int minVal = floor(arr, val);
            int maxVal = ceil(arr, val);
            answer.push_back({minVal, maxVal});
        }
        return answer;
    }
};