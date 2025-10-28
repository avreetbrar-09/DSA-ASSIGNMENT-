#include<iostream>
#include <queue>
#include <unordered_map>
using namespace std;
class nonrepeating {
    public:
nonrepeating(string &s) {
    queue<char> q;
unordered_map <char,int> m;
for(int i=0; i<s.length(); i++) {

q.push(s[i]);
m[s[i]]++;
    }

    while(!q.empty() && m[q.front()]>1 ) {
        q.pop();
    }

    if (q.empty()) {
        cout<<"no unique character : "<<endl;
    }
    else {
        cout<<q.front()<<endl;
    }
}
};

int main() {
    string s;
    cout<<"enter string : " << endl;
cin>>s;
nonrepeating a(s);
return 0;
}