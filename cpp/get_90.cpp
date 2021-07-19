#include <vector>
#include <iostream>

void method1(int start, int end, int target, int &res){
    if(target == 0){
        ++res;
        return;
    }

    if(start > end || target < 0){
        return;
    }

    for(int i = 0;i<=10;++i){
        method1(start + 1, end, target - i, res);
    }
}


int get_90(int target){
    int res = 0;
    std::vector<std::vector<int>> dp(10, std::vector<int>(target + 1, 0));

    
    for(int i = 0;i<10;++i){
        dp[i][0] = i + 1;
        dp[0][i+1] = 1;
    }

    for(int i = 1;i<10;++i){
        for(int j = 1;j<=(i+1)*10 && j < target + 1 ;++j){
            for(int score = 0;score <= 10;++score){
                dp[i][j] += (j >= score ? dp[i-1][j - score] : 0);
            }
        }
    }

    return dp[9][target];
    {
        method1(1, 10, target, res);
        return res;
    }
}


int main(){
    std::cout<<get_90(90)<<std::endl;

    return 0;
}

