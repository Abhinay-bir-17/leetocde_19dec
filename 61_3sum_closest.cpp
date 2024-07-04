class Solution {
public:
    int threeSumClosest(vector<int>& ar, int k) {
        int dif = INT_MAX;
        int n = ar.size();
        sort(ar.begin(),  ar.end());
        int ans ;
        for (int i = 0; i <= n - 3; i++) {
            if ( (i > 0) && (ar[i] == ar[i - 1]))continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                // cout<<"start0"<<endl;
                //                 cout<<"l:"<<l<<",r:"<<r<<",i:"<<i<<endl;

                while ( ((r + 1) < n) && (ar[r] == ar[r + 1])) {r -= 1; if (l >= r)break;}
                if (l >= r)break;
                while (((l - 1) > i) && (ar[l] == ar[l - 1])) {l += 1; if (l >= r)break;}
                if (l >= r)break;
                // cout<<"l:"<<l<<",r:"<<r<<",i:"<<i<<endl;
                int temp = ar[i] + ar[l] + ar[r];
                // cout<<"temp:"<<temp<<endl;
                if (temp > k)r -= 1;
                else if (temp < k)l += 1;
                else {l += 1; r -= 1;}
                if (dif > abs(k - temp)) {dif = abs(k - temp); ans = temp;}
                // cout<<"dif:"<<dif<<endl;
            }

        } return ans ;
    }
};