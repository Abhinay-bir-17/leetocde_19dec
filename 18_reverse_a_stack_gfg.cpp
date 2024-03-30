// wrote recursion on my own
class Solution {
public:
	void code(stack<int>&st, stack<int>&temp) {
		if (st.size() == 1) {
			return;
		}
		int top_el = st.top();
		st.pop();
		// now from here we assume remaining el in stack r reversed
		code(st, temp);
		while (!st.empty()) {
			int x = st.top(); st.pop(); temp.push(x);
		}
		st.push(top_el);
		while (!temp.empty()) {
			int x = temp.top(); temp.pop(); st.push(x);
		}
	}
	void Reverse(stack<int> &st) {

		stack<int> temp;
		code(st, temp); // st is reversed
	}
};
/*
now a solution s.t extra space is removed, we do this by writing the  logic of
adding the current element at bottom of stacks using recursion rather than
using an extra stack.
*/
class Solution {
public:
	void code1(stack<int>&st, int el) {
		if (st.size() == 0) {
			st.push(el); return;
		}
		int top_el = st.top(); st.pop();
		code1(st, el);// this ensures the el is at bottom
		st.push(top_el);
	}
	void code(stack<int>&st) {
		if (st.size() == 1)return;
		int top_el = st.top();
		st.pop();
		code(st); //this ensures the elements after the pooped el r reversed using recu
		code1(st, top_el); // logic to remove all el from st to add top_el at bottom nd
		// then re add all el back in same order
	}
	void Reverse(stack<int> &st) {
		code(st);
	}
};













