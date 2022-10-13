#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int>q;
    public:
        void push(int x){
            int s=q.size();
            q.push(x);
            for(int i=0; i<s; i++){
                q.push(q.front());
                q.pop();
            }
        }

        void pop(){
             q.pop();
        }
        int Top(){
            return q.front();
        }
        int Size()
        {
            return q.size();
        }

        void print()
        {
            while(!q.empty()){
                cout<<q.front()<<endl;
                q.pop();
            }
        }

};

int main()
{
    Stack st;
    st.push(3);
    st.push(2);
    st.push(4);
    st.push(1);
    // st.pop();
    cout<<st.Top()<<endl;
    st.print();
    

    return 0;
}