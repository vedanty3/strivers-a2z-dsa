// Approach 1

Node* solve(int indx, vector<int>&arr) {
	if(indx>=arr.size()) {
		return nullptr;
	}

	Node* root = new Node(arr[indx]);
	root->left = solve(2*indx+1, arr);
	root->right = solve(2*indx+2, arr);
	return root;
}

Node* createTree(vector<int>&arr) {
	return solve(0, arr);
}

// Approach 2

Node* createTree(vector<int>&arr) {
	int n = arr.size();
	Node* root = new Node(arr[0]);
	queue<Node*>q;
	q.push(root);
	int i = 1;

	while(!q.empty() and i<n) {
		Node* node = q.front();
		q.pop();
		node->left = new Node(arr[i++]);
		node->right = new Node(arr[i++]);
		q.push(node->left);
		q.push(node->right);
	}

	return root;
}
