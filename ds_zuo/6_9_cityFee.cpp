#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
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
		if(nodeMap.count(a)&&nodeMap.count(b))
			return nodeMap[a] == nodeMap[b];
		else
			return false;
	}
	void unionNodeSet(Node *a, Node *b){
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
class UnionFind{
	unordered_map<Node*, Node*> fatherMap;
	unordered_map<Node*, int> sizeMap;
public:
	UnionFind(unordered_map<int, Node*> nodes){
		fatherMap.clear();
		sizeMap.clear();
		for(auto p=nodes.begin();p!=nodes.end();p++){
			fatherMap[p->second] = p->second;
			sizeMap[p->second] = 1;
		}
	}
	Node* findFather(Node* n){
		stack<Node*> path;
		while(n != fatherMap[n]){
			path.push(n);
			n = fatherMap[n];
		}
		while(!path.empty()){
			fatherMap[path.top()] = n;
			path.pop();
		}
		return n;
	}
	bool isSameSet(Node* e1, Node* e2){
		return findFather(e1) == findFather(e2);
	}
	void unionNodeSet(Node* a, Node* b){
		if(a == NULL or b == NULL){
			return;
		}
		Node *aDai = findFather(a);
		Node *bDai = findFather(b);
		if(aDai != bDai){
			int aSetSize = sizeMap[aDai];
			int bSetSize = sizeMap[bDai];
			if(aSetSize <= bSetSize){
				fatherMap[aDai] = bDai;
				sizeMap[bDai] = aSetSize + bSetSize;
				sizeMap.erase(aDai);
			}
			else{
				fatherMap[bDai] = aDai;
				sizeMap[aDai] = aSetSize + bSetSize;
				sizeMap.erase(bDai);
			}
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
	for (auto p= v.begin();p!=v.end();p++) {
		int from = (*p)[0];
		int to = (*p)[1];
		int weight = (*p)[2];

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
/**********kruskal*************/
unordered_set<Edge*> kruskal(Graph *graph){
	if(graph == NULL)
		return unordered_set<Edge*>{};
	UnionFind mysets(graph->nodes);
	unordered_set<Edge*> resultEdge;
	priority_queue<Edge*,vector<Edge*>,EdgeCompare> edgeQueue;
	for(auto p = graph->edges.begin();p!=graph->edges.end();p++){
		edgeQueue.push(*p);
	}
	while(!edgeQueue.empty()){
		Edge* curEdge = edgeQueue.top();
		edgeQueue.pop();
		//cout<<curEdge->from<<" "<<curEdge->to<<" "<<curEdge->weight<<endl;
		if(!mysets.isSameSet(curEdge->from,curEdge->to)){
			resultEdge.insert(curEdge);
			//cout<<"choice "<<curEdge->weight<<endl;
			mysets.unionNodeSet(curEdge->from,curEdge->to);
		}
	}
	return resultEdge;
}

int main() {
	vector<vector<int> > matrix;
    int fee;
    int roadNum;
    int cityNum;
    int from,to,weight;
    cin>>fee>>roadNum>>cityNum;
    for(int i=0;i<roadNum;i++){
        cin>>from>>to>>weight;
		matrix.push_back(vector<int>{from,to,weight});
    }
	Graph *graph = createGraphByMatrix(matrix);
	//cout<<":"<<endl;
    unordered_set<Edge*> result = kruskal(graph);
    int sum=0;
    for(auto p=result.begin();p!=result.end();p++){
        sum = sum + (*p)->weight;
    }
	//cout<<"sum:"<<sum<<endl;
    if(fee>=sum)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

	return 0;
}

/*****************************************
 *			main.cpp

int main() {
	vector<vector<int> > matrix;
    map<vector<int>,int> inmap;
    int fee;
    int roadNum;
    int cityNum;
    int from,to,weight;
    cin>>fee>>roadNum>>cityNum;
    for(int i=0;i<roadNum;i++){
        cin>>from>>to>>weight;
        vector<int> temp = from>to?vector<int>{to,from}:vector<int>{from,to};
        if(!inmap.count(temp)){
            inmap[temp] = weight;
        }else{
            inmap[temp] = min(weight,inmap[temp]);
        }
    }
    for(auto p=inmap.begin();p!=inmap.end();p++){
        vector<int> temp = p->first;
        int i=temp[0];
        int j=temp[1];
        int k=p->second;
        matrix.push_back(vector<int>{i,j,k});
        matrix.push_back(vector<int>{j,i,k});
    }
	cout<<"begin"<<endl;
	for(auto p=matrix.begin();p!=matrix.end();p++){
		cout<<(*p)[0]<<" "<<(*p)[1]<<" "<<(*p)[2]<<endl;
	}
	Graph *graph = createGraphByMatrix(matrix);
    cout<<matrix.size()<<endl;
    unordered_set<Edge*> result = kruskal(graph);
    int sum=0;
    for(auto p=result.begin();p!=result.end();p++){
        sum = sum + (*p)->weight;
    }
    if(fee>=sum)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0;
}

*****************************************/