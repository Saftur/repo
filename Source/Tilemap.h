/*******************************************************************************************/
//Authors: Arthur Bouvier (abouvier)
//FileName: TileMap.h
//Date: 10/17/17
//Brief: File that contains the data for the tilemap
/*******************************************************************************************/

#pragma once

#include <AEEngine.h>
#include "Sprite.h"
#include "SpriteSource.h"
#include "Mesh.h"

class Tilemap {
public:
	Tilemap(const char* spritesheetFilename, const char* tilemapFilename, const char* collisionMapFilename, 
		int onScreenOffsetX, int onScreenOffsetY, int onScreenWidth, int onScreenHeight);
	~Tilemap();
	void Draw();
	bool isObjectCollidingWithMap(AEVec2 objectPosition, AEVec2 objectScale);
	void setOffset(int onScreenOffsetX, int onScreenOffsetY);

private:
	void readFiles(const char* tilemapFilename, const char* collisionMapFilename);

	int getTilenum(int x, int y);
	int getCollides(int x, int y);

	int offsetX, offsetY; // on-screen offset from top-left
	int width, height;    // on-screen width/height
	int tileWidth, tileHeight; // on-screen size of tiles
	int *tilemap;         // 2d array of tile nums
	int tilemapWidth, tilemapHeight; // width/height of tilemap
	bool *collisionMap;   // 2d array of colliding sprites

	Sprite* sprite;
	SpriteSource* spriteSource;
	AEGfxTexture* texture;
	AEGfxVertexList* meshQuad;
};