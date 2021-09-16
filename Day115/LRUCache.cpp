struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key,int value)
    {
        this->key=key;
        this->value=value;
        next=prev=NULL;
    }
};

class LRUCache
{
    private:
    static unordered_map<int,Node*> mp;
    static int capacity,count;
    static Node* head;
    static Node* tail;
    
    public:
    //Constructor for initializing the cache capacity with the given value.
    
    LRUCache(int cap)
    {
        unordered_map<int,Node*> temp;
        mp=temp;
        capacity=cap;
        count=0;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        head->prev=NULL;
        tail->next=NULL;
        tail->prev=head;
    }
    
    static void addToHead(Node* node)
    {
        node->next=head->next;
        node->next->prev=node;
        node->prev=head;
        head->next=node;
    }
    static  void deleteNode(Node* node){
        node->next->prev=node->prev;
        node->prev->next=node->next;
        // mp.erase(node->value);
        // delete(node);
        
    }
    //Function to return value corresponding to the key.
    static int get(int key)
    {
        if(mp.count(key)>0)
        {
            Node* temp=mp[key];
            int res =temp->value;
            deleteNode(temp);
            addToHead(temp);
            return res;
        }
        return -1;
        
    }
    
    //Function for storing key-value pair.
    static void set(int key, int value)
    {
        if(mp.count(key)>0)
        {
            Node* temp = mp[key];
            temp->value = value;
            deleteNode(temp);
            addToHead(temp);
        }
        else{
            Node* temp=new Node(key,value);
            mp[key]=temp;
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

unordered_map<int, Node *> temp;
int LRUCache::capacity = 0;
Node *LRUCache::head = new Node(0, 0);
Node *LRUCache::tail = new Node(0, 0);
int LRUCache::count = 0;
unordered_map<int, Node *> LRUCache::mp = temp;
