/*=============================================================================================
Auteur : Raphaël Fraser
Projet : Lab7 - BlockDoku
Nom du fichier : square.h
Date : 2021-04-08
But : 
===============================================================================================*/

// LES LIBRAIRIES
#pragma once
#include <iostream>
#include "rectangle.h"
#include <cassert>	// Assert


// LA CLASSE SQUARE
class square : public rectangle
{
private:
	int _value;			// Value de la square
	bool _active;		// Servira pour nos pièces
	int _color;			// Couleur de la square entre 1 et 15 inlcu. À Valider assert
	int _borderColor;	// Couleur de la bordure de la square entre 1 et 15 inlcus.

public:
	/*Constructeurs*/
	square();		// Init tout à 0 ou false
	square(int x, int y, int side, int color = 0, int bdColor = 0, int value = 0, bool active = true);
	
	/*Destructeur*/
	~square();		// Init tout à 0 ou false

	/*Setteurs*/
	void setValue(int value);
	void setColor(int color);
	void setBorderColor(int bdColor);
	void setActive(bool active);
	void setSquare(int x, int y, int side, int color = 0, int bdColor = 0, int value = 0, bool active = true);

	/*Getteurs*/
	int getValue()const;
	int getColor()const;
	int getBorderColor()const;
	bool isActive()const;

	/*Méthodes*/
	void draw(ostream& out)const;		// Nouveau draw qui tient compte des couleurs
	void drawFull(ostream& out)const;	// et qui affiche la value au centre si <> 0 

};


