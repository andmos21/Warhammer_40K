#ifndef DICE_H
#define DICE_H


class Dice
{
private:
    int maxValue;
public:
    Dice(int maxValue=6){
        this->maxValue=maxValue;
    }
    ~Dice();

    int roll();

    void dicetoss(int times);
};

#endif // DICE_H
