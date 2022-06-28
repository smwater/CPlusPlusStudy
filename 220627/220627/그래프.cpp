#define ����� 0
#define ���缺 1
#define ������ 2
#define ���ǹ� 3
#define �̽��� 4

#include <vector>
#include <algorithm>

// true : ����, false : �񿬰�
bool graph[5][5];
std::vector<int> graph2[5];

// �����ߴ��� �˷���?? => ���� ��� ����
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

// �����ߴ��� �˷���?? => ���� ����Ʈ ����
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

// ���������� ���Ѵ�. => ���� ��� ����
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

// ���������� ���Ѵ�. => ���� ����Ʈ ����
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
	// �׷��� ���� : ���� ���
	// ���� : ���� ���⵵ ����
	// ���� : ������ �ʹ� ������ �޸� ���� ����
	graph[�����][�̽���] = true;

	graph[���缺][������] = true;
	graph[���缺][���ǹ�] = true;
	graph[���缺][�̽���] = true;
	
	graph[������][�����] = true;
	graph[������][���缺] = true;
	graph[������][���ǹ�] = true;
	graph[������][�̽���] = true;

	graph[���ǹ�][���缺] = true;
	graph[���ǹ�][������] = true;
	graph[���ǹ�][�̽���] = true;

	// [i][j] : i -> j
	// 0 0 0 0 1
	// 0 0 1 1 1
	// 1 1 0 1 1
	// 0 1 1 0 1
	// 0 0 0 0 0

	// �׷��� ���� : ���� ����Ʈ
	// ���� : �޸� ���� ����
	// ���� : ���� ���⵵�� ����
	// [0] : { 4 }
	// [1] : { 2, 3, 4 }
	// [2] : { 0, 1, 3, 4 }
	// [3] : { 1, 2, 4 }
	// [4] : {}
	graph2[�����].push_back(�̽���);

	graph2[���缺].push_back(������);
	graph2[���缺].push_back(���ǹ�);
	graph2[���缺].push_back(�̽���);

	graph2[������].push_back(�����);
	graph2[������].push_back(���缺);
	graph2[������].push_back(���ǹ�);
	graph2[������].push_back(�̽���);

	graph2[���ǹ�].push_back(���缺);
	graph2[���ǹ�].push_back(������);
	graph2[���ǹ�].push_back(�̽���);
}