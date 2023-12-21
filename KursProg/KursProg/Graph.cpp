#include "Graph.h"



void SmezList::addSmezList_from_matrixSmez(string str)
{
    int col = 0, row = 0, col_vo_ver = 0;
    bool firstCol = 1;
    string str2, str3;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '\n')
        {
            break;
        }
        else
        {
            if (str[i] >= 'A' && str[i] <= 'z')
            {
                string vr_t;
                while (str[i] != ' ' && str[i] != '\n')
                {
                    vr_t += str[i];
                    i++;
                }
                spis_ver.push_back(vr_t);
                col_vo_ver++;
            }
        }
    }
    number_ver = col_vo_ver;
    for (int i = 0; i < str.size(); i++)
    {
        str2 = spis_ver[row];
        int number = 0;
        if (str[i] >= '0' && str[i] <= '9')
        {
            while (str[i] != ' ' && str[i] != '\n')
            {
                str3.push_back(str[i]);
                i++;
            }
            col++;
            number = stoi(str3);
            str3.clear();
        }
        if (col > col_vo_ver || row > col_vo_ver)
        {
            cout << "Ошибка ввода";
            return;
        }
        if (number > 0)
        {
            Edge smezNode;
            smezNode.to = str2;
            smezNode.from = spis_ver[col - 1];
            smezNode.weight = number;
            bool go_Graph = 1;
            for (int i = 0; i < GraphList.size(1); i++)
            {
                if (GraphList[i].from == smezNode.to && GraphList[i].to == smezNode.from &&
                    GraphList[i].weight == smezNode.weight)
                {
                    go_Graph = 0;
                    break;
                }
            }
            if (go_Graph)
                GraphList.push_back(smezNode);
            

        }
        if (str[i] == '\n')
        {
            if (firstCol)
            {
                firstCol = 0;
            }
            else row++;
            col = 0;
        }
    }
}

