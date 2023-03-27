#pragma once
#include <iostream>
#include <iomanip>
using std::ostream;
using std::setw;

class Card
{
private:
    // Define your member data below this comment
    int color;  /*maybe string?*/
    int shading;
    int shape;
    int count;
public:
    // Define a set of constants for the class
    // Don't touch these definitions, the code needs them
    static const int RED = 1;
    static const int GREEN = 2;
    static const int PURPLE = 3;
    static const int FILLED = 1;
    static const int OPEN = 2;
    static const int STRIPED = 3;
    static const int OVAL = 1;
    static const int SQUIGGLE = 2;
    static const int DIAMOND = 3;
    // here are a couple of operator overloads to make you life easier

    bool operator==(const Card& right) { return isEqual(right); }
    friend ostream& operator<<(ostream& os, const Card& card);

    // your methods should be defined below this comment


    Card();
    Card(int count, int color, int shading, int shape);
    
    void setCount(int count);
    void setColor(int color);
    void setShading(int shading);
    void setShape(int shape);
    int getCount() const;
    int getColor() const;
    int getShading() const;
    int getShape() const;
    
    Card completeSet(const Card& second); //this is going to return the third card required to complete the set 
    
    bool isSet(const Card& second, const Card& third); // it will return true if the three cards form a set otherwise false. 
    
    bool isEqual(const Card& second);// return true only when two cards have same count, color, shading and shape
};