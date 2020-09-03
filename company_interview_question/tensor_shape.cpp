/**
TensorFlow中tensor的shape：以字符串形式给出多维数组，求其构造的tensor的shape。比如：a=tf.Variable([[[1,2,3],[4,5,6]]])中a.shape=(1, 2, 3) ，但是多维数组是以字符串形式给出。
输入：字符串 "[[[1,2,3],[4,5,6]]]"
输出：(1,2,3)。

输入："[[[1],[2],[3]],[[4],[5],[6]]]"
输出：(2,3,1)
*/

#include <iostream>
#include<stack>
#include<vector>

using namespace std;

int tensor_shape(string s) {
    int n = s.length();
    int top = -1;
    vector<int> temp(1000), res(1000);
    
    for(int i=0; i<n; i++) {
        if(s[i] == '[') {
            top++;
        }
        if(s[i] == ']') {
            res[top] = max(res[top], temp[top] + 1);
            temp[top] = 0;
            top--;
        }
        if(s[i] == ',') {
            temp[top]++;
        }
    }

    cout<<'(';
    for(int i=0; i<100; i++) {
        if(res[i]>0) {
            if(i>0) cout << ",";
            cout << res[i];
        }
        else
            break;
    }
    cout<<')'<<endl;
}


int get_shape(string str) {
    if (str.size() == 0) return 0;
    int  size = 0;
    while (str[size] == '[') {
        size++;
    }

    vector<int> res(size, 1);
    int limit = size-1;

    stack<char> stack;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '[') {
            stack.push('[');
        } else if (str[i] == ']') {
            stack.pop();
        } else if (str[i] == ',') {
            int index = stack.size() - 1;
            if (index <= limit) {
                res[index]++;
                limit = index;
            }
        }
    }

    cout<<str<<"=(";
    for (int i=0;  i<res.size()-1; ++i)
        cout<<res[i]<<",";
    cout<<res[res.size()-1]<<")"<<endl;
}

int get_shape2(string str) {
    if (str.size() == 0) return 0;
    int  size = 0;
    while (str[size] == '[') {
        size++;
    }
    vector<int> res(size);
    stack<char> stk;

    for(int i=0; i<str.length(); ++i) {
        if(str[i] == '[') {
            stk.push('[');
            res[stk.size() - 1] = 1;
        }
        else if(str[i] == ',') {
            res[stk.size() - 1] += 1;
        }
        else if(str[i] == ']') {
            stk.pop();
        }
    }

    cout<<str<<"=(";
    for (int i=0;  i<res.size()-1; ++i)
        cout<<res[i]<<",";
    cout<<res[res.size()-1]<<")"<<endl;
}

int main() {
    //tensor_shape("[[[1,2,3],[4,5,6]]]");
    //tensor_shape("[[[1],[2],[3]],[[4],[5],[6]]]");
    get_shape2("[[[0.7, 7, 7],[ 4, 5, 6]]]");
    get_shape2("[[[0.7],[0.7],[3]],[[4],[5],[6]]]");
    //get_shape("[[[1,2,3]],[[4,5,6]]]");
    return 0;
}


