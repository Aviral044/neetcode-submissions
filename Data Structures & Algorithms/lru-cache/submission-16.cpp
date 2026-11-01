class Node{
    public:
    int key;int val;
    Node* next; Node* prev;
    Node(int k,int v)
    {
        key=k;
        val=v;
        prev=nullptr;
        next=nullptr;
    }
};
class LRUCache {
private:
    int cap;
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;
    void insert(Node* dummy)//insert towards right side
    {
        Node* prev=right->prev;
        prev->next=dummy;
        dummy->prev=prev;
        dummy->next=right;
        right->prev=dummy;
    }
    void remove(Node* dummy)//remove from left
    {
        Node* pre=dummy->prev;
        Node* nex=dummy->next;
        pre->next=nex;
        nex->prev=pre;
    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next=right;
        right->prev=left;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end())
        {
            Node* node=cache[key];
            int val=node->val;
            remove(node);
            insert(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
        {
            remove(cache[key]);
        }
        Node* dummy=new Node(key,value);
        cache[key]=dummy;
        insert(dummy);

        if(cache.size()>cap)
        {
            Node* lru=left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
        
    }
};
