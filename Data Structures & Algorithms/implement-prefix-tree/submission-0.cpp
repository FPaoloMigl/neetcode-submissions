// To create a trie we first need the node of the tree
class TrieNode {
public:
    // we need the map to keep track of the sequenc
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false; // this is used to keep track when the word ends
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        // we first need the root node
        root = new TrieNode();      
    }
    
    void insert(string word) {
        // We need to set the curr pointer to the root node
        TrieNode* curr = root;

        // for each letter in the word
        for (char c : word) {
            // we need to check if the letter is already in children, if not add it
            if (curr->children.find(c) == curr->children.end()) {
                // word not present in the children then add it
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        // at the end we reach the end of the word and set end of word = true
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        // always start from the root
        TrieNode* cur = root;

        for (char c: word) {
            // we can't use [] operator otherwise we are gonna access the pointer, hence the value
            // of the hashmap with key value = c
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }
            cur = cur->children[c];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;

        // we check the prefix
        for (char c : prefix) {
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }

            // move to the next letter
            cur = cur->children[c];
        }

        return true;
    }
};
