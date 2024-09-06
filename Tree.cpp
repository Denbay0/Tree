#include "Tree.h"

// Конструктор TrieNode
TrieNode::TrieNode() : isEndOfWord(false) {}

// Конструктор Trie
Trie::Trie() {
    root = new TrieNode();
}

// Функция добавления слова в префиксное дерево
void Trie::insert(const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (node->children.find(ch) == node->children.end()) {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->isEndOfWord = true;  // Помечаем конец слова
}

// Поиск всех слов с данным префиксом
vector<string> Trie::searchByPrefix(const string& prefix) {
    vector<string> results;
    TrieNode* node = root;

    // Идем по дереву до конца префикса
    for (char ch : prefix) {
        if (node->children.find(ch) == node->children.end()) {
            return results; // Если префикс не найден, возвращаем пустой результат
        }
        node = node->children[ch];
    }

    // Собираем все слова с данным префиксом
    findAllWords(node, prefix, results);
    return results;
}

// Рекурсивная функция для поиска всех слов
void Trie::findAllWords(TrieNode* node, const string& currentPrefix, vector<string>& results) {
    if (node->isEndOfWord) {
        results.push_back(currentPrefix);  // Добавляем найденное слово в результаты
    }

    for (const auto& pair : node->children) {
        findAllWords(pair.second, currentPrefix + pair.first, results);
    }
}
