#pragma once
#include "DataBase.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#define random(a,b) a+rand()%(b+1-a)
using namespace std;

class NodeData : public DataBase {
private:
    int id;
    string products_name;
    string category_id;
    static int countId;
    static vector<string> products_names;

public:
    NodeData() = default;
    NodeData(const string& products_name);
    NodeData(int id, const string& name);
    int getId() const;
    string NodeString() const;
    static NodeData* generateProducts();
    static NodeData* findId(string product_id);
    void showInterface() const;
    static  vector<string> product_ids;
    static map<string, string> product_map;


};
