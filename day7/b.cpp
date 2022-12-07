#include <bits/stdc++.h>
using namespace std;

#define int long long

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#endif

struct Node {
    int size;
    string directory;
    Node *parent;
    vector<Node*> children;
};

class FileSystem {
public:
    Node *rootDir;
    Node *currentDir;
    string currentPath;

    FileSystem() {
        rootDir = new Node();
        rootDir->size = 0;
        rootDir->directory = "/";
        rootDir->parent = NULL;
    }

    void cd(string dir) {
        for (int i = 0; i < (int)currentDir->children.size(); i++) {
            if (currentDir->children[i]->directory == dir) {
                currentDir = currentDir->children[i];
                break;
            }
        }
    }

    void cdBack() {
        if (currentDir->parent != NULL) {
            currentDir = currentDir->parent;
        }
    }

    void cdRoot() {
        currentDir = rootDir;
    }

    void mkdir(Node *newDir) {
        if (rootDir == NULL) {
            rootDir = newDir;
        } else {
            currentDir->children.push_back(newDir);
            newDir->parent = currentDir;
        }
    }

    void adjustSize(int size) {
        currentDir->size += size;
        Node *temp = currentDir;
        while (temp->parent != NULL) {
            temp->parent->size += size;
            temp = temp->parent;
        }
    }

    int solveHelper(Node *node, int dirSize) {
        int minSize = INT_MAX;

        if (node->size >= dirSize) {
            minSize = node->size;
        }

        for (int i = 0; i < (int)node->children.size(); i++) {
            int temp = solveHelper(node->children[i], dirSize);
            if (temp < minSize) {
                minSize = temp;
            }
        }

        return minSize;
    }

    int solve() {
        return solveHelper(rootDir, rootDir->size - 40000000);
    }

};

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    FileSystem fs = FileSystem();

    string line;

    while (getline(cin, line)) {
        if (line[0] == '$') {
            if (line[2] == 'c') {
                if (line[5] == '.') {
                    fs.cdBack();
                } else if (line[5] == '/') {
                    fs.cdRoot();
                } else {
                    fs.cd(line.substr(5));
                }
            }
        } else {
            if (line[0] == 'd') {
                Node *newDir = new Node();
                newDir->directory = line.substr(4);

                fs.mkdir(newDir);
            } else {
                fs.adjustSize(stoll(line.substr(0, line.find(' '))));
            }
        }
    }

    cout << fs.solve() << '\n';
}
