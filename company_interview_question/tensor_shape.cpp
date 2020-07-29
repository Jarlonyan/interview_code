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


int main() {
    tensor_shape("[[[1,2,3],[4,5,6]]]");
    tensor_shape("[[[1],[2],[3]],[[4],[5],[6]]]");
    return 0;
}


