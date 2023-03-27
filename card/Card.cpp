#include "Card.h"

// this is the definition for overloading the << operation
// use it as follows
// Card m;
// cout << "This is your card: " << m << endl;
ostream& operator<<(ostream& os, const Card& card)
{
	os << card.count;
	if (card.color == Card::RED) { os << setw(7) << "red"; }
	else if (card.color == Card::GREEN) { os << setw(7) << "green"; }
	else if (card.color == Card::PURPLE) { os << setw(7) << "purple"; }

	if (card.shading == Card::OPEN) { os << setw(8) << "open"; }
	else if (card.shading == Card::FILLED) { os << setw(8) << "filled"; }
	else if (card.shading == Card::STRIPED) { os << setw(8) << "striped"; }

	if (card.shape == Card::OVAL) { os << setw(9) << "oval"; }
	else if (card.shape == Card::DIAMOND) { os << setw(9) << "diamond"; }
	else if (card.shape == Card::SQUIGGLE) { os << setw(9) << "squiggle"; }
	return os;
}

// place the your code below this line.
    Card::Card()
        {
            count = 1;
            color = RED;
            shading = FILLED;
            shape = OVAL;
        }
    
    Card::Card(int count, int color, int shading, int shape)
        {
            this->count = count;
            this->color = color;
            this->shading = shading;
            this->shape = shape;
        }
    
    void Card::setCount(int count)
        {
            this->count = count;
        }
    int Card::getCount() const
        {
            return this->count;
        }
    
    void Card::setColor(int color)
        {
            this->color = color;
        }
    int Card::getColor() const
        {
            return this->color;    
        }
    
    void Card::setShading(int shading)
        {
            this->shading = shading;
        }
    int Card::getShading() const
        {
            return this-> shading;
        }
    
    void Card::setShape(int shape)
        {
           this->shape = shape; 
        }
    int Card::getShape() const
        {
            return this->shape;
        }
    
    Card Card::completeSet(const Card &second) //returns the third card required to complete the set
        {
            
            int tempCount;
            if (count == second.count)
                {
                    tempCount = count;
                }
            else
                {
                    tempCount = 1 + 2 + 3 - count - second.getCount();
                }
            
            int tempColor;
            if (color == second.getColor())
                {
                    tempCount = color;
                }
            else
                {
                    tempColor = 1 + 2 + 3 - color - second.getColor();
                }
            
            int tempShading;
            if (shading == second.getShading())
                {
                    tempShading = shading;
                }
            else
                {
                    tempShading = 1 + 2 + 3 - shading - second.getShading();
                }
            
            int tempShape;
            if (shape == second.getShape())
                {
                    tempShape = shape;
                }
            else
                {
                    tempShape = 1 + 2 + 3 - shape - second.getShape();
                }

        return Card(tempCount, tempColor, tempShading, tempShape);
        }

    bool Card::isSet(const Card &second, const Card &third) //returns true if the third card matches the card in order to complete the set
        {
            bool countSet = false;

            if (count == second.getCount() && count == third.getCount() && third.getCount() == second.getCount())
                {
                    countSet = true;
                }

            if (count != second.getCount() && count != third.getCount() && third.getCount() != second.getCount())
                {
                    countSet = true;
                }

            bool colorSet = false;

            if (color == second.getColor() && color == third.getColor() && third.getColor() == second.getCount()) 
                {
                    countSet = true;
                }

            if (color != second.getColor() && color != third.getColor() && third.getColor() != second.getColor())
                {
                    countSet = true;
                }

            bool shadingSet = false;
            
            if (shading == second.getShading() && shading == third.getShading() && third.getShading() == second.getShading())
                {
                    countSet = true;
                }

            if (shading != second.getShading() && color != third.getShading() && third.getShading() != second.getShading())
                {
                    countSet = true;
                }

            bool shapeSet = false;

            if (shape == second.getShape() && shape == third.getShape() && third.getShape() == second.getShape())
                {
                    countSet = true;
                }

            if (shape != second.getShape() && color != third.getShape() && third.getShape() != second.getShape())
                {
                    countSet = true;
                }

        return countSet && colorSet && shadingSet && shapeSet;
        }

    bool Card::isEqual(const Card &second) // return true if the two cards have the same count, color, shading, and shape.
        {
            return count == second.count && color == second.color && shading == second.shading && shape == second.shape;
        }

