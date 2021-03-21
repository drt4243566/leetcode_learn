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
	vector<Node*> nexts;
	vector<Edge*> edges;
	Node(int val) {
		value = val;
		in = 0;
		out = 0;
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
/*******************建图***********************/
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

vector<Node*> topolySort(Graph *graph) {
	if (graph == NULL)
		return vector<Node*>{};
	unordered_map<Node*, int> inMap;
	queue<Node*> zeroInQueue;
	for (auto p = graph->nodes.begin(); p != graph->nodes.end();p++) {
		Node* curNode = p->second;
		inMap[curNode] = curNode->in;
		if (curNode->in == 0) {
			zeroInQueue.push(curNode);
		}
	}
	vector<Node*> result;
	while (!zeroInQueue.empty()) {
		Node* curNode = zeroInQueue.front();
		zeroInQueue.pop();
		result.push_back(curNode);
		for (int i = 0; i < curNode->nexts.size(); i++) {
			inMap[curNode->nexts[i]]--;
			if (inMap[curNode->nexts[i]] == 0) {
				zeroInQueue.push(curNode->nexts[i]);
			}
		}
	}
	return result;
}
unordered_set<int> bfs(Graph *graph) {
    Node *node;
    if(!graph->nodes.count(1))
        node = NULL;
    else
    {
            node = graph->nodes[1];
    }
    
	if (node == NULL)
		return unordered_set<int>{};
    unordered_set<int> resultSet;
	queue<Node*> Q;
	unordered_set<Node*> S;
	Q.push(node);
	S.insert(node);
	while (!Q.empty()) {
		Node *cur = Q.front();
		Q.pop();
		resultSet.insert(cur->value);
		for (int i = 0; i < cur->nexts.size(); i++) {
			if (!S.count(cur->nexts[i])) {
				Q.push(cur->nexts[i]);
				S.insert(cur->nexts[i]);
			}
		}
	}
    return resultSet;
}
/*****************************************
 *			   main.cpp
*****************************************/
int main() {
	vector<vector<int> > matrix;
    int M,N;
    while(cin>>M>>N){
        int temp;
        for(int i=1;i<M;i++){
            cin>>temp;
            matrix.push_back(vector<int>{i, i+temp, 1});
        }
        Graph *graph = createGraphByMatrix(matrix);
        unordered_set<int> r = bfs(graph);
        if(r.count(N))
            cout<<"YES"<<endl;
        else
        {
                cout<<"NO"<<endl;
        }
        
    }
	return 0;
}

