#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector <int>> edges;
std::vector <bool> visited;
int n, m;
static int cnt;
bool check_edge(int start_node, int depth);
int main()
{
	std::cin >> n >> m;
	edges.resize(n);
	visited.resize(n);
	for (int i = 0; i < m; i++)
	{
		int from, to;
		
		std::cin >> from >> to;
		edges[from].push_back(to);
		edges[to].push_back(from);
	}

	for (int i = 0; i < edges.size(); i++)
	{
		bool a = check_edge(i, 0);
		if (a) {
			std::cout << 1;
			return 0;
		}
	}
	std::cout << 0;
}
bool check_edge(int start_node, int depth) {
	if (depth == 4)
		return true;
		
	visited[start_node] = true;

	for (int i = 0; i <  edges[start_node].size(); i++)
	{
		if (visited[edges[start_node][i]] == false) {
			if (check_edge(edges[start_node][i], depth + 1)) {
				return true;
			}
		}
		
	}

	visited[start_node] = false;
	return false; 
}

