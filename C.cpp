#include<iostream>
#include<vector>
#include<set>

std::vector<std::vector<int>> Read() {
    int num_vertex, num_edges;
    std::cin >> num_vertex >> num_edges;

    std::vector<std::vector<int>> graph(num_vertex);
    while (num_edges--) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
    }
    return graph;
}

void dfs(int vertex, const std::vector<std::vector<int>> &graph, std::vector < int > &colors,
         std::vector< int > &stack) {
    if (colors[vertex] == 1 && vertex == 0 && stack.size() == graph.size()) {
        std::cout << "YES\n";
        for (auto el : stack) {
            std::cout << el + 1 << " ";
        }
        std::cout << vertex + 1 << "\n";
        exit(0);
    }
    if (colors[vertex] != 0) {
        return;
    }

    colors[vertex] = 1;
    stack.push_back(vertex);
    for (auto u : graph[vertex]) {
        dfs(u, graph, colors, stack);
        if (vertex == 0) {
            //colors[u] = 2;
        }
    }
    colors[vertex] = 0;
    stack.pop_back();
}

void Solve(const std::vector<std::vector<int>>& graph) {
    int num_vertex = graph.size();
    std::vector<int> income(num_vertex, 0);
    std::vector<int> outcome(num_vertex, 0);

    for (int u = 0; u < num_vertex; ++u) {
        for (auto v : graph[u]) {
            income[v]++;
            outcome[u]++;
        }
    }

    for (const auto &arr : {income, outcome}) {
        for (auto val: arr) {
            if (val == 0) {
                std::cout << "NO\n";
                return;
            }
        }
    }

    //0 - white, 1 - gray, 2 - black
    std::vector < int > colors(num_vertex, 0), stack;

    dfs(0, graph, colors, stack);

    std::cout << "NO\n";
    return;

    if (false) {
        std::vector<int> multiple_output;
        for (int i = 0; i < outcome.size(); ++i) {
            if (outcome[i] > 1) {
                multiple_output.push_back(i);
            }
        }

        std::set<std::pair<int, int>> chains;
        for (int u = 0; u < num_vertex; ++u) {
            if (outcome[u] > 1) {
                continue;
            }
            for (auto v: graph[u]) {
                chains.insert({u, v});
            }
        }

        while (!chains.empty()) {
            auto head = *chains.begin();

        }
    }

}

void Run() {
    auto graph = Read();
    Solve(graph);
}