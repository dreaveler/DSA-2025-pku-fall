#include <iostream>
#include <vector>
#include <stack>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> seq[i];
    }

    std::stack<int> s;
    std::vector<std::string> ops;
    int idx = 0; // 输出序列索引
    int next = 1; // 下一个入栈元素
    bool possible = true;

    while (idx < n) {
        // 入栈直到栈顶匹配当前输出元素或无法入栈
        while (next <= n && (s.empty() || s.top() != seq[idx])) {
            s.push(next);
            ops.push_back("PUSH " + std::to_string(next));
            next++;
        }
        // 检查是否能弹出
        if (s.empty() || s.top() != seq[idx]) {
            possible = false;
            break;
        }
        // 弹出
        ops.push_back("POP "+std::to_string(s.top()));
        s.pop();
        idx++;
    }

    if (possible && s.empty()) {
        for (const auto& op : ops) {
            std::cout << op << '\n';
        }
    } else {
        std::cout << "NO\n";
    }

    return 0;
}