#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

/*
    f[i][j] = max(f[i-1][j'] + |j' - j|) + p[i][j]    j'取值为0~cols - 1
    case 1： j' ≤ j
        f[i][j] = max(f[i-1][j'] - j') + p[i][j] + j
    case 2: j' > j
        f[i][j] = max(f[i-1][j'] + j') + p[i][j] - j
*/

long long copy_web(vector<vector<int>> &points){
    int m = points.size(), n = points[0].size();
    vector<long long> dp(points[0].begin(), points[0].end());

    for(int i = 1;i<m;++i){
        long long maxL = LONG_MIN, maxR = LONG_MIN;
        vector<long long> temp = dp;
        for(int j = 0;j<n;++j){
            maxL = std::max(maxL, temp[j] + j);
            dp[j] = std::max(dp[j], points[i][j] - j + maxL);
        }
        for(int j = n - 1;j>=0;--j){
            maxR = std::max(maxR, temp[j] - j);
            dp[j] = std::max(dp[j], points[i][j] + j + maxR);
        }
    }
    return *std::max_element(dp.begin(), dp.end());
}


long long maxPoints(vector<vector<int>> &points){
    int rows = points.size(), cols = points[0].size();

    std::pair<long long, long long> f(INT_MIN, INT_MIN);
    long long res = INT_MIN;
    vector<std::pair<long long, long long>> last(cols);

    for(int i = 0;i < cols; ++i){
        res = std::max(res, (long long)points[0][i]);
        f.first = std::max(f.first, (long long)points[0][i] - i);
        f.second = std::max(f.second, (long long)points[0][i] + i);
    }
    //std::cout<<"f.first, f.second: "<<f.first<<" , "<<f.second<<std::endl;

    for(int i = 1;i<rows;++i){
        long long first = INT_MIN, second = INT_MIN;
        for(int j = 0;j < cols; ++j){
            int val = std::max(f.first + points[i][j] + j, f.second + points[i][j] - j);
            res = std::max(res, (long long)val);
            first = std::max(first, (long long)val - j);
            second = std::max(second, (long long)val + j);
        }
        f.first = first;
        f.second = second;
        //std::cout<<"f.first, f.second: "<<f.first<<" , "<<f.second<<std::endl;
    }
    return res;
}

int main(){
    {
        vector<vector<int>> nums{
            {1,2,3},
            {1,5,1},
            {3,1,1}
        };
        std::cout<<maxPoints(nums)<<std::endl;
        std::cout<<copy_web(nums)<<std::endl;
    }

    {
        vector<vector<int>> nums{
            {1,5},
            {2,3},
            {4,2}
        };
        std::cout<<maxPoints(nums)<<std::endl;
        std::cout<<copy_web(nums)<<std::endl;
    }

    return 0;
}

