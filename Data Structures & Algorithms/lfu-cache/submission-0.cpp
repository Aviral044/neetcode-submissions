
class LFUCache {
    struct ListNode{
        int key;
        int val;
        int freq;
        ListNode* prev;
        ListNode* next;
        ListNode(int key,int val)
        {
            this->key=key;
            this->val=val;
            freq=1;
            prev=nullptr;
            next=nullptr;
        }
    };
    struct LinkedList{
        ListNode* left;
        ListNode* right;
        int size;

        LinkedList()
        {
            left=new ListNode(0,0);
            right=new ListNode(0,0);
            left->next=right;
            right->prev=left;
            size=0;
        }
        void push(ListNode* node)
        {
            ListNode* prev=right->prev;
            node->next=right;
            node->prev=prev;
            prev->next=node;
            right->prev=node;
            size++;
        }
        void pop(ListNode* node)
        {
            ListNode* pre=node->prev;
            ListNode* nex=node->next;
            pre->next=nex;
            nex->prev=pre;
            size--;
        }
    };
public:
    int capacity;
    int lfuCount;
    unordered_map<int,ListNode*> nodeMap;
    unordered_map<int,LinkedList*> listMap;
    LFUCache(int capacity) {
        this->capacity=capacity;
        lfuCount=0;
    }
    void counter(ListNode* node)
    {
        int count=node->freq;
        listMap[count]->pop(node);

        if(count==lfuCount && listMap[count]->size==0)
        {
            lfuCount++;
        }
        node->freq++;
        if(!listMap.count(node->freq))//i do not understand this
        {
            listMap[node->freq]=new LinkedList();
        }
        listMap[node->freq]->push(node);
    }
    
    int get(int key) {
        if(nodeMap.find(key)==nodeMap.end())
        {
            return -1;
        }
        ListNode* node=nodeMap[key];
        counter(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(nodeMap.find(key)!=nodeMap.end())
        {
            ListNode* node=nodeMap[key];
            node->val=value;
            counter(node);
            return;
        }
        if(nodeMap.size()==capacity)
        {
            //remove LRU
            ListNode* remove=listMap[lfuCount]->left->next;
            listMap[lfuCount]->pop(remove);
            nodeMap.erase(remove->key);
            delete remove;
        }
        ListNode* node=new ListNode(key,value);
        nodeMap[key]=node;
        if(!listMap.count(1))
        {
            listMap[1]=new LinkedList();
        }
        listMap[1]->push(node);
        lfuCount=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */