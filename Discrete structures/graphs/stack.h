class Stack{
    public:
        int arr[100000];
        int top =-1;
        void pop(){
            top--;
        }
        void push(int x){
            arr[++top] = x;
        }
        bool empty(){
            if(top == -1) return true;
            return false;
        }
        int tos(){
            return arr[top];
        }
};