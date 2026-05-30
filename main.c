#include <stdio.h>

int main (void)
{
    typedef struct 
    {
        char *name;
        int level;
        int attack;
        int def;
    } pokemon;

    typedef struct 
    {
        char * name;
        int power;
        int accuracy;
    } move;

    pokemon pikachu;
    pikachu.name = "Pikachu";
    pikachu.level = 100;
    pikachu.attack = 100;
    pikachu.def = 100;

    pokemon slowbro;
    slowbro.name = "Slowbro";
    slowbro.level = 100;
    slowbro.attack = 100;
    slowbro.def = 100;



}