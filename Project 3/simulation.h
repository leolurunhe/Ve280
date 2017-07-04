#ifndef _SIMULATION_H_
#define _SIMULATION_H_

#include "world_type.h"

using namespace std;

bool initworld(world_t &world,const string &speciesfile,const string &worldfile);
//EFFECTS: First initialize an empty world, then read from speciesfile and worldfile, finally create a world.

void printGrid(const grid_t grid);
//MODIFIES: cout
//EFFECTS: Print a grid representation of the world.

point_t ajacentPoint(point_t pt,direction_t dir);
//EFFECTS: Return the point which is the result of moving one square from pt along direction dir.

direction_t leftFrom(direction_t dir);
//EFFECTS: Return the direction of turning left from the direction dir. 

direction_t rightFrom(direction_t dir);
//EFFECTS: Return the direction of turning right form the direction dir.

instruction_t getInstruction(const creature_t &creature);
//EFFECTS: return the instruction.

creature_t* getCreature(const grid_t &grid,point_t location);
//EFFECTS: return a pointer of creature at point location.

bool ifWall(world_t &world,creature_t* creature);

void if_wall(world_t &world,creature_t* creature,unsigned int address);

bool ifSame(world_t &world,creature_t* creature);

void if_same(world_t &world,creature_t* creature,unsigned int address);

bool ifEmpty(world_t &world,creature_t* creature);

void if_empty(world_t &world,creature_t* creature,unsigned int address);

void go(world_t &world,creature_t* creature,unsigned int address);

bool ifEnemy(world_t &world,creature_t* creature);
//EFFECTS: ifempty,ifwall,iffroest->false, else true

void if_enemy(world_t &world,creature_t* creature,unsigned int address);

void left(creature_t* creature);

void right(creature_t* creature);

void hop(world_t &world,creature_t* creature);

void infect(world_t &world,creature_t* creature);

void simulateCreature(creature_t &creature,world_t &world,bool verbose);
//REQUIRES: creature is inside the grid.
//MODIFIES: creature,cout,grid.
//EFEECTS: simulate one turn.


















#endif
