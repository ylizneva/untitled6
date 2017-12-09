//
// Created by Yulia Lizneva on 2017-12-04.
//

#ifndef UNTITLED6_VECTOR_H
#define UNTITLED6_VECTOR_H

//klassmall kan inte delas upp

template <typename T>


class MyVector
{
private:
    int currentNrOfElements;
    int cap;
    T *myArray;

public:
    MyVector(int cap=10);
   // virtual~MyVector();

    MyVector(const MyVector & otherObjekt);
    //MyVector& operator =(const MyVector & otherObjekt);

    void addLast(T item);
    T getLast() const;

    void addFirst(T item); //placera in item på pos 0, flyta alla övriga ett åt högre index
    T getFirst() const;

    int size() const; //returnare antalet element som finns i Vector, currentNr

    void addAt(int index, T item); // lägg till po en speciell pos, den som fanns
    // tidigare flyttas ett steg framåt(åt höger index)
    T getAt(int index) const;


    T removeFirst(); // ta bort det som finns fösrt o returnera detta samt flytta alla
    // efterföljande ett steg åt lägre index
    T removeLast(); // ta bort det som finns sist o returnera minska current -1;
    T removeAt(int index); //motsvarande o flytta efterföljande ett steg åt lägre index
    void removeBetween(int start, int end); // ta bort alla element inom [start, slut]
    void clear(); // current=0, töm
    /*
       +operatorn
       []operatorn
   */




};


#endif //UNTITLED6_VECTOR_H

template <typename T>
MyVector<T>::MyVector(int cap)
{
    this->cap=cap;
    this->currentNrOfElements=0;
    this->myArray = new T[this->cap];
}

template <typename T>
void MyVector<T>::addLast(T item)
{
    this->myArray[this->currentNrOfElements++] = item;
}

template <typename T>
T MyVector<T>::getLast() const
{
    return this->myArray[this->currentNrOfElements-1]; // varför -1???
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T> & otherObjekt) // samma i tilldelningsoperator
{
    this->cap=otherObjekt.cap;
    this->currentNrOfElements=otherObjekt.currentNrOfElements;
    for(int i=0; i<this->currentNrOfElements; i++)
    {
        this->myArray[i]=new MyVector(*otherObjekt.myArray[i]);
    }
}
template <typename T>
void MyVector<T>::addFirst(T item)
{
    currentNrOfElements++;
    for(int i=currentNrOfElements; i>0; i--)
    {
        this->myArray[i]=this->myArray[i-1];
    }
    this->myArray[0]= item;
}

template <typename T>
T MyVector<T>::getFirst() const
{
    return this->myArray[0];
}
template <typename T>
T MyVector<T>::size() const
{
    return this->currentNrOfElements;
}
template <typename T>
void MyVector<T>::addAt(int index, T item)
{

    currentNrOfElements++;
    for (int i = currentNrOfElements; i>index; i--)
    {
        this->myArray[i]=myArray[i-1];
    }
    this->myArray[index] = item;
}
template <typename T>
T MyVector<T>::getAt(int index) const
{
    return this->myArray[index];
}

template <typename T>
T MyVector<T>::removeFirst()
{
    T bla = myArray[0];

    for(int i=0; i<this->currentNrOfElements-1; i++)
    {
        this->myArray[i]=myArray[i+1];
    }
    currentNrOfElements--;
    return bla;
}
template <typename T>
T MyVector<T>::removeLast()
{
    currentNrOfElements--;
   return this->myArray[currentNrOfElements];
}

template <typename T>
T MyVector<T>::removeAt(int index)
{
    this->myArray[index]=0;
    for(int i=index; i<currentNrOfElements; i++)
    {
        this->myArray[i]=myArray[i+1];
    }
}
template <typename T>
void MyVector<T>::removeBetween(int start, int end)
{

    for(int i=0; i<this->currentNrOfElements-1; i++)

    {
        myArray[i+start]=myArray[i+end+1];
        currentNrOfElements-=(end-start);

    }
}

template <typename T>
void MyVector<T>::clear()
{
    this->currentNrOfElements=0;
}