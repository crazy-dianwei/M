/*
    重复数：
    1. 287，寻找重复数：一个长度为n+1的数组，其中元素的大小为1~n，且只有一个元素重复，找出这个重复数
    2. 442，数组中重复的数据：一个长度为n的数组，其中元素大小为1~n，其中有些元素出现两次而其他元素出现一次，找出所有出现两次的元素





*/


#include <vector>
#include <iostream>

using namespace std;


    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0;i<len;++i){
            nums[nums[i] % 8 - 1] += len;
        }

        vector<int> res;
        for(int i = 0;i<len;++i){
            if(nums[i] > 2 * len){
                res.push_back(i+1);
            }
        }
        return res;
    }

int main(){
    vector<int> nums{4,3,2,7,8,2,3,1};
    auto res = findDuplicates(nums);
    cout<<"nums in nums: "<<endl;
    for(auto n: nums){
        cout<<n<<" ";
    }
    cout<<endl;
    for(auto n: res){
        cout<<n<<" ";
    }
    cout<<endl;

    return 0;
}

