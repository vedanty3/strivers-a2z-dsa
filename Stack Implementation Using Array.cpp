class Stack {
	public:
		int capacity;
		vector<int>arr;
		Stack(int capacity) {
			this->capacity = capacity;
		}

		void push(int num) {
			if(arr.size()<capacity) {
				arr.push_back(num);
			}
		}

		int pop() {
			if(arr.size()==0) {
				return -1;
			}
			int num = arr[arr.size()-1];
			arr.pop_back();
			return num;
		}

		int top() {
			if(arr.size()==0) {
				return -1;
			}
			return arr[arr.size()-1];
		}

		int isEmpty() {
			return arr.size()==0;
		}

		int isFull() {
			return arr.size()==capacity;
		}
};

