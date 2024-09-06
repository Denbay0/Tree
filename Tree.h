#pragma once

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// ���� ����������� ������
struct TrieNode {
    unordered_map<char, TrieNode*> children; // ���� ������� ����
    bool isEndOfWord;                        // �������� �� ���� ������ �����

    TrieNode(); // �����������
};

// ���������� ������ (Trie)
class Trie {
public:
    Trie(); // �����������

    // ������� ���������� ����� � ���������� ������
    void insert(const string& word);

    // ����� ���� ���� � ������ ���������
    vector<string> searchByPrefix(const string& prefix);

private:
    TrieNode* root;

    // ����������� ������� ��� ������ ���� ����
    void findAllWords(TrieNode* node, const string& currentPrefix, vector<string>& results);
};
