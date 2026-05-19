class LFUCache {
public:

    class Node {
    public:
        int key;
        int val;
        int freq;

        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1;
        }
    };

    int cap;
    int minFreq;

    // key -> node
    unordered_map<int, Node*> keyNode;

    // freq -> list of nodes
    list<Node*> freqList[10001];

    // key -> iterator position in list
    unordered_map<int, list<Node*>::iterator> position;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFrequency(Node* node) {

        int oldFreq = node->freq;

        // Remove from old frequency list
        freqList[oldFreq].erase(position[node->key]);

        // If old list empty and was minimum
        if(freqList[oldFreq].empty() && minFreq == oldFreq) {
            minFreq++;
        }

        // Increase frequency
        node->freq++;

        int newFreq = node->freq;

        // Insert into new frequency list
        freqList[newFreq].push_back(node);

        auto it = freqList[newFreq].end();
        it--;

        position[node->key] = it;
    }

    int get(int key) {

        if(keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];

        updateFrequency(node);

        return node->val;
    }

    void put(int key, int value) {

        if(cap == 0) {
            return;
        }

        // Key already exists
        if(keyNode.find(key) != keyNode.end()) {

            Node* node = keyNode[key];

            node->val = value;

            updateFrequency(node);

            return;
        }

        // Cache full
        if(keyNode.size() == cap) {

            // Remove LRU from minimum frequency
            Node* nodeToDelete = freqList[minFreq].front();

            freqList[minFreq].pop_front();

            keyNode.erase(nodeToDelete->key);
            position.erase(nodeToDelete->key);

            delete nodeToDelete;
        }

        // Create new node
        Node* newNode = new Node(key, value);

        minFreq = 1;

        freqList[1].push_back(newNode);

        auto it = freqList[1].end();
        it--;

        keyNode[key] = newNode;
        position[key] = it;
    }
};