#include<iostream> 
#include<queue> 
#include<string> 
using namespace std; 
int count(string s,char ch){ 
    int count=0; 
    for(char c: s) { 
        if(c==ch) count++; 
    } 
    return count; 
} 
int main(){ 
    string line; 
    cout << "Enter a string:"; 
    getline(cin,line); 
    queue<char>q; 
    string seen=""; 
    for(char ch:line){ 
        q.push(ch); 
        seen+=ch; 
 
        while(!q.empty()&& count(seen,q.front())>1){  
        q.pop(); 
        } 
        if(q.empty()) cout<< -1 << " "; 
        else cout<< q.front()<< " ";  
    } 
return 0; 
}
