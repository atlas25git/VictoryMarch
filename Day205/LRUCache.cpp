struct Node{
  int key,value;
  Node* next,*prev;
    
    Node(int key,int value)
    {
        this->key = key;
        this->value = value;
    }
};

//3 Steps to remember:
//1. DLL structure
//2. Add/Del Node custom fn.
//3. Condn to add vis-a-vis capacity & count.

class LRUCache {
private:
    unordered_map<int,Node*> mp;
    int count;
    int capacity;
    Node* head,*tail;
    
public:
    
    LRUCache(int capacity) {
       this->capacity = capacity;
       this->count = 0;
        head = new Node(0,0);
        tail = new Node(0,0);
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key))
        {
            deleteNode(mp[key]);
            addToHead(mp[key]);
            return mp[key]->value;
        }
        else return -1;
    }
    
    void deleteNode(Node* node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        // delete(node);
    }
    
    void addToHead(Node* node)
    {
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
        {
            mp[key]->value = value;
            deleteNode(mp[key]);
            addToHead(mp[key]);                
        }
        else{
            mp[key] = new Node(key,value);
            if(count<capacity)
            {
                count++;
                addToHead(mp[key]);
            }
            else{
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
                addToHead(mp[key]);
            }
        }
    }
};