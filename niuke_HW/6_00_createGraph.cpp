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
	vector<Node*> nexts;  // 延伸出去的邻居节点
	vector<Edge*> edges;  // 直接发散出去的边的集合
	Node(int val) {
		value = val;
		// in表示入度，指的是有多少条边连进来，out表示出度；
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
/**********kruskal相关类*************/
class MySets{
	unordered_map<Node*,unordered_set<Node*>*> nodeMap;
public:
	MySets(unordered_map<int, Node*> nodes){
		for(auto p=nodes.begin();p!=nodes.end();p++){
			nodeMap[p->second] = new unordered_set<Node*>{p->second};
		}
	}
	bool isSameSet(Node *a, Node *b){
		if(nodeMap.count(a)&&nodeMap.count(b)){
			cout<<"-----------"<<endl;
			cout<<a->value<<" "<<b->value<<"!";
			cout<<(nodeMap[a] == nodeMap[b])<<":"<<endl;
			for(auto p=nodeMap[a]->begin();p!=nodeMap[a]->end();p++){
				cout<<(*p)->value<<" ";
			}
			cout<<endl;
			for(auto p=nodeMap[b]->begin();p!=nodeMap[b]->end();p++){
				cout<<(*p)->value<<" ";	
			}
			cout<<endl<<"-------------";
			cout<<endl;
			return nodeMap[a] == nodeMap[b];
		}	
		else
			return false;
	}
	void unionNodeSet(Node *a, Node *b){
		/*unordered_set<Node*> unionset;
		if(a->value<=b->value){
			for(auto p=nodeMap[b]->begin();p!=nodeMap[b]->end();p++){
			//unionset.insert(*p);
			nodeMap[a]->insert(*p);
			}
			nodeMap[b] = nodeMap[a];
		}
		else{
			for(auto p=nodeMap[a]->begin();p!=nodeMap[a]->end();p++){
			//unionset.insert(*p);
			nodeMap[b]->insert(*p);
			}
			nodeMap[a] = nodeMap[b];
		}
		*/
		unordered_set<Node*> *ps;
		unordered_set<Node*> *pq;
		if(nodeMap[a]->size()>nodeMap[b]->size()){
			ps = nodeMap[a];
			pq = nodeMap[b];
			nodeMap[b] = nodeMap[a];
		}
		else{
			pq = nodeMap[a];
			ps = nodeMap[b];
			nodeMap[a] = nodeMap[b];
		}

		for(auto p=pq->begin();p!=pq->end();p++){
			ps->insert(*p);
		}
	}
};
struct EdgeCompare{/*比较器*/
	bool operator()(Edge *a, Edge *b){
		return a->weight > b->weight;
	}
};
Graph* createGraphByMatrix(vector< vector<int> > v) {
	/*every row [from  to  weight]*/
	Graph *graph = new Graph;
	// 从from节点到to节点，第三列表示权重
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
void bfs(Graph *graph, Node *node) {
	if (node == NULL)
		return;
	queue<Node*> Q;
	unordered_set<Node*> S;
	Q.push(node);
	S.insert(node);
	while (!Q.empty()) {
		Node *cur = Q.front();
		Q.pop();
		cout << cur->value << endl;
		for (int i = 0; i < cur->nexts.size(); i++) {
			if (!S.count(cur->nexts[i])) {
				Q.push(cur->nexts[i]);
				S.insert(cur->nexts[i]);
			}
		}
	}
}

void dfs(Graph *graph, Node *node) {
	if (node == NULL)
		return;
	stack<Node*> stk;
	unordered_set<Node*> S;
	stk.push(node);
	S.insert(node);
	cout << node->value << endl;
	while (!stk.empty()) {
		Node *cur = stk.top();
		stk.pop();
		for (int i = 0; i < cur->nexts.size(); i++) {
			if (!S.count(cur->nexts[i])) {
				stk.push(cur);
				stk.push(cur->nexts[i]);
				S.insert(cur->nexts[i]);
				cout << cur->nexts[i]->value << endl;
				break;
			}
		}
	}
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
/**********kruskal*************/
unordered_set<Edge*> kruskal(Graph *graph){
	if(graph == NULL)
		return unordered_set<Edge*>{};
	MySets mysets(graph->nodes);
	unordered_set<Edge*> resultEdge;
	priority_queue<Edge*,vector<Edge*>,EdgeCompare> edgeQueue;
	for(auto p = graph->edges.begin();p!=graph->edges.end();p++){
		edgeQueue.push(*p);
	}
	while(!edgeQueue.empty()){
		Edge* curEdge = edgeQueue.top();
		edgeQueue.pop();
		cout<<"pop:"<<curEdge->weight<<endl;
		if(!mysets.isSameSet(curEdge->from,curEdge->to)){
			resultEdge.insert(curEdge);
			mysets.unionNodeSet(curEdge->from,curEdge->to);
		}
	}
	return resultEdge;
}
/**********prim*************/
unordered_set<Edge*> prim(Graph *graph, Node *node){
	if(graph==NULL or node==NULL)
		return unordered_set<Edge*>{};
	unordered_set<Edge*> resultEdge;
	unordered_set<Node*> nodeSet;
	priority_queue<Edge*,vector<Edge*>,EdgeCompare> edgeQueue;
	if(!nodeSet.count(node)){
		nodeSet.insert(node);
		for(auto p=node->edges.begin();p!=node->edges.end();p++){
			edgeQueue.push(*p);
		}
	}
	while(!edgeQueue.empty()){
		Edge *curEdge = edgeQueue.top();
		edgeQueue.pop();
		Node *toNode = curEdge->to;
		if(!nodeSet.count(toNode)){
			resultEdge.insert(curEdge);
			for(auto p=toNode->edges.begin();p!=toNode->edges.end();p++){
				edgeQueue.push(*p);
			}
		}
	}
	return resultEdge;
}
/**********dijkstral*************/
/**********单源最短路径算法*************/
Node* getMinDistanceAndUnselectedNode(unordered_map<Node*, int> &distanceMap, 
									  unordered_set<Node*> &selectedNodesSet){
	Node *minNode = NULL;
	int minDistance = INT_MAX;
	for(auto p=distanceMap.begin();p!=distanceMap.end();p++){
		if(!selectedNodesSet.count(p->first)&&(p->second<minDistance)){
			minNode = p->first;
			minDistance = p->second;
		}
	}
	return minNode;
}
unordered_map<Node*,int> dijkstral(Node *node){
	if(node==NULL)
		return unordered_map<Node*,int>{};
	unordered_map<Node*, int> distanceMap;
	unordered_set<Node*> selectedNodesSet;
	distanceMap[node] = 0;
	Node *minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodesSet);
	while(minNode !=NULL){
		int distance = distanceMap[minNode];
		for(auto p=minNode->edges.begin();p!=minNode->edges.end();p++){
			Node *toNode = (*p)->to;
			if(!distanceMap.count(toNode)){
				distanceMap[toNode] = distance + (*p)->weight;
			}else{
				distanceMap[toNode] = min(distanceMap[toNode],distance+(*p)->weight);
			}
		}
		selectedNodesSet.insert(minNode);
		minNode = getMinDistanceAndUnselectedNode(distanceMap,selectedNodesSet);
	}
	return distanceMap;
}
/*****************************************
 *			main.cpp
*****************************************/
int main() {
	vector<vector<int> > matrix;
	matrix.push_back(vector<int>{1, 6, 1});
	matrix.push_back(vector<int>{5, 6, 2});
	matrix.push_back(vector<int>{6, 7, 4});
	matrix.push_back(vector<int>{7, 8, 5});
	matrix.push_back(vector<int>{5, 7, 10});
	matrix.push_back(vector<int>{1, 5, 3});
	Graph *graph = createGraphByMatrix(matrix);
	unordered_set<Edge*> re = kruskal(graph);
	cout<<endl;
	for(auto p=re.begin();p!=re.end();p++){
		cout<<(*p)->weight<<endl;
	}
	/*
	vector<Node*> v = topolySort(graph);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i]->value << endl;
	}
	*/
	return 0;
}
