#pragma once
#include<iostream>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include<list>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

#define WIDTH 50
#define HEIGHT 30
#define OBS_PERCENT 45
#define FEEDMAX 10
#define TIME_FEED 1000
#define SPACEBAR 32

#define WALL "¢Ë"
#define OBSTACLE "¢Ã"
#define FEED "¢½"
#define HEAD "¢Á"
#define TAIL "¡Û"

enum MENU
{
	MENU_START = 1,
	MENU_END
};

enum BLOCK
{
	BLOCK_WALL = 1,
	BLOCK_OBS,
	BLOCK_FEED,
	BLOCK_HEAD,
	BLOCK_TAIL
};

struct Position
{
	int m_ix;
	int m_iy;
};