#include <iostream>
#include <math.h>
using namespace std;
class Sets{
    public:
        int set[100]={0};
        int pointer=0;
        Sets(){}
        Sets(int arr[],int size);
        void userInput();
        bool isMember(int num);
        void cardinality();
        void powerSet();
        void display();
        Sets unionSet( Sets & obj);
        Sets intersection(Sets & obj);
        Sets difference(Sets & obj);
        Sets symmetricDifference(Sets & obj);
};
Sets::Sets(int arr[],int size){
    for(int i = 0 ; i < size ; i++){
        set[i] = arr[i];
        pointer++;
    }
}
void Sets::userInput(){
    if(pointer==100){
        cout << "cannot add more elements set maximum capacity reached" << endl;
        return;
    }
    int num;
    cout << "enter element of set: ";
    cin >> num;
    if(isMember(num)){
        cout << "element already present, please enter distinct element!!" << endl;
        userInput();
    }
    else{
        set[pointer]=num;
        pointer++;
        cout<<"element added successfully"<<endl;
        cout<<"wanna add more elements?\npress 0 for no and 1 for yes" << endl;
        int choice;
        cin >> choice;
        if(choice == 1) userInput();
        else return;
    }
}
bool Sets::isMember(int num){
    for(int i = 0 ; i < pointer ; i++){
        if(set[i] == num) return true;
    }
    return false;
}
void Sets::cardinality(){
    cout<<"current elements in set are: "<<pointer<<endl;
}
void Sets::display(){
    cout<<"S = { ";
    for(int i = 0 ; i < pointer ; i++){
        if(i == pointer-1){
            cout << set[i];
        }
        else{
            cout << set[i] << " , ";
        }
    }
    cout<<" }"<<endl;
}
void Sets::powerSet(){
    cout<<"P(S) = { ";
    for(int i = 0 ; i < pow(2,pointer) ; i++){
        if(i == 0){
            cout << char(232) << " , ";
            continue;
        }
        cout<<"{ ";
        for(int j = 0 ; j < pointer ; j++){
            if( i & ( 1 << j)){
                if(j == pointer-1){
                    cout << set[j];
                }
                else{
                    cout << set[j] << " , ";
                }
            }
        }
        if(i == pow(2,pointer)-1){
            cout << " }";
        }
        else{
            cout << " } , ";
        }
    }
    cout << " }" << endl;
}
Sets Sets :: unionSet(Sets & obj){
    Sets result;
    for(int i=0 ; i < pointer ; i++){
        result.set[result.pointer] = set[i];
        result.pointer++;
    }
    for(int i=0 ; i < obj.pointer ; i++){
        if(! isMember(obj.set[i])){
            result.set[result.pointer] = obj.set[i];
            result.pointer++;
        }
    }
    return result;
}
Sets Sets :: intersection(Sets  & obj){
    Sets result;
    for(int i = 0 ; i < pointer ; i++){
        if(obj.isMember(set[i])){
            result.set[result.pointer] = set[i];
            result.pointer++;
        }
    }
    return result;
}
Sets Sets :: difference(Sets & obj){
    Sets result;
    for(int i = 0 ; i < pointer ; i++){
        if(! (obj.isMember(set[i]))){
            result.set[result.pointer] = set[i];
            result.pointer++;
        }
    }
    return result;
}
Sets Sets :: symmetricDifference(Sets & obj){
    Sets result;
    cout << "the symmetric difference of sets is: ";
    for(int i=0 ; i < pointer ; i++){
        if(! obj.isMember(set[i])){
            result.set[result.pointer] = set[i];
            result.pointer++;
        }
    }
    for(int i=0 ; i<obj.pointer ; i++){
        if(! isMember(obj.set[i])){
            result.set[result.pointer] = obj.set[i];
            result.pointer++;
        }
    }
    return result;
}