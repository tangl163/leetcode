/**
 * [reference](https://leetcode.com/problems/basic-calculator/discuss/62361/Iterative-Java-solution-with-stack)
 */
class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int sign, number, result;

        sign = 1;
        number = result = 0;

        for (auto token : s) {
            if (token >= '0' && token <= '9') {
                number = number * 10 - '0' + token;
            } else if (token == '+') {
                result += number * sign;
                number = 0;
                sign = 1;
            } else if (token == '-') {
                result += number * sign;
                number = 0;
                sign = -1;
            } else if (token == '(') {
                stack.push(result);
                stack.push(sign);
                sign = 1;
                result = 0;
                number = 0;
            } else if (token == ')') {
                result += sign * number;
                number = 0;
                result *= stack.top();
                stack.pop();
                result += stack.top();
                stack.pop();
            }
        }

        if (number != 0) {
            result += number * sign;
        }

        return result;
    }
};
