#include <stdio.h>

typedef struct
    {
        char *name;
        char* type1;
        char* type2;
        int level;
        int atk;
        int def;
    } Pokemon;

typedef struct
    {
        char* name;
        char* type;
        int power;
        int accuracy;
    } Move;

int damageGen1 (Pokemon atk, Pokemon def, Move move);

int main (void)
{
    // [To-do] Get Pokemon Attacker, Defender names from user

    // [To-do] Serve list of the Attacker's Moves from API 

    // [To-do] Get Pokemon Stats from API
    Pokemon pikachu;
    pikachu.name = "Pikachu";
    pikachu.type1 = "Electric";
    pikachu.level = 100;
    pikachu.atk = 100;
    pikachu.def = 100;

    Pokemon slowbro;
    slowbro.name = "Slowbro";
    slowbro.type1 = "Water";
    slowbro.level = 100;
    slowbro.atk = 100;
    slowbro.def = 100;

    Move thunderShock;
    thunderShock.power = 40;

    int damage = damageGen1(pikachu, slowbro, thunderShock);
    printf("Damage caused: %i\n", damage);
    return 0;
}



int damageGen1 (Pokemon atk, Pokemon def, Move move)
{
    int crit = 1;
    int type1;
    int type2 = 1;
    float stab;
    float random;

    // Calculating STAB multiplier
    if (atk.type1 == move.type)
        stab = 1.5;

    // Calculating Type 1 Effectiveness 
    if (move.type == "Electric" && def.type1 == "Water")
         type1 = 2;

    // [To-do] Calculating Type 2 Effectiveness 

    // [To-do] Calculating Crit. Multiplier

    // Calculating damage
    float damage = ((((2 * atk.level * crit) / 5 + 2) * move.power * atk.atk / def.def) / 50 + 2) * stab * type1 * type2;

    // Adding randomness to damage
    if (damage == 1)
        random = 1;
        else
        {
            // [To-do] Generate a random number between 217 and 255 inclusive, divide it by 255.

        }

    return damage*random;

    // ((((2 * Level * Critical)/5 +2) * Power * A/D) / 50 + 2) * STAB * type1 * type2 * random

    // WHERE:

    // Level is the level of the attacking Pokémon.
    // Critical is 2 for a critical hit, and 1 otherwise.
    // A is the effective Attack stat of the attacking Pokémon if the used move is a physical move, or the effective Special stat of the attacking Pokémon if the used move is a special move (for a critical hit, all modifiers are ignored, and the unmodified Attack or Special is used instead). If either this or D are greater than 255, both are divided by 4 and rounded down.
    // D is the effective Defense stat of the target if the used move is a physical move, or the effective Special stat of the target if the used move is an other special move (for a critical hit, all modifiers are ignored, and the unmodified Defense or Special is used instead). If the move is physical and the target has Reflect up, or if the move is special and the target has Light Screen up, this value is doubled (unless it is a critical hit). If the move is Explosion or Selfdestruct, this value is halved (rounded down, with a minimum of 1). If either this or A are greater than 255, both are divided by 4 and rounded down. Unlike future Generations, if this is 0, the division is not made equal to 0; rather, the game will try to divide by 0 and softlock, hanging indefinitely until it is turned off.
    // Power is the power of the used move.
    // STAB is the same-type attack bonus. This is equal to 1.5 if the move's type matches any of the user's types, and 1 if otherwise. Internally, it is recognized as an addition of the damage calculated thus far divided by 2, rounded down, then added to the damage calculated thus far.
    // Type1 is the type effectiveness of the used move against the target's type that comes first in the type matchup table, or only type if it only has one type. This can be 0.5 (not very effective), 1 (normally effective), 2 (super effective).
    // Type2 is the type effectiveness of the used move against the target's type that comes second in the type matchup table. This can be 0.5 (not very effective), 1 (normally effective), 2 (super effective). If the target only has one type, Type2 is 1. If this would result in 0 damage, the calculation ends here and the move is stated to have missed, even if it would've hit.
    // random is realized as a multiplication by a random uniformly distributed integer between 217 and 255 (inclusive), followed by an integer division by 255. If the calculated damage thus far is 1, random is always 1.
}
