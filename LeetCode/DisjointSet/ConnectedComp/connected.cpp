class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz), comp(sz)
    {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x) 
    {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }
    void unionSet(int x, int y) 
    {
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
            comp--; 
        }
    }
    int getNumber()
    {
        return comp;
    }
private:
    vector<int> root;
    vector<int> rank;
    int comp;
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind ut(n);
        for(int i=0; i < edges.size(); i++)
        {
            ut.unionSet(edges[i][0],edges[i][1]);
        }
        return ut.getNumber();   
    }
};