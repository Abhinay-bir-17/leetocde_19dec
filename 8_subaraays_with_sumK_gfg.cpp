//User function Template for C++
class Solution {
public:
  int findSubArraySum(int ar[], int n, int k) {
    int cumSum = 0; unordered_map<int, int>mp;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      cumSum += ar[i];
      if ( mp[cumSum - k])ans += mp[cumSum - k]; /* this adds all combinations like
      for  0 0 0 5 ==>  0 0 5, 0 5, 5; we need 0 0 0 5. basically this line takes care of
      ar[i]== k, think using the exampel : 0 0 5 5  0  0
                                           0 0 5 10 10 10
      */
      if (cumSum == k) { // this adds 1 for the subarray from 0th el to el where
        // cumSum = k;
        ans += 1;
      }
      mp[cumSum] += 1;
    }
    return ans;
  } // input : 0 0 5 5 0 0
};