#include <vector>
#include <iostream>
#include <set>
using namespace std;
class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz)
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
        }
    }
    bool connected(int x, int y) 
    {
        return find(x) == find(y);
    }
    int getProvinces()
    {
        for(int i=0; i<root.size(); i++)
        {
            province.insert(find(i));
        }
        return province.size();
    }
private:
    vector<int> root;
    vector<int> rank;
    set<int> province;
};
int findCircleNum(vector<vector<int>>& isConnected){
    UnionFind uf(isConnected.size());
    for(auto i=0; i < isConnected.size(); i++){
        for(auto j=i; j< isConnected.size(); j++){
            if(isConnected[i][j] == 1){
                uf.unionSet(i,j);
            }
        }
    }
    return uf.getProvinces();
}
// Test Case
int main() {
    // for displaying booleans as literal strings, instead of 0 and 1
    vector<vector<int>> isConnected{
    /*        1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 */
    /* 1 */  {1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    /* 2 */  {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* 3 */  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    /* 4 */  {0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    /* 5 */  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    /* 6 */  {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    /* 7 */  {0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
    /* 8 */  {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    /* 9 */  {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
    /* 10 */ {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    /* 11 */ {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
    /* 12 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    /* 13 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    /* 14 */ {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
    /* 15 */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}
    };
    cout << boolalpha;
    // 1-2-3-4-5 6-8-9 0 7
    //uf.unionSet(1, 1);
    //uf.unionSet(1, 2);
    //uf.unionSet(2, 1);
    //uf.unionSet(2, 2);
    //uf.unionSet(3, 3);
    //cout << uf.connected(1, 3) << endl;
    cout << findCircleNum(isConnected) << endl;
    return 0;
}