class Solution {
public:

    struct Node{
        int idx;
        int child[26];

        Node(){
            idx = -1;
            memset(child, -1, sizeof(child));
        }
    };

    vector<Node> trie;

    bool better(int newIdx, int oldIdx,
                vector<string>& words){

        if(oldIdx == -1) return true;

        if(words[newIdx].size() <
           words[oldIdx].size())
            return true;

        if(words[newIdx].size() ==
           words[oldIdx].size()
           && newIdx < oldIdx)
            return true;

        return false;
    }

    void insert(string &word, int idx,
                vector<string>& words){

        int node = 0;

        if(better(idx, trie[node].idx, words))
            trie[node].idx = idx;

        for(int i = word.size()-1; i >= 0; i--){

            int c = word[i]-'a';

            if(trie[node].child[c] == -1){

                trie[node].child[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[c];

            if(better(idx, trie[node].idx, words))
                trie[node].idx = idx;
        }
    }

    int search(string &q){

        int node = 0;

        for(int i = q.size()-1; i >= 0; i--){

            int c = q[i]-'a';

            if(trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.push_back(Node());

        for(int i = 0; i < wordsContainer.size(); i++)
            insert(wordsContainer[i], i,
                   wordsContainer);

        vector<int> ans;

        for(auto &q : wordsQuery)
            ans.push_back(search(q));

        return ans;
    }
};