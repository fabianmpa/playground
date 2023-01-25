#include <vector>
#include <iostream>

using namespace std;

class UnionFind {
    public:
        UnionFind(int sz): root(sz){
            for(int i=0; i<sz; i++){
                root[i] = i;
            }
        }

    int find(int x){
        while(x != root[x]){
            x = root[x];
        }
        return x;
    }

    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY){
            root[rootY] = rootX;
        }
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }

    vector <int> root;
};

// Test Case
int main() {
    // for displaying booleans as literal strings, instead of 0 and 1
    cout << boolalpha;
    UnionFind uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);
    cout << uf.connected(1, 5) << endl;  // true
    cout << uf.connected(5, 7) << endl;  // true
    cout << uf.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9, 4);
    // 0-1-2-5-6-7 3-8-9-4
    uf.unionSet(0, 7);
    // in gdb, print with "p uf->uf root" and you will get {0,0,1,3,3,1,1,1,3,3}
    // this is because only the root node is updated (1, previously) as we have a new root node, which in this case is zero (0)
    // so now, 0 is the new root of the chain 1-2-5-6-7
    cout << uf.connected(4, 9) << endl;  // true

    return 0;
}