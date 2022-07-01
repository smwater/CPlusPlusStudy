#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

int N, M;
char map[105][105];

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i)
        scanf("%s", map[i]);

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    map[0][0] = '2';

    int exitCount = 1;
    while (false == q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            auto [r, c] = q.front();
            q.pop();

            if (r == N - 1 && c == M - 1)
                goto EXIT;

            static const int dr[] = { -1, 1, 0, 0 };
            static const int dc[] = { 0, 0, -1, 1 };

            for (int i = 0; i < 4; ++i)
            {
                const int nr = r + dr[i];
                const int nc = c + dc[i];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;

                if (map[nr][nc] == '1')
                {
                    map[nr][nc] = '2';
                    q.emplace(nr, nc);
                }
            }
        }

        ++exitCount;
    }

EXIT:
    printf("%d", exitCount);
}