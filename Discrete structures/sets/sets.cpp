#include <iostream>
#include "sets.h"
using namespace std;
int main(){
    Sets s;
    int cont = 1;
    do{
        int n , isMemberNum;
        bool res;
        int dum = 1 , cnt = 0;
        Sets result;
        cout << "\n\n\n\n************************* Welcome to Mayank Sets World *************************\n";
        cout << "Choose an option from the menu given below: \n";
        cout << "1. Add elements to the set\n2. Check for a given number if member or not\n3. Display cardinality of the set\n4. Display the set\n5. Display the powerset\n6. Find union of sets\n7. Find Intersection of sets\n8. Find Difference of sets\n9. Find Symmetric Difference of sets\n10. Exit\nYour Choice: ";
        cin >> n;
        switch(n){
            case 1:
                s.userInput();
                break;
            case 2:
                cout << "enter a number you want to check if member or not: ";
                cin >> isMemberNum;
                res = s.isMember(isMemberNum);
                if(res) cout << "Yes, " << isMemberNum << " is a member of the set" << endl;
                else cout << "No, " << isMemberNum << " is not a member of the set" << endl;
                break;
            case 3:
                s.cardinality();
                break;
            case 4:
                s.display();
                break;
            case 5:
                s.powerSet();
                break;
            case 6:
                while(dum){
                    cout << "enter the details of another set you wanna take Union with: " << endl;
                    Sets obj;
                    obj.userInput();
                    if(cnt == 0){
                        result = s.unionSet(obj);
                        cout << "Current union is: " << endl;
                        result.display();
                        cout << "You wish to take more union?\npress 0 for no and 1 for yes: ";
                        cin >> dum;
                        cnt++;
                    }
                    else{
                        result = result.unionSet(obj);
                        cout << "Current union is: " << endl;
                        result.display();
                        cout << "You wish to take more union?\npress 0 for no and 1 for yes: ";
                        cin >> dum;
                    }
                }
                break;
            case 7:
                dum = 1 , cnt = 0;
                while(dum){
                    cout << "enter the details of another set you wanna take intersection with: " << endl;
                    Sets obj;
                    obj.userInput();
                    if(cnt == 0){
                        result = s.intersection(obj);
                        cout << "Current intersection is: " << endl;
                        result.display();
                        cout << "You wish to take more intersection?\npress 0 for no and 1 for yes: ";
                        cin >> dum;
                        cnt++;
                    }
                    else{
                        result = result.intersection(obj);
                        cout << "Current intersection is: " << endl;
                        result.display();
                        cout << "You wish to take more intersection?\npress 0 for no and 1 for yes: ";
                        cin >> dum;
                    }
                }
                break;
            case 8:
                dum = 1 , cnt = 0;
                while(dum){
                    cout << "enter the details of another set you wanna take Difference with: " << endl;
                    Sets obj;
                    obj.userInput();
                    if(cnt == 0){
                        result = s.difference(obj);
                        cout << "Current difference is: " << endl;
                        result.display();
                        cout << "You wish to take more difference?\npress 0 for no and 1 for yes: ";
                        cin >> dum;
                        cnt++;
                    }
                    else{
                        result = result.difference(obj);
                        cout << "Current difference is: "<<endl;
                        result.display();
                        cout<<"You wish to take more difference?\npress 0 for no and 1 for yes: ";
                        cin >> dum;
                    }
                }
                break;
            case 9:
                dum = 1 ,cnt = 0;
                while(dum){
                    cout << "enter the details of another set you wanna take Symmetric Difference with: " << endl;
                    Sets obj;
                    obj.userInput();
                    if(cnt == 0){
                        result = s.symmetricDifference(obj);
                        cout<<"Current Symmetric Difference is: " << endl;
                        result.display();
                        cout << "You wish to take more Symmetric Difference?\npress 0 for no and 1 for yes: ";
                        cin >> dum;
                        cnt++;
                    }
                    else{
                        result = result.symmetricDifference(obj);
                        cout << "Current Symmetric Difference is: " << endl;
                        result.display();
                        cout << "You wish to take more Symmetric Difference?\npress 0 for no and 1 for yes: ";
                        cin >> dum;
                    }
                }
                break;
            case 10:
                cont = 0;
                cout<<"Thanks for using my sets data structure, See you again!!"<<endl;
                break;
            default:
                cout << "wrong choice entered, Exiting program.......\n";
                cont = 0;
        }
    } while(cont);
    return 0;
}