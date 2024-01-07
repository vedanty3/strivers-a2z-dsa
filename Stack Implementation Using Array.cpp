class Stack {
	public:
		vector<int>arr;
		int capacity;
		Stack(int capacity) {
			this->capacity = capacity;
		}

		void push(int num) {
			if(arr.size()<this->capacity) {
				arr.push_back(num);
			}
		}

		int pop() {
			int ele = -1;
			if(arr.size()>0) {
				ele = arr[arr.size()-1];
				arr.pop_back();
			}
			return ele;
		}

		int top() {
			if(arr.size()<=0) {
				return -1;
			}

			return arr[arr.size()-1];
		}

		int isEmpty() {
			return arr.size()==0;
		}

		int isFull() {
			return arr.size()==this->capacity;
		}

};

