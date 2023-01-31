#include <vector>
#include <iostream>
using namespace std;
#pragma once
class UnionFind {
public:
    UnionFind(int sz):root(sz), rank(sz),validTree(true), count(sz)
    {        
        for (int i = 0; i < sz; i++) {
            root[i]           = i;
            rank[i]           = 1;
        }
    }
    int find(int x);
    void unionSet(int x, int y);
    bool connected(int x, int y);
    int isValidTree();
private:
    vector<int> root;
    vector<int> rank;
    bool validTree;
    int count;
};
bool validTree(int n, vector<vector<int>>& edges);