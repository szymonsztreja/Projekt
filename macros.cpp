#include "macros.h"

Macros macros_summary(10,3,3);

auto Macros::CalorieIntake(double Weight, Macros& Produkt) -> double
{
    double grams = 0.01;
    CaloriesTotal += (Produkt.Carbs+Produkt.Protein)*4 + Produkt.Fats*9;
    macros_summary.Carbs += grams*Produkt.Carbs;
    macros_summary.Protein += grams*Produkt.Protein;
    macros_summary.Fats += grams*Produkt.Fats;
    return grams*Weight*CaloriesTotal;
}
