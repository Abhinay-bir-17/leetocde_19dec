class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int lsum = 0, csum = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int temp;
            temp = gas[i] - cost[i];

            lsum += temp;
            if (ans != -1) {
                if ((csum + temp) >= 0) {
                    csum += temp;
                } else {
                    ans = -1; csum = 0;
                }
            } else {
                if (temp >= 0) {
                    ans = i; csum = temp;
                }
            }
            // cout<<"temp:"<<temp<<",ans:"<<ans<<",lsum="<<lsum<<",csum:"<<csum<<endl;
        } if (lsum >= 0)return ans; return - 1;
    }
};