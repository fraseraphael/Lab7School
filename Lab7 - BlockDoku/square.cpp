

#include "square.h"

// LA DÉFINITION DES CONSTRUCTEURS (2)

// Constructeur sans paramêtres
square::square()
{
	_value = _color = _borderColor = _active = 0;
}

// Constructeur avec tt les paramêtres
square::square(int x, int y, int side, int color, int bdColor, int value, bool active)
{
	setSquare(x, y, side, color, bdColor, value, active);
}

// DESTRUCTEUR
square::~square()
{
	_value = _color = _borderColor = _active = 0;
}


// SETTEURS (5)
void square::setValue(int value)
{
	_value = value;
}

void square::setColor(int color)
{
	assert(color >= 0 && color <= 15);
	_color = color;
}

void square::setBorderColor(int bdColor)
{
	assert(bdColor >= 0 && bdColor <= 15);
	_borderColor = bdColor;
}

void square::setActive(bool active)
{
	_active = active;
}

void square::setSquare(int x, int y, int side, int color, int bdColor, int value, bool active)
{
	setPosition(x, y);
	setDimension(side, side);

	setValue(value);
	setActive(active);

	setColor(color);
	setBorderColor(bdColor);
}


// GETTEURS
int square::getValue()const
{
	return _value;
}
 
int square::getColor()const
{
	return _color;
}

int square::getBorderColor()const
{
	return _borderColor;
}

bool square::isActive()const
{
	return _active;
}


// MÉTHODES
void square::draw(ostream& sortie)const {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);

    gotoxy(_coord.getX(), _coord.getY());    // Bordure du carré ligne du haut

    for (int i = 0; i < _w; i++) {
        sortie << "\xFE ";
    }

    for (int i = 0; i < _h - 2; i++) {

        gotoxy(_coord.getX(), _coord.getY() + i + 1);
        sortie << "\xFE";                    // Bordure carré ligne de gauche


        for (int j = 0; j < _w - 2; j++) {    // Carré au centre (constitué de pts)
            sortie << "  ";
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);
        sortie << " \xFE";                    // Bordure carré ligne de droite
    }

    gotoxy(_coord.getX(), _coord.getY() + _h - 1);
    for (int i = 0; i < _w; i++) {            // Bordure du carré ligne du bas

        sortie << "\xFE ";
    }

    gotoxy(_coord.getX() + _w - 1, _coord.getY() + _h / 2);
    cout << getValue();                        // Chiffre au centre du carré

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}


void square::drawFull(ostream& sortie)const {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);

    gotoxy(_coord.getX(), _coord.getY());    // Bordure du carré ligne du haut

    for (int i = 0; i < _w; i++) {
        sortie << "\xFE ";
    }

    for (int i = 0; i < _h - 2; i++) {

        gotoxy(_coord.getX(), _coord.getY() + i + 1);
        sortie << "\xFE";                    // Bordure carré ligne de gauche

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        for (int j = 0; j < _w - 2; j++) {    // Carré au centre (constitué de pts)
            sortie << " \xFE";
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _borderColor);
        sortie << " \xFE";                    // Bordure carré ligne de droite
    }

    gotoxy(_coord.getX(), _coord.getY() + _h - 1);
    for (int i = 0; i < _w; i++) {            // Bordure du carré ligne du bas

        sortie << "\xFE ";
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

