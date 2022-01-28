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

    auto CalorieIntake(double Weight, Macros& Produkt) -> double;

};

//auto CalorieIntake(double Weight, Macros& Produkt) -> double;

//class macros_summary : public Macros{
//public:
//        double calories_total;
//}


#endif // MACROS_H
