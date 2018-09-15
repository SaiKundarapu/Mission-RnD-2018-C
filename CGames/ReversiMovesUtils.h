/*
This struct denotes the move played by user, X means the x cordinate and Y means y cordinate.
*/
typedef struct ReversiMove {
	int x, y;
}ReversiMove;

/*
Create a ReversiMove struct (malloc/calloc etc) and return it.
Assign parameters x and y to its fields.
*/
ReversiMove *createMove(int x, int y) 
{
	ReversiMove *move = (ReversiMove*)malloc(sizeof(ReversiMove));
	move->x = x;
	move->y = y;
	return move;
}

/*
	Take Only Valid Input x, y two integers . If Invalid input is entered ,Take input again . Keep Taking input until its valid
	Hint : Use While Loop and isValidInput function
	Cordinates are 1 indexed. Ie first row/column is denoted by 1 while giving input.
*/
int isValidMove(ReversiGame *game, ReversiMove *move);

ReversiMove *inputMove(ReversiGame *game) 
{
	ReversiMove* move = (ReversiMove*)malloc(sizeof(ReversiMove));
	while (true)
	{
		printf("Enter x and y coordinates respectively");
		scanf("%d", &(move->x));
		scanf("%d", &(move->y));
		if (isValidMove(game,move)==1)
			break;

	}
	return move;

}


/*
	To check the validity of coordinate on the board 
*/

int isvalidCoordinate(ReversiGame *game, int x, int y) 
{
	if (x >= 0 && y >= 0 && x < game->rows&&y < game->cols)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
Check if the move can be placed, if its going to make a valid capture to the opponent coins
*/

int isValidMove(ReversiGame *game, ReversiMove *move)
{
	if (isvalidCoordinate(game, move->x-1, move->y-1) != 1||game->board[move->x - 1][move->y - 1] != ' ')
		return 0;
	
	char pc,oc;
	int coins_captured = 0;
	int x, y;
	if (game->turn == 1)
	{
		pc = 'w';
		oc = 'b';
	}
	else
	{
		pc = 'b';
		oc = 'w';
	}
	if (isvalidCoordinate(game, move->x - 2, move->y-1)==1)
		if (game->board[move->x - 2][move->y - 1] == oc)
		{
			x = move->x-3;
			y = move->y-1;
			coins_captured = 0;
			
			while (x >= 0)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				x--;
			}
			
			if (x < 0)
				coins_captured = 0;

			if (coins_captured > 0)
				return 1;
			
		}
	if (isvalidCoordinate(game, move->x - 1, move->y - 2) == 1)
		if (game->board[move->x - 1][move->y - 2] == oc)
		{
			x = move->x - 1;
			y = move->y - 3;
			coins_captured = 0;

			while (y >= 0)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				y--;
			}

			if (y < 0)
				coins_captured = 0;

			if (coins_captured > 0)
				return 1;
		}
	if (isvalidCoordinate(game, move->x - 2, move->y) == 1)
		if (game->board[move->x - 2][move->y] == oc)
		{
			x = move->x - 3;
			y = move->y +1;
			coins_captured = 0;

			while (x >= 0 && y<game->cols)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				x--;
				y++;
			}
			if (x < 0 || y == game->cols)
				coins_captured = 0;

			if (coins_captured > 0)
				return 1;
		
		}
	if (isvalidCoordinate(game, move->x, move->y-2) == 1)
		if (game->board[move->x][move->y-2] == oc)
		{
			x = move->x +1;
			y = move->y -3;
			coins_captured = 0;

			while (y >= 0 && x<game->rows)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				x++;
				y--;
			}
			if (y < 0 || x == game->rows)
				coins_captured = 0;

			if (coins_captured > 0)
				return 1;
		}
	if (isvalidCoordinate(game, move->x, move->y - 1) == 1)
		if (game->board[move->x][move->y - 1] == oc)
		{
			x = move->x +1;
			y = move->y -1;
			coins_captured = 0;

			while (x <game->rows)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				x++;
			}

			if (x == game->rows)
				coins_captured = 0;

			if (coins_captured > 0)
				return 1;

		}
	if (isvalidCoordinate(game, move->x - 1, move->y ) == 1)
		if (game->board[move->x - 1][move->y] == oc)
		{
			x = move->x - 1;
			y = move->y + 1;
			coins_captured = 0;

			while (y <game->cols)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				y++;
			}

			if (y ==game->cols)
				coins_captured = 0;

			if (coins_captured > 0)
				return 1;

		}
	if (isvalidCoordinate(game, move->x , move->y) == 1)
		if (game->board[move->x][move->y] == oc)
		{
			x = move->x + 1;
			y = move->y + 1;
			coins_captured = 0;

			while (x<game->rows&&y <game->cols)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				x++;
				y++;
			}

			if (x==game->rows||y == game->cols)
				coins_captured = 0;

			if (coins_captured > 0)
				return 1;

		}
	if (isvalidCoordinate(game, move->x-2, move->y-2) == 1)
		if (game->board[move->x-2][move->y-2] == oc)
		{
			x = move->x - 3;
			y = move->y - 3;
			coins_captured = 0;

			while (x>=0 && y >=0)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				x--;
				y--;
			}

			if (x <0 || y <0)
				coins_captured = 0;

			if (coins_captured > 0)
				return 1;

		}
		return 0;	
}

