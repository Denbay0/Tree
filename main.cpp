#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
    Trie trie;

    // ���������� �������� �������
    vector<string> dictionary = { "apple", "application", "applet", "banana", "band", "bandwidth", "bandana" };

    // ��������� ����� �� ������� � ������
    for (const string& word : dictionary) {
        trie.insert(word);
    }

    string input;
    cout << "������� ����� ����� ��� �������������� (��� 'exit' ��� ������): " << endl;

    while (true) {
        cout << "����� �����: ";
        cin >> input;

        // ����� �� ���������
        if (input == "exit") {
            break;
        }

        // ����� ���� �� ��������
        vector<string> suggestions = trie.searchByPrefix(input);

        if (suggestions.empty()) {
            cout << "��� ����������." << endl;
        }
        else {
            cout << "��������� ��������:" << endl;
            for (const string& word : suggestions) {
                cout << " - " << word << endl;
            }
        }
    }

    return 0;
}
