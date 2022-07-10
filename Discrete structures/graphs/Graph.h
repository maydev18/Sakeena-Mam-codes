#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <math.h>
#include "stack.h"
using namespace std;
class Graph{
    public:
        int adjacencyMatrix[100][100]={{0}};
        int incidenceMatrix[101][1001]={{0}};
        int vertices,edges;
        bool directed;
        void getGraph(string source);
        bool isDirected();
        bool isSimple();
        bool isComplete();
        void display();
        Graph unionGraph(Graph & g);
        void getIncidenceMatrix();
        void showIncidenceMatrix();
        int degreeOfGraph();
        void inDegreeOutDegree();
        void isEuler();
        bool isCyclic();
};
void Graph::getGraph(string source){
    //first line of graph.txt contains three numbers denoting the number of vertices , edges and is graph is directed or not and successive lines contain those vertices where there is an edge.
    ifstream file;
    file.open(source);
    file >> vertices >> edges >> directed;
    for(int i=0 ; i < edges ; i++){
        int v1,v2;
        file >> v1 >> v2;
        if(directed){
            adjacencyMatrix[v1][v2]++;
        }
        else{
            adjacencyMatrix[v1][v2]++;
            adjacencyMatrix[v2][v1]++;
        }
    }
}
bool Graph::isDirected(){
    for(int i=1 ; i<=vertices ; i++){
        for(int j=1 ; j<=vertices ; j++){
            if(adjacencyMatrix[i][j] && adjacencyMatrix[j][i]==0){
                return true;
            }
        }
    }
    return false;
}
bool Graph::isSimple(){
    for(int i=1 ; i<=vertices ; i++){
        for(int j=1 ; j<=vertices ;j++){
            if(adjacencyMatrix[i][i]==1 || adjacencyMatrix[i][j]>1){
                return false;
            }
        }
    }
    return true;
}
bool Graph::isComplete(){
    for(int i=1 ; i<=vertices ; i++){
        for(int j=1 ; j<=vertices , j!=i ; j++){
            if(adjacencyMatrix[i][j]==0){
                return false;
            }
        }
    }
    return true;
}
Graph Graph::unionGraph(Graph & g){
    Graph newGraph;
    vertices > g.vertices ? newGraph.vertices=vertices : newGraph.vertices=g.vertices;
    for(int i=1 ;  i<=newGraph.vertices ; i++){
        for(int j=1 ; j<=newGraph.vertices ; j++){
            newGraph.adjacencyMatrix[i][j] = max(adjacencyMatrix[i][j],g.adjacencyMatrix[i][j]);
        }
    }
    return newGraph;
}
void Graph::display(){
    for(int i=1 ; i<=vertices ; i++){
        for(int j=1 ; j<=vertices ; j++){
            cout<<setw(5)<<left;
            cout<<adjacencyMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Graph::getIncidenceMatrix(){
    int currEdge=1;
    if(directed){
        for(int i=1 ; i<=vertices ; i++){
            for(int j=1 ; j<=vertices ; j++){
                if(adjacencyMatrix[i][j]){
                    incidenceMatrix[i][currEdge] = -1;
                    incidenceMatrix[j][currEdge] = 1;
                    currEdge++;
                }
            }
        }
    }
    else{
        for(int i=1 ; i<=vertices ; i++){
            for(int j=i ; j<=vertices ; j++){
                if(adjacencyMatrix[i][j]){
                    incidenceMatrix[i][currEdge]=1;
                    incidenceMatrix[j][currEdge]=1;
                    currEdge++;
                }
            }
        }
    }
}
int Graph::degreeOfGraph(){
    int deg=0;
    for(int i=1 ; i<=vertices ; i++){
        for(int j=1 ; j<=edges ; j++){
            if(incidenceMatrix[i][j]) deg++;
        }
    }
    return deg;
}
void Graph::inDegreeOutDegree(){
    if(!directed){
        cout<<"cannot calculate in-deg and out-deg for an undirected graph"<<endl;
        return;
    }
    getIncidenceMatrix();
    for(int i=1 ; i<=vertices ; i++){
        int in=0 , out=0;
        for(int j=1 ; j<=edges ; j++){
            if(incidenceMatrix[i][j]==-1) out++;
            else if(incidenceMatrix[i][j]==1) in++;
        }
        cout<<"In-degree of vertex "<<i<<" is :"<<in<<endl;
        cout<<"Out-degree of vertex "<<i<<" is :"<<out<<endl;
    }
}
void Graph::isEuler(){
    if(directed){
        int countUnequalVertices=0;
        int v1,v2,val1,val2;
        getIncidenceMatrix();
        for(int i=1 ; i<=vertices ; i++){
            int in =0, out =0;
            for(int j=1 ; j<=edges ; j++){
                if(incidenceMatrix[i][j]==-1) out++;
                else if(incidenceMatrix[i][j]==1) in++;
            }
            if(in != out){
                countUnequalVertices++;
                if(abs(in-out)!=1 || countUnequalVertices>2){
                    cout<<"given graph has neither euler path nor euler circuit"<<endl;
                    return;
                }
                else{
                    if(countUnequalVertices==1) {
                        v1 = i;
                        val1 = in-out;
                    }
                    else{
                        v2 = i;
                        val2 = in-out;
                    }
                }
            }
        }
        if(countUnequalVertices == 0) cout<<"given graph has euler circuit"<<endl;
        else{
            if(val1 + val2 ==0) cout<<"given graph has euler path"<<endl;
        }
    }
    else{
        int countOddVertices=0;
        for(int i=1 ; i<=vertices ; i++){
            int countEdges=0;
            for(int j=1 ; j<=vertices ; j++){
                if(adjacencyMatrix[i][j]) countEdges++;
            }
            if(countEdges & 1) countOddVertices++;
        }
        if(countOddVertices == 0) cout<<"given graph has euler circuit"<<endl;
        else if(countOddVertices == 2) cout<<"given graph has euler path"<<endl;
        else cout<<"given graph has neither euler path nor euler circuit"<<endl;
    }
}
bool Graph::isCyclic(){
    Stack s;
    // int source; cin>>source;
    s.push(1);
    bool visited[vertices+1]={0};
    int flag =0;
    while(!s.empty()){
        int top = s.tos();
        if(visited[top]){
            flag = 1;
            
            break;
        }
        s.pop();
        visited[top]=1;
        for(int i =1 ; i<=vertices ; i++){
            if(adjacencyMatrix[top][i]){
                if(!visited[i]){
                    s.push(i);
                }
            }  
        }
    }
    if(flag == 0) return false;
    else {
        return true;
    }
}

