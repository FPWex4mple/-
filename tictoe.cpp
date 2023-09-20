#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<windows.h>

using namespace std;

//	глобальны константы
	const char X = 'X';
	const char O = 'O';
	const char EMPTY = ' ';
	const char TIE = 'T';
	const char NOone = 'N';
	
//	прототипы функций
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(const vector<char>& board, char computer);
void announceWinner(char winner, char computer, char human);

main(){
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);
	instructions();
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;
	displayBoard(board);
	while(winner(board) == NOone){
		if(turn == human){
			move = humanMove(board, human);
			board[move] = human;
		}
		else{
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBoard(board);
		turn = opponent(turn);
	}
	announceWinner(winner(board),computer,human);
	return 0;
}

void instructions(){
	SetConsoleOutputCP(65001);
	cout<<"Добро подаловть в игру крестики-нолики\n";
	cout<<"Вы будете сражаться с машиной\n";
	cout<<"Выбор поля 0-8\n";
	cout<<"Позиции выглядят так\n\n";
	cout<<" 0 | 1 | 2\n";
	cout<<"------------\n";
	cout<<" 3 | 4 | 5\n";
	cout<<"------------\n";
	cout<<" 6 | 7 | 8\n";
	cout<<"Приготовтесь к игре";
}

char askYesNo(string question){
	char response;
	do{
		cout<< question << "y/n: " ;
		cin>>response;
	}
	while(response != 'y' && response != 'n');
	return response;
}

int askNumber(string question, int high, int low){
	int number;
	do{
		cout<<question<<" ("<<low<<" - "<<high<<"): ";
		cin>>number;
	}
	while (number > high || number < low);
	return number;
	
}

char humanPiece(){
	SetConsoleOutputCP(65001);
	char go_first = askYesNo("Хотите ли вы сделать ход первым?");
	if(go_first == 'y'){
		cout<<"\nВы делайте первый ход";
		return X;
	}
	else{
		cout<<"\nПервый ход делает компьютер";
		return 0;
	}
}

char opponent(char piece){
	if(piece == X){
		return 0;
	}
	else{
		return X;
	}
}

void displayBoard(const vector<char>& board){
	cout << "\n\t"<<board[0]<<" | "<<board[1]<<" | "<<board[2];
	cout<<"\n\t"<<"----------";
	cout << "\n\t"<<board[3]<<" | "<<board[4]<<" | "<<board[5];
	cout<<"\n\t"<<"----------";
	cout << "\n\t"<<board[6]<<" | "<<board[7]<<" | "<<board[8];
	cout<<"\n\n";
}

char winner(const vector<char>& board){
	const int WINNING_ROWS[8][3] = {{0, 1, 2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{0,4,8},
		{2,4,6} };
		const int TOTAL_ROWS = 8;
		for(int row = 0; row < TOTAL_ROWS; ++row){
			if((board[WINNING_ROWS[row][0]] != EMPTY)&&
			(board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]])&&
			(board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]])){
				return board[WINNING_ROWS[row][0]];
			}
		}
		if(count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;
		return NOone;
}

inline bool isLegal(int move, const vector<char>& board){
	return(board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human){
	SetConsoleOutputCP(65001);
	int move = askNumber("Куда вы будете идти? ", (board.size() - 1));
	while(!isLegal(move, board)){
		cout<<"\nЭтот ход уже сделан, тупой додик\n";
		move = askNumber("Куда ты будешь ходить?", (board.size() - 1));
	}
	cout<<"Хорошо...\n";
	return move;
}

int computerMove(vector<char>& board, char computer){
	SetConsoleOutputCP(65001);
	unsigned int move = 0;
	bool found = false;
	while (!found && move < board.size()) 
	{ 
		if (isLegal(move, board)) 
		{ 
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY; 
		} 
		if (!found) 
		{ 
			++move;
		}
	}
	if (!found) 
	{ 
		move = 0; 
		char human = opponent(computer); 
		while (!found && move < board.size()) 
		{ 
		if (isLegal(move, board)) 
		{ 
			board[move] = human; 
			found = winner(board) == human;
			board[move] = EMPTY; 
		} 
		if (!found) 
		{ 
			++move;
			}
		}
	}
	if (!found) 
	{ 
		move = 0;
		unsigned int i = 0; 
		const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
		while (!found && i < board.size()) 
		{ 
				move = BEST_MOVES[i];
				if (isLegal(move, board)) 
			{ 
			found = true;
			} 
			++i;
		}
	}
	cout<<" Я пойду в квадратик "<< move<<endl;
	return move;
}

void announceWinner(char winner, char computer, char human){
	SetConsoleOutputCP(65001);
	if(winner == computer)
	{
		cout<<winner<<" выиграл!"<<endl;
		cout<<" Как я и думал, додик цветочный"<<endl;
	}
	else if (winner == human){
		cout<<winner<<" победил!"<<endl;
		cout<<"а ты умнее чем я думал!";
	}
	else{
		cout<<"Ничья"<<endl;
		cout<<"Тебе просто повезло";
	}
}