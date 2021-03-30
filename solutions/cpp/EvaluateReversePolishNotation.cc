class Solution {
public:
    enum class Kind {
        OPERATOR,
        OPERAND
    };

    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;

        for (auto &token : tokens) {
            auto k = kind(token);

            if (k == Kind::OPERAND) {
                stack.push(std::stoi(token));
            } else {
                auto op2 = stack.top();
                stack.pop();
                auto op1 = stack.top();
                stack.pop();

                switch (token[0]) {
                case '+':
                    stack.push(op1 + op2);
                    break;
                case '-':
                    stack.push(op1 - op2);
                    break;
                case '*':
                    stack.push(op1 * op2);
                    break;
                case '/':
                    stack.push(op1 / op2);
                default:
                    // error
                    break;
                }
            }
        }

        return stack.top();
    }

private:
    Kind kind(const std::string &token) {
        if (token.length() == 1) {
            switch (token[0]) {
            case '+':
            case '-':
            case '*':
            case '/':
                return Kind::OPERATOR;
            default:
                return Kind::OPERAND;
            }
        }

        return Kind::OPERAND;
    }
};
