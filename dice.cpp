#include <iostream>
#include <ctime>
#include <cmath>

#include "dice.h"

Dice::~Dice(){}

int Dice::roll(){
    return rand()%maxValue;
}

void Dice::dicetoss(int times){
    int value=maxValue;

    //default d6 dice
    int dice[value]={0};

    for(int i =0; i<times;i++){
        int dr= roll();
        dice[dr]++;
    }

    if(value==6)
    {
        for(int k=1;k<=value;k++){
            int d=k-1;
            if(k==1){
                std::cout<<dice[d]<<" Miss\t"<<std::endl;
            }
            if(k==6){
                std::cout<<dice[d]<<" Hit\t"<<std::endl;
            }
            std::cout<<k<<": "<<dice[d]<<"\t"<<std::endl;
        }
    }
    if (value==3){
        for(int k=1;k<=value;k++){
            int a=k-1;
            if(k==1){
                std::cout<<dice[a]<<" casted spell 1\t"<<std::endl;
            }
            if(k==3){
                std::cout<<dice[a]<<" casted spell 2\t"<<std::endl;
            }
            if(k==3){
                std::cout<<dice[a]<<" casted spell 3\t"<<std::endl;
            }
            std::cout<<k<<": "<<dice[a]<<"\t";
        }
    }
    if (value==20){
        for(int k=1;k<=value;k++){
            int b=k-1;
            std::cout<<k<<": "<<dice[b]<<"\t";
        }
    }
    else{
        for(int k=1;k<=value;k++){
            int b=k-1;
            std::cout<<k<<": "<<dice[b]<<"\t";
        }
    }

    std::cout<<std::endl<<std::endl;
}
