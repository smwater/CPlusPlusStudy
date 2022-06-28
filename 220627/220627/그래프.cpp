#define 김재민 0
#define 김재성 1
#define 안중재 2
#define 성권문 3
#define 이승일 4

#include <vector>
#include <algorithm>

// true : 연결, false : 비연결
bool graph[5][5];
std::vector<int> graph2[5];

// 인접했는지 알려면?? => 인접 행렬 버전
bool isAdjacent(int** graph, int v1, int v2)
{
	if (graph[v1][v2] || graph[v2][v1])
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 인접했는지 알려면?? => 인접 리스트 버전
bool isAdjacent(std::vector<int>* graph, int v1, int v2)
{
	if (graph[v1].end() != std::find(graph[v1].begin(), graph[v1].end(), v2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 진입차수를 구한다. => 인접 행렬 버전
int CountIndegree(int** graph, int vertex)
{
	int inDegree = 0;
	for (int i = 0; i < 5; i++)
	{
		if (true == graph[i][vertex])
		{
			inDegree++;
		}
	}

	return inDegree;
}

// 진입차수를 구한다. => 인접 리스트 버전
int CountIndegree(std::vector<int>* graph, int vertex)
{
	int inDegree = 0;
	for (int i = 0; i < 5; i++)
	{
		if (graph[i].end() != std::find(graph[i].begin(), graph[i].end(), vertex))
		{
			inDegree++;
		}
	}

	return inDegree;
}

int main()
{
	// 그래프 구성 : 인접 행렬
	// 장점 : 구현 복잡도 낮음
	// 단점 : 간선이 너무 적으면 메모리 낭비가 심함
	graph[김재민][이승일] = true;

	graph[김재성][안중재] = true;
	graph[김재성][성권문] = true;
	graph[김재성][이승일] = true;
	
	graph[안중재][김재민] = true;
	graph[안중재][김재성] = true;
	graph[안중재][성권문] = true;
	graph[안중재][이승일] = true;

	graph[성권문][김재성] = true;
	graph[성권문][안중재] = true;
	graph[성권문][이승일] = true;

	// [i][j] : i -> j
	// 0 0 0 0 1
	// 0 0 1 1 1
	// 1 1 0 1 1
	// 0 1 1 0 1
	// 0 0 0 0 0

	// 그래프 구성 : 인접 리스트
	// 장점 : 메모리 낭비가 적음
	// 단점 : 구현 복잡도가 높음
	// [0] : { 4 }
	// [1] : { 2, 3, 4 }
	// [2] : { 0, 1, 3, 4 }
	// [3] : { 1, 2, 4 }
	// [4] : {}
	graph2[김재민].push_back(이승일);

	graph2[김재성].push_back(안중재);
	graph2[김재성].push_back(성권문);
	graph2[김재성].push_back(이승일);

	graph2[안중재].push_back(김재민);
	graph2[안중재].push_back(김재성);
	graph2[안중재].push_back(성권문);
	graph2[안중재].push_back(이승일);

	graph2[성권문].push_back(김재성);
	graph2[성권문].push_back(안중재);
	graph2[성권문].push_back(이승일);
}