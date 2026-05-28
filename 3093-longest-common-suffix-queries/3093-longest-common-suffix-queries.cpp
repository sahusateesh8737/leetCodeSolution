#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // trie[i][c] store karega ki node 'i' se character 'c' par jaane par kaun sa naya node ID milega
    vector<vector<int>> trie;
    // minIndexTable[i] store karega node 'i' par ab tak ka sabse best word index
    vector<int> minIndexTable;
    int nextNodeId;

    // Helper to check if current index 'i' is better than existing 'bestIdx'
    bool isBetter(int i, int bestIdx, const vector<string>& wordsContainer) {
        if (bestIdx == -1) return true;
        if (wordsContainer[i].length() < wordsContainer[bestIdx].length()) return true;
        if (wordsContainer[i].length() == wordsContainer[bestIdx].length()) return i < bestIdx;
        return false;
    }

    // Naya node create karne ka optimized function
    void createNewNode() {
        trie.push_back(vector<int>(26, -1));
        minIndexTable.push_back(-1);
    }

    void insert(string& word, int wordIdx, const vector<string>& wordsContainer) {
        int currNode = 0; // Root node ID hamesha 0 hota hai
        int n = word.length();

        // Reverse order mein loop (Suffix to Prefix)
        for (int i = n - 1; i >= 0; i--) {
            int charIdx = word[i] - 'a';

            // Agar naya character hai, to matrix mein space badhao
            if (trie[currNode][charIdx] == -1) {
                trie[currNode][charIdx] = nextNodeId++;
                createNewNode();
            }

            currNode = trie[currNode][charIdx];
            
            // Best index update karo is node ke liye
            if (isBetter(wordIdx, minIndexTable[currNode], wordsContainer)) {
                minIndexTable[currNode] = wordIdx;
            }
        }
    }

    int search(string& query, int defaultBest) {
        int currNode = 0;
        int n = query.length();
        int bestIdx = defaultBest;

        for (int i = n - 1; i >= 0; i--) {
            int charIdx = query[i] - 'a';

            if (trie[currNode][charIdx] == -1) {
                break;
            }

            currNode = trie[currNode][charIdx];
            bestIdx = minIndexTable[currNode];
        }
        return bestIdx;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Memory clear aur reset karo har test case ke liye
        trie.clear();
        minIndexTable.clear();
        nextNodeId = 1;

        // Root node (ID = 0) create karo
        createNewNode();

        // 1. Default absolute best index dhoondho (empty suffix ke liye)
        int defaultBest = 0;
        for (int i = 1; i < wordsContainer.size(); i++) {
            if (isBetter(i, defaultBest, wordsContainer)) {
                defaultBest = i;
            }
        }
        minIndexTable[0] = defaultBest; // Root ka default index

        // 2. Insert words
        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        // 3. Process queries
        vector<int> ans;
        for (int i = 0; i < wordsQuery.size(); i++) {
            ans.push_back(search(wordsQuery[i], defaultBest));
        }

        return ans;
    }
};