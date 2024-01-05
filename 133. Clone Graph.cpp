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
	public:
		Node* clone(Node* node, unordered_map<int, Node*>&vis) {
			Node* new_node = new Node(node->val);
			vis[node->val] = new_node;

			for(auto adjNode : node->neighbors) {
				auto it = vis.find(adjNode->val);
				if(it==vis.end()) {
					Node* cn = clone(adjNode, vis);
					new_node->neighbors.push_back(cn);
				} else {
					new_node->neighbors.push_back(it->second);
				}
			}

			return new_node;
		}

		Node* cloneGraph(Node* node) {
			if(!node) {
				return nullptr;
			}
			unordered_map<int, Node*>vis;
			return clone(node, vis);
		}
};
