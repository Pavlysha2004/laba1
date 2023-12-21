#include "Graph.h"
#include <fstream>

int main()
{
	setlocale(LC_CTYPE, "Russian");
    string str;

	string filename = "Matrix.txt";
    ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
        return 1;
    }
    string line;
    while (std::getline(file, line))
    {
        str += line;
        str += '\n';
    }
    file.close();
    SmezList arr;
    arr.addSmezList_from_matrixSmez(str);
    cout << "Полученный список смежности из файла:\n";
    for (int i = 0; i < arr.GraphList.size(1); i++)
    {
        cout << arr.GraphList[i].to << " " << arr.GraphList[i].from << " " << arr.GraphList[i].weight << endl;
    }
    cout << endl;
    cout << "Матрица индентности:";
    cout << endl;
    arr.indentMatrixOut();
    Graph MyG(arr.number_ver + 1);
    MyG.kruskal(arr);
    cout << "\nОбход полученного графа в ширину (Начиная с элемента D):\n";
    MyG.bfs("D", arr);
    cout << "\nОбход полученного графа в глубину (Начиная с элемента D):\n";
    MyG.dfs("D", arr);

    cout << "\n" << endl;
    cout << "Полученный результат:\n";
    MyG.out_rez(arr);
    return 0;
}
