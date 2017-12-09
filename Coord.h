//
// Created by Yulia Lizneva on 2017-12-08.
//

#ifndef UNTITLED6_COORD_H
#define UNTITLED6_COORD_H


class Coord
{
private:
    int xPos;
    int yPos;

public:

    Coord(int xPos=0, int yPos=0);
    virtual~Coord();


    int getXPos() const;
    int getYPos() const;

    void changeXPos(const int change);
    void changeYPos(const int change);


};


#endif //UNTITLED6_COORD_H