void SmezList::indentMatrixOut()
{  
    for (int i = 0; i < spis_ver.size(1); i++)
    {
        cout << spis_ver[i] << " ";
        for (int h = 0; h < GraphList.size(1); h++)
        {
            if (GraphList[h].to == spis_ver[i] || GraphList[h].from == spis_ver[i])
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;        
    }
}

DynamicArray<strPair> SmezList::strTop()
{
    DynamicArray<strPair> top;
    int ch = 1;
    for (int i = 0; i < GraphList.size(1); i++)
    {
        if (top.size(1) != 0)
        {
            bool no_top_first = 1, no_top_second = 1;
            for (int g = 0; g < top.size(1); g++)
            {
                if (GraphList[i].from == top[g].first)
                {
                    no_top_first = 0;
                }
            }
            for (int g = 0; g < top.size(1); g++)
            {
                if (GraphList[i].to == top[g].first)
                {
                    no_top_second = 0;
                }
            }
            if (no_top_first)
            {
                top.push_back(make_pair(GraphList[i].from, ch++));
            }
            if (no_top_second)
            {
                top.push_back(make_pair(GraphList[i].to, ch++));
            }
        }
        else
        {
            top.push_back(make_pair(GraphList[i].from, ch++));
            if (GraphList[i].from != GraphList[i].to)
            {
                top.push_back(make_pair(GraphList[i].to, ch++));
            }
        }
        if (ch > number_ver)
        {
            break;
        }
    }
    return top;

}

void SmezList::mergeSort (int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

void SmezList::merge(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    DynamicArray<Edge> Left;
    DynamicArray<Edge> Right;

    for (int i = 0; i < n1; i++) {
        Left[i] = GraphList[left + i];
    }

    for (int i = 0; i < n2; i++) {
        Right[i] = GraphList[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (Left[i].weight <= Right[j].weight) 
        {
            GraphList[k] = Left[i];
            i++;
        }
        else {
            GraphList[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        GraphList[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2) {
        GraphList[k] = Right[j];
        j++;
        k++;
    }
}

void Graph::DFSUtil(int v, bool visited[], DynamicArray<strPair>& top)
{
    visited[v] = true;
    string strV;
    for (int i = 0; i < top.size(1); i++)
    {
        if (top[i].second == v)
        {
            strV = top[i].first;
            break;
        }
    }
    cout << strV << " ";
    for (int i = 0; i != adj[v].size(1); i++)
    {
        if (!visited[adj[v][i].first])
        {
            DFSUtil(adj[v][i].first, visited, top);
        }
    }
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new DynamicArray<Pair>[V];
}



Graph::~Graph()
{
    delete[] adj;
}


void Graph::addEdge(int v, int w, int weight)
{
    adj[v].push_back(make_pair(w, weight));
    adj[w].push_back(make_pair(v, weight));
}

void Graph::dfs(string v, SmezList& G)
{
    bool* visited = new bool[V];
    int Iv = 0;
    DynamicArray<strPair> top = G.strTop();
    for (int i = 0; i < top.size(1); i++)
    {
        if (top[i].first == v)
        {
            Iv = top[i].second;
            break;
        }
    }
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    DFSUtil(Iv, visited, top);

    delete[] visited;
}

void Graph::bfs(string v, SmezList& G)
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    int Iv = 0;
    DynamicArray<strPair> top = G.strTop();
    for (int i = 0; i < top.size(1); i++)
    {
        if (top[i].first == v)
        {
            Iv = top[i].second;
            break;
        }
    }
    queue<int> queue;
    visited[Iv] = true;
    queue.push(Iv);
    while (!queue.empty())
    {
        Iv = queue.front();
        for (int i = 0; i < top.size(1); i++)
        {
            if (top[i].second == Iv)
            {
                v = top[i].first;
                break;
            }
        }
        cout << v << " ";
        queue.pop();

        for (int i = 0; i != adj[Iv].size(1); i++)
        {
            if (!visited[adj[Iv][i].first])
            {
                visited[adj[Iv][i].first] = true;
                queue.push(adj[Iv][i].first);
            }
        }
    }

    delete[] visited;
}

void Graph::kruskal(SmezList& G)
{
    G.mergeSort(0, G.GraphList.size(1) - 1);
    DynamicArray<int> parent;    // создаёт массив куда заносятся значения добавленных рёбер, а если их нет, то значение -1
    for (int i = 0; i < V; i++)
    {
        parent.push_back(-1);
    }

    DynamicArray<strPair> top = G.strTop();
    int j = 0;
    while (j < G.GraphList.size(1))
    {
        Edge next_edge = G.GraphList[j++];
        int fromG, toG;
        for (int g = 0; g < top.size(1); g++)
        {
            if (next_edge.from == top[g].first)
            {
                fromG = top[g].second;
            }
            if (next_edge.to == top[g].first)
            {
                toG = top[g].second;
            }
        }
        int x = findParent(parent, toG);
        int y = findParent(parent, fromG);
        if (x != y)
        {
            addEdge(toG, fromG, next_edge.weight);
            unionSets(parent, x, y);
        }
    }
}

void Graph::out_rez(SmezList& G)
{
    int we = 0;
    DynamicArray<Pair> buffer;
    for (int i = 0; i < V; i++)
    {
        for (int g = 0; g < adj[i].size(1); g++)
        {
            buffer.push_back(make_pair(i, adj[i][g].first));
            bool rep = 0;
            for (int j = 0; j < buffer.size(1); j++)
            {
                if (i == buffer[j].second && adj[i][g].first == buffer[j].first)
                    rep = 1;
            }
            if (!rep)
            {
                string strVI = "", strAdj = "";
                DynamicArray<strPair> top = G.strTop();
                for (int j = 0; j < top.size(1); j++)
                {
                    if (top[j].second == i)
                    {
                        strVI = top[j].first;
                    }
                    if (top[j].second == adj[i][g].first)
                    {
                        strAdj = top[j].first;
                    }
                    if (strVI != "" && strAdj != "")
                        break;
                }
                cout << strVI << " " << strAdj << endl;
                we += adj[i][g].second;
            }
        }
    }
    cout << we;
}
