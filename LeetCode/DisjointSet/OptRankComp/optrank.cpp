#include <vector>
#include <iostream>
using namespace std;
class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            tree = valid;
        } 
        else 
        {
            tree = invalid;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};

// Test Case
int main() {
    cout << boolalpha;
    UnionFind uf(5);
    //uf.unionSet(1, 2);
    //uf.unionSet(2, 3);
    //uf.unionSet(1, 3);
    //uf.unionSet(0, 1);
    //uf.unionSet(1, 4);

    uf.unionSet(0,1);
    uf.unionSet(0,2);
    uf.unionSet(0,3);
    uf.unionSet(1,4);

    return 0;
}