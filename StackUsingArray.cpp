#include <iostream>
using namespace std;
#define n 100
class stack{
  int* arr;
  int top;
  
  public:
  stack(){
     arr = new int[n];
     top = -1;
  }
  
  void push(int val){
      if(top == n-1){
          cout<<"stack overflow"<<endl;
          return;
      }
      top++;
      arr[top] = val;
  }
  void pop(){
      if(top == -1){
          cout<<"stack underflow"<<endl;
          return;
      }
      top--;
  }
  bool empty(){
      return (top==-1);
  }
  int Top(){
      if(top==-1){
          cout<<"stack underflow"<<endl;
          return -1;
      }
      return arr[top];
  }
};
int main() {
	stack st;
	cout<<st.Top()<<endl;
	st.push(1);
	cout<<st.Top()<<endl;
	st.push(2);
	cout<<st.Top()<<endl;
	st.push(3);
	cout<<st.Top()<<endl;
	st.pop();
	cout<<st.Top()<<endl;
	st.pop();
	st.pop();
	st.pop();
	return 0;
}
