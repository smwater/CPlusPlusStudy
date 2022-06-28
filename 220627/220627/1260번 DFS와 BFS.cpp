#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1001];
int N, M, V;

void dfs(int vertex)
{
	static bool isVisited[1001] = { false };

	isVisited[vertex] = true;

	cout << vertex << " ";

	for (int next : graph[vertex])
	{
		if (isVisited[next] == false)
		{
			dfs(next);
		}
	}
}

void dfsWithStack()
{
	// 1. �湮 ���θ� �����ؾ� �Ѵ�.
	bool isVisited[1001] = { false };

	// 2. DFS�� ����� ������ �����.
	stack<int> st; // ���ÿ��� ������ �湮�� ������ ����ȴ�.
	st.push(V); // ù ��°�� �湮�� ����
	isVisited[V] = true;

	// 3. ���̻� �湮�� ������ ���� ������ �湮�Ѵ�.
	while (false == st.empty())	// ������ ����ִٸ� ��� ������ �湮�� ���̴�.
	{
		// 3 - 1. ������ �湮�Ѵ�.
		int node = st.top();
		st.pop();
		cout << node << ' ';

		// 3-2. �������� �湮�� ������ ã�´�.
		for (int nextNode : graph[node])
		{
			if (false == isVisited[nextNode])
			{
				st.push(nextNode);
				isVisited[nextNode] = true;
			}
		}
	}
}

void bfs()
{
	// 1. �湮 ���θ� �����ؾ� �Ѵ�.
	bool isVisited[1001] = { false };

	// 2. BFS�� ����� ť�� �����.
	queue<int> que; // ť���� ������ �湮�� ������ ����ȴ�.
	que.push(V); // ù ��°�� �湮�� ����
	isVisited[V] = true;

	// 3. ���̻� �湮�� ������ ���� ������ �湮�Ѵ�.
	while (false == que.empty())	// ť�� ����ִٸ� ��� ������ �湮�� ���̴�.
	{
		// 3 - 1. ������ �湮�Ѵ�.
		int node = que.front();
		que.pop();
		cout << node << ' ';

		// 3-2. �������� �湮�� ������ ã�´�.
		for (int nextNode : graph[node])
		{
			if (false == isVisited[nextNode])
			{
				que.push(nextNode);
				isVisited[nextNode] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. �׷��� ����
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 2. ���� �������� ���Ľ�Ű�� ���� ����
	for (int i = 0; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfsWithStack();
	cout << "\n";
	dfs(V);
	cout << "\n";
	bfs();
}