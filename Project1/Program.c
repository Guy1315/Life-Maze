#include <stdio.h>
#define row 3
#define col 3
void createBoard(char(*a)[col+2]);
void printBoard(char(*a)[col+2]);
void game(char(*a)[col+2]);
int samePlace(char(*a)[col + 2]);
int countPoints(char(*a)[col + 2]);

int bRow;
int bCol;
int dRow;
int dCol;

int main() {
	char board[row+2][col+2];
	again:createBoard(board);
	if (samePlace(board)) {
		printBoard(board);
		printf(" snail bear is in the same place as booli, please input new locations \n");
		goto again;
	}
	printBoard(board);
	game(board);
	return 0;
}
void game(char(*a)[col+2]) {
	int pAmount = countPoints(a),move;
	int lastRow=0, lastCol=0;
	char keep='#';
	//run the loop until all the points have been eaten or when booli is eaten by the bear
	while (pAmount != 0){
		printf("enter move: ");
		scanf_s("%d", &move);
	//תנועות השחקן לפי הקלט
		//do the move the player did previously, if there isn't don't move
		if (move == 0) {
			if (a[bRow + lastRow][bCol+ lastCol] == '#') {
				pAmount--;
				a[bRow][bCol] = '|';
				a[bRow + lastRow][bCol + lastCol] = 'b';
			}
			else {
				if (a[bRow + lastRow][bCol + lastCol] == '|') {
					a[bRow][bCol] = '|';
					a[bRow + lastRow][bCol + lastCol] = 'b';
				}
				else printf("can't move, wall ahead \n");
			}
		}
		//move right
		if (move == 1) {
			if (a[bRow][bCol + 1] == '#') {
				pAmount--;
				lastCol = 1;
				lastRow = 0;
				a[bRow][bCol] = '|';
				a[bRow][bCol + 1] = 'b';
				bCol += 1;
			}
			else {
				if (a[bRow][bCol + 1] == '|') {
					lastCol = 1;
					lastRow = 0;
					a[bRow][bCol] = '|';
					a[bRow][bCol + 1] = 'b';
					bCol += 1;
				}
				if (a[bRow][bCol + 1] == '*')
					printf("can't move forward, wall ahead \n");
			}
		}
		//move left
		if (move == 2) {
			if (a[bRow][bCol - 1] == '#') {
				pAmount--;
				lastCol = -1;
				lastRow = 0;
				a[bRow][bCol] = '|';
				a[bRow][bCol - 1] = 'b';
				bCol -= 1;
			}
			else {
				if (a[bRow][bCol - 1] == '|') {
					lastCol = -1;
					lastRow = 0;
					a[bRow][bCol] = '|';
					a[bRow][bCol - 1] = 'b';
					bCol -= 1;
				}
				if (a[bRow][bCol - 1] == '*')
					printf("can't move forward, wall ahead \n");
			}
		}
		//move up
		if (move == 3) {
			if (a[bRow-1][bCol] == '#') {
				pAmount--;
				lastCol = 0;
				lastRow = -1;
				a[bRow][bCol] = '|';
				a[bRow-1][bCol] = 'b';
				bRow -= 1;
			}
			else {
				if (a[bRow- 1][bCol] == '|') {
					lastCol = 0;
					lastRow = -1;
					a[bRow][bCol] = '|';
					a[bRow - 1][bCol] = 'b';
					bRow -= 1;
				}
				if (a[bRow-1][bCol] == '*')
					printf("can't move forward, wall ahead \n");
			}
		}
		//move down
		if (move == 4) {
			if (a[bRow + 1][bCol] == '#') {
				pAmount--;
				lastCol = 0;
				lastRow = 1;
				a[bRow][bCol] = '|';
				a[bRow + 1][bCol] = 'b';
				bRow += 1;
			}
			else {
				if (a[bRow + 1][bCol] == '|') {
					lastCol = 0;
					lastRow = 1;
					a[bRow][bCol] = '|';
					a[bRow + 1][bCol] = 'b';
					bRow += 1;
				}
				if (a[bRow + 1][bCol] == '*')
					printf("can't move forward, wall ahead \n");
			}
		}
		//the snail bear movements according to booli's
		if (a[bRow] - a[dRow] < 0) {
			if (a[dRow - 1][dCol] == '#') {
				a[dRow][dCol] = keep;
				keep = '#';
				a[dRow - 1][dCol] = 'd';
				dRow -= 1;
				goto con1;
			}
			if (a[dRow - 1][dCol] == '|') {
				a[dRow][dCol] = keep;
				keep = '|';
				a[dRow - 1][dCol] = 'd';
				dRow -= 1;
				goto con1;
			}
			if (a[dRow - 1][dCol] == 'b') {
				a[dRow][dCol] = keep;
				a[dRow-1][dCol] = 'd';
				printBoard(a);
				printf("game over! snail bear won");
				break;
			}
		}
		else {
			if (a[bRow] - a[dRow] > 0) {
				if (a[dRow + 1][dCol] == '#') {
					a[dRow][dCol] = keep;
					keep = '#';
					a[dRow + 1][dCol] = 'd';
					dRow += 1;
					goto con1;
				}
				if (a[dRow + 1][dCol] == '|') {
					a[dRow][dCol] = keep;
					keep = '|';
					a[dRow + 1][dCol] = 'd';
					dRow += 1;
					goto con1;
				}
				if (a[dRow + 1][dCol] == 'b') {
					a[dRow][dCol] = keep;
					a[dRow + 1][dCol] = 'd';
					printBoard(a);
					printf("game over! snail bear won");
					break;
				}
			}
		} con1:
		if (a[bCol] - a[dCol] < 0) {
			if (a[dRow][dCol-1] == '#') {
				a[dRow][dCol] = keep;
				keep = '#';
				a[dRow ][dCol-1] = 'd';
				dCol -= 1;
				goto con2;
			}
			if (a[dRow][dCol-1] == '|') {
				a[dRow][dCol] = keep;
				keep = '|';
				a[dRow ][dCol-1] = 'd';
				dCol -= 1;
				goto con2;
			}
			if (a[dRow][dCol - 1] == 'b') {
				a[dRow][dCol] = keep;
				a[dRow][dCol - 1] = 'd';
				printBoard(a);
				printf("game over! snail bear won");
				break;
			}
		}
		else {
			if (a[bCol] - a[dCol] > 0) {
				if (a[dRow][dCol + 1] == '#') {
					a[dRow][dCol] = keep;
					keep = '#';
					a[dRow][dCol + 1] = 'd';
					dCol += 1;
					goto con2;
				}
				if (a[dRow][dCol + 1] == '|') {
					a[dRow][dCol] = keep;
					keep = '|';
					a[dRow][dCol + 1] = 'd';
					dCol += 1;
					goto con2;
				}
				if (a[dRow][dCol + 1] == 'b') {
					a[dRow][dCol] = keep;
					a[dRow][dCol + 1] = 'd';
					printBoard(a);
					printf("game over! snail bear won");
					break;
				}
			}
		}
		con2:
		printBoard(a);
	}
	if (pAmount == 0)
		printf("game over, booli wins!");
}

