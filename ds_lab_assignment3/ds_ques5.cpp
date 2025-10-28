#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

bool isOperator(char s) {
    return (s=='+' || s=='-' || s=='*' || s=='/' || s=='^');
}

bool isOperand(char c) {
    return (c >= '0' && c <= '9');
}

float postfixval(string postfix) {
    stack<float> st;

    for(char c : postfix) {
        if(isOperand(c)) {
            st.push(c - '0'); 
        }
        else if (isOperator(c)) {
            float op1 = st.top(); st.pop();
            float op2 = st.top(); st.pop();
            float result;

            if(c=='+') result = op2 + op1;
            else if(c=='-') result = op2 - op1;
            else if(c=='*') result = op2 * op1;
            else if(c=='/') result = op2 / op1;
            else if(c=='^') result = pow(op2, op1);

            st.push(result);
        }
    }
    return st.top();  // final answer
}

int main() {
    string postfix;
    cout << "Enter your postfix expression: ";
    cin >> postfix;   
    float res = postfixval(postfix);
    cout << "Your result is: " << res;
    return 0;
}