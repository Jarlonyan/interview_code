#include <iostream>
#include<stack>
#include<vector>

using namespace std;

int tensor_shape(string s) {
    int n = s.length();
    char st[1000];
    int top = -1;
    int a[1000];
    int b[1000];
    int f = 0;
    for(int i=0;i<=100;i++) a[i] = 0, b[i] = 0;
    
    for(int i=0; i<n; i++) {
        if(s[i] == '[') {
            st[++top] = s[i];
        }
        if(s[i]==']') {
            b[top] = max(b[top], a[top] + 1);
            a[top] = 0;
            top--;
        }
        if(s[i]==',') {
            a[top]++;
        }
    }
    cout<<'(';
    for(int i=0; i<100; i++) {
        if(b[i]>0) {
            if(i>0)cout<<",";
            cout<<b[i];
        }
        else
            break;
    }
    cout<<')';
}



int main() {
    //tensor_shape("[[[1,2,3],[4,5,6]]]");
    tensor_shape("[[[1],[2],[3]],[[4],[5],[6]]]");
    return 0;
}