/*
Check if the player can move , if the player is not able to move, he looses the turn
and the opponent gets the chance to play.
If both players are not able to make a move, then the game ends.
*/

int hasMove(ReversiGame *game)
{
	bool flag = false;
	ReversiMove* move = (ReversiMove*)malloc(sizeof(ReversiMove));

	for (int i = 1; i <= game->rows; i++)
	{
		for (int j = 1; j <= game->cols; j++)
		{
			move->x = i;
			move->y = j;
			if (isValidMove(game, move) == 1)
				return 1;
		}
	}
	return 0;
}

/*
Increment the number of moves in ReversiGame struct.
*/
void incrementMoves(ReversiGame *game) 
{
	game->NumberofMoves++;
}

/*
Toggle the turn in Reversi Game.
This function is to be called when you want to change the turn.
*/
void modifyTurn(ReversiGame *game)
{
	if (game->turn == -1)
		game->turn = 1;
	else
		game->turn = -1;
}

/*
End Reversi Game.
Populate game->winner field accordingly with who won. 1 for white, -1 for black.
This function is to be called when the game is ended.
*/
void endGame(ReversiGame *game) 
{
	if (game->blackCount > game->whiteCount){
		printf("\n\nblack coins count: %d", game->blackCount);
		printf("\nwhite coins count: %d", game->whiteCount);
		game->winner = -1;
	}

	else if (game->whiteCount > game->blackCount){
		printf("\n\nblack coins count: %d", game->blackCount);
		printf("\nwhite coins count: %d", game->whiteCount);
		game->winner = 1;
	}
	else
	{
		printf("\n\nblack coins count: %d", game->blackCount);
		printf("\nwhite coins count: %d", game->whiteCount);
		game->winner = 0;
	}
	game->state = 1;
	return;
}

/*
	Wrapper function you will call only modify to increment moves and modify the turn.
*/

void modify(ReversiGame *game) 
{
	incrementMoves(game);
	modifyTurn(game);
}

