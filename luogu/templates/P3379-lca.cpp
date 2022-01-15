#include <iostream>
#include <vector>

class LCA {
private:
    std::vector<std::vector<int>> tree;
    std::vector<std::vector<int>> fa;
    std::vector<int> depth;

    void dfs(int root, int fno) {
        fa[root][0] = fno;
        depth[root] = depth[fno] + 1;

        for (int i = 1; i < 31; i++) {
            fa[root][i] = fa[fa[root][i - 1]][i - 1];
        }

        for (int i = 0; i < tree[root].size(); ++i) {
            if (tree[root][i] == fno) continue;

            dfs(tree[root][i], root);
        }
    }

    int lca(int x, int y) {
        if (depth[x] > depth[y]) std::swap(x, y);

        int tmp = depth[y] - depth[x], ans = 0;
        for (int j = 0; tmp > 0; ++j, tmp >>= 1) {
            if (tmp & 1) {
                y = fa[y][j];
            }
        }

        if (x == y) return x;

        for (int j = 30; j >= 0 && x != y; --j) {
            if (fa[x][j] != fa[y][j]) {
                x = fa[x][j];
                y = fa[y][j];
            }
        }

        return fa[x][0];
    }

public:
    LCA(int vertex_nums) {
        tree.resize(vertex_nums);
        fa.resize(vertex_nums);
        for (int i = 0; i < vertex_nums; ++i) {
            fa[i].resize(31);
        }

        depth.resize(vertex_nums);
    }

    void add_edge(int x, int y) {
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    void process(int root, int father) { dfs(root, father); }

    int query(int x, int y) { return lca(x, y); }
};

int main(int argc, char **argv) {
    LCA lca(6);

    lca.add_edge(3, 1);
    lca.add_edge(2, 4);
    lca.add_edge(5, 1);
    lca.add_edge(1, 4);

    lca.process(4, 4);

    std::vector<std::pair<int, int>> q = {
        {2, 4},
        {3, 2},
        {3, 5},
        {1, 2},
        {4, 5},
    };
    for (auto i : q) {
        std::cout << i.first << " " << i.second << "\t";
        std::cout << lca.query(i.first, i.second) << std::endl;
    }

    return 0;
}