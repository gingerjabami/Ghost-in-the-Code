class LRUCache {
public:
        struct Node { 
        int key, value;
        Node* next, *prev;
        Node(int key, int value){ //node declaration fn
            this->key = key;
            this->value = value;
            next = NULL;
            prev= NULL;  // making a dummy node with both pointers pointing to nothing
        }
        };
int cap ;
unordered_map<int, Node*> mp;

Node* head = new Node (-1,-1);
Node* tail = new Node (-1,-1); //-1 indicates not a real data; just placeholder aka dummy node

void deletionNode(Node* node){

    /* suppose A <---> node <---> B
     node--->prev = A then node->prev->next essentially is A->next;
     same with [node->next]->prev = B-> prev 
     */ 
    node->prev->next = node->next;
    node->next->prev = node->prev;

}
void insertHead(Node* node){
    // suppose head <---> A <---> B ... & u need to insert node b/w head and A
Node* temp = head->next; // temp is a pointer variable, that points to A in memory
head->next= node; // head -------> node
node->prev= head;  // head <------- node

node->next= temp; // node is pointing next to the temp ; which is A
temp->prev= node;

}
LRUCache(int capacity) {    
        this->cap= capacity;
        head->next= tail;
        tail->prev = head;
        
    }
    
int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* currnode = mp[key];
            deletionNode(currnode);
            insertHead(currnode);
            return currnode->value;
        }
        else
        return -1;
        
    }
    
void put(int key, int value) {
        if(mp.find(key) != mp.end()) {  //  if true, this means the key exists in map
        Node* currnode = mp[key];
        currnode->value = value;
        deletionNode(currnode);
        insertHead(currnode);
        
        }

    else{
        Node* newnode = new Node(key, value);
        if(mp.size() == cap){
            Node* lru_node = tail->prev;
            mp.erase(lru_node->key);
            deletionNode(lru_node);
            insertHead(newnode);
            mp[key] = newnode;
            delete lru_node;
        }
        else{
            insertHead(newnode);
            mp[key] = newnode;
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