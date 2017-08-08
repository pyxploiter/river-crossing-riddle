#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

SDL_Window* window=NULL;
SDL_Surface* surface = NULL;
SDL_Surface* background = NULL;
SDL_Surface* lionR = NULL;
SDL_Surface* goatR = NULL;
SDL_Surface* grass = NULL;
SDL_Surface* boatR = NULL;
SDL_Surface* lionL = NULL;
SDL_Surface* goatL = NULL;
SDL_Surface* boatL = NULL;
SDL_Surface* lion = NULL;
SDL_Surface* goat = NULL;
SDL_Surface* boat = NULL;
SDL_Surface* win = NULL;
SDL_Surface* over = NULL;
SDL_Rect lionRect = { 200, 440, 67, 66 };
SDL_Rect goatRect = { 120, 445, 55, 57 };
SDL_Rect grassRect = { 50, 460, 50, 50 };
SDL_Rect boatRect = { 330, 440, 144, 133 };
int boatSpeed = 6;

void init(){
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG;
	window = SDL_CreateWindow("Riddle Puzzle", 15, 30, 1195, 637, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
}

void loadgraphics(){
	background = IMG_Load("assets/background.png");
	lionR = IMG_Load("assets/lionR.png");
	goatR = IMG_Load("assets/goatR.png");
	grass = IMG_Load("assets/grass.png");
	boatR = IMG_Load("assets/boatR.png");
	lionL = IMG_Load("assets/lionL.png");
	goatL = IMG_Load("assets/goatL.png");
	boatL = IMG_Load("assets/boatL.png");
	win = IMG_Load("assets/win.png");
	over = IMG_Load("assets/over.png");
	boat = boatR;
	lion = lionR;
	goat = goatR;
}
void close();
bool result(){
	if (boatRect.x > 500 && boatRect.x < 510){
		if (((lionRect.x == 200) && (goatRect.x == 120) && (grassRect.x != 50)) || ((lionRect.x == 1100) && (goatRect.x == 1050) && (grassRect.x != 1000))){
			SDL_BlitSurface(over, NULL, surface, NULL);
			return true;
		}
		else if (((lionRect.x != 200) && (goatRect.x == 120) && (grassRect.x == 50)) || ((lionRect.x != 1100) && (goatRect.x == 1050) && (grassRect.x == 1000))){
			SDL_BlitSurface(over, NULL, surface, NULL);
			return true;
		}
	}
	if ((lionRect.x == 1100) && (goatRect.x == 1050) && (grassRect.x == 1000)){
		SDL_BlitSurface(win, NULL, surface, NULL);
		return true;
	}
	return false;
}

void close(){
	SDL_DestroyWindow(window);
	window = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int a, char* b[]){
	bool quit = false;
	SDL_Event eve;
	bool flag = false;
	init();
	loadgraphics();

	while (!quit){
		while (SDL_PollEvent(&eve)){
			if (eve.type == SDL_QUIT)
				quit = true;
			if (eve.type == SDL_MOUSEBUTTONUP){
				int x, y;
				SDL_GetMouseState(&x, &y);
				if (flag != true){
					if (boatRect.x < 337){
						if ((x > lionRect.x) && (x < (lionRect.x + lionRect.w)) && (y > lionRect.y) && (y < (lionRect.y + lionRect.h))){
							lionRect.x = 390;
							lionRect.y += 38;
							flag = true;
						}
						if ((x > goatRect.x) && (x < (goatRect.x + goatRect.w)) && (y > goatRect.y) && (y < (goatRect.y + goatRect.h))){
							goatRect.x = 390;
							goatRect.y += 38;
							flag = true;
						}
						if ((x > grassRect.x) && (x < (grassRect.x + grassRect.w)) && (y > grassRect.y) && (y < (grassRect.y + grassRect.h))){
							grassRect.x = 390;
							grassRect.y += 38;
							flag = true;
						}
					}
					else if (boatRect.x > 790){
						if ((x > lionRect.x) && (x < (lionRect.x + lionRect.w)) && (y > lionRect.y) && (y < (lionRect.y + lionRect.h))){
							lionRect.x = 856;
							lionRect.y += 38;
							flag = true;
						}
						if ((x > goatRect.x) && (x < (goatRect.x + goatRect.w)) && (y > goatRect.y) && (y < (goatRect.y + goatRect.h))){
							goatRect.x = 862;
							goatRect.y += 38;
							flag = true;
						}
						if ((x > grassRect.x) && (x < (grassRect.x + grassRect.w)) && (y > grassRect.y) && (y < (grassRect.y + grassRect.h))){
							grassRect.x = 862;
							grassRect.y += 38;
							flag = true;
						}
					}
				}
				if (flag == true){
					if (boatRect.x < 337){
						if ((x > lionRect.x) && (x < (lionRect.x + lionRect.w)) && (y > lionRect.y) && (y < (lionRect.y + lionRect.h))&& (lionRect.x > 330)){
							lionRect.x = 200;
							lionRect.y -= 38;
							flag = false;
						}
						if ((x > goatRect.x) && (x < (goatRect.x + goatRect.w)) && (y > goatRect.y) && (y < (goatRect.y + goatRect.h)) && (goatRect.x > 330)){
							goatRect.x = 120;
							goatRect.y -= 38;
							flag = false;
						}
						if ((x > grassRect.x) && (x < (grassRect.x + grassRect.w)) && (y > grassRect.y) && (y < (grassRect.y + grassRect.h))&& (grassRect.x > 330)){
							grassRect.x = 50;
							grassRect.y -= 38;
							flag = false;
						}
					}
					else if (boatRect.x > 790){
						if ((x > lionRect.x) && (x < (lionRect.x + lionRect.w)) && (y > lionRect.y) && (y < (lionRect.y + lionRect.h)) && (lionRect.x < 880)){
							lionRect.x = 1100;
							lionRect.y -= 38;
							flag = false;
						}
						if ((x > goatRect.x) && (x < (goatRect.x + goatRect.w)) && (y > goatRect.y) && (y < (goatRect.y + goatRect.h)) && (goatRect.x < 880)){
							goatRect.x = 1050;
							goatRect.y -= 38;
							flag = false;
						}
						if ((x > grassRect.x) && (x < (grassRect.x + grassRect.w)) && (y > grassRect.y) && (y < (grassRect.y + grassRect.h)) && (grassRect.x < 880)){
							grassRect.x = 1000;
							grassRect.y -= 38;
							flag = false;
						}
					}

				}
			}
			if ((eve.key.keysym.sym == SDLK_LEFT) && boatRect.x >= 330){
				boat = boatL;
				if ((lionRect.x >= 390) && (lionRect.x != 1100)){
					lionRect.x -= boatSpeed;
					lion = lionL;
				}
				if ((goatRect.x >= 390) && (goatRect.x != 1050)){
					goatRect.x -= boatSpeed;
					goat = goatL;
				}
				if ((grassRect.x >= 390) && (grassRect.x != 1000))
					grassRect.x -= boatSpeed;	
				boatRect.x -= boatSpeed;
			}
			if (eve.key.keysym.sym == SDLK_RIGHT && boatRect.x <= 800){
				boat = boatR;
				//cout << "Boat: " << boatRect.x;
				//cout << " !! Lion: " << lionRect.x;
				//cout << " !! Goat: " << goatRect.x;
				//cout << " !! Grass: " << grassRect.x << endl;
				if ((lionRect.x >= 380) && (lionRect.x != 1100)){
					lionRect.x += boatSpeed;
					lion = lionR;
				}
				if ((goatRect.x >= 380) && (goatRect.x != 1050)){
					goatRect.x += boatSpeed;
					goat = goatR;
				}
				if ((grassRect.x >= 380) && (grassRect.x != 1000))
					grassRect.x += boatSpeed;
				boatRect.x += boatSpeed;
			}
		}
		bool status;
		SDL_BlitSurface(background, NULL, surface, NULL);
		SDL_BlitSurface(boat, NULL, surface, &boatRect);
		SDL_BlitSurface(lion, NULL, surface, &lionRect);
		SDL_BlitSurface(goat, NULL, surface, &goatRect);
		SDL_BlitSurface(grass, NULL, surface, &grassRect);
		status = result();
		SDL_UpdateWindowSurface(window);
		if (status == true){
			SDL_Delay(3000);
			break;
		}
	}
	close();
	return 0;
}