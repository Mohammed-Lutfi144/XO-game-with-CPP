//! created by the developer Mohammed Lutfi Bassief - a  junior student in Computer science major
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int counter=1; //? the number of the player
char player_Marker='X'; //* the player's marker when plays with computer
char computer='O';  //* the computer's marker
int number=0; //! index of the matrix space
bool condition =1; //todo playing repeating
int option = 1; //todo playing choices

class Player
{
    private:
        string name="Unknown";
        char marker=' ';
    public:
        void set_Value(Player ob)
        {
            cout<<"Enter the player "<<counter<<" name : ";
            cin>>name;
           cout<<"choose on of these markers to play (X-O) : ";
            
            while(!(cin>>marker))
            {
                //!illustrate the Error
                cout<<"ERROR , choose on of these markers to play (X-O) : ";
                //todo clear the previous value of the variable (marker)
                cin.clear();
                //todo discard the pervious value of the variable (marker)
                cin.ignore(123,'\n');
                
            }
            marker=check_XO(marker);
            while(marker == ob.marker)
            { 
                cout<<"This marker has been choosen"<<endl;
                      cout<<"choose on of these markers to play (X-O) : ";
                           while(!(cin>>marker))
                          {
                                //!illustrate the Error
                                      cout<<"ERROR , choose on of these markers to play (X-O) : ";
                                         //todo clear the previous value of the variable (marker)
                                             cin.clear();
                                                 //todo discard the pervious value of the variable (marker)
                                                     cin.ignore(123,'\n');
                          } 
                    marker=check_XO(marker);
            }
            counter++;
        }
        char check_XO(char marker); 
        void set_default(char player,string defaultName)
        {
            marker=player;
            name=defaultName;
        }
        friend void player_Move(char *space,Player ob);
        friend bool check_Win(char *space, Player ob1);
        friend void computer_Move(char *space, Player ob);

};
char Player :: check_XO(char marker)
{
    while(marker != 'X' && marker != 'O')
    {
        cout<<"ERROR , Please choose again"<<endl;
            cout<<"choose on of these markers to play (X-O) : ";
                 while(!(cin>>marker))
            {
                //!illustrate the Error
                cout<<"ERROR , choose on of these markers to play (X-O) : ";
                //todo clear the previous value of the variable (marker)
                cin.clear();
                //todo discard the pervious value of the variable (marker)
                cin.ignore(123,'\n');
                
            }
    }
    return marker;
}
void design(char *space);
void play_With_friend();
void play_With_Computer();
void player_Move(char *space,Player ob);
void computer_Move(char *space, Player ob);
void result(string n, int option);
bool check_Win(char *space, Player ob1);
bool check_Tie(char *space);
char check_Marker(char m, int option);
int main()
{
  char symbol=' ';
   do
   {
     do{    
            if(option != 1 && option != 2)
             {
                cout<<"Sorry, please choose an accurate choice,,"<<endl;
             }
                cout<<"1-play with your friend"<<endl;
                  cout<<"2-play with computer"<<endl;
                     cout<<"choose one of these options by entering its number : ";
                         while(!(cin>>option))
                            {
                                //!illustrate the Error
                                    cout<<"ERROR .. please enter an accurate choice (1-2) : ";
                                        //todo clear the previous value of the variable (option)
                                            cin.clear();
                                                  //todo discard the previous value fo the variable (option)
                                                        cin.ignore(123,'\n');
                            }
                     
                    
        }while(option != 1 && option != 2);
                 switch(option)
                {
                     case 1: 
                    {
                          play_With_friend();
                            break;
                    }
                     case 2: 
                    {
                          play_With_Computer();
                            break;
                    }
                }
             cout<<"Enter X or x to exit from the game, if not enter any symbol : ";
          
           while(!(cin>>symbol))
        {
            //! illustrate the Error
            cout<<"ERROR .. Enter X or x to exit from the game, if not enter any symbol : ";
            //todo clear the previous value of the variable (symbol)
            cin.clear();
            //todo discard the pervious value of the variable (symbol)
            cin.ignore(123,'\n');
        }
    }while(symbol != 'X' && symbol != 'x'); 
  cout<<"Thank you for your playing"<<endl;

    return 0;
}
void design(char *space)
{
    cout<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<space[0]<<"  |  "<<space[1]<<"  |  "<<space[2]<<"  "<<endl;
    cout<<"-----------------"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<space[3]<<"  |  "<<space[4]<<"  |  "<<space[5]<<"  "<<endl;
    cout<<"-----------------"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<space[6]<<"  |  "<<space[7]<<"  |  "<<space[8]<<"  "<<endl;
    cout<<endl;
}
void play_With_friend()
{
    Player p1; //* player 1
    Player p2; //* player 2
    p1.set_Value(p2); //? set value of player 1
    p2.set_Value(p1);   //? set value of player 2
      char repeat= 'a';
  do{ 
      char space[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '}; 
      design(space);
      condition=1;
     while(condition)
      {
        player_Move(space,p1);
            design(space);
                  if(check_Win(space,p1))
                  {
                    break;
                  }
                  else if(check_Tie(space))
                  {
                    break;
                  }
        player_Move(space,p2);
            design(space);
                  if(check_Win(space,p2))
                  {
                     break;
                  }
                  else if(check_Tie(space))
                  {
                     break;
                  }  
      }
      counter=1;
         cout<<"if you would play again. please enter any character, if not enter \'E\' or \'e\' : ";
                while(!(cin>>repeat))
                  {
                     //! illustrate the Error
                          cout<<"ERROR .. if you would play again. please enter any character, if not enter \'E\' or \'e\' : ";
                                //todo clear the previous value of the variable (number)
                                     cin.clear();
                                         //todo discard the pervious value of the variable (number)
                                              cin.ignore(123,'\n');
                  }
    }while(repeat != 'E' && repeat !='e');
}
void play_With_Computer()
{
    Player p1;
    p1.set_default(player_Marker,"You");
    Player p2;
    p2.set_default(computer,"Computer");
     char repeat= 'a';
  do{ 
      char space[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
      design(space);
      condition=1;
     while(condition)
     {
      player_Move(space,p1);
      design(space);
        if(check_Win(space,p1))
        {
            break;
        }
        else if(check_Tie(space))
        {
            break;
        }
      computer_Move(space,p2);
      design(space);
        if(check_Win(space,p2))
        {
            break;
        }
        else if(check_Tie(space))
        {
            break;
        }  
     }
     cout<<"if you would play again. please enter any character, if not enter \'E\' or \'e\' : ";
     while(!(cin>>repeat))
        {
            //! illustrate the Error
            cout<<"ERROR .. if you would play again. please enter any character, if not enter \'E\' or \'e\' : ";
            //todo clear the previous value of the variable (number)
            cin.clear();
            //todo discard the pervious value of the variable (number)
            cin.ignore(123,'\n');
        }

    }while(repeat != 'E' && repeat !='e');
}
void player_Move(char *space,Player ob)
{
  
    bool empty=0;
        
       do{ 
        cout<<ob.name<<" >> Choose a place form (1-9) : ";
        while(!(cin>>number))
        {
            //! illustrate the Error
            cout<<"ERROR .. Choose a place form (1-9) : ";
            //todo clear the previous value of the variable (number)
            cin.clear();
            //todo discard the pervious value of the variable (number)
            cin.ignore(123,'\n');
        }
        number--;

                if(space[number] == ' ')
                  {
                        empty=0;//! false
                  }
                else if (number <0 || number > 9)
                  {
                       cout<<"*please choose again*"<<endl;
                        empty=1;//! true
                  }
                 else
                  {
                        cout<<"*this place has been choosen, please choose again*"<<endl;
                        empty=1;//! true
                 }
        
       }while(empty);

    space[number]=ob.marker;
 
}
void computer_Move(char *space, Player ob)
{
    srand(time(0));
    bool empty=0;
    
   do{ 
        number= rand()%9;
            if(space[number] == ' ')
            {
                empty=0;//! false
            }
            else
            {
                empty=1;//! true
            }
   }while(empty);

    space[number]=ob.marker;
  
   
}
void result(string n, int option)
{
    if(option == 1)//? play with your friend : player2
    {
        cout<<n<<" Wins!!\n";
    }
    else if (option == 2)//? play with computer : computer
    {
        if(n == "You")
        {
             cout<<"you Win!!\n";
        }
        else
        {
        cout<<"the computer Wins!\n";
        }
    }
}
bool check_Win(char *space,Player ob1)
{
    if(space[0] !=' ' && space[0]==space[1] && space[1]==space[2])
    {
         space[0] == check_Marker(ob1.marker,option) ? result(ob1.name,option) : result(ob1.name,option);
         condition=0;
    }
    else if (space[3] != ' ' && space[3]==space[4] && space[4]==space[5])
    {
         space[3] == check_Marker(ob1.marker,option) ? result(ob1.name,option) : result(ob1.name,option);
         condition=0;
    }
    else if (space[6] != ' ' && space[6]==space[7] && space[7]==space[8])
    {
         space[6] == check_Marker(ob1.marker,option) ? result(ob1.name,option) : result(ob1.name,option);
         condition=0;
    }
    else if (space[0] != ' ' && space[0]==space[3] && space[3]==space[6])
    {
         space[0] == check_Marker(ob1.marker,option) ? result(ob1.name,option) : result(ob1.name,option);
         condition=0;
    }
    else if (space[1] != ' ' && space[1]==space[4] && space[4]==space[7])
    {
         space[1] == check_Marker(ob1.marker,option) ? result(ob1.name,option) : result(ob1.name,option);
         condition=0;
    }
    else if (space[2] != ' ' && space[2]==space[5] && space[5]==space[8])
    {
         space[3] == check_Marker(ob1.marker,option) ? result(ob1.name,option) : result(ob1.name,option);
         condition=0;
    }
    else if (space[0] != ' ' && space[0]==space[4] && space[4]==space[8])
    {
         space[0] == check_Marker(ob1.marker,option) ? result(ob1.name,option) : result(ob1.name,option);
         condition=0;
    }
    else if (space[2] != ' ' && space[2]==space[4] && space[4]==space[6])
    {
         space[2] == check_Marker(ob1.marker,option) ? result(ob1.name,option) : result(ob1.name,option);
         condition=0;
    }
    else
    {
        return 0;
    }
}
bool check_Tie(char *space)
{
   for(int i=0;i<9;i++)
   {
     if(space[i] == ' ')
     return 0;
   }
   cout<<"It is a TIE!!"<<endl;
   condition=0;
    return 1;
}
char check_Marker(char m , int option)
{
    if(option == 1)
    {
        return m;
    }
    if(option == 2)
    {
        return player_Marker;
    }
}