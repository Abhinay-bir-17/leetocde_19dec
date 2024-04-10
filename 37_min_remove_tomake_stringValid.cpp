//leetcode potd
class Solution {
public:
	string minRemoveToMakeValid(string s) {
		int n = s.length();
		stack<int> st;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(')st.push(i);
			else if (s[i] == ')') {
				if (st.empty()) {//if stack is empty
					s[i] = '#'; // for extra closing brackets
				} else {
					st.pop();// no opening bracket left for closed brackt
				}
			}
		}
		while (!st.empty()) { //returns true if stack is empty
			// this loop does for extra opening brackets
			int ind = st.top();
			st.pop();
			s[ind] = '#';
		}
		string ans = "";
		for (int i = 0; i < n; i++) {
			if (s[i] != '#')ans.push_back(s[i]);
		}
		return ans;
	}
};