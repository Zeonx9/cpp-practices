//
// Created by musht on 24.12.2022.
//

#define A

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <deque>
#include <stack>

#ifdef A
void rotate(std::vector<int> &v, int d) {
    auto g = std::gcd(v.size(), d);
    auto l = v.size() / g;
    for (int i = 0; i < g; ++i) {
        int tmp1 = v[i], tmp2;
        int ind = i;
        for (int j = 0; j < l; ++j) {
            int nxt = (ind + (int) v.size() + d) % (int) v.size();
            tmp2 = v[nxt];
            v[nxt] = tmp1;
            tmp1 = tmp2;
            ind = nxt;
        }
    }
}

void print_v(const std::vector<int> &v) {
    for (auto e : v) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6};
    print_v(v);
    rotate(v, -2);
    print_v(v);
}
#endif

#ifdef B
int main() {
    int n, k, a, b;
    std::cin >> n;
    std::vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    std::cin >> k >> a >> b;
    v.erase(v.begin() + k - 1);
    v.erase(v.begin() + a - 1, v.begin() + b - 1);

    std::cout << v.size() << "\n";
    for (auto e : v)
        std::cout << e << " ";
}
#endif

#ifdef C
void print_max_for_sliding_window(const std::vector<int> &v, int k) {
    std::deque<int> d;
    for (int i = 0; i < v.size(); ++i) {
        while (!d.empty() and d.back() < v[i])
            d.pop_back();
        d.push_back(v[i]);

        if (i < k - 1)
            continue;

        std::cout << d.front() << " ";

        if (v[i - k + 1] == d.front())
            d.pop_front();
    }
    std::cout << "\n";
}

int main() {
    int t;
    std::cin >> t;

    for (; t > 0; --t) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> v(n, 0);
        for (int j = 0; j < n; ++j)
            std::cin >> v[j];

        print_max_for_sliding_window(v, k);
    }
}
#endif

#ifdef D
using arr = std::vector<int>;
using arrs = std::vector<arr>;

int max_ind(const arr &v) {
    int ind = 0;
    for (int i = 1; i < v.size(); ++i)
        if (v[i] > v[ind])
            ind = i;
    return ind;
}

int find_maximum_equal_height(const arrs &stacks) {
    arr heights;
    for (auto &stack : stacks) {
        int h = 0;
        for(auto e : stack)
            h += e;
        heights.push_back(h);
    }

    arr tops(stacks.size(), 0);
    auto not_equal = [&heights](int e){return e != heights[0];};

    while (std::any_of(heights.begin(), heights.end(), not_equal)) {
        int ind = max_ind(heights);
        heights[ind] -= stacks[ind][tops[ind]++];
    }
    return heights[0];
}

arr input_vector(int n) {
    arr v(n);
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    return v;
}

int main() {
    arr lens = input_vector(3);
    arrs stacks(3);
    for (int i = 0; i < 3; ++i)
        stacks[i] = input_vector(lens[i]);
    std::cout << find_maximum_equal_height(stacks);
}
#endif

#ifdef E
bool is_open(char br) {
    return br == '(' or br == '[' or br == '{';
}
char closing_for(char br) {
    if (br == '(') return ')';
    else if (br == '[') return ']';
    else if (br == '{') return '}';
    return '|';
}

std::string is_correct(const std::string &s) {
    std::stack<char> stack;
    for (auto br : s) {
        if (is_open(br))
            stack.push(br);
        else {
            if (!stack.empty() and br == closing_for(stack.top()))
                stack.pop();
            else
                return "NO";
        }
    }
    if (stack.empty())
        return "YES";
    return "NO";
}
int main() {
    int n;
    std::cin >> n;
    std::string input;
    for (; n > 0; --n) {
        std::cin >> input;
        std::cout << is_correct(input) << "\n";
    }
}
#endif

#ifdef F
using Graph = std::vector<std::vector<int>>;

std::vector<int> find_components(const Graph &g) {
    std::vector<bool> visited(g.size() + 1, false);
    int min_count = (int) g.size() + 1, max_count = 0;

    for (int i = 0; i < g.size(); ++i) {
        if (g[i].empty() or visited[i])
            continue;

        int cur_count = 0;
        std::stack<int> stack;
        stack.push(i);
        visited[i] = true;

        while (!stack.empty()) {
            int cur = stack.top();
            stack.pop();

            ++cur_count;
            for (auto v : g[cur]) {
                if (!visited[v]) {
                    stack.push(v);
                    visited[v] = true;
                }
            }
        }

        if (cur_count > 1 and cur_count < min_count)
            min_count = cur_count;
        if (cur_count > max_count)
            max_count = cur_count;
    }
    return std::vector<int> {min_count, max_count};
}

int main() {
    int n;
    std::cin >> n;

    Graph graph(2 * n + 1);
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    auto pair = find_components(graph);
    std::cout << pair[0] << " " << pair[1] << "\n";
}
#endif