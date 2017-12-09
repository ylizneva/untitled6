//
// Created by Yulia Lizneva on 2017-11-16.
//

#ifndef UNTITLED6_GEOMETRISKAFIGURER_H
#define UNTITLED6_GEOMETRISKAFIGURER_H

#include <string>

using namespace std;

class GeometriskaFigurer
{
private:
    int xKoord;
    int yKoord;

public:
    GeometriskaFigurer();
    GeometriskaFigurer(int xKoord, int yKoord);
    virtual~GeometriskaFigurer();

    GeometriskaFigurer(const GeometriskaFigurer &originalObjekt);

    void operator=(const GeometriskaFigurer &original);
    int getX() const;
    int getY() const;
    string toString() const;

    virtual string toStringSpecefik() const =0;

};


#endif //UNTITLED6_GEOMETRISKAFIGURER_H










