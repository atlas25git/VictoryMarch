struct Node{
    int key;
    int value;
    Node* next,*prev;
    Node(int key,int value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    private:
    unordered_map<int,Node*> mp;
    int capacity,count;
    Node* head,*tail;
    
    public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->count = 0;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key))
        {
            Node* temp = mp[key];
            int res = temp->value;
            deleteNode(temp);
            addToHead(temp);
            return res;
        }
        return -1;
    }
    
    void addToHead(Node* node)
    {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    
    void deleteNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // delete(node);
    }
    
    void put(int key, int value) {
        
        if(mp.count(key))
        {
            Node* temp = mp[key];
            temp->value = value;
            deleteNode(temp);
            addToHead(temp);
        }
        else{
            Node* temp = new Node(key,value);
            mp[key] = temp;
            if(count<capacity)
            {
                count++;
                addToHead(temp);
            }
            else{
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
                addToHead(temp);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */