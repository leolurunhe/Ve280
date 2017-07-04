#include<iostream>
#include "world_type.h"
#include "simulation.h"

using namespace std;

int main(int argc,char* argv[]){
		world_t world;
		int i,j;
		j=1;
		bool verbose=0;
		int flag[world.numCreatures]={0};
		if(initworld(world,"species","./world-tests/outside-world")){
				cout<<"Initial state"<<endl;
				printGrid(world.grid);		
				while(j<=40){
						cout<<"Round "<<j<<endl;
						if(verbose==true){
								for(i=0;i<world.numCreatures;i++){
										if(world.grid.terrain[world.creatures[i].location.r][world.creatures[i].location.c]!=HILL)
												simulateCreature(world.creatures[i],world,verbose);
										else if( world.grid.terrain[world.creatures[i].location.r][world.creatures[i].location.c]==HILL && world.creatures[i].ability[FLY])
												simulateCreature(world.creatures[i],world,verbose);
										else if(!world.creatures[i].ability[FLY] && world.grid.terrain[world.creatures[i].location.r][world.creatures[i].location.c]==HILL)
										{
												if(flag[i]!=0){
														simulateCreature(world.creatures[i],world,verbose);
														flag[i]=0;
												}
												else
														flag[i]++;
										}
								}		
						}
						else{	
								for(i=0;i<world.numCreatures;i++){
										if(world.grid.terrain[world.creatures[i].location.r][world.creatures[i].location.c]!=HILL)
												simulateCreature(world.creatures[i],world,verbose);
										else if( world.grid.terrain[world.creatures[i].location.r][world.creatures[i].location.c]==HILL && world.creatures[i].ability[FLY])
												simulateCreature(world.creatures[i],world,verbose);
										else if(!world.creatures[i].ability[FLY] && world.grid.terrain[world.creatures[i].location.r][world.creatures[i].location.c]==HILL)
										{
												if(flag[i]!=0){
												simulateCreature(world.creatures[i],world,verbose);
												flag[i]=0;
												}
										else
												flag[i]++;
										}
								}
								printGrid(world.grid);
						}
						j++;
				}
		}
}
