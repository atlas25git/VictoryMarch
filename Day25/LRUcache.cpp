// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

//Approach->
//Struct Dll
//constructor to intialize lru cache head-tail, hashmap
//add to head for most recent cache
//delete fn to delete a particular node
//get fn->if present bring it to head delete prev occr and return value
//set fn: if present add to head and delete prev oocurrence
//else add the node first check if count<capacity then bring tot front
//else delete the prev node from tail least recently used

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

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends