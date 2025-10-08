#include <iostream> 
using namespace std; 
 
#define MAX 5  // Maximum size of the queue 
 
class CircularQueue { 
    int arr[MAX]; 
    int front, rear; 
 
public: 
    CircularQueue() { 
        front = -1; 
        rear = -1; 
    } 
bool isFull(){ 
    return(front==0 && rear==MAX-1)||(rear+1==front); 
} 
bool isEmpty(){ 
    return front==-1; 
} 
void enqueue(int val){ 
    if(isFull()) {cout<<"Queue is full"<<endl; 
    return; 
} 
else{ 
    if(isEmpty()){ 
        front=0; 
        rear=0; 
    } 
    else{ 
        rear=(rear+1)%MAX; 
    } 
arr[rear]=val; 
cout<< val << " enqueued into queue"<<endl; 
} 
} 
int dequeue(){ 
      if (isEmpty()) { 
            cout << "Queue Underflow! Cannot dequeue" << endl; 
            return -1; 
        } 
    int data=arr[front]; 
    if(front==rear){ 
        front=-1; 
        rear=-1; 
    } 
    else{ 
        front=(front+1)%MAX; 
    } 
return data; 
} 
int peek() { 
        if (isEmpty()) { 
            cout << "Queue is empty!" << endl; 
            return -1; 
        } 
        return arr[front]; 
    } 
 void display() { 
        if (isEmpty()) { 
            cout << "Queue is empty!" << endl; 
            return; 
        } 
        cout << "Queue elements: "; 
        int i=front; 
        while(true){ 
            cout <<arr[i]<<" "; 
            if(i==rear) break; 
            i=(i+1)%MAX; 
        } 
    cout<<endl; 
} 
}; 
int main(){ 
    CircularQueue q; 
    int choice,value; 
    do{ 
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
        switch(choice){ 
            case 1: 
            cout<<"Enter value to insert:"<<endl; 
            cin>>value; 
            q.enqueue(value); 
            break; 
            case 2: 
           value = q.dequeue(); 
                if (value != -1) 
                    cout << "Dequeued element: " << value << endl; 
                break; 
            case 3: 
            value = q.peek(); 
                if (value != -1) 
                    cout << "Front element: " << value << endl; 
                break; 
            case 4: 
            q.display(); 
            break; 
            case 5: 
            cout<<"Exiting code ..."; 
            break; 
            default: 
            cout <<"Invalid input"; 
        } 
    }while(choice!=5); 
     
}
