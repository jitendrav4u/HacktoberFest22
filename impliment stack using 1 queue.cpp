// 100% WORKING CODE
// discussion sol
// submit on leetcode




/*

- Front of queue always points to the last element added to stack.
- To impliment push: add element to queue. Then transfer all elements to the left of last added element to the back of queue.

By doing this, we make the push operation costly but all the other operations are cheap.



*/







//using only 1 queue
class Stack{

private:
	queue<int> q;

public:


	// Push element x onto stack.
	void push(int ele){
		q.push(ele);
		for(int i=0; i<q.size()-1; i++){
			q.push(q.front());
			q.pop();
		}

		return;
	}



	// Removes the element on top of the stack.
	int pop(){
		
		if(q.empty()){
			return -1;
		}

		int x = q.front();
        q.pop();
        return x;

	}



	// Get the top element.
	int top() {
		if(q.empty()){
			return -1;
		}

		return q.front();
	}



	// Return whether the stack is empty.
	bool empty(){
		return q.empty();
	}


};
