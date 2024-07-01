class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int k) {
        // wht is messi doin mate wtf mate
        vector<int> ans;
        int n = ar.size();
        for (int i = 0; i < n; i++) {
            int temp = k - ar[i];
            // find temp in ar
            int flag = 0;
            int ii = 0, j = n - 1;
            while (ii <= j) {
                int mid = (ii + j) / 2;

                if (ar[mid] == temp && mid != i) {ans.push_back(i + 1); ans.push_back(mid + 1); flag = 1; break;}
                else if (ar[mid] <= temp)ii = mid + 1;
                else j = mid - 1;
            } if (flag) {
                break;
            }
        } return ans;
    }
};
// focus  here abhinay bir
class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int k) {
        int n = ar.size();
        int i = 0, j = n - 1;
        int sum = 0;
        while (i < j) {
            sum = ar[i] + ar[j];
            if (sum > k)j -= 1;
            else if (sum < k)i += 1;
            else {
                return {i + 1, j + 1};
            }
        } return {};
    }
};