void createBoard(char(*a)[col+2]) {
	int roe,coll;
	//taking care of points on the board where walls weren't placed
	for (int i = 0; i < row + 2; i++)
	{
		for (int j = 0; j < col + 2; j++)
		{
			a[i][j] = '#';
		}
	}
	//creating a border so that the player won't leave the board
	for (int i = 0; i < row+2; i++)
	{
		for (int j = 0; j < col+2; j++)
		{
			a[0][j] = '*';
			a[row+1][j] = '*';
			a[i][0] = '*';
			a[i][col+1] = '*';
		}
	}
	//getting the coordinates for the walls in the board, 0 to finish
	printf("input row and collumn of a wall, enter 0 to end\n");
	scanf_s("%d %d", &roe, &coll);
	while(roe!=0&&coll!=0){
		a[roe][coll] = '*';
		scanf_s("%d %d", &roe, &coll);
	}
	printf("input row and col where booli will start \n");
	scanf_s("%d %d", &roe, &coll);
	a[roe][coll] = 'b';
	bRow = roe;
	bCol = coll;
	printf("\n");
	printf("input row and col where snail bear will start \n");
	scanf_s("%d %d", &roe, &coll);
	dRow = roe;
	dCol = coll;
	a[roe][coll] = 'd';
}
void printBoard(char(*a)[col+2]) {
	for (int i = 0; i < row+2; i++)
	{
		for (int j = 0; j < col+2; j++)
		{
			printf("%c ", a[i][j]);
		}
		printf("\n");
	}
}
//check the possibility of placing booli and the snail bear in the same coordinates
int samePlace(char(*a)[col + 2]) {
	int check=0;
	for (int i = 0; i < row+2; i++)
		for (int j = 0; j < col+2; j++) {
			if (a[i][j]=='b') {
				check=1;
				break;
			}
		}
	if (check == 1)
		return 0;
	return 1;
}
//count the points in the board
int countPoints(char(*a)[col + 2]) {
	int count = 0;
	for (int i = 0; i < row+2; i++)
		for (int j = 0; j < col+2; j++)
			if (a[i][j] == '#')
				count++;
	return count;
}