#include "macros.h"

Macros macros_summary(0.1,0.1,0.1);

auto Macros::CalorieIntake(double Weight, Macros& Produkt) -> void
{
    double grams = 0.01;
    macros_summary.CaloriesTotal += grams*Weight*
                                    ((Produkt.Carbs+Produkt.Protein)*4 + Produkt.Fats*9);
    macros_summary.Carbs += Weight*grams*Produkt.Carbs;
    macros_summary.Protein += Weight*grams*Produkt.Protein;
    macros_summary.Fats += Weight*grams*Produkt.Fats;

}
