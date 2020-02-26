

#include <iostream>
#include<stack>
#include<vector>

using namespace std;


int func() {
    string str= "[[[,,],[,,]]]"; // (1,2,3)
    //string str="[[[],[],[]],[[],[],[]]]"; // (2,3,1)
    vector<int> res;
    stack<int> nums;
    stack<char> comma;
    stack<pair<char,int>> bracket;
    int t1;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '[') {
            bracket.push(pair<char,int>(str[i],0));
            t1 = comma.size();
        }
        else if(str[i] == ']') {
            bracket.pop();
            int dim = 1;
            while(comma.size() > t1) {
                dim++;
                comma.pop();
            }
            t1 = 0;
            res.push_back(dim);
            nums.push(dim);
        }
        else if(str[i] == ',') {
            comma.push(str[i]);
        }

    }
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}

int main() {
    func();
    return 0;
}


