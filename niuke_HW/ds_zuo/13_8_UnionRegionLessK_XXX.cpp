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
int numOfUnionRegionLessK(Graph *graph) {
    return 0;
}
/*****************************************
 *			main.cpp
*****************************************/
int main() {
	vector<vector<int> > matrix;
    int N, K;
    int x,y;
    cin >> N >> K;
    for(int i = 1; i < N; i++) {
        cin >> x >> y;
        matrix.push_back(vector<int>{x,y,1});
        matrix.push_back(vector<int>{y,x,1});
    }
    Graph *graph = createGraphByMatrix(matrix);
    cout << numOfUnionRegionLessK(graph) << endl;
    showGraph(graph);
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

/*

#include <iostream>
#include <vector>
using namespace std;

#define mod 998244353
typedef long long ll;
ll n, kk;
vector<ll>ve[2005];
ll dp[2005][2005];
ll siz[2005];
ll num[2005];

void dfs(ll x, ll fa) {
    dp[x][1] = 1;
    siz[x] = 1;

    for (ll i = 0; i < ve[x].size(); i++) {
        ll to = ve[x][i];
        if (to == fa) continue;
        dfs(to, x);

        for (ll j = 1; j <= siz[x]; j++) {
            for (ll k = 0; k <= siz[to]; k++) {
                if (j + k > kk) break;
                num[j + k] += dp[x][j] * dp[to][k];
                num[j + k] %= mod;
            }
        }
        siz[x] += siz[to];
        for (ll j = 1; j <= siz[x]; j++) dp[x][j] = num[j], num[j] = 0;
    }
    for (ll i = 1; i <= kk; i++) {
        dp[x][0] = (dp[x][0] + dp[x][i]) % mod;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> kk;
    ll x, y;

    for (ll i = 1; i < n; i++) {
        scanf_s("%lld%lld", &x, &y);
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
    dfs(1, 0);
    ll ans = 0;
    for (ll i = 1; i <= kk; i++) ans = (ans + dp[1][i]) % mod;
    printf_s("%lld\n", ans);
    return 0;
}

/*
你，你认错人了。我真的，真的不是食人魔。”--蓝魔法师

给出一棵树，求有多少种删边方案，使得删后的图每个连通块大小小于等于k，
两种方案不同当且仅当存在一条边在一个方案中被删除，
而在另一个方案中未被删除，答案对998244353取模
*/

