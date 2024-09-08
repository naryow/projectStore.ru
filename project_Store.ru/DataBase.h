#pragma once
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class DataBase {
private:
    string path;
    vector<string> splitStr(string str, char del);

public:
    DataBase() = default;
    DataBase(string path);
    string addLine(const string& line);
    bool removeLines(const vector<int>& ids);
    void showDoc();
};
