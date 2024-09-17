class Solution {
public:
    int minimumRounds(vector<int>& ar) {
        unordered_map<int, int> mp;
        int n = ar.size();
        for (int i = 0; i < n; i++)mp[ar[i]] += 1; int ans = 0;
        for (auto it : mp) {
            if (it.second == 1)return -1;
            if (it.second % 3 == 0)ans += it.second / 3;
            else if (it.second % 3 == 2) ans += ((it.second - 2) / 3) + 1;
            else {
                ans += ((it.second - 4) / 3) + 2;
            }
        } return ans;
    }
};