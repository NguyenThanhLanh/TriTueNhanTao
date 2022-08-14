#include <iostream>
#include <vector>
using namespace std;


vector <int> k[1005];
bool visit[105];
int n, m;
void DFS (int u)
{
	visit[u] = true;
	cout << u << ' ';
	for(int i=0; i<k[u].size(); i++)
		if(!visit[k[u][i]]) 
			DFS(k[u][i]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("DFS.txt", "r", stdin);
	freopen("ketqua.txt", "w", stdout);
	
	cin >> n >> m;
	for(int i=1; i<=9; i++)
	{
		int u, v;
		cin >> u >> v;
		k[u].push_back(v);
	}
	DFS(1);
	return 0;
}
