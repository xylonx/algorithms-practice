#include <iostream>
#include <queue>
#include <vector>

class SPFA {
private:
    struct outedge {
        int idx, w;
        outedge(int v, int w) {
            this->idx = v;
            this->w   = w;
        }
    };

    std::vector<std::vector<struct outedge>> graph;

public:
    SPFA(int vertex_num) { graph.resize(vertex_num); }

    void reset(int vertex_num) { graph.resize(vertex_num); }

    void add_edge(int u, int v, int w) {
        struct outedge e(v, w);
        graph[u].push_back(e);
    }

    bool contains_neg_cycle(int s) {
        int dis[graph.size()], cnt[graph.size()], vis[graph.size()];
        std::queue<int> q;
        for (int i = 0; i < graph.size(); ++i) {
            dis[i] = INT_MAX;
            cnt[i] = 0;
            vis[i] = false;
        }
        vis[s] = true;
        dis[s] = 0;
        cnt[s]++;
        q.push(s);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            vis[u] = false;
            if (cnt[u] >= graph.size() - 1) return true;
            cnt[u]++;
            for (auto v : graph[u]) {
                // relax
                if (dis[v.idx] > dis[u] + v.w) {
                    dis[v.idx] = dis[u] + v.w;
                    if (!vis[v.idx]) {
                        q.push(v.idx);
                        vis[v.idx] = true;
                    }
                }
            }
        }
        return false;
    }
};

int main(int argc, char **argv) {
    SPFA s(3);
    s.add_edge(0, 1, 2);
    s.add_edge(0, 2, 4);
    s.add_edge(1, 2, 1);
    s.add_edge(2, 0, -3);

    std::cout << s.contains_neg_cycle(0) << std::endl;

    s.reset(4);
    s.add_edge(1, 2, 3);
    s.add_edge(2, 3, 4);
    s.add_edge(3, 1, -8);
    std::cout << s.contains_neg_cycle(1) << std::endl;
}