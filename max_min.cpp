#include <iostream>
#include <deque>
#include <vector>
#include <time.h>

using namespace std;

int max_min_cnt(vector<int> &nums, int target){
    //cal numbers that max - min <= target
    int len = nums.size();
    if(len == 0)return 0;
    deque<int> maxs, mins;
    int start = 0, end = 0, res = 0;
    while(end < len){
        //update maxs
        while(!maxs.empty() && nums[maxs.back()] <= nums[end]){
            maxs.pop_back();
        }
        maxs.push_back(end);

        //update mins
        while(!mins.empty() && nums[mins.back()] >= nums[end]){
            mins.pop_back();
        }
        mins.push_back(end);

        while(!maxs.empty() && !mins.empty() && nums[maxs.front()] - nums[mins.front()] > target){
            res += (end - start);
            if(start == maxs.front()){
                maxs.pop_front();
            }
            if(start == mins.front()){
                mins.pop_front();
            }
            ++start;
        }
        ++end;
    }

    while(start < len){
        res += (len - start++);
    }
    return res;
}


int main(){
    srand(time(NULL));

    int len = rand() % 5 + 2;
    cout<<"len: "<<len<<endl;
    vector<int> nums(len);
    for(int i = 0; i < len;++i){
        nums[i] = rand() % 10;
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    int target = rand() % 10;
    cout<<"target: "<<target<<endl;
    cout<<max_min_cnt(nums, target)<<endl;
    return 0;
}


