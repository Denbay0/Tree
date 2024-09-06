#pragma once

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Узел префиксного дерева
struct TrieNode {
    unordered_map<char, TrieNode*> children; // Дети данного узла
    bool isEndOfWord;                        // Является ли узел концом слова

    TrieNode(); // Конструктор
};

// Префиксное дерево (Trie)
class Trie {
public:
    Trie(); // Конструктор

    // Функция добавления слова в префиксное дерево
    void insert(const string& word);

    // Поиск всех слов с данным префиксом
    vector<string> searchByPrefix(const string& prefix);

private:
    TrieNode* root;

    // Рекурсивная функция для поиска всех слов
    void findAllWords(TrieNode* node, const string& currentPrefix, vector<string>& results);
};
