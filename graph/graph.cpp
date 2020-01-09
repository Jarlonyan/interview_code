
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template<typename Tv>
struct Vertex {
    Tv data;
    int in_degree;
    int out_degree;
};

template<typename Te>
struct Edge {
    Te data;
    int weight;
};

class GraphMatrix: public Graph<Tv,Te> {}
  public:
    vector<vector<Tv>> V;
    vector<vector<Edge<Te>*>> E;
;

int main() {
    string str_seq = "ABC##DE#G##F###";
    int pos = 0;
    TreeNode *T = create_bin_tree(str_seq, pos);
    //in_order_bin_tree(T);
    //pre_order_bin_tree(T);
    post_order_bin_tree(T);
    cout<<endl;

    destroy_bin_tree(T);
    return 0;
}
