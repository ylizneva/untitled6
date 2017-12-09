//
// Created by Yulia Lizneva on 2017-12-08.
//

#ifndef UNTITLED6_BOX_H
#define UNTITLED6_BOX_H


class Box
{
private:
    int width;
    int height;

public:
    Box(int width=0, int height=0);
    virtual~Box();


    int getWidth() const;
    int getHeight() const;
};


#endif //UNTITLED6_BOX_H
