//Thuat toan tim kiem theo chieu rong tu dinh s den dinh g
#include <stdio.h>
#include <queue>
#include <conio.h>
#include <iostream>
using namespace std;
 
// Dinh nghia lop do thi
class Graph
{
	private:
	
		int n;

		int **edge;
	public:
		
		Graph(int size = 2);
		
		~Graph();
	
		bool isConnected(int, int);
		//Them canh
		void addEdge(int, int);
		//Thuat toan tim kiem theo chieu rong tu dinh A -> dinh B
		void breadthFirstSearch(int, int);
};
 
Graph::Graph(int size)
{
	int i, j;
 

	if (size < 2)
		n = 2;
	else 
		n = size;
 

	edge = new int*[n];
	for (i = 0; i < n; i++)
		edge[i] = new int[n];
	
	
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
 
bool Graph::isConnected(int x, int y)
{
	if (edge[x - 1][y - 1] == 1)
		return true;
	return false;
}
 

void Graph::addEdge(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > n)
		return;

	edge[x - 1][y - 1] = edge[y - 1][x - 1] = 1;
}
 
void Graph::breadthFirstSearch(int s, int g)
{
	if (s > n || s < 0 || g > n || g < 0)
	{
		cout<<"Khong tim thay duong di\n";
		return;
	}

	queue <int> open;

	bool *close = new bool[n];
	int i;
	int p;

	for (i = 0; i < n; i++)
		close[i] = false;
 

	open.push(s);
 
	cout<<"Ket qua sau khi duyet bang thuat toan BFS tu dinh "<<s<<"den dinh:"<<g<<"\n";
 
	while (!open.empty())
	{
		//Lay mot dinh ra khoi open tro thanh dinh dang xet p
		do
		{
			if (open.empty())
				break;
 
			p = open.front();
			open.pop();
		} while (close[p - 1] == true);
 
		printf("%d ", p);
 
		close[p - 1] = true;

		if (p == g)
			break;
		

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
    //Khoi tao do thi gom 9 dinh
	Graph g(9);

	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(2, 6);
	g.addEdge(3, 6);
	g.addEdge(3, 7);
	g.addEdge(3, 8);
	g.addEdge(7, 9);
	g.addEdge(7, 8);
	g.addEdge(8, 9);
 
    //Duyet bang Breadth First Search tu dinh 2 den dinh 7
	g.breadthFirstSearch(2, 7);
}
