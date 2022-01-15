#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>

class PrimMST {
private:
    struct node {
        int idx, weight;
        node(int v, int w) {
            this->idx    = v;
            this->weight = w;
        }
    };

    std::vector<bool> vis;
    std::vector<std::vector<struct node>> adj;
    // distense -> (u, v)
    std::vector<std::pair<int, std::pair<int, int>>> dis;

    int get_min_dis_idx() {
        int min = INT_MAX, idx = 0;
        for (int i = 0; i < dis.size(); ++i) {
            if (!vis[i] && dis[i].first < min) {
                min = dis[i].first;
                idx = i;
            }
        }
        vis[idx] = true;
        return idx;
    }

public:
    PrimMST(int vertex_num) {
        dis.resize(vertex_num);
        vis.resize(vertex_num);
        adj.resize(vertex_num);
    }

    void add_edge(int u, int v, int w) {
        struct node n(v, w);
        adj[u].push_back(n);
    }

    void print_mst(int n) {
        if (n >= dis.size()) return;

        int res = 0;
        for (int i = 0; i < dis.size(); ++i) {
            dis[i] = {
                INT_MAX, {n, i}
            };
            vis[i] = false;
        }
        dis[n] = {
            0, {0, 0}
        };

        std::vector<std::pair<int, int>> path;

        // add one node per loop
        for (int i = 0; i < dis.size(); ++i) {
            int u = get_min_dis_idx();

            // record the tree edge
            if (u != n) {
                path.push_back(dis[u].second);
            }

            res += dis[u].first;

            for (auto v : adj[u]) {
                if (v.weight < dis[v.idx].first) {
                    dis[v.idx].first  = v.weight;
                    dis[v.idx].second = {u, v.idx};
                }
            }
        }

        for (auto p : path) {
            std::cout << p.first << " - " << p.second << std::endl;
        }
        std::cout << "the min weight is " << res << std::endl;
    }
};

class KruskalMST {
private:
    typedef struct edge {
        int u, v, weight;
        edge(int u, int v, int w) {
            this->u      = u;
            this->v      = v;
            this->weight = w;
        }

        static bool edge_sorter(const struct edge &left, const struct edge &right) {
            return left.weight < right.weight;
        }
    } edge;

    std::vector<struct edge> edges;

    std::vector<int> f;
    int find(int x) {
        while (x != f[x]) {
            x    = f[x];
            f[x] = f[f[x]];
        }
        return x;
    }
    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        f[fx] = fy;
    }

public:
    KruskalMST(int vertex_num) {
        f.resize(vertex_num);
        for (int i = 0; i < vertex_num; ++i) {
            f[i] = i;
        }
    }

    void add_edge(int u, int v, int w) {
        struct edge n(u, v, w);
        edges.push_back(n);
    }

    void print_mst() {
        std::vector<std::pair<int, int>> path;
        int res = 0, edge_num = edges.size();

        // sort edges
        std::sort(edges.begin(), edges.end(), edge::edge_sorter);

        for (int i = 0; i < edges.size(); ++i) {
            auto e = edges[i];

            if (find(e.u) != find(e.v)) {
                merge(e.u, e.v);
                res += e.weight;

                // record path
                path.push_back({e.u, e.v});
            }
        }

        for (auto e : path) {
            std::cout << e.first << " -> " << e.second << std::endl;
        }

        std::cout << "the min weight is " << res << std::endl;
    }
};

int main(int argc, char **argv) {
    // PrimMST graph(4);
    // graph.add_edge(0, 1, 2);
    // graph.add_edge(0, 2, 2);
    // graph.add_edge(0, 3, 3);
    // graph.add_edge(1, 2, 4);
    // graph.add_edge(2, 3, 3);

    // graph.print_mst(0);

    KruskalMST graph(4);
    graph.add_edge(0, 1, 2);
    graph.add_edge(0, 2, 2);
    graph.add_edge(0, 3, 3);
    graph.add_edge(1, 2, 4);
    graph.add_edge(2, 3, 3);

    graph.print_mst();
}