#include <iostream>
#include "Graph.h"
using namespace std;
int main(){
    Graph g;
    g.getGraph("graph.txt");
    cout<<g.isCyclic()<<endl;
    int choice = 1;
    // do{
    //     cout<<"Welcome geek, following is the menu you can choose from"<<endl;
    //     cout<<"1.Check if graph is directed or not\n2.Check if graph is simple or not\n3.Check if graph is complete or not\n4.Display the graph\n5.Take union of graph with other graph\n6.Show incidence matrix of graph\n7.Tell degree of graph\n8.See in and out degree of all vertices of graph\n9.Check is given graph has euler path/circuit\n10.Check if graph is cyclic or not\n11.Exit\n\n";
    //     cout<<"Enter your choice: ";
    //     int user; cin>>user;
    //     Graph g1, res;
    //     switch(user){
    //         case 1:
    //             if(g.isDirected()){
    //                 cout<<"YES, graph is directed"<<endl;
    //             }
    //             else cout<<"NO, the graph is not directed"<<endl;
    //             break;
    //         case 2:
    //             if(g.isSimple()){
    //                 cout<<"YES, graph is simple"<<endl;
    //             }
    //             else{
    //                 cout<<"NO, the graph is not simple"<<endl;
    //             }
    //             break;
    //         case 3:
    //             if(g.isComplete()){
    //                 cout<<"YES, graph is complete"<<endl;
    //             }
    //             else{
    //                 cout<<"NO, the graph is not complete"<<endl;
    //             }
    //             break;
    //         case 4:
    //             g.display();
    //             break;
    //         case 5:
    //             g1.getGraph("graphUnion.txt");
    //             res = g.unionGraph(g1);
    //             cout<<"the union of graph is: "<<endl;
    //             res.display();
    //             break;
    //         case 6:
    //             g.getIncidenceMatrix();
    //             for(int i=1 ; i<=g.vertices ; i++){
    //                 for(int j = 1 ; j<=g.edges ; j++){
    //                     cout<<setw(5)<<left;
    //                     cout<<g.incidenceMatrix[i][j];
    //                 }
    //                 cout<<endl;
    //             }
    //             break;
    //         case 7:
    //             cout<<"The degree of graph is: "<<g.degreeOfGraph()<<endl;
    //             cout<<endl;
    //             break;
    //         case 8:
    //             g.inDegreeOutDegree();
    //             break;
    //         case 9:
    //             g.isEuler();
    //             break;
    //         case 10:
    //             cout<<"HI";
    //             g.isCyclic()? cout<<"yes":cout<<"no";
    //             cout<<endl;
    //             break;
    //         case 11:
    //             choice =0;
    //             cout<<"good bye"<<endl;
    //             break;
    //         default:
    //             cout<<"Please make a valid choice"<<endl;
    //     }
    // }while(choice);
    return 0;
}