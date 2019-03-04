
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct GraphNode {
    vector<float> data_vec;
    vector<GraphNode*> input;
    vector<GraphNode*> output; 
};



vector<GraphNode*> bfs_solve(GraphNode* first) {
    vector<GraphNode*> res;
    if(first==NULL) {
        return res;
    }

    queue<GraphNode*> que;
    que.push(first);

    while(!que.empty()) {
        GraphNode* p = que.top();
        que.pop();
        //print p
        res.push_back(p);
        for(int i=0; i < p->output.size(); ++i) {
            que.push(p->output[i]);
        }
    }

    return 0;
}


int topology_sort() {
    
}


int main() {
    return 0;
}


