#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

#define COL 20
#define ROW 9
#define PLAYER_X 9
#define PLAYER_Y 6

void clear_console();
void draw();
void update();
void modification();
bool game();
int options_menu(vector<string> phrases, string message);
void modification(char mod);

class Player {
	public:
		vector<int> position;
		vector<char> character;
		int lives;
};

// declarations
vector<vector<char>> game_array;
Player player;

int main () {
	// declarations
	for (int i = 0; i < ROW; i++) {
	       	vector<char> v1;
	       	for (int j = 0; j < COL; j++) {
			v1.push_back(' ');
	       	}
	       	game_array.push_back(v1);
	}	
	player.position = {PLAYER_X,PLAYER_Y};
	player.character = {'c',':'};
	player.lives = 3;
	//vector<string> options = {"Try Again","Quit"};
	//options_menu(options, "You lose");
	bool repeat = true;
	while (repeat){
		bool result = game();
		if (result){
			vector<string> options = {"Continue", "Quit"};
			string text = "Congratulations! You won!";
			if (options_menu(options, text) == 0){
				repeat = true;
			} else {
				repeat = false;
			}
		} else {
			vector<string> options = {"Try Again", "Quit"};
			string text = "Ups... You lose...";
			if (options_menu(options, text) == 0){
				repeat = true;
			} else {
				repeat = false;
			}
		}
	}
	return 0;
}

bool game(){
	// first update
	update();
	while (true){
		// draw
		draw();
		// modification
		char mod = getch();
		modification(mod);
		// update
		update();
	}
	return false;
}
void modification(char mod){
	if ( mod == 'W' || mod == 'w' ){
		if ((player.position.at(1) > 0) && (player.position.at(0) == PLAYER_X)){
			player.position = {player.position.at(0), player.position.at(1) - 2};
		}
	}
	else if ( mod == 'S' || mod == 's' ){
		if ((player.position.at(1) < ROW - 3) && (player.position.at(0) == PLAYER_X)){
			player.position = {player.position.at(0), player.position.at(1) + 2};
		}
	}
	if ( mod == 'a' || mod == 'A' ){
		if (player.position.at(0) > PLAYER_X - 6){
			player.position = {player.position.at(0) - 6, player.position.at(1)};
		}
	}
	else if ( mod == 'd' || mod == 'D' ){
		if (player.position.at(0) < PLAYER_X + 6){
			player.position = {player.position.at(0) + 6, player.position.at(1)};
		}
	}
}
void update(){
	
	for (int i = 0; i < ROW; i++) {
	       	for (int j = 0; j < COL; j++) {
			game_array.at(i).at(j) = ' ';
	       	}
	}

	for (int i=0; i < game_array.size(); i++){
		for (int j=0; j < game_array.at(i).size(); j++){
			if (j == 0 || j == COL - 1){
				game_array.at(i).at(j) = '|';
			}
		}
	}
	for (int i=0; i < game_array.at(0).size(); i++){
		game_array.at(ROW - 1).at(i) = '-';
	}
	for (int i=0; i < game_array.size(); i++){
		if ((i % 2) == 1){
			for (int j=0; j < game_array.at(i).size(); j++){
				if ((j>0 && j <6) || (j< COL-1 && j > COL - 7)){
					game_array.at(i).at(j) = '=';
				}
			}
		}
	}
	game_array.at(player.position.at(1)).at(player.position.at(0)) = player.character.at(0);
	game_array.at(player.position.at(1)).at(player.position.at(0) + 1) = player.character.at(1);
	game_array.at(player.position.at(1) + 1).at(PLAYER_X + 1) = '-';
	game_array.at(player.position.at(1) + 1).at(PLAYER_X) = '-';

		
}
void draw(){
	clear_console();
	for (int i=0; i < game_array.size(); i++){
		for (int j=0; j <game_array.at(i).size(); j++){
		cout << game_array.at(i).at(j);
		}
		cout << "\n";
	}
	cout << "VIDAS " << player.lives << ".\n";
	cout << "Controles:\n";
	cout << "WASD \n";
	cout << "F Abandonar. \n";
	cout << "Instrucciones: \n";
	cout << "Encontrar el lugar secreto el\n";
	cout << "cual es elegido al azar.\n";
	cout << "Prueba tu suerte eligiedo 3 lugares \n";
	cout << "porque cada vez que lleges a un\n";
	cout << "lugar incorrecto perderas una vida.\n";
	cout << "De Manuel Gonzalez." << endl;
}

void clear_console(){
	system("clear");
}

int options_menu(vector<string> phrases, string message){
	// declaration
	int option = 0;
	// first update
	clear_console();
	
	while (true){
		// draw
		cout << message << endl;
		for (int i = 0; i<phrases.size(); i++){
			if (i == option){
				cout << "-->" ;
			} else {
				cout << "   ";
			}
			cout << phrases.at(i) << endl;
		}
	
		// mod
		char mod = getch();
		if (mod == 'w' || mod == 'W'){
			if (option > 0){
				option--;
			}
		} else if (mod == 's' || mod == 'S'){
			if (option < phrases.size() - 1){
				option++;
			}
		}
		if (mod == '\n' || mod == ' '){
			return option;
		}
		// update
		clear_console();
	}
}
