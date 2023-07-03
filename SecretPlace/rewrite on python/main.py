import getch
import os
import numpy as np
from random import randrange
import sys

def main():
	game()
	
def game():
	while True:
		update()
		draw()
		mod = getch.getch()
		modification(mod)
		if player["X"] == winning_position["X"] and player["Y"] == winning_position["Y"]:
			player["ganar"] = True
			break
		if player["vidas"] <= 0:
			break
	clear_console()
	if player["ganar"]:
		win_menu()
	else:
		lose_menu()

def lose_menu():
	global player
	global level
	text = "Perdiste :C\nQuedaste en el nivel " + str(level) + "."
	level = 0
	resultado = selector_menu(["Jugar de nuevo", "Salir"], text)
	if resultado == 0:
		reset_variables(0)
		game()
def win_menu():
	global level
	global player
	level += 1
	text = "Ganaste!\nAhora eres nivel " + str(level) + ".\nTe sobrán " + str(player["vidas"]) + " vidas que se suman a las siguientes."
	resultado = selector_menu(["Continuar", "Salir"], text)
	if resultado == 0:
		reset_variables(player["vidas"])
		game()
def selector_menu(lista, mensaje):
	position = 0
	limit = len(lista)
	while True:
		#draw
		clear_console()
		print(mensaje)
		for i in range(limit):
			if i == position:
				print("--> ", end = "")
			else:
				print("    ", end = "")
			print(lista[i])
		#mod
		mod = getch.getch()
		if mod == "w" or mod == "W":
			if position != 0:
				position -= 1
		elif mod == "s" or mod == "S":
			if position != limit -1:
				position += 1
		
		if mod == "\n" or mod == " ":
			return position

def modification(the_input):
	if player["X"] == PLAYER_X:
		if the_input == "w" or the_input == "W":
			if player["Y"] != 0:
				player["Y"] -= 2
		elif the_input == "s" or the_input == "S":
			if player["Y"] != PLAYER_Y:
				player["Y"] += 2
			
	if the_input == "d" or the_input == "D":
		if player["X"] != PLAYER_X + 6:
			player["X"] += 6
	elif the_input == "a" or the_input == "A":
		if player["X"] != PLAYER_X - 6:
			player["X"] -= 6
	global temp_no_remove_life
	if temp_no_remove_life == False and player["X"] != PLAYER_X and (player["X"] != winning_position["X"] or player["Y"] != winning_position["Y"]):
		player["vidas"] -= 1
		temp_no_remove_life=True
	if player["X"] == PLAYER_X and temp_no_remove_life == True:
		temp_no_remove_life = False
	
	
		
def update():
	for i in range (len(game_place)):
		for j in range(len(game_place[i])):
			game_place[i][j] = " "
	
	for i in range (len(game_place)):
		game_place[i][0] = "|"
		game_place[i][X - 1] = "|"
	for i in range (len(game_place[Y-1])):
		game_place[Y-1][i] = "-"

	for i in range (len(game_place)):
		if (i % 2) == 1:
			game_place[i][1] = "="
			game_place[i][2] = "="
			game_place[i][3] = "="
			game_place[i][4] = "="
			game_place[i][5] = "="
			game_place[i][X-2] = "="
			game_place[i][X-3] = "="
			game_place[i][X-4] = "="
			game_place[i][X-5] = "="
			game_place[i][X-6] = "="
	
	game_place[player["Y"]][player["X"]] = player["CH1"]
	game_place[player["Y"]][player["X"]+1] = player["CH2"]
	game_place[player["Y"] +1][PLAYER_X] = "-"
	game_place[player["Y"] +1][PLAYER_X +1] = "-"
	
	if random_number == 0:
		winning_position["X"] = PLAYER_X - 6
		winning_position["Y"] = 0
	elif random_number == 1:
		winning_position["X"] = PLAYER_X + 6
		winning_position["Y"] = 0
	elif random_number == 2:
		winning_position["X"] = PLAYER_X - 6
		winning_position["Y"] = 2
	elif random_number == 3:
		winning_position["X"] = PLAYER_X + 6
		winning_position["Y"] = 2
	elif random_number == 4:
		winning_position["X"] = PLAYER_X - 6
		winning_position["Y"] = 4
	elif random_number == 5:
		winning_position["X"] = PLAYER_X + 6
		winning_position["Y"] = 4
	elif random_number == 6:
		winning_position["X"] = PLAYER_X - 6
		winning_position["Y"] = 6
	elif random_number == 7:
		winning_position["X"] = PLAYER_X + 6
		winning_position["Y"] = 6
	

def draw():
	clear_console()
	
	global debug
	if debug:
		print(random_number, player["ganar"], player["X"] == winning_position["X"], player["Y"] == winning_position["Y"])
		print(player["X"], player["Y"])
		print(winning_position["X"], winning_position["Y"])
	
	for i in range (len(game_place)):
		for j in range(len(game_place[i])):
			print(game_place[i][j], end="")
		print("\n", end="")
	print("VIDAS " + str(player["vidas"]))
	print('''Controles:
WASD
F Abandonar.
Instrucciones:
Encontrar el lugar secreto el
cual es elegido al azar.
Prueba tu suerte eligiedo 3 lugares
porque cada vez que lleges a un
lugar incorrecto perderas una vida.
De Manuel Gonzalez.''')
	
def reset_variables(more_lives):
	global X
	X=20
	global Y
	Y=9
	global game_place
	game_place = np.array([[" "] * X] * Y)
	global PLAYER_X
	PLAYER_X = 9
	global PLAYER_Y
	PLAYER_Y = 6
	global player
	player = {
	  "X": PLAYER_X,
	  "Y": PLAYER_Y,
	  "CH1": "c",
	  "CH2": ":",
	  "vidas": 3 + more_lives,
	  "ganar": False
	}
	global winning_position
	winning_position = {
		"X": 0,
		"Y": 0
	}
	global random_number
	random_number = randrange(8)	
	global temp_no_remove_life
	temp_no_remove_life = False

# Variables
temp_no_remove_life = False
X = 20
Y = 9
game_place = np.array([[" "] * X] * Y)
PLAYER_X = 9
PLAYER_Y = 6
player = {
  "X": PLAYER_X,
  "Y": PLAYER_Y,
  "CH1": "c",
  "CH2": ":",
  "vidas": 3,
  "ganar": False
}
winning_position = {
	"X": 0,
	"Y": 0
}
random_number = randrange(8)

debug = False
level = 0

def clear_console():
	if sys.platform == "win32":
		os.system("cls")
	else:
		os.system("clear")

if __name__ == "__main__":
	main()
	#win_menu()
	
