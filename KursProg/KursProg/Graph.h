#pragma once
#include <iostream>
#include "dinMass.h"
#include <queue>

using namespace std;
typedef pair<int, int> Pair;
typedef pair<string, int> strPair;


struct Edge // ��� ������ ���������
{
    int weight;
    string to, from;
};

struct SmezList //��� ������ ���������
{
    DynamicArray<Edge> GraphList;
    DynamicArray<string> spis_ver;
    int number_ver = 0;
    void addSmezList_from_matrixSmez(string);
    void indentMatrixOut();
    void merge(int p, int q, int r);
    void mergeSort(int p, int r);
    DynamicArray<strPair> strTop();
};

class Graph
{
private:
    int V; // ��������� ������
    DynamicArray<Pair>* adj; 
    // ������ ���������, ��� ����� �������� ������� ��� ����� �������, 
    //������ int ��� ����� ���� ��� �������, � ������, ��� �����
    void DFSUtil(int v, bool visited[], DynamicArray<strPair>& top); // ������� ������ ��� �������� ������ � �������
    int findParent(DynamicArray<int>& parent, int i)   // ������ ��������
    {
        if (parent[i] == -1) return i;
        return findParent(parent, parent[i]);
    }
    void unionSets(DynamicArray<int>& parent, int x, int y) // ���
    {
        int xset = findParent(parent, x);
        int yset = findParent(parent, y);
        parent[xset] = yset;
    }

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w, int weight);
    void dfs(string v, SmezList& G);  // ����� � �������
    void bfs(string v, SmezList& G);  // ����� � ������ 
    void kruskal(SmezList& G);
    void out_rez(SmezList& G);
};

