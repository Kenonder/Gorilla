//============================================================================
// Name        : gorillas.cpp
// Author      : sc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

#ifndef MARMOSET_TESTING

int main();

#endif

double horizontal_velocity(double velocity, double theta);
double vertical_velocity(double velocity, double theta);
double gravity();
double computed_range(double velocity, double theta, double height);



#ifndef MARMOSET_TESTING

int main(){
         //Part A
         double height = 10;
         double initial_velocity = 600;
         double angle[12]={10,20,25.5,30,40,50,55.5,60,70,75.5,80,90};
         for (int i = 0; i < 12; i++){
                   double range = computed_range(initial_velocity, angle[i] , height);
                   std::cout << "The range the banana reaches for the launch angle of "
                                << angle[i] << " degrees is " << range <<std::endl;
         }


         return 0;
}

#endif

double horizontal_velocity( double velocity, double theta){
        return velocity * std::cos(theta/180*3.14159265358979);
}

double vertical_velocity( double velocity, double theta){
        return velocity * std::sin(theta/180*3.14159265358979);
}

double gravity(){
        return 9.80665;
}

double computed_range(double velocity, double theta, double height){
        double v1 = horizontal_velocity(velocity, theta);
        double v2 = vertical_velocity(velocity, theta);
        double g = gravity();
        return  v1 * v2 / g + v1 * std::sqrt(v2 * v2 + 2 * g * height) / g;
}
