class Solution {
public:
    int mySqrt(int x) {
        long long int l = 0, r = 65536;
        while (l <= r) {
            long long int m = (l + r) / 2;
            long long int temp = m * m;
            if (temp == x)return m;
            else if (temp > x)r = m - 1;
            else l = m + 1;
        }
        long long int temp = l * l;
        if (temp < x)return l;
        else return r;
    }
};