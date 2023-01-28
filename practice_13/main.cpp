//
// Created by musht on 26.01.2023.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define F

#ifdef A
double getMedian(std::vector<int> &left, std::vector<int> &right) {
    if (left.size() > right.size())
        return left.front();
    return (left.front() + right.front()) / 2.0;
}

void putInHalf(std::vector<int> &left, std::vector<int> &right, int v) {
    auto greater = [](int c, int d) {
        return c >= d;
    };
    if (v <= getMedian(left, right)) {
        left.push_back(v);
        std::push_heap(left.begin(), left.end());
    } else {
        right.push_back(v);
        std::push_heap(right.begin(), right.end(), greater);
    }
}

void balance(std::vector<int> &left, std::vector<int> &right) {
    auto greater = [](int c, int d) {
        return c >= d;
    };
    if (left.size() > right.size() + 1) {
        right.push_back(left.front());
        std::push_heap(right.begin(), right.end(), greater);
        std::pop_heap(left.begin(), left.end());
        left.pop_back();
    }
    else if (right.size() > left.size()) {
        left.push_back(right.front());
        std::push_heap(left.begin(), left.end());
        std::pop_heap(right.begin(), right.end(), greater);
        right.pop_back();
    }
}

std::vector<double> runningMedian(std::vector<int> &a) {
    std::vector<double> res;
    std::vector<int> left, right;
    for (auto v : a) {
        if (left.empty() and right.empty())
            left.push_back(v);
        else
            putInHalf(left, right, v);
        balance(left, right);
        res.push_back(getMedian(left, right));
    }
    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n, 0);
    for (int &v : a)
        std::cin >> v;
    auto res = runningMedian(a);
    for (auto c : res)
        std::cout << c << " ";
    std::cout << "\n";
}
#endif

#ifdef B
#define INF 1000000000

class Graph {
private:
    std::vector<std::vector<std::pair<int, int>>> adjList;
public:
    explicit Graph(int n) {
        adjList = std::vector<std::vector<std::pair<int, int>>>(n);
    }

    void addEdge(int from, int to, int weight) {
        adjList[from].push_back({to, weight});
    }

    int getSize() const {
        return (int) adjList.size();
    }

    std::vector<std::pair<int, int>> getAdj(int n) const {
        return adjList[n];
    }
};

std::vector<int> dijkstra(const Graph &g, int start) {
    std::vector<int> dist(g.getSize(), INF);
    dist[start] = 0;

    std::priority_queue<std::pair<int, int>> queue;
    queue.push({0, start});

    while (!queue.empty()) {
        auto [l, u] = queue.top();
        queue.pop();
        if (-l != dist[u])
            continue;

        for (const auto [v, w] : g.getAdj(u)) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                queue.push({l - w, v});
            }
        }
    }
    return dist;
}

std::vector<int> solveTask(int n, std::vector<std::vector<int>> edges, int s) {
    Graph g = Graph(n);
    for (auto &edge : edges) {
        g.addEdge(edge[0] - 1, edge[1] - 1, 6);
        g.addEdge(edge[1] - 1, edge[0] - 1, 6);
    }
    auto res = dijkstra(g, s - 1);
    std::vector<int> output;
    for (auto e : res) {
        if (e == 0)
            continue;
        if (e == INF)
            e = -1;
        output.push_back(e);
    }
    return output;
}

int main() {
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int n, m, s;
        std::cin >> n >> m;
        std::vector<std::vector<int>> edges(m, std::vector<int>(2));
        for (int j = 0; j < m; ++j) {
            std::cin >> edges[j][0] >> edges[j][1];
        }
        std::cin >> s;
        auto output = solveTask(n, edges, s);
        for (int j : output) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}
#endif

#ifdef C
std::string lowerBound(std::vector<int> &arr, int s) {
    auto [start, end] = std::equal_range(arr.begin(), arr.end(), s);
    std::string out;
    if (start == end)
        out = "No ";
    else
        out = "Yes ";

   return out + std::to_string(start - arr.begin() + 1) + "\n";
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (auto &e : arr)
        std::cin >> e;

    int q;
    std::cin >> q;

    int y;
    for (int i = 0; i < q; ++i) {
        std::cin >> y;
        std::cout << lowerBound(arr, y);
    }
}
#endif

#ifdef D
class Solution {
public:
    static int mostWordsFound(std::vector<std::string> &ss) {
        int maxCount = 0;
        for (auto &s : ss) {
            maxCount = std::max(
                    maxCount,
                    (int) std::count(s.begin(), s.end(), ' ') + 1
            );
        }
        return maxCount;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> sent(n);

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, sent[i]);
    }
    std::cout << Solution::mostWordsFound(sent);
}
#endif

#ifdef E

class Solution {
public:
    static std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
        std::vector<int> res;
        res.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            res.insert(res.begin() + index[i], nums[i]);
        return res;
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i];
    }
    auto res = Solution::createTargetArray(a, b);
    for (auto e : res)
        std::cout << e << ", ";
}
#endif

#ifdef F

class Solution {
public:
    static int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid) {
        std::vector<int> maxInRow(grid.size()), maxInCol(grid.size());
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid.size(); ++j) {
                maxInRow[i] = std::max(maxInRow[i], grid[i][j]);
                maxInCol[i] = std::max(maxInCol[i], grid[j][i]);
            }
        int res = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid.size(); ++j)
                res += std::min(maxInRow[i], maxInCol[j]) - grid[i][j];
        return res;
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            std::cin >> a[i][j];
    }
    std::cout << Solution::maxIncreaseKeepingSkyline(a);
}
#endif





