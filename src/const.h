#ifndef __CONST_H__
#define __CONST_H__

#define __WINDOW_W__ 640
#define __WINDOW_H__ 480
#define __TILE_SIZE__ 32
#define __VELOCITY__ 2
#define FPS 33

#define __LEVEL_EXT__ ".lvl"

typedef enum BALL_DIRECTION{

	DOWN,
	UP,
	RIGHT_UP,
	LEFT_UP,
	RIGHT_DOWN,
	LEFT_DOWN

}BALL_DIRECTION;

typedef enum BRICK{

	AIR,
	WEAK,
	NORMAL,
	HARD,
	VERY_HARD,
	ASIAN,

}BRICK;


#endif
