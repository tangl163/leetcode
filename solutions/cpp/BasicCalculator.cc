class Solution {
public:
    enum class Kind {
        OPERATOR,
        OPERAND,
        PARENTHESES
    };

    int calculate(string s) {
        int result = 0;
        stack<int> stack;
        auto postfix = infixToPostfix(s);

        for (auto &token : *postfix) {
            auto kd = kind(token);

            if (kd == Kind::OPERAND) {
                stack.push(std::stoi(token));
            } else {
                auto op2 = stack.top();
                stack.pop();
                auto op1 = stack.top();
                stack.pop();

                if (token[0] == '+') {
                    stack.push(op1 + op2);
                } else {
                    stack.push(op1 - op2);
                }
            }
        }

        return stack.top();
    }
private:
    std::shared_ptr<vector<string>> infixToPostfix(const string s) {
        string tmp;
        stack<char> stack;
        char token, preToken = 0;
        auto input = std::istringstream(s);
        auto ret = std::make_shared<vector<string>>();

        while (input >> token) {
            auto kd = kind(token);

            if (kd == Kind::OPERATOR) {
                if (preToken == 0 || preToken == '(') {
                    ret->push_back("0");
                }

                if (!tmp.empty()) {
                    ret->push_back(tmp);
                    tmp.clear();
                }

                if (stack.empty()) {
                    stack.push(token);
                } else {
                    auto top = stack.top();

                    while (kind(top) == Kind::OPERATOR && !stack.empty()) {
                        ret->emplace_back(1, top);
                        stack.pop();

                        if (stack.empty()) {
                            break;
                        }

                        top = stack.top();
                    }

                    stack.push(token);
                }
            } else if (kd == Kind::OPERAND) {
                tmp.append(1, token);
            } else {
                if (!tmp.empty()) {
                    ret->push_back(tmp);
                    tmp.clear();
                }

                if (token == '(') {
                    stack.push(token);
                } else {
                    auto top = stack.top();
                    while (top != '(') {
                        ret->emplace_back(1, top);
                        stack.pop();
                        top = stack.top();
                    }

                    stack.pop();
                }
            }

            preToken = token;
        }

        if (!tmp.empty()) {
            ret->push_back(tmp);
        }

        while (!stack.empty()) {
            ret->emplace_back(1, stack.top());
            stack.pop();
        }

        return ret;
    }

    Kind kind(const char token) {
        switch (token) {
        case '+':
        case '-':
            return Kind::OPERATOR;
        case '(':
        case ')':
            return Kind::PARENTHESES;
        default:
            return Kind::OPERAND;
        }
    }

    Kind kind(const string &token) {
        if (token.size() == 1) {
            if (token[0] == '+' || token[0] == '-') {
                return Kind::OPERATOR;
            }
        }

        return Kind::OPERAND;
    }
};
