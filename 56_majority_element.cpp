class Solution {
public:
    int majorityElement(vector<int>& ar) {
        int n = ar.size();
        int ans = ar[0]; int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (ar[i] == ans)cnt += 1;
            else {
                if (cnt == 1)ans = ar[i];
                else cnt -= 1;
            }
            if (cnt < 0)ans = ar[i];
        }
        // cnt = 0;
        // for(int i=0;i<n;i++){
        //     if(ar[i]== ans)cnt+=1;
        // }
        // if(cnt>  (n/2))return
        return ans;
    }
};