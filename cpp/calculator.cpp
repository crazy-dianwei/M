#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int process_pathesis(const string& s, int &i, vector<int> &symbols){
        if(i >= s.size())return 0;
        if(s[i] != '(')return 0;
        stack<int> nums;
        stack<char> ops;
        for(int j = i + 1;j<s.size();){
            if(s[j] == ')'){
                i = j + 1;
                if(!ops.empty()){                    
                    //process 
                    char op = ops.top();
                    ops.pop();
                    int second = nums.top();
                    nums.pop();
                    int first = nums.top();
                    nums.pop();
                    if(op == '+'){
                        first += second;
                    }
                    else if(op == '-'){
                        first -= second;
                    }
                    nums.push(first);
                }
                cout<<"process_pathesis return: "<<nums.top()<<" .i: "<<i<<endl;
                return nums.top();
            }
            else if(s[j] == '('){
                nums.push(process_pathesis(s, j, symbols));
            }
            else if(s[j] == ' '){
                ++j;
            }
            else if(s[j] == '+' || s[j] == '-'){
                if(symbols[j]){
                    //cal number
                    bool flag = s[j] == '-' ? false : true;
                    ++j;
                    int val = 0;
                    while(j < s.size() && s[j] >= '0' && s[j] <= '9'){
                        val = 10 * val + (int)(s[j] - '0');
                        ++j;
                    }
                    val = flag ? val : -val;
                    nums.push(val);
                }
                else{
                    if(!ops.empty()){
                        //cal
                        char op = ops.top();
                        ops.pop();
                        int second = nums.top();
                        nums.pop();
                        int first = nums.top();
                        nums.pop();
                        if(op == '+'){
                            first += second;
                        }
                        else if(op == '-'){
                            first -= second;
                        }
                        nums.push(first);
                    }
                    ops.push(s[j]);
                    ++j;
                }            
            }
            else{
                int val = 0;
                while(j < s.size() && s[j] >= '0' && s[j] <= '9'){
                    val = 10 * val + (int)(s[j] - '0');
                    ++j;
                }
                nums.push(val);
            }
        }
        return 0;
    }


    int calculate(string s) {
        //method2
        {
            /*
                + - ( ) 0~9
            */

            int len = s.size();
            vector<int> symbols(len, false);
            stack<char> sys;
            for(int i = len - 1;i>=0;){
                if(s[i] == '+' || s[i] == '-'){
                    if(!sys.empty()){
                        symbols[sys.top()] = true;
                        sys.pop();
                    }
                    sys.push(i);
                    --i;
                }
                else if(s[i] == '(' || s[i] == ')' || s[i] == ' '){
                    --i;
                }
                else{
                    while(i >= 0 && s[i] >= '0' && s[i] <= '9'){
                        --i;
                    }
                    if(!sys.empty())sys.pop();
                }
            }
            if(!sys.empty()){
                symbols[sys.top()] = true;
            }
            for(int i = 0;i<len;++i){
                cout<<symbols[i]<<" ";
            }
            cout<<endl;

            stack<int> nums;
            stack<char> ops;

            for(int i = 0;i<len;){
                if(s[i] == '+' || s[i] == '-'){
                    if(symbols[i]){
                        bool flag = s[i] == '-' ? false : true;
                        ++i;
                        int val = 0;
                        while(i < len && s[i] >= '0' && s[i] <= '9'){
                            val = 10 * val + (int)(s[i] - '0');
                            ++i;
                        }
                        nums.push(flag ? val : -val);
                    }
                    else{
                        if(!ops.empty()){
                            //cal
                            char op = ops.top();
                            ops.pop();
                            int second = nums.top();
                            nums.pop();
                            int first = nums.top();
                            nums.pop();
                            if(op == '+'){
                                first += second;
                            }
                            else if(op == '-'){
                                first -= second;
                            }
                            nums.push(first);
                        }
                        ops.push(s[i]);
                        ++i;
                    }
                }
                else if(s[i] == ' '){
                    ++i;
                }
                else if(s[i] == '('){
                    nums.push(process_pathesis(s, i, symbols));
                }
                else if(s[i] >= '0' && s[i] <= '9'){
                    int val = 0;
                    while(i < len && s[i] >= '0' && s[i] <= '9'){
                        val = 10 * val + (int)(s[i] - '0');
                        ++i;
                    }
                    nums.push(val);
                }
            }

            if(!ops.empty()){
                //cal
                char op = ops.top();
                ops.pop();
                int second = nums.top();
                nums.pop();
                int first = nums.top();
                nums.pop();
                if(op == '+'){
                    first += second;
                }
                else if(op == '-'){
                    first -= second;
                }
                nums.push(first);
            }
            return nums.top();
        }
    }
};

int main(){
    string s = "(1)";
    Solution so;
    cout<<so.calculate(s)<<endl;
    return 0;
}


