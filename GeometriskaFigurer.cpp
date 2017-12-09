//
// Created by Yulia Lizneva on 2017-11-16.
//

#include "GeometriskaFigurer.h"
#include <iostream>
#include <sstream>

using namespace std;

GeometriskaFigurer::GeometriskaFigurer()
{
    this->xKoord=0;
    this->yKoord=0;
}
GeometriskaFigurer::GeometriskaFigurer(int xKoord, int yKoord)
{
    this->xKoord=xKoord;
    this->yKoord=yKoord;
}
GeometriskaFigurer::~GeometriskaFigurer()
{

}

GeometriskaFigurer::GeometriskaFigurer(const GeometriskaFigurer &originalObjekt)
{
    this->yKoord=originalObjekt.yKoord;
    this->xKoord=originalObjekt.xKoord;
}

void GeometriskaFigurer::operator=(const GeometriskaFigurer &original)
{
    this->yKoord=original.yKoord;
    this->xKoord=original.xKoord;
}
int GeometriskaFigurer::getX() const
{
    return this->xKoord;
}
int GeometriskaFigurer::getY() const
{
    return this->yKoord;
}

string GeometriskaFigurer::toString() const
{
    stringstream out;
    out<<"X-koordinate is" <<this->xKoord<<"\n Y-koordinate is "<<this->yKoord<<toStringSpecefik();
    return out.str();
}