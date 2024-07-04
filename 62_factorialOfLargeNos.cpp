//User function template for C++

class Solution {
public:
    // do check out video of mik for this problem
    void code(vector<int>&ar, int mul, int&size) {
        int carry = 0;
        for (int i = 0; i < size; i++) {
            int temp = ar[i] * mul;
            temp = temp + carry;
            ar[i] = temp % 10;
            carry = temp / 10;
        }
        while (carry > 0) {
            ar[size] = carry % 10;
            size += 1;  carry = carry / 10;
        }
    }
    vector<int> factorial(int n) {
        vector<int> ar(2600, 0);
        ar[0] = 1;
        int size = 1;
        for (int i = 2; i <= n; i++) {
            code(ar, i, size);
        }
        // put the reverse in ans
        vector<int> ans;
        for (int i = size - 1; i >= 0; i--)ans.push_back(ar[i]);
        return ans;
    }
};