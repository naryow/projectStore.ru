#include "NodeData.h"
#include <iomanip>
#include <sstream>

using namespace std;

int NodeData::countId = 1;
vector<string> NodeData::products_names = { "other", "meat", "milk", "grocery" };

map<string, string> NodeData::product_map = {
    {"meat", "1"},
    {"grocery", "2"},
    {"milk", "3"},
    {"other", "4"}
};

NodeData::NodeData(const string& products_name) {
    this->products_name = products_name;
    this->id = countId++;
    this->category_id = NodeData::product_map[products_name];
}

NodeData::NodeData(int id, const string& name) {
    this->id = id;
    this->products_name = name;
    this->category_id = NodeData::product_map[name];
}

int NodeData::getId() const {
    return id;
}



string NodeData::NodeString() const {
    stringstream ss;
    ss << setw(10) << left << id << " "
        << setw(15) << left << to_string(id) + ";" + products_name << "   "
        << setw(10) << left << category_id;
    return ss.str();
}

NodeData* NodeData::generateProducts() {
    NodeData* node = new NodeData(products_names[random(0, products_names.size() - 1)]);
    return node;
}

NodeData* NodeData::findId(string product_id) {
    for (const auto& pair : NodeData::product_map) {
        if (pair.second == product_id) {
            return new NodeData(stoi(product_id), pair.first);
        }
    }
    return nullptr;
}

void NodeData::showInterface() const {
    cout << left << setw(10) << "product_id" << "|"
        << left << setw(15) << "product_name" << "|"
        << left << setw(10) << "category_id" << "|" << endl;

    cout << string(10, '-') << "|"
        << string(15, '-') << "|"
        << string(10, '-') << "|" << endl;
}