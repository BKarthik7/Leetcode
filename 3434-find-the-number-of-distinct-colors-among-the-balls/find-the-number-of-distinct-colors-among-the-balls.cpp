class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> color;
        unordered_map<int, int> freq;
        vector<int> ans;

        for (auto& q : queries) {
            if (color.count(q[0]) && --freq[color[q[0]]] == 0) freq.erase(color[q[0]]);
            color[q[0]] = q[1];
            freq[q[1]]++;
            ans.push_back(freq.size());
        }
        return ans;
    }
};
