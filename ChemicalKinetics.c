#include <stdio.h>
#include <math.h>

//reaction function declaration
float reaction(float ammoniaCon, float oxygenCon, float nitrogenCon, float waterCon, float time);

int main(){
    //declaring variables for concentrations and time
    float ammoniaCon;
    float oxygenCon;
    float nitrogenCon = 0;
    float waterCon = 0;
    float time = 0;

    //printing and scanning for the initial concentrations of the reactants
    printf("Enter initial ammonia and oxygen concentrations: ");
    scanf("%f %f", &ammoniaCon, &oxygenCon);

    // print statement to print the final time at reaction rate of 0.001
    printf("The reaction will take %.2f seconds to reach a rate 0.001 M/s.", reaction(ammoniaCon, oxygenCon, nitrogenCon, waterCon, time));

}

//reaction function definition
float reaction(float ammoniaCon, float oxygenCon, float nitrogenCon, float waterCon, float time){
    float rate = (0.0965*ammoniaCon*(pow(oxygenCon, 2))); //initial flow rate calculation using concentrations given by user
    //calculating new concentration rates based on
    ammoniaCon += -rate*4*0.01;
    oxygenCon += -rate*3*0.01;
    nitrogenCon += rate*2*0.01;
    waterCon += rate*6*0.01;
    //if the reaction rate is less than 0.001, print the new updated concentrations
    if(rate < 0.001){
        printf("Final Reaction Molarities:\n");
        printf("NH3: %.2f M\n", ammoniaCon);
        printf("O2:  %.2f M\n", oxygenCon);
        printf("N2:  %.2f M\n", nitrogenCon);
        printf("H2O: %.2f M\n", waterCon);
        return time;
    }
    //tail recursion to recall the function within itself
    return reaction(ammoniaCon, oxygenCon, nitrogenCon, waterCon, time+= 0.01);
}