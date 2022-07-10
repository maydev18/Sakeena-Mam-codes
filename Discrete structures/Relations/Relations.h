#include <iostream>
using namespace std;
class Relations{
    private:
        int relationMatrix[101][101]={{0}};
        int set[100]={0};
        int pointer=0;
    public:
        bool isPresent(int a);
        void getRelation();
        void displayRelation();
        bool isReflexive();
        bool isSymmetric();
        bool isAntiSymmetric();
        bool isTransitive();
        void tellRelationType();
};
bool Relations::isPresent(int a){
    for(int i=0 ; i<pointer ; i++){
        if(set[i]==a) return true;
    }
    return false;
}
void Relations::getRelation(){
    int setsize;
    cout<<"enter the size of your set for which you wanna define your relation: ";
    cin>>setsize;
    cout<<"please enter your set elements separated by a space: "<<endl;
    for(int i=0 ; i<setsize ; i++) cin>>set[i];
    pointer = setsize;
    int relationsize;
    cout<<"enter the number of elements in your relation: ";
    cin>>relationsize;
    for(int i=0 ; i<relationsize ; i++){
        cout<<"enter your relation separated by space: ";
        int a,b; cin>>a>>b;
        if(isPresent(a) && isPresent(b)){
            relationMatrix[a][b]=1;
        }
        else{
            cout<<"Cannot create a relation since element of relation are not in our set"<<endl;
            i--;
        }
    }
}
void Relations::displayRelation(){
    for(int i=1 ; i<101 ; i++){
        for(int j=1 ; j<101 ; j++){
            if(relationMatrix[i][j]==1){
                cout<<"( "<<i<<" , "<<j<<" ) ";
            }
        }
    }
    cout<<endl;
}
bool Relations::isReflexive(){
    for(int i=0 ; i<pointer ; i++){
        if(relationMatrix [set[i]] [set[i]]!=1){
            return false;
        }
    }
    return true;
}
bool Relations::isSymmetric(){
    for(int i=1 ; i<100 ; i++){
        for(int j=i+1 ; j<101 ; j++){
            if((relationMatrix[i][j]==1 && relationMatrix[j][i]==0) || (relationMatrix[i][j]==0 && relationMatrix[j][i]==1)){
                return false;
            }
        }
    }
    return true;
}
bool Relations::isAntiSymmetric(){
    for(int i=1 ; i<100 ; i++){
        for(int j=i+1 ; j<101 ; j++){
           if(relationMatrix[i][j]==1 && relationMatrix[j][i]==1) return false;
        }
    }
    return true;
}
bool Relations::isTransitive(){
    for(int i=1 ; i<101 ; i++){
        for(int j=1 ; j<101 ; j++){
            if(relationMatrix[i][j]){
                for(int k=1 ; k<101 ; k++){
                    if(relationMatrix[j][k] && relationMatrix[i][k]==0){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
void Relations::tellRelationType(){
    if(isReflexive() && isSymmetric() && isTransitive()){
        cout<<"given relation is Equivalence relation:"<<endl;
    }
    else if(isReflexive() && isAntiSymmetric() && isTransitive()){
        cout<<"given relation is partial-order relation"<<endl;
    }
    else{
        cout<<"given relation is neither equivalence nor partial-order"<<endl;
    }
}