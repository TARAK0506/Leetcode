class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if(a.second == b.second) return a.first > b.first;
            return a.second > b.second;
        }
    };
    string decimal2Binary(int n) {
        string str = "";
        while (n) {
            str = char((n % 2) + '0') + str;
            n >>= 1;
        }
        return str;
    }

    string reverseBinary(string& s) {
        int j = 0, n = s.length() - 1;
        while (j < n) {
            swap(s[j], s[n]);
            j++;
            n--;
        }
        return s;
    }

    int binary2Decimal(string& s) {
        int decimal = 0;
        for (char ch : s) {
            decimal = decimal * 2 + (ch - '0');
        }
        return decimal;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (auto& num : nums) {
            string s = decimal2Binary(num);
            string revBin = reverseBinary(s);
            int decimal = binary2Decimal(revBin);
            pq.push(make_pair(num, decimal));
        }

        while (!pq.empty()) {
            auto top = pq.top().first;
            ans.emplace_back(top);
            pq.pop();
        }
        return ans;
    }
};