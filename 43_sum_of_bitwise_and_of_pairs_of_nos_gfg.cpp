class Solution {
public:
    typedef long long ll;
    long long pairAndSum(int n, long long ar[]) {
        // code here
        ll ans = 0;
        for (int i = 0; i < 32; i++) {
            ll cnt = 0;
            for (int j = 0; j < n; j++) {
                if (ar[j] & 1)cnt += 1;
                ar[j] = ar[j] >> 1;
            }
            // cout<<"cnt is:"<<cnt<<endl;
            ans +=  (1 << i) * (cnt * (cnt - 1) / 2);
        }
        return ans;
    }