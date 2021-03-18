#include <iostream>
#include<stack>
using namespace std;
void reverseSentence(string s){   //Reverse a Sentence using Stacks
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word ="";
        while(s[i] !=' ' && i<s.length()){
            word +=s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
void insertAtBottom(stack<int> &st,int ele){ //insert the element at the bottom of the stack
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topele);
}
void reverseStack(stack<int> &st){ // Reverse a Stack
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,top);
}
int main() {
	string s = "I am santanu garai";
	reverseSentence(s);
	return 0;
}
