#include <iostream>
#include <string>

int main() {
    std::string str;
    std::string substr;
    while(std::cin>>str>>substr){
        if (str.empty()) {
            std::cout << substr << '\n';
            return 0;
        }

        size_t idx = 0;
        char c_max = str[0];
        for (size_t i = 1; i < str.size(); ++i) {
            if (str[i] > c_max) {
                c_max = str[i];
                idx = i;
            }
        }
        str.insert(idx + 1, substr);
        std::cout << str << '\n';
    }
}