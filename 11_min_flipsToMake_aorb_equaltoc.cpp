class Solution {
public:
	int minFlips(int a, int b, int c) {
		int leftMostBit;
		int ind = 0;
		int temp = a;
		// going thru a
		while (temp) {
			if (temp & 1)leftMostBit = ind;
			ind += 1;
			temp = temp >> 1;
		}
		// going thru b
		temp  = b; ind = 0;
		while (temp) {
			if (temp & 1)leftMostBit = max(leftMostBit, ind);
			ind += 1; temp = temp >> 1;
		}
		// going thru c
		temp  = c; ind = 0;
		while (temp) {
			if (temp & 1)leftMostBit = max(leftMostBit, ind);
			ind += 1; temp = temp >> 1;
		}
		ind = 0;
		int ans = 0;
		while (ind <= leftMostBit) {
			temp = 0; temp +=  (b & 1) + (a & 1);
			if (c & 1) {if (temp == 0)ans += 1;}
			else {if (temp == 1)ans += 1; else if (temp == 2)ans += 2;}
			ind += 1;
			a = a >> 1; b = b >> 1; c = c >> 1;
		} return ans;
	}
};


/* another approach to solve this  from codestorywithMIK: count seet bits in
	((a|b)^c)  and in (a&b)where a&b is used to find bits where both a and b have 1 in
	the same positions
*/


class Solution {
public:
	int minFlips(int a, int b, int c) {
		int temp = ((a | b)^c);
		int temp1 = ((a & b)&temp);
		return () + ();
	}
};