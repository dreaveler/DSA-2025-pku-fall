#include<iostream>
#include<string>
#include<stack>

int main(){
    std::string str1,str2;
    while(std::cin>>str1>>str2){
        if (str1.empty()) {
            std::cout << "Yes" << std::endl;
            continue;
        }

        int i = 0, j = 0;
        int len1 = str1.length(), len2 = str2.length();
        
        while (i < len1 && j < len2) {
            if (str1[i] == str2[j]) {
                i++;
            }
            j++;
        }

        if (i == len1) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}
//双指针