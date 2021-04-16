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


/*CODE PRINCIPALE ---- MAIN */
void main() 
{
	
	square grilleJeu[5][5];
	square piece[2][2];


	// Message de Bienvenu du BlockDoku
	cout << "Bienvenue dans ce petit jeu ou vous pouvez placer des prieces sur la grille" <<
		endl << "mais attention de ne pas choisir un emplacement qui est deja occupe" << endl;

	initGrille(grilleJeu, NBLINE, NBCOL);
	drawGrille(grilleJeu, NBLINE, NBCOL);

	initPiece(piece, PIECELINE, PIECECOL);
	
	gotoxy(0, 27);
	cout << "Prochaine piece";
	drawPiece(piece, PIECELINE, PIECECOL);
	
	
	 

	

}

/*Fonctions du main*/

void initGrille(square tab[][NBCOL], int line, int col) 
{
	for (int i = 0; i < line; i++)			// i = ligne
	{		
		for (int j = 0; j < col; j++)		// j = colonne
		{
			tab[i][j].setSquare(j * 8, (i * 4) + 3, 5, 0, 9, i * 5 + j + 1, false);
			tab[i][j].draw(cout);
		}
	}
}

void drawGrille(square tab[][NBCOL], int line, int col) 
{
	for (int i = 0; i < line; i++)			// i = ligne
	{
		for (int j = 0; j < col; j++) 		// j = colonne
		{	
			tab[i][j].draw(cout);
		}
	}
}

void initPiece(square tab[][PIECECOL], int pieceH, int pieceL) 
{
	for (int i = 0; i < pieceH; i++)		// i = ligne
	{
		for (int j = 0; j < pieceL; j++)	// j = colonne
		{
			tab[i][j].setSquare(j*8,(i*4) + 28, 5, 5, 9, 0, true);
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

void putPiece(square piece[2][2], square grilleJeu[5][5], int line, int col)
{

}