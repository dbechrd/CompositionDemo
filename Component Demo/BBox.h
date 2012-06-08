#pragma once

#include <vector>
class Vertex;

class BBox{
	public:
		//Store Vertices
		std::vector<Vertex*> vertices;
        std::vector<Vertex*>::iterator verticesIter;

		BBox(float x, float y, float z, float w = 0.1f, float h = 0.1f, float l = 0.1f);
		~BBox();
};
