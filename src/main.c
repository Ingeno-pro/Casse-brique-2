#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "const.h"

void loadLevel(int map[(__WINDOW_W__/__TILE_SIZE__)/2][5], char levelname[8]);

int main(){

	/************************************Initialisation*********************************************************/
	printf("Casse Brique\n");
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *sw = SDL_CreateWindow("Casse brique", 0, 0, __WINDOW_W__, __WINDOW_H__, 0);
	SDL_Renderer *sr = SDL_CreateRenderer(sw, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Surface *ss = NULL;
	/**********************************Création des personnages**************************************************/
	printf("Chargement...\n");
	SDL_Rect ball = {64, 1, 32, 32};int ball_direction = DOWN;
	SDL_Rect player = {__WINDOW_W__/2 - 2*__TILE_SIZE__, __WINDOW_H__-__TILE_SIZE__*2, 4*__TILE_SIZE__, __TILE_SIZE__};
	/********************************Chargement du niveau******************************************************/
	int map[(__WINDOW_W__/__TILE_SIZE__)/2][5];
	loadLevel(map, "default");
	SDL_Event e;
	SDL_bool loop = true;
	
	//main loop
	while(loop){
	
		//SDL Event
		if(SDL_PollEvent(&e)){
			switch(e.type){
				case SDL_QUIT:
					loop = false;
				break; 
				case SDL_KEYDOWN:
					if(e.key.keysym.sym == SDLK_LEFT && player.x < __WINDOW_W__ - 4 * __TILE_SIZE__){
						player.x -= 3;
					}else if(e.key.keysym.sym == SDLK_RIGHT && player.x > 0){
						player.x += 1;
					}
				break;
			}
		}
		
		//player-ball collision event
		if(ball.y + ball.h >= player.y &&  ball.y + ball.h <= player.y + player.h && ball.x + __TILE_SIZE__ >= player.x && ball.x <= player.x + __TILE_SIZE__){ // Left
			ball_direction = LEFT_UP;
		}else if(ball.y + ball.h >= player.y &&  ball.y + ball.h <= player.y + player.h && ball.x >= player.x + __TILE_SIZE__ && ball.x <= player.x + 2*__TILE_SIZE__){ // Middle Left
			ball_direction = UP;
		}else if(ball.y + ball.h >= player.y &&  ball.y + ball.h <= player.y + player.h && ball.x <= player.x + player.w - __TILE_SIZE__ && ball.x >= player.x + player.w - 2*__TILE_SIZE__){ // Middle Right
			ball_direction = UP;
		}else if(ball.y + ball.h >= player.y &&  ball.y + ball.h <= player.y + player.h && ball.x <= player.x + player.w && ball.x >= player.x + player.w - __TILE_SIZE__){ // Right
			ball_direction = RIGHT_UP;
		}
		
		//wall-ball collision event
		if(ball.x <= 0 && ball_direction == LEFT_DOWN){
			ball_direction = RIGHT_DOWN;
		}else if(ball.x <= 0 && ball_direction == LEFT_UP){
			ball_direction = RIGHT_UP;
		}
		if(ball.x + __TILE_SIZE__ >= __WINDOW_H__ && ball_direction == RIGHT_DOWN){
			ball_direction = LEFT_DOWN;
		}else if(ball.x + __TILE_SIZE__ >= __WINDOW_H__ && ball_direction == RIGHT_UP){
			ball_direction = LEFT_UP;
		}
		//Brick-ball collision event
		
		
		//Game over event
		if(ball.y + __TILE_SIZE__ >= __WINDOW_H__){
			printf("Game Over \n");
			loop = false;
		}else if(ball.y <= 0){
			printf("Game Over \n");
			loop = false;
		}
		
		//Ball movement
		switch(ball_direction){
			case DOWN:
				ball.y+=__VELOCITY__;
			break;
			case UP:
				ball.y-=__VELOCITY__;
			break;
			case RIGHT_UP:
				ball.y-=__VELOCITY__/2;
				ball.x+=__VELOCITY__/2;
			break;
			case LEFT_UP:
				ball.y-=__VELOCITY__/2;
				ball.x-=__VELOCITY__/2;
			break;
		
		}
		
		//Clear Renderer
		SDL_SetRenderDrawColor(sr, 0, 0, 0, 0);
		SDL_RenderClear(sr);
		//Draw personnage
		SDL_SetRenderDrawColor(sr, 255, 255, 255, 0);
		SDL_RenderFillRect(sr, &ball);
		SDL_RenderFillRect(sr, &player);
		SDL_Delay(16); //FPS temporaire
		SDL_RenderPresent(sr);
	}
	SDL_DestroyRenderer(sr);
	SDL_DestroyWindow(sw);
	SDL_Quit();


	return 0;
}
void loadLevel(int map[(__WINDOW_W__/__TILE_SIZE__)/2][5], char levelname[8]){




}
