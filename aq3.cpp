#include <iostream> 
#include <queue> 
using namespace std; 
 
void interleaveQueue(queue<int>& q) { 
    int n = q.size(); 
 
    int half = n / 2; 
    queue<int> firstHalf; 
 
    // Move first half into  queue 
    for (int i = 0; i < half; i++) { 
        firstHalf.push(q.front()); 
        q.pop(); 
    } 
 
    // Interleave 
    while (!firstHalf.empty()) { 
        q.push(firstHalf.front());  // one element from first half 
        firstHalf.pop(); 
 
        q.push(q.front());          // one element from second half 
        q.pop(); 
    } 
} 
 
int main() { 
    queue<int> q; 
 
    q.push(4); 
    q.push(7); 
    q.push(11); 
    q.push(20); 
    q.push(5); 
    q.push(9); 
 
    cout << "Original Queue: "; 
    queue<int> temp = q;  
    while (!temp.empty()) { 
        cout << temp.front() << " "; 
        temp.pop(); 
    } 
    cout << endl; 
 
    interleaveQueue(q); 
 
    cout << "Interleaved Queue: "; 
    while (!q.empty()) { 
        cout << q.front() << " "; 
        q.pop(); 
    } 
    cout << endl; 
 
    return 0; 
}
