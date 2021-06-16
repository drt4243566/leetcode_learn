#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
using namespace std;
/**********图相关结构定义*************/
struct Edge;
struct Node {
	int value;
	int in;
	int out;
    bool isVis;
	vector<Node*> nexts;
	vector<Edge*> edges;
	Node(int val) {
		value = val;
		in = 0;
		out = 0;
        isVis = false;
	}
};
struct Edge {
	int weight;
	Node *from;
	Node *to;
	Edge(int w, Node *f, Node *t) {
		weight = w;
		from = f;
		to = t;
	}
};
struct Graph {
	unordered_map<int, Node*> nodes;
	unordered_set<Edge*> edges;
};
struct Info {
    int no;
    int yes;
    Info(int n, int y) {
        no = n;
        yes = y;
    }
};
Graph* createGraphByMatrix(vector< vector<int> > v) {
	/*every row [from  to  weight]*/
	Graph *graph = new Graph;
	for (int i = 0; i < v.size(); i++) {
		int from = v[i][0];
		int to = v[i][1];
		int weight = v[i][2];

		if (!graph->nodes.count(from)) {
			Node *temp = new Node(from);
			graph->nodes[from] = temp;
		}
		if (!graph->nodes.count(to)) {
			Node *temp = new Node(to);
			graph->nodes[to] = temp;
		}
		Node *fromNode = graph->nodes[from];
		Node *toNode = graph->nodes[to];
		Edge *newEdge = new Edge(weight, fromNode, toNode);
		fromNode->nexts.push_back(toNode);
		fromNode->out++;
		toNode->in++;
		fromNode->edges.push_back(newEdge);
		graph->edges.insert(newEdge);
	}
	return graph;
}
void showGraph(Graph *graph) {
    cout<<graph->edges.size()<<endl;
    for(auto p=(graph->edges).begin();p!=(graph->edges).end();p++) {
        cout<<(*p)->from->value<<"-->"<<(*p)->to->value<<endl;
    }
}
Info* process(Node *head) {
    if(head->nexts.empty()) {
        return new Info(0,1);
    }
    head->isVis = true;
    int no = 0;
    int yes = 1;
    for(Node *node : head->nexts) {
        if(!node->isVis) {
            Info *inf = process(node);
            no += max(inf->no, inf->yes);
            yes += inf->no;
        }
    }
    return new Info(no,yes);
}
int maxVacation(Graph *graph) {
    Info *info = process((graph->nodes).begin()->second);
    return max(info->no,info->yes);
}
/*****************************************
 *			main.cpp
*****************************************/
int main() {
	vector<vector<int> > matrix;
    int N;
    int x,y;
    cin>>N;
    for(int i=1;i<N;i++) {
        cin>>x>>y;
        matrix.push_back(vector<int>{x,y,1});
        matrix.push_back(vector<int>{y,x,1});
    }
    Graph *graph = createGraphByMatrix(matrix);
    cout<<maxVacation(graph);
    //showGraph(graph);
	return 0;
}
/*

    matrix.push_back(vector<int>{6,2,1});
    matrix.push_back(vector<int>{2,6,1});

    matrix.push_back(vector<int>{3,4,1});
    matrix.push_back(vector<int>{4,3,1});

    matrix.push_back(vector<int>{2,3,1});
    matrix.push_back(vector<int>{3,2,1});

    matrix.push_back(vector<int>{1,2,1});
    matrix.push_back(vector<int>{2,1,1});

    matrix.push_back(vector<int>{7,6,1});
    matrix.push_back(vector<int>{6,7,1});

    matrix.push_back(vector<int>{5,6,1});
    matrix.push_back(vector<int>{6,5,1});
    
    
*/