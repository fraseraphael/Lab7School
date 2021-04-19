/*=============================================================================================
Auteur : Raphaël Fraser
Projet : Lab7 - BlockDoku
Nom du fichier : square.h
Date : 2021-04-08
But :
===============================================================================================*/

#include <iostream>
#include "rectangle.h"
#include "square.h"

using namespace std;

/*Constantes*/
const int NBCOL = 5;
const int NBLINE = 5;

const int PIECECOL = 2;
const int PIECELINE = 2;

/*Prototypes*/
void initGrille(square tab[][NBCOL], int line, int col);
void drawGrille(square tab[][NBCOL], int line, int col);

void initPiece(square tab[][PIECECOL], int pieceH, int pieceW);
void drawPiece(square tab[][PIECECOL], int pieceH, int pieceW);

void putPiece(square piece[2][2], square grilleJeu[5][5], int line, int col);
bool collisionPiece(square piece[2][2], square grilleJeu[5][5], int line, int col);

int choseCase();

/*CODE PRINCIPALE ---- MAIN */
void main() 
{
	// Variables Main
	bool gameOver = false;
	int noCase;
	int	score = 0;
	


	square grilleJeu[5][5];
	square piece[2][2];


	// Message de Bienvenu du BlockDoku
	cout << "Bienvenue dans ce petit jeu ou vous pouvez placer des prieces sur la grille" <<
		endl << "mais attention de ne pas choisir un emplacement qui est deja occupe" << endl;

	initGrille(grilleJeu, NBLINE, NBCOL);

	while (!gameOver)
	{
		drawGrille(grilleJeu, NBLINE, NBCOL);

		gotoxy(0,25);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Prochaine piece";

		initPiece(piece, PIECELINE, PIECECOL);
		drawPiece(piece, PIECELINE, PIECECOL);

		noCase = choseCase();

		int line = (noCase - 1) / 5; //ici c’est la division entière
		int col = (noCase - 1) % 5; //ici c’est le reste du modulo 

		if (!collisionPiece(piece, grilleJeu, line, col))
		{
			putPiece(piece, grilleJeu, line, col);

			drawGrille(grilleJeu, NBLINE, NBCOL);
			Sleep(100);
		}
		else
		{
			gotoxy(0, 38);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "Cette place n'est pas possible" << endl;
		}
		
		system("pause>0");
	}
	
	 

	

}

/*Fonctions du main*/

void initGrille(square grilleJeu[][NBCOL], int line, int col) 
{
	for (int i = 0; i < line; i++)			// i = ligne
	{		
		for (int j = 0; j < col; j++)		// j = colonne
		{
			grilleJeu[i][j].setSquare(j * 8, (i * 4) + 3, 5, 0, 9, i * 5 + j + 1, false);
			grilleJeu[i][j].draw(cout);
		}
	}
}

void drawGrille(square grilleJeu[][NBCOL], int line, int col) 
{
	for (int i = 0; i < line; i++)			// i = ligne
	{
		for (int j = 0; j < col; j++) 		// j = colonne
		{	
			if (grilleJeu[i][j].isActive())
				grilleJeu[i][j].drawFull(cout);
			else
				grilleJeu[i][j].draw(cout);
		}	
	}
}

void initPiece(square piece[][PIECECOL], int pieceH, int pieceL) 
{
	for (int i = 0; i < pieceH; i++)		// i = ligne
	{
		for (int j = 0; j < pieceL; j++)	// j = colonne
		{
			piece[i][j].setSquare(j*8,(i*4) + 28, 5, 5, 9, 0, true);
		}
	}
}

void drawPiece(square tab[][PIECECOL], int pieceH, int pieceL) 
{
	for (int i = 0; i < pieceH; i++) 
	{
		for (int j = 0; j < pieceL; j++) 
		{
			tab[i][j].drawFull(cout);
		}
		
	}
}	

int choseCase()
{
	int noCase;

	do
	{
		gotoxy(0, 37);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Choisissez l'endroit ou placer cette piece : ";
		cin >> noCase;
	} while (noCase < 1 && noCase > 25);
	return noCase;
}

void putPiece(square piece[2][2], square grilleJeu[5][5], int line, int col)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (piece[i][j].isActive() && (line + i < 5 && col + j < 5))
			{
				grilleJeu[line + i][col + j].setColor(piece[i][j].getColor());
				grilleJeu[line + i][col + j].setActive(piece[i][j].isActive());
				grilleJeu[line + i][col + j].drawFull(cout);
			}
		}
	}
}

bool collisionPiece(square piece[2][2], square grilleJeu[5][5], int line, int col)
{
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (piece[i][j].isActive())
			{
				if (line + i >= 5 || col + j >= 5)
					return true;
				if (grilleJeu[line + i][col + j].isActive())
					return true;
			}
		}
	}
	return false;
}
