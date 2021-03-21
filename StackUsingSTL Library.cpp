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
int postfixEvalution(string s){  //Prefix Expression Evaluation
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();
            switch(s[i]){
                case '+':
                  st.push(operand1 + operand2);
                  break;
                case '-':
                  st.push(operand1 - operand2);
                  break;
                case '*':
                  st.push(operand1 * operand2);
                  break;
                case '/':
                  st.push(operand1 / operand2);
                  break;
                case '^':
                  st.push(pow(operand1, operand2));
                  break;
            }
        } 
   }
   return st.top();
}
/*  Infix to postfix conversion start */
int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if(c=='/' || c=='*'){
        return 2;
    }
    else if (c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infixToPostfix(string s){
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z')|| (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
    }
}
/* infix to postfix ends */
int main() {
	string s = "I am santanu garai";
	reverseSentence(s);
	return 0;
}
