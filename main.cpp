#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
    Trie trie;

    // Изначально заданный словарь
    vector<string> dictionary = { "apple", "application", "applet", "banana", "band", "bandwidth", "bandana" };

    // Добавляем слова из словаря в дерево
    for (const string& word : dictionary) {
        trie.insert(word);
    }

    string input;
    cout << "Введите часть слова для автодополнения (или 'exit' для выхода): " << endl;

    while (true) {
        cout << "Часть слова: ";
        cin >> input;

        // Выход из программы
        if (input == "exit") {
            break;
        }

        // Поиск слов по префиксу
        vector<string> suggestions = trie.searchByPrefix(input);

        if (suggestions.empty()) {
            cout << "Нет совпадений." << endl;
        }
        else {
            cout << "Возможные варианты:" << endl;
            for (const string& word : suggestions) {
                cout << " - " << word << endl;
            }
        }
    }

    return 0;
}
