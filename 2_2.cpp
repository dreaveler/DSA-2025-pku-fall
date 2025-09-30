#include<iostream>
#include<map>
#include<algorithm>

static std::map<int, long long> read_poly() {
    std::map<int, long long> p;
    int a, b;
    while (true) {
        std::cin>>a>>b;
        if (b < 0) break;
        p[b] += a; 
    }
    return p;
}

int main(){
    int num;
    std::cin>>num;
    while(num--){
        auto p1 = read_poly();
        auto p2 = read_poly();
        for (const auto& kv : p2) {
            p1[kv.first] += kv.second;
        }
        for (auto it = p1.rbegin(); it != p1.rend(); ++it) {
            if (it->second == 0) continue;
            std::cout << "[ " << it->second << " " << it->first << " ] ";
        }
        std::cout << '\n';
    }
}