
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> subset(vector<int> a) {
    vector<vector<int>> ret;
    
    return ret;
}

int  main() {
    vector<int> a = {1,2,3,4,5,6,7};

    auto ret = subset(a);
    for(int i=0; i<ret.size(); ++i) {
        for(int j=0; j<ret[i].size(); ++j) {
            cout<< ret[i][j]<<", ";
        }
        cout<<endl;
    }
    return 0;
}


