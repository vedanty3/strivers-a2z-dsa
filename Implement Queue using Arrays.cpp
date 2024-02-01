class Queue {

		int front, rear;
		vector<int> arr;

	public:
		Queue() {
			front = 0;
			rear = 0;
			arr.resize(100001);
		}

		void enqueue(int e) {
			arr[rear] = e;
			++rear;
		}

		int dequeue() {
			if(rear==0) {
				return -1;
			}

			int ans = arr[front];
			++front;

			if(front>=rear) {
				front = 0;
				rear = 0;
			}

			return ans;
		}
};
