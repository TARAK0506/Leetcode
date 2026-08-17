class Solution {
    struct Node {
        int val;
        bool used;
        Node() : val(0), used(false) {}
        Node(int x, bool placed = false) : val(x), used(placed) {}
    };

    int n, cnt;
    vector<Node> seg;
    Node merge(Node& left, Node& right) {
        Node res;
        res.val = max(left.val, right.val);
        res.used = left.used && right.used;
        return res;
    }
    void buildTree(int node, int low, int high, vector<int>& baskets) {
        if (low == high) {
            seg[node] = Node(baskets[low], false);
            return;
        }
        int mid = low + (high - low) / 2;
        buildTree(2 * node + 1, low, mid, baskets);
        buildTree(2 * node + 2, mid + 1, high, baskets);
        seg[node] = merge(seg[2 * node + 1], seg[2 * node + 2]);
    }

    int query(int node, int low, int high, int quantity) {
        if (!seg[node].used && seg[node].val < quantity) {
            return -1;
        }
        if (low == high) {
            return low;
        }
        int mid = low + (high - low) / 2;
        if (!seg[node].used && seg[2 * node + 1].val >= quantity)
            return query(2 * node + 1, low, mid, quantity);
        else if (!seg[node].used && seg[2 * node + 1].val < quantity) {
            return query(2 * node + 2, mid + 1, high, quantity);
        }
        return -1;
    }

    void update(int node, int low, int high, int index) {
        if (low == high) {
            seg[node].val = -1;
            seg[node].used = true;
            return;
        }
        int mid = low + (high - low) / 2;
        if (index <= mid)
            update(2 * node + 1, low, mid, index);
        else
            update(2 * node + 2, mid + 1, high, index);
        seg[node] = merge(seg[2 * node + 1], seg[2 * node + 2]);
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        n = fruits.size();
        seg.resize(4 * n);
        buildTree(0, 0, n - 1, baskets);
        for (int i = 0; i < n; i++) {
            int quantity = fruits[i];
            int idx = query(0, 0, n - 1, quantity);
            if (idx != -1) {
                update(0, 0, n - 1, idx);
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};