#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;
    Node(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

map<char, int> freqMap;
map<char, string> codes;

void generateCodes(Node* root, string str) {
    if (!root) return;
    if (root->data != '$') {
        codes[root->data] = str;
        return ;
    }

    generateCodes(root->left, str + '0');
    generateCodes(root->right, str + '1');
}

void buildTree(string text) {
    for (auto ch : text) {
        freqMap[ch]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto p : freqMap) {
        pq.push(new Node(p.first, p.second));
    }

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node* top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    generateCodes(pq.top(), "");
}

int main()
{
    string text = "the pandemic of covid is a test of social system";
    buildTree(text);

    int sum = 0;

    cout << "=========================" << "\n";
    cout << "字符频数分别是:\n";
    for (auto p : freqMap) {
        cout << p.first << "出现 " << p.second << " 次\n";
    }

    cout << "=========================" << "\n";
    for (auto p : codes) {
        sum += freqMap[p.first] * p.second.length();
        cout << p.first << "编码为: ";
        cout << p.second << " 长度为: ";
        cout << p.second.length() << "\n";
    }
    
    cout << "=========================" << "\n";
    cout << "文档总长度为: " << sum << "\n";

    return 0;
}