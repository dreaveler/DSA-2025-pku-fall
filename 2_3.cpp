#include<iostream>
#include<vector>

int main(){
    int n;
    std::cin>>n;
    auto N = 2*n -1;
    auto m = std::vector<std::vector<int>>(N, std::vector<int>(N));
    int v = 1;
    int x = 0;
    int y = N/2;
    while(v != N*N){
        m[x][y] = v;
        int nx = (x - 1 + N) % N;
        int ny = (y + 1)%N;
        if(m[nx][ny]!=0){
            x = x + 1;
        }else{
            x = nx;
            y = ny;
        }
        v+=1;
    }
    m[x][y] = v;
    for(int i = 0;i < N;i++){
        for(int j = 0 ; j < N;j++){
            std::cout<<m[i][j];
            if(j != N - 1) std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}