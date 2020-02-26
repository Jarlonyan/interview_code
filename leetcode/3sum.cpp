
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> three_sum(vector<int>& s) {
    vector<vector<int>> ret;
    int n = s.size();

    sort(s.begin(), s.end());
    for(int i=0; i<n-2; ++i) {
        int j=i+1, k=n-1;
        while(j<k) {
            auto sum = s[i]+s[j]+s[k];
            if(sum < 0) {
                //++j;
                while(s[j]==s[j-1] && j<k) ++j;
            }
            else if(sum > 0) {
                //--k;
                while(s[k]==s[k+1] && j<k) --k;
            }
            else{
                ret.push_back({s[i], s[j], s[k]});
                ++j;
                --k;
                while(s[j]==s[j-1] && s[k]==s[k-1] && j<k) ++j;
            }
        }
    }
    return ret;
}

int  main() {
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    auto ret = three_sum(a);
    for(int i=0; i<ret.size(); ++i) {
        for(int j=0;j<ret[i].size(); ++j) {
            cout<< ret[i][j] <<" ";
        } 
        cout<<endl;
    }
    return 0;
}


