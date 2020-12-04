#include<iostream>
using namespace std;
char a[30],b[30];
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char current_marker;
int current_player;
void showboard()
{
	cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" | "<<endl;
	cout<<"-------------"<<endl;
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" | "<<endl;
	cout<<"-------------"<<endl;
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" | "<<endl;
}
bool place_marker(int slot)
{
	int row,col;
	row=slot/3;
	if(slot%3==0)
	{
		row=row-1;
		col=2;
	}
	else
	col=(slot%3)-1;
	if(board[row][col]!='O'&&board[row][col]!='X')
	{
		board[row][col]=current_marker;
		return true;
	}
	else
	return false;
}
int winner()
{
	for(int i=0;i<3;i++)
	{
		if((board[i][0]==board[i][1])&&(board[i][1]==board[i][2]))
		return current_player;
		if((board[0][i]==board[1][i])&&(board[1][i]==board[2][i]))
		return current_player;
	}
	if( board[0][0]==board[1][1] && board[1][1]==board[2][2] )
	return current_player;
	if( board[0][2]==board[1][1] && board[1][1]==board[2][0] )
	return current_player;
	return 0;
}
void swap()
{
	if(current_marker=='X')
	current_marker='O';
	else
	current_marker='X';
	if(current_player==1)
    current_player=2;
	else
	current_player=1;
}
void game()
{
	char marker1;
	cout<<"PLAYER "<< a<<" "<< "PLEASE CHOOSE YOUR MARKER:"<<endl;
	cin>>marker1;
	current_player=1;
	current_marker=marker1;
	showboard();
	int player_won;
	for(int i=0;i<9;i++)
	{
		int slot;
		cout<<"IT'S PLAYER Number "<< current_player <<"'s CHANCE , PLEASE ENTER YOUR SLOT=";
		cin>>slot;
		cout<<endl;
		if(slot<1 || slot>9)
		{
			cout<<"INVALID CHOICE,PLEASE ENTER CORRECT SLOT"<<endl;
			i--;
			continue;
		}
		if(!place_marker(slot))
		{
			cout<<"SLOT IS OCCUPIED";
			i--;
			continue;
		}
		showboard();
		player_won=winner();
		if(player_won==1)
		{
	    cout<<"\nGAME OVER\n";
		cout<<"CONGRATULATIONS,PLAYER 1 " <<a<<" HAS WON THE GAME"<<endl;
		break;
		}
		if(player_won==2)
		{
	    cout<<"\nGAME OVER\n";
		cout<<"CONGRATULATIONS,PLAYER 2 "<< b <<" HAS WON THE GAME"<<endl;
        break;
	    }
		swap();
		}
		if(player_won==0)
		cout<<"THE GAME IS TIE BETWEEN "<< a <<" AND "<< b <<endl;
	
}
int main()
{
	int c;
	cout<<"\nPRESS ANY NUMBER TO DISPLAY INFORMATION AND GAME FORMAT : ";
	cin>>c;
	cout<<endl;
	cout<<"                                    NAME : ISHIKA JAIN\n                                    COURSE : BTECH CSE\n                                    SEMESTER : 3\n                                    MINI PROJECT TIC TAC TOE\n";
	cout<<"   FORMAT\n";
	showboard();
	cout<<"ENTER THE FIRST PLAYER'S NAME: ";
	cin>>a;
	cout<<"ENTER THE SECOND PLAYER'S NAME: ";
	cin>>b;
	game();
}
