// Design a stack that supports push, pop, top, and retrieving the minimum
//  element in constant time.

// push(x) – Push element x onto stack.
// pop() – Removes the element on top of the stack.
// top() – Get the top element.
// getMin() – Retrieve the minimum element in the stack.
// Note that all the operations have to be constant time operations.

// Questions to ask the interviewer :

// Q: What should getMin() do on empty stack? 
// A: In this case, return -1.

// Q: What should pop do on empty stack? 
// A: In this case, nothing. 

// Q: What should top() do on empty stack?
// A: In this case, return -1
//  NOTE : If you are using your own declared global variables, make sure to clear 
// them out in the constructor. 

stack<pair<int,int>> st;

MinStack::MinStack(){
    while(!st.empty())
        st.pop();
}

void MinStack::push(int x){
    if(st.empty())
        st.push({x, x});
    else
        st.push({x, min(x, st.top().second)});
}

void MinStack::pop(){
    if(!st.empty())
        st.pop();
}

int MinStack::top(){
    return st.empty() ? -1 : st.top().first;
}

int MinStack::getMin(){
    return st.empty() ? -1 : st.top().second;
}