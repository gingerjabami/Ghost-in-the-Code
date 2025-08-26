/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   unordered_map<Node*,bool> visited ;
    unordered_map<Node*,Node*> clone ;
    void build(Node* node,Node* &head){
        visited[node]=true ;
        Node* newNode = new Node(node->val) ;
        clone[node]=newNode ;
            if(head==NULL)
            head = newNode ;
        for(auto nbr : node->neighbors){
            if(!visited[nbr]){
                build(nbr,head) ;
            }
        }
        for(auto nbr : node->neighbors){
        newNode->neighbors.push_back(clone[nbr]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL  ;
        Node* head = NULL ; 
        build(node,head) ;
        return head ;
    }
};