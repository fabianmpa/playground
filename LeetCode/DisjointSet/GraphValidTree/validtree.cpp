#include "validtree.h"
int UnionFind::find(int x) 
{
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
}
void UnionFind::unionSet(int x, int y) 
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
            count--; 
        }
        else
        {
            validTree = false;
        }
}
bool UnionFind::connected(int x, int y) 
{
        return find(x) == find(y);
}
int UnionFind::isValidTree()
{
        if(count != 1)
        {
            validTree = false;
        }
        return validTree;
}
bool validTree(int n, vector<vector<int>>& edges)
{
        UnionFind ut(n);
        for(int i=0; i < edges.size(); i++)
        {
            ut.unionSet(edges[i][0],edges[i][1]);
        }
        return ut.isValidTree();
}
//int main() 
//{
//    cout << boolalpha;
//    int n = 4;
//    vector<vector<int>> edges{
//    {0,1},
//    {2,3},
//    {1,2}
//    };
//    cout << validTree(n,edges) << endl;
//    return 0;
//}