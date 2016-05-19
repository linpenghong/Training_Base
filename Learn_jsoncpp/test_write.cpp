#include <string>
#include <iostream>
#include <fstream>

#include "json/json.h"

using namespace std;

void writeFileJson();

int main()
{
    writeFileJson();

    return 0;
}

void writeFileJson()
{
    // root
    Json::Value root;

    // attributes of root
    root["name"] = Json::Value("Mike King");
    root["age"] = Json::Value(23);
    root["sex_is_male"] = Json::Value(true);

    // subtree
    Json::Value partner;
    partner["partner_name"] = Json::Value("Galatea");
    partner["partner_age"] = Json::Value(21);
    partner["partern_sex_is_male"] = Json::Value(false);

    // append subtree to root
    root["partern"] = Json::Value(partner);

    // array
    root["achievement"].append("ach1");
    root["achievement"].append("ach2");
    root["achievement"].append("ach3");

    // fast writer
    cout << "FastWriter:" << endl;
    Json::FastWriter fw;
    cout << fw.write(root) << endl << endl;
    
    // styled write
    cout << "StyledWriter:" << endl;
    Json::StyledWriter sw;
    cout << sw.write(root) << endl << endl;

    // write to file
    ofstream os;
    os.open("demo.json");
    os << sw.write(root);
    os.close();
}
