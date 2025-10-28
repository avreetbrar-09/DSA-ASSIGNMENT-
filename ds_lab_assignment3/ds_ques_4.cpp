#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char a) {
    if (a=='+'|| a=='-') return 1;
    if (a=='*'|| a=='/') return 2;
    if (a=='^') return 3;
    return 0;  
}

bool isoperator(char s) {
    return (s=='+' || s=='-' || s=='*' || s=='/' || s=='^');
}


bool isOperand(char c) {
    return ( (c >= '0' && c <= '9') || 
             (c >= 'a' && c <= 'z') || 
             (c >= 'A' && c <= 'Z') );
}

string infixtopostfix(string infix) {
    string postfix;
    stack <char> st;

    for(char c : infix) {
        if(isOperand(c)) {
            postfix += c;
        }
        else if(c=='(') {
            st.push(c);
        }
        else if(c==')') {
            while(!st.empty() && st.top()!='(') {
                postfix += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // remove '('
        }
        else if (isoperator(c)) {
            while(!st.empty() && 
                  ((precedence(st.top()) > precedence(c)) || 
                  (precedence(st.top()) == precedence(c) && c != '^'))) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main() {
    string infix;
    cout << "Enter your infix expression: ";
    cin >> infix;   
    string postfix = infixtopostfix(infix);
    cout << "Your postfix expression is: " << postfix;
    return 0;
}