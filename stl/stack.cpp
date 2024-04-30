#include <iostream>
#include <stack>
#include <string>

class BracketValidator {
private:
    std::stack<char> stack;

    // 检查两个括号是否匹配
    bool isMatch(char l, char r) {
        return (l == '(' && r == ')') || (l == '{' && r == '}') || (l == '[' && r == ']');
    }

public:
    // 构造函数
    BracketValidator() {}

    // 析构函数
    ~BracketValidator() {}

    // 验证括号是否有效的函数
    bool validate(const std::string &s) {
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stack.empty() || !isMatch(stack.top(), c)) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }
};

int main() {
    BracketValidator validator;
    std::string s1 = "()";
    std::string s2 = "()[]{}";
    std::string s3 = "(]";

    std::cout << "Example 1: " << (validator.validate(s1) ? "true" : "false") << std::endl;
    std::cout << "Example 2: " << (validator.validate(s2) ? "true" : "false") << std::endl;
    std::cout << "Example 3: " << (validator.validate(s3) ? "true" : "false") << std::endl;

    return 0;
}