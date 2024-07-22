// recursive soln
class Solution {
public:
	int code(int startValue, int target) {
		if (startValue > target)return (startValue - target);
		else if (startValue == target)return 0;

		if ( target & 1) {
			return 1 + code(startValue, target + 1);
		} else {
			return 1 + code(startValue, target / 2);
		}
	}
	int brokenCalc(int startValue, int target) {
		return code(startValue, target);
	}
};
// iterative soln
class Solution {
public:
	int brokenCalc(int startValue, int target) {

		int moves = 0;
		for (; target > startValue;) {
			moves = moves + 1;
			if (target & 1) target += 1;
			else target = target / 2;
		}
		moves += (startValue - target);
		return moves;
	}
};
// write a bfs soln for this