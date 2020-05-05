#include <iostream>
#include <map>
using namespace std;

class Folder {
public:
    map<string, Folder *> inside;
    Folder *getFolder(string const name) {
        if (inside.find(name) != inside.end()) {
            return inside[name];
        } else {
            inside[name] = new Folder();
            return inside[name];
        }
    }
    void show(string space) {
        string tab = " ";
        tab += space;
        map<string, Folder*>::iterator it;
        for (it = inside.begin(); it != inside.end(); it++) {
            cout << space << it->first << endl;
            it->second->show(tab);
        }
    }

};

int main() {
    int count;
    cin >> count;
    string path;
    Folder *main = new Folder();
    for (int i = 0; i < count; i++) {
        cin >> path;
        size_t pos = 0;
        Folder *cur = main;
        string del = "\\";
        string token;
        while ((pos = path.find(del)) != string::npos) {
            token = path.substr(0, pos);
            cout << token << endl;
            cur = cur->getFolder(token);
            path.erase(0, pos + del.length());
        }
        cur->getFolder(path);
    }
    main->show("");
}