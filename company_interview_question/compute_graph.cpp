#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
题目：给你一些神经网络的layer，求出在forward过程中，layer的先后计算顺序
*/

template<class T ,class E>
struct Edge		//边界点的定义
{
	int dest;	//边的另一顶点位置
	E  cost;	//权值
	Edge<T ,E> *link;//下一条边链指针
	Edge(){}		//构造函数
	Edge(int num , E weight):dest(num),cost(weight),link(NULL){} //构造函数
	bool operator != (Edge<T,E> &R)const{	//判边不等否
		return (dest!=R.dest)? true:false;
	}
};

template<class T ,class E >
struct Vertex{	//顶点的定义
	T data;		//顶点名字
	Edge<T ,E> *adj;	//边链表的头指针
};

template<class T>
struct Edge{
    Node<T>* _node_1;
    Node<T>* _node_2;
    string _name;

    Edge(string name, ){

    }

};

template<class T>
class Graph{
public:
    vector<GraphNode<T>*> _head_nodes_vec;

};

int main() {
    typedef vector<float> VecFloat;

    VecFloat x1 = {1, 1, 1};
    VecFloat x2 = {2, 2, 2};
    VecFloat x3 = {3, 3, 3};
    VecFloat x4 = {4, 4, 4};
    VecFloat x5 = {5, 5, 5};
    VecFloat x6 = {6, 6, 6};
    Graph<VecFloat> G;

    G.insert_node(x1, "slot1");
    G.insert_node(x2, "slot2");
    G.insert_node(x3, "layer_x3", "slot2");
    G.insert_node(x5, "layer_x5", "layer_x3");
    G.insert_node(x4, "layer_x4", "slot2");
    
    G.bfs_solve();

    return 0;
}

//====================
template<class T>
string vec2str(T& a) {
    int n = a.size();
    string res;
    for (int i = 0; i<n-1; i++) {
        res += to_string(a[i]) + ", ";
    }
    res += to_string(a[n-1]);
    return res;
}