void turnCoins(ReversiGame *game, ReversiMove *move)
{
	char pc, oc;
	int coins_captured = 0,coinsTurned=0;
	int x, y;
	if (game->turn == 1)
	{
		pc = 'w';
		oc = 'b';
		game->board[move->x - 1][move->y - 1] = 'w';
	}
	else
	{
		pc = 'b';
		oc = 'w';
		game->board[move->x - 1][move->y - 1] = 'b';
	}
	if (isvalidCoordinate(game, move->x - 2, move->y - 1) == 1)
		if (game->board[move->x - 2][move->y - 1] == oc)
		{
			x = move->x - 3;
			y = move->y - 1;
			coins_captured = 0;

			while (x >= 0)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				x--;
			}

			if (x < 0)
				coins_captured = 0;

			coinsTurned = coinsTurned + coins_captured;

			if (coins_captured > 0)
			{
				x++; 
				while (coins_captured != 0)
				{
					game->board[x][y] = pc;
					x++;
					coins_captured--;
				}

			}
		}
	if (isvalidCoordinate(game, move->x - 1, move->y - 2) == 1)
		if (game->board[move->x - 1][move->y - 2] == oc)
		{
			x = move->x - 1;
			y = move->y - 3;
			coins_captured = 0;

			while (y >= 0)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				y--;
			}

			if (y < 0)
				coins_captured = 0;

			coinsTurned = coinsTurned + coins_captured;

			if (coins_captured > 0)
			{
				y++;
				while (coins_captured != 0)
				{
					game->board[x][y] = pc;
					y++;
					coins_captured--;
				}

			}
		}
	if (isvalidCoordinate(game, move->x - 2, move->y) == 1)
		if (game->board[move->x - 2][move->y] == oc)
		{
			x = move->x - 3;
			y = move->y + 1;
			coins_captured = 0;

			while (x >= 0 && y<game->cols)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				x--;
				y++;
			}
			if (x < 0 || y == game->cols)
				coins_captured = 0;

			coinsTurned = coinsTurned + coins_captured;

			if (coins_captured > 0)
			{
				x++;
				y--;
				while (coins_captured != 0)
				{
					game->board[x][y] = pc;
					x++;
					y--;
					coins_captured--;
				}

			}

		}
	if (isvalidCoordinate(game, move->x, move->y - 2) == 1)
		if (game->board[move->x][move->y - 2] == oc)
		{
			x = move->x + 1;
			y = move->y - 3;
			coins_captured = 0;

			while (y >= 0 && x<game->rows)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				x++;
				y--;
			}
			if (y < 0 || x == game->rows)
				coins_captured = 0;

			coinsTurned = coinsTurned + coins_captured;

			if (coins_captured > 0)
			{
				x--;
				y++;
				while (coins_captured != 0)
				{
					game->board[x][y] = pc;
					x--;
					y++;
					coins_captured--;
				}

			}
		}
	if (isvalidCoordinate(game, move->x, move->y - 1) == 1)
		if (game->board[move->x][move->y - 1] == oc)
		{
			x = move->x + 1;
			y = move->y - 1;
			coins_captured = 0;

			while (x <game->rows)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				x++;
			}

			if (x == game->rows)
				coins_captured = 0;

			coinsTurned = coinsTurned + coins_captured;

			if (coins_captured > 0)
			{
				x--;
				while (coins_captured != 0)
				{
					game->board[x][y] = pc;
					x--;
					coins_captured--;
				}

			}

		}
	if (isvalidCoordinate(game, move->x - 1, move->y) == 1)
		if (game->board[move->x - 1][move->y] == oc)
		{
			x = move->x - 1;
			y = move->y + 1;
			coins_captured = 0;

			while (y <game->cols)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				y++;
			}

			if (y == game->cols)
				coins_captured = 0;

			coinsTurned = coinsTurned + coins_captured;

			if (coins_captured > 0)
			{
				y--;
				while (coins_captured != 0)
				{
					game->board[x][y] = pc;
					y--;
					coins_captured--;
				}

			}

		}
	if (isvalidCoordinate(game, move->x, move->y) == 1)
		if (game->board[move->x][move->y] == oc)
		{
			x = move->x + 1;
			y = move->y + 1;
			coins_captured = 0;

			while (x<game->rows&&y <game->cols)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				x++;
				y++;
			}

			if (x == game->rows || y == game->cols)
				coins_captured = 0;

			coinsTurned = coinsTurned + coins_captured;

			if (coins_captured > 0)
			{
				x--;
				y--;
				while (coins_captured != 0)
				{
					game->board[x][y] = pc;
					x--;
					y--;
					coins_captured--;
				}

			}

		}
	if (isvalidCoordinate(game, move->x - 2, move->y - 2) == 1)
		if (game->board[move->x - 2][move->y - 2] == oc)
		{
			x = move->x - 3;
			y = move->y - 3;
			coins_captured = 0;

			while (x >= 0 && y >= 0)
			{
				coins_captured++;
				if (game->board[x][y] == pc)
				{
					break;
				}
				if (game->board[x][y] == ' ')
				{
					coins_captured = 0;
					break;
				}
				x--;
				y--;
			}

			if (x <0 || y <0)
				coins_captured = 0;

			coinsTurned = coinsTurned + coins_captured;

			if (coins_captured > 0)
			{
				x++;
				y++;
				while (coins_captured != 0)
				{
					game->board[x][y] = pc;
					x++;
					y++;
					coins_captured--;
				}

			}

		}
	if (game->turn == 1)
	{
		game->whiteCount += coinsTurned;
	}
	else
	{
		game->blackCount += coinsTurned;
	}
}
/*
	This function performs move action on the board
	Note : call validity check performs using above functions before making a move
	returns :
	true on move sucess
	false if move is invalid
*/

bool playMove(ReversiGame *game, ReversiMove *move) 
{
	if (isValidMove(game, move) == 1)
	{
		turnCoins(game, move);
		modify(game);
		if (hasMove(game) != 1)
			modifyTurn(game);
		printMoves(game);
		return true;
	}
	else if (hasMove(game) != 1)
	{
		modifyTurn(game);
		if (isValidMove(game, move) == 1){
			turnCoins(game, move);
			modify(game);
			if (hasMove(game) != 1)
				modifyTurn(game);
			printMoves(game);
		}
		return false;
	}
	else
	{
		return false;
	}
}


void printWinner(ReversiGame *game) 
{
	/*
	Sample output :
	Result Praveen has won. / Game is Drawn.
	*/
	if (game->winner == 1)
		printf("\n\nplayer 1 %s (WHITE) has won.", game->player1name);
	if (game->winner == -1)
		printf("\n\nplayer 2 %s (BLACK) has won.", game->player2name);
	if (game->winner == 0)
		printf("\n---------- Game is Drawn----------\n");

	printf("Game state: %d", game->state);
}