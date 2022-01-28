#ifndef MACROS_H
#define MACROS_H
#include <vector>

class Macros
{
public:
    double CaloriesTotal;
    double Protein;
    double Carbs;
    double Fats;    
    Macros(double P, double C, double F){
        Protein = P;
        Carbs = C;
        Fats = F;
    };

    auto CalorieIntake(double Weight, Macros& Produkt) -> void;

};


#endif // MACROS_H
