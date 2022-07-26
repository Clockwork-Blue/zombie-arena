#include "ZombieArena.h"

int createBackround(VertexArray& rVA, IntRect Arena) {
	// Anything we do to rVA we are really doing

	// to background (in the main function)

	// How big is each tile/texture

	const int TILE_SIZE = 50;
	const int TILE_TYPES = 3;
	const int VERTS_IN_QUAD = 4;
	int worldWidth = Arena.width / TILE_SIZE;
	int worldHeight = Arena.height / TILE_SIZE;
	// what type of primitives are we using
	rVA.setPrimitiveType(Quads);
	// set the size of the vertex array
	rVA.resize(worldWidth * worldHeight * VERTS_IN_QUAD);
	//start at the beginning of the vertex array
	int currentVertex = 0;
	for (int w = 0; w < worldWidth; w++)
	{
		for (int h = 0; h < worldHeight; h++)
		{
			//position each vertex in the current quad
			rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) +TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
			rVA[currentVertex + 3].position = Vector2f(w * TILE_SIZE, (h * TILE_SIZE)+TILE_SIZE);

			//define the position in the textue for the current quad
			// grass dirt stone wall other
			if (h == 0 || h == worldHeight - 1 || w == 0 || w == worldWidth - 1)
			{
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
			}
			else
			{
				// use random floor texture
				srand((int)time(0) + h * w - h);
				int mOrG = (rand() % TILE_TYPES);
				int verticalOffset = mOrG * TILE_SIZE;
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);
			}

			//position ready for the next 4 vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}
	return TILE_SIZE;
}