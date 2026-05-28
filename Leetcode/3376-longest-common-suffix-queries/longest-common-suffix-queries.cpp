struct TrieNode {
    int children[26];
    int best_index;

    TrieNode(){
        for(int i = 0;i<26;i++) children[i] = -1;
        best_index = -1;
    }
};

class Solution {
private:
    bool isBetter(int i, int j, const vector<string>& wordsContainer) {
        if (j == -1) return true;
        if (wordsContainer[i].length() != wordsContainer[j].length()) {
            return wordsContainer[i].length() < wordsContainer[j].length();
        }
        return i < j;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<TrieNode> trie;
        trie.push_back(TrieNode());
        int global_best = 0;
        for(int i = 1;i<wordsContainer.size();i++){
            if(isBetter(i, global_best, wordsContainer)) global_best = i;
        }
        trie[0].best_index = global_best;
        for(int i = 0;i<wordsContainer.size();i++){
            int curr = 0;
            const string& word = wordsContainer[i];
            for(int j = word.length()-1;j>=0;j--){
                int idx = word[j] - 'a';
                
                if(trie[curr].children[idx] == -1){
                    trie.push_back(TrieNode());
                    trie[curr].children[idx] = trie.size() - 1;
                }
                curr = trie[curr].children[idx];
                
                if(isBetter(i, trie[curr].best_index, wordsContainer)) trie[curr].best_index = i;
            }
        }
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for(const string& query : wordsQuery){
            int curr = 0;
            for(int j = query.length()-1;j>=0;j--){
                int idx = query[j] - 'a';
                if(trie[curr].children[idx] != -1) curr = trie[curr].children[idx];
                else break;
            }
            ans.push_back(trie[curr].best_index);
        }
        return ans;
    }
};