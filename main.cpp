#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <string>
#include<windows.h>

using namespace std;


struct Move 
{
	int player;
	int color;
	int column;
} move;

int p1c;
int p2c;



int game_board[8][8];
int indi[8];

// Utilities

string ab_to_bi ( string ab ) 
{
	string binary = "";
	for (int i = 0; i < ab.length(); i++)
	{
		if (ab[i]=='A') 
		{
			binary += "1";
		}
		if (ab[i]=='B') 
		{
			binary += "0";
		}
	}
	return binary;
}


int bi_to_deci(string bi)
{
    int len = bi.length();
    int deci = 0;
    for ( int i = len - 1, j = 0; i >= 0; i --, j ++ ) 
	{
    	int c = bi [ i ] - '0';
    	deci += c * pow ( 2, j );
	}
	return deci;
}

int ab_to_deci(string ab)
{
	return bi_to_deci ( ab_to_bi ( ab ) );
}

// [END] Utilities






// game functions

void apply_move1(Move move) 
{
	game_board[indi[move.column]][move.column] = 0;
	indi[move.column]++;

}

void apply_move2(Move move) 
{
	game_board[indi[move.column]][move.column] = 3;
	indi[move.column]++;

}


void apply_move(Move move) 
{
	game_board[indi[move.column]][move.column] = move.color;
	indi[move.column]++;

}



void draw_board()
{
     for (int i = 7 ; i>=0 ; i--)  
	 {
		
		for (int j = 0 ; j<8 ; j++)
		{
			if (game_board[i][j]== -1 )
				cout << "-";
			else
				cout << game_board[i][j];
		}
		
		cout << endl;
	 }
	
}

void win_check()
{
	// baresi movarab chap be rast
	for (int i = 0 ; i<8 ; i++)
	{
		for (int j = 0 ; j<8 ; j++)
		{
			if (game_board[i][j]==0 && game_board[i+1][j+1]==0 && game_board[i+2][j+2]==0 && game_board[i+3][j+3]==0)
            {
                cout << "player 1 win " << endl;
                break;
	        }
		
		}
	}
	
	// barresi ofoghi
	for (int i = 0 ; i<8 ; i++)
	{
		for (int j = 0 ; j<8 ; j++)
		{
			if (game_board[i][j]==0 && game_board[i][j+1]==0 && game_board[i][j+2]==0 && game_board[i][j+3]==0)
            {
                cout << "player 1 win " << endl;
                break;
	        }
		
		}
	}
	
	
	//movarab rast be chap
	for (int i = 0 ; i<8 ; i++)
	{
		for (int j = 0 ; j<8 ; j++)
		{
			if(game_board[j][i]==0 && game_board[j+1][i-1]==0 && game_board[j+2][i-2]==0 && game_board[j+3][i-3]==0)
            {
               cout << "player 1 win " << endl;
                break;
	        }
		
		}
	}
	
	

	//amoudi

	for (int i = 0 ; i<8 ; i++)
	{
		for (int j = 0 ; j<8 ; j++)
		{
			if (game_board[j][i]==0 && game_board[j+1][i]==0 && game_board[j+2][i]==0 && game_board[j+3][i]==0)
            {
                cout << "player 1 win " << endl;
                break;
	        }
		
		}
	}
	
	
	
	
	
	
	
		
	for (int i = 0 ; i<8 ; i++)
	{
		for (int j = 0 ; j<8 ; j++)
		{
			if (game_board[i][j]==3 && game_board[i+1][j+1]==3 && game_board[i+2][j+2]==3 && game_board[i+3][j+3]==3)
            {
                cout << "player 2 win " << endl;
                 break;
	        }
		
		}
	}
	
	
	
	for (int i = 0 ; i<8 ; i++)
	{ 
		for (int j = 0 ; j<8 ; j++)
		{
			if(game_board[j][i]==3 && game_board[j+1][i-1]==3 && game_board[j+2][i-2]==3 && game_board[j+3][i-3]==3)
            {
               cout << "player 2 win " << endl;
                break;
	        }
		
		}
	}
	
	
	// barresi ofoghi
	for (int i = 0 ; i<8 ; i++)
	{
		for (int j = 0 ; j<8 ; j++)
		{
			if (game_board[i][j]==3 && game_board[i][j+1]==3 && game_board[i][j+2]==3 && game_board[i][j+3]==3)
            {
                cout << "player 2 win " << endl;
                break;
	        }
		
		}
	}
	
	
		//amoudi

	for (int i = 0 ; i<8 ; i++)
	{
		for (int j = 0 ; j<8 ; j++)
		{
			if (game_board[j][i]==3 && game_board[j+1][i]==3 && game_board[j+2][i]==3 && game_board[j+3][i]==3)
            {
                cout << "player 2 win " << endl;
                break;
	        }
		
		}
	}
	
	

}




// [END] game functions










int main () 
{
	int x;
	cout << "1:  agar mikhahid az file bekhanid" << endl << "2:  agar mikhahid khodetan vared konid" << endl;
	cin >> x;
	if (x==1)
	{
	
		for (int i = 0 ; i<8 ; i++)
		{
			for (int j = 0 ; j<8 ; j++)
			{
				game_board[i][j]=-1;
			
			}
		}
		
		for (int i = 0; i<8 ; i++)
		{
			indi[i]=0;
		}
		// Open the file
		ifstream fin ("game.moves");
		// Save all the lines into an array
		
		string move_count_str;
		int move_count;
		fin >> move_count_str;
		move_count_str = ab_to_bi ( move_count_str );
		move_count = bi_to_deci(move_count_str );
		Move moves[move_count];
		for(int i = 0 ; i < move_count ; i++)
		{
			string mabna2;
			string current_line;
			fin >> current_line;
			moves[i].player = ab_to_deci(current_line.substr(0,3));
	    	moves[i].column = ab_to_deci(current_line.substr(3,3));
	        moves[i].color = ab_to_deci(current_line.substr(6,3));
			
		}
		
		
		for (int i = 0 ; i < move_count ; i++)
		{
			apply_move(moves [i]);
		}
		
		draw_board();
		win_check();
    }
    
    if (x==2)
    {      
        for (int i = 0 ; i<8 ; i++)
		{
					for (int j = 0 ; j<8 ; j++)
			{
				game_board[i][j]=-1;
			
		}
	}
		
		for (int i = 0 ; i<8 ; i++)
		{
			indi[i]=0; 
	    }
	     
	    int a;
	    int b;
		while (true)
		{
		 cout << "enter column:  "	;
		 cin >> a;
		 move.column = a;
		 apply_move1(move);
		 system("cls"); 
		 draw_board();
		 win_check();
		  
		 cout << "enter column:  ";
		 cin >> b;
		 move.column = b;
	     apply_move2(move);
	     system("cls");
	     draw_board();
		 win_check();      
 	    }
   }
	
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
       
    
    
    
    
    
    
    
    
    
    
    
    
	return 0;
}

