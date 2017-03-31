
// Author : lixianmin?live.cn
// Date   : 2017-03-31


#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <numeric>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>

struct Comparer
{
    bool operator() (int a, int b)
    {
        return a < b;
    }
};

int main ()
{
    // std::priority_queue<int, std::vector<int>, std::less<int> > q;
    // std::priority_queue<int, std::vector<int>, Comparer> q;
    std::priority_queue<int> q;
    for (int i= 0; i< 30; ++i)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        int top = q.top();
        printf("%d->", top);
        q.pop();
    }

    printf("\n");
}
