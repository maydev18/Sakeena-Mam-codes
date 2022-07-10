#include <iostream>
#include "Relations.h"
using namespace std;
int main(){
    Relations r;
    r.getRelation();
    r.displayRelation();
    r.isReflexive()==1?cout<<"Given relation is reflexive"<<endl:cout<<"given relation is not reflexive"<<endl;
    r.isSymmetric()==1?cout<<"Given relation is symmetric"<<endl:cout<<"given relation is not symmetric"<<endl;
    r.isAntiSymmetric()==1?cout<<"Given relation is anti-symmetric"<<endl:cout<<"given relation is not anti-symmetric"<<endl;
    r.isTransitive()==1?cout<<"Given relation is transitive"<<endl:cout<<"given relation is not transitive"<<endl;
    r.tellRelationType();
    return 0;
}