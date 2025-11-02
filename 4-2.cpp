#include<iostream>
#include<string>
#include<vector>

int main(){
    while(true){
        std::string str;
        std::cin>>str;
        if((str.length()==1)&&str[0]=='.') break;
        int len = str.length();
        std::vector<int>prefix(len,0);
        int k = 0;
        for(int i = 1 ; i < len ; i++){
            while(k > 0 && str[k] != str[i]){
                k = prefix[k-1];
            }
            if(str[k] == str[i]){
                k += 1;
            }else k = 0;
            prefix[i] = k;
        }
        int period_len = len - prefix[len-1];
        if(len % period_len == 0){
            std::cout<<len/period_len<<'\n';
        }else{
            std::cout<<1<<'\n';
        }
    }
}
//借助kmp算法