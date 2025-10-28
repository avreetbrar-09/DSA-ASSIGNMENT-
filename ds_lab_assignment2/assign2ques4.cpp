/*4) String Related Programs 
(a) Write a program to concatenate one string to another string. 
(b) Write a program to reverse a string. 
(c) Write a program to delete all the vowels from the string. 
(d) Write a program to sort the strings in alphabetical order. 
(e) Write a program to convert a character from uppercase to lowercase. */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void concatenate(string str) {
    string st;
    cout << "Enter a second string: ";
    getline(cin, st);
    string result=str+st;
    cout<< "the resultant string is :"<< result<<endl;   
}

void reversestring (string str) {
  reverse(str.begin(), str.end());  
    cout << "Reversed string is: " << str << endl;
}
string lowercase(string str) {
 for (int i = 0; i < str.length(); i++) {
str[i]=tolower(str[i]);
}
return str;
}
void delvowels (string str) {
    string result;
    str = lowercase(str);
    for(char c: str) {
        if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u') {
result+=c;
        }}
        cout<<"string without vowels :"<< result<<endl;
    
}
void alphabetically(string str) {
sort(str.begin(), str.end());
cout<<"the string in alphabetical order is :"<< str<<endl;
}


int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);   
    concatenate(str);
    reversestring(str);
    delvowels (str);
alphabetically(str);
    str=lowercase (str);
cout<<"string in lowercase is :"<<str;
    return 0;
}