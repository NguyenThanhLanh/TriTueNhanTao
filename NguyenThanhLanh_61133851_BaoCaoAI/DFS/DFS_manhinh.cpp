#include <stdio.h>
#include <stack>
using namespace std;

class Graph
{
private:
	int n;
	int **edge;
public:
	Graph(int size = 2);
	~Graph();
	bool isConnected(int, int);
	void addEdge(int x, int y);
	void depthFirstSearch(int, int);
};
Graph::Graph(int size)
{
	int i, j;

	// xac dinh so dinh cua do thi
	if (size < 2)
		n = 2;
	else 
		n = size;

	// tao ra cac dinh trong do thi
	edge = new int*[n];
	for (i = 0; i < n; i++)
		edge[i] = new int[n];
	
	// mac dinh giua cac dinh khong co ket noi voi nhau (= 0)
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			edge[i][j] = 0;
}

Graph::~Graph()
{
	for (int i = 0; i < n; ++i)
		delete[] edge[i];
	delete[] edge;
}

// kiem tra giua hai dinh co ke nhau hay khong
bool Graph::isConnected(int x, int y)
{
	if (edge[x - 1][y - 1] == 1)
		return true;

	return false;
}

// th?m c?nh n?i d?nh x v? d?nh y
void Graph::addEdge(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > n)
		return;

	edge[x - 1][y - 1] = edge[y - 1][x - 1] = 1;
}

void Graph::depthFirstSearch(int s, int g)
{
	if (s > n || s < 0 || g > n || g < 0)
	{
		printf("Could not traverse this graph with your request\n");
		return;
	}

	stack <int> open;
	bool *close = new bool[n];
	int i;
	int p;

	// mac dinh cac dinh chua duoc duyet
	for (i = 0; i < n; i++)
		close[i] = false;

	// dua dinh goc s vao stack open, chuan bi duyet
	open.push(s);
	
	printf("With Depth first Search , we have vertex(s):\n");

	while (!open.empty())
	{
		// lay mot dinh ra khoi open tro thanh dinh dang xet p
		do
		{
			if (open.empty())
				return;

			p = open.top();
			open.pop();
		} while (close[p - 1] == true);

		// in ra dinh dang xet
		printf("%d ", p);

		// p da duyet qua
		close[p - 1] = true;

		// ket thuc duyet khi tim ra ket qua can tim		
		if (p == g)
			return;
		
		// tim dinh ke voi dinh dang xet, dinh nao chua duoc duyet dua vao open
		for (i = 1; i <= n; i++)
		{
			if (isConnected(p, i) && !close[i - 1])
			{
				open.push(i);
			}
		}
	}
	printf("\n");

	delete[] close;
}
int main()
{
   // khoi tao do thi
	Graph g(8);

	// tao canh noi giua cac dinh ke
	g.addEdge(1, 2);
	g.addEdge(1, 6);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 5);
	g.addEdge(3, 6);
	g.addEdge(3, 7);
	g.addEdge(3, 8);
	g.addEdge(3, 9); 
	g.addEdge(4, 3);

    // duyet bang Depth First Search
	g.depthFirstSearch(1, 4);
}

