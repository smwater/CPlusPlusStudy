#include <vector>

struct Edge
{
	int Vertex;
	int Weight;

	Edge(int v, int w) : Vertex(v), Weight(w) { }
};

std::vector<Edge> graph[7];

// [index] : 연결된 정점

// [0] : { (1, 1) }
// [1] : { (0, 1), (2, 2), (3, 2) }
// [2] : { (1, 2), (5, 6), (6, 3) }
// [3] : { (1, 2), (4, 1), (5, 4) }
// [4] : { (3, 1) }
// [5] : { (2, 6), (3, 4) }
// [6] : { (2, 3) }

int main()
{
	Edge edge(1, 1);
	graph[0].push_back(edge);

	graph[1].emplace_back(0, 1);
	graph[1].emplace_back(2, 2);
	graph[1].emplace_back(3, 2);

	graph[2].emplace_back(1, 2);
	graph[2].emplace_back(5, 6);
	graph[2].emplace_back(6, 3);

	graph[3].emplace_back(1, 2);
	graph[3].emplace_back(4, 1);
	graph[3].emplace_back(5, 4);

	graph[4].emplace_back(3, 1);

	graph[5].emplace_back(2, 6);
	graph[5].emplace_back(3, 4);

	graph[6].emplace_back(2, 3);
}
