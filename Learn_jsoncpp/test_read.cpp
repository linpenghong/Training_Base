#include <string>
#include <iostream>
#include <fstream>

#include "json/json.h"

using namespace std;

void readFileJson();

int main()
{
    readFileJson();

    return 0;
}

void readFileJson()
{
    Json::Reader reader;
    Json::Value root;

    ifstream in("test.json", ios::binary);

    if (!in.is_open())
    {
        cout << "Error opening file\n";
        return;
    }

    if (reader.parse(in, root))
    {
        cout << "parse success!" << endl;

        // read information from root

        string name = root["name"].asString();
        cout << "My name is " << name << "." << endl;

        int age = root["age"].asInt();
        cout << "I'm " << age << " years old." << endl;

        bool sex_is_male = root["sex_is_male"].asBool();
        cout << "I'm a " << (sex_is_male ? "man" : "woman") << "." << endl;

        // read information from subtree
        
        string partner_name = root["partner"]["partner_name"].asString();
        cout << "My partner's name is " << partner_name << "." << endl;

        int partner_age = root["partner"]["partner_age"].asInt();
        bool partner_sex_is_male = root["partner"]["partner_sex_is_male"].asBool();

        cout << (partner_sex_is_male ? "He" : "She")
             << " is "
             << partner_age
             << " years old."
             << endl;

        // read array
        
        cout << "Here is my achievements:" << endl;
        for (unsigned int i = 0; i < root["achievement"].size(); i++)
        {
            string ach = root["achievement"][i].asString();
            cout << ach << '\t';
        }
        cout << endl;

        cout << "Reading complete!" << endl;
    }
    else
    {
        cout << "parse error!" << endl;
    }
}
