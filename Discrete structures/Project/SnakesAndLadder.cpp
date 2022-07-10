#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;
class SnakesAndLadder{
    public:
        int board[101][101]={{0}};
        int currpos = 0;
        void setDefaultBoard(){
            ifstream input("snakesandladders.txt");
            int total;
            input>>total;
            for(int i=0 ; i<total ; i++){
                int v1,v2;
                input >> v1 >>v2;
                board[v1][v2] = 1;
            }
        }
        void showBoard(){
            for(int i=1 ; i<=100 ; i++){
                for(int j=1 ; j<=100 ; j++){
                    if(board[i][j]==1){
                        if(i>j){
                            cout<<"snake from "<<i<<" to "<<j<<endl;
                        }
                        else{
                            cout<<"ladder from "<<i<<" to "<<j<<endl;
                        }
                    }
                }
            }
        }
};
class StartGame : public SnakesAndLadder{
    public:
    string playerName = "";
    bool isValidToBegin(int die){ //check if currpos is -1 and die gave 6 so player can begin
        if (currpos == 0 && die != 6 ){
            return false;
        }
        else if(currpos == 0 &&  die ==6){
            cout<<"Yuhhuuuuuuuu "<<playerName<<"'s spawn is unlocked now!"<<endl;
            return true;
        }
        else{
            return true;
        }
    }
    int throwDie(){
        cout<<"Its "<<playerName<<"'s turn"<<endl;
        cout<<"Press 1 to throw the die or any other key to exit(player with greater spawn will win then)";
        string choice;
        cin>>choice;
        if(choice == "1"){
            int num = (rand()%6)+1;
            cout<<playerName<<" got "<<num<<endl;
            incrementCurrPos(num);
            return 1;
        }
        else{
            cout<<"BYE! have a good day"<<endl;
            return 0;
        }
    };  
    void incrementCurrPos(int n){
        if(isValidToBegin(n)){
            if(!isMoveValid(n)){
                cout<<playerName<< "'s move is wasted since you are going beyond 100"<<endl;
                int diff = 100 - currpos;
                cout<<"get a number between 1 to "<<diff<<endl;
                return;
            }
            currpos += n;
            int sOrL = checkForLadderOrLadder(currpos);
            if(sOrL == 0){
                cout<<"You found nothing"<<endl;
            }
            else{
                if(sOrL < currpos){
                    cout<<"OH NO !!! you found a snake !!! HISSSSSSSSSSSS"<<endl;
                    currpos = sOrL;
                }
                else{
                    cout<<"OH YEAH!!! you got a ladder"<<endl;
                    currpos = sOrL;
                }
            }
        }
        else{
            cout<<"get a 6 to begin your game"<<endl;
        }
    }; //increments currpos by the die and then checks for snakes/ladders
    bool isMoveValid(int n){
        if(currpos + n > 100) return false;
        else return true;
    }; // check if final position after incrementing die to currpos exceeds 100 or not
    int checkForLadderOrLadder(int initial){
        for(int i=1 ; i<=100 ; i++){
            if(board[initial][i]==1){
                return i;
            }
        }
        return 0;
    }
};
class changeBoard : public SnakesAndLadder{
    public:
    void addLadder();// to add a ladder
    void addSnake(); // to add a snake 
    bool canAddLadder(int init , int final);// returns true if ladder to add is a valid ladder
    bool canAddSnake(int init , int final); // returns true if snake to add is a valid snake
    void deleteSnake(int init , int final); // to delete a snake
    void deleteLadder(int init , int final); // to delete a ladder
};
int main(){
    srand(time(0));
    /*we will have a menu here having two choices to startgame with default board or to first change the board and then start.
    if user select start game then*/ 
    StartGame player1,player2;
    player1.playerName = "mayank";
    player2.playerName = "manav";
    while(true){
        int num1 = player1.throwDie();
        int num2 = player2.throwDie();
        if(num1 == 0 || num2 ==0){
            if(player1.currpos > player2.currpos){
                cout<<player1.playerName<<" won the game"<<endl;
                break;
            }
            else if(player1.currpos < player2.currpos){
                cout<<player2.playerName<<" won the game"<<endl;
                break;
            }
            else{
                cout<<"there's a tie"<<endl;
                break;
            }
        }
        else{
            if(player1.currpos == 100){
                cout<<player1.playerName<<"won the game"<<endl;
                break;
            }
            if(player2.currpos == 100){
                cout<<player2.playerName<<"won the game"<<endl;
                break;
            }
        }
        cout<<"below is current leaderBoard"<<endl;
        cout<<player1.playerName<<"----> "<<player1.currpos<<endl;
        cout<<player2.playerName<<"----->"<<player2.currpos<<endl;
    }
    /* if user select to change board then we will again display menu to add/delete a snake/ladder*/
    // changeBoard cb;
    // int vertex1 , vertex2;
    // cout<<"enter starting number of snake/ladder";
    // cin>>vertex1;
    // cout<<"enter ending number of snake/ladder";
    // cin>>vertex2;
    // // checking if a snake/ladder can  be added or not
    // cb.canAddLadder(vertex1 , vertex2);
    // cb.canAddSnake(vertex1 , vertex2);
    // // to delete
    // cb.deleteLadder(vertex1 , vertex2);
    // cb.deleteSnake(vertex1 , vertex2);
    // SnakesAndLadder s;
    // s.setDefaultBoard();
    // s.showBoard();
    // StartGame g;
}