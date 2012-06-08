#include "BBox.h"
#include "Vertex.h"

BBox::BBox(float x, float y, float z, float w, float h, float l)
{
	//x, y, and z are center points
	x -= (w/2);
	y -= (h/2);
	z -= (l/2);

	//Add vertices
	if(l == 0.0) {
		vertices.push_back(new Vertex(    x, y + h, z, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_LEFT));
		vertices.push_back(new Vertex(x + w, y + h, z, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_RIGHT));
		vertices.push_back(new Vertex(x + w,     y, z, 1.0f, 1.0f, 1.0f, TEX_TOP_RIGHT));
		vertices.push_back(new Vertex(    x,     y, z, 1.0f, 1.0f, 1.0f, TEX_TOP_LEFT));
	}else{
		//Get absolute value of length
		if(l < 0.0) {
			l += 2*l;
		}

		//Top
		vertices.push_back(new Vertex(x + w, y + h,     z, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_LEFT));
		vertices.push_back(new Vertex(    x, y + h,     z, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_RIGHT));
		vertices.push_back(new Vertex(    x, y + h, z + l, 1.0f, 1.0f, 1.0f, TEX_TOP_RIGHT));
		vertices.push_back(new Vertex(x + w, y + h, z + l, 1.0f, 1.0f, 1.0f, TEX_TOP_LEFT));
		
		//Bottom
		vertices.push_back(new Vertex(x + w,     y, z + l, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_LEFT));
		vertices.push_back(new Vertex(    x,     y, z + l, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_RIGHT));
		vertices.push_back(new Vertex(    x,     y,     z, 1.0f, 1.0f, 1.0f, TEX_TOP_RIGHT));
		vertices.push_back(new Vertex(x + w,     y,     z, 1.0f, 1.0f, 1.0f, TEX_TOP_LEFT));

		//Back
		vertices.push_back(new Vertex(x + w, y + h, z + l, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_LEFT));
		vertices.push_back(new Vertex(    x, y + h, z + l, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_RIGHT));
		vertices.push_back(new Vertex(    x,     y, z + l, 1.0f, 1.0f, 1.0f, TEX_TOP_RIGHT));
		vertices.push_back(new Vertex(x + w,     y, z + l, 1.0f, 1.0f, 1.0f, TEX_TOP_LEFT));

		//Front
		vertices.push_back(new Vertex(x + w,     y,     z, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_LEFT));
		vertices.push_back(new Vertex(    x,     y,     z, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_RIGHT));
		vertices.push_back(new Vertex(    x, y + h,     z, 1.0f, 1.0f, 1.0f, TEX_TOP_RIGHT));
		vertices.push_back(new Vertex(x + w, y + h,     z, 1.0f, 1.0f, 1.0f, TEX_TOP_LEFT));

		//Left
		vertices.push_back(new Vertex(    x, y + h, z + l, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_LEFT));
		vertices.push_back(new Vertex(    x, y + h,     z, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_RIGHT));
		vertices.push_back(new Vertex(    x,     y,     z, 1.0f, 1.0f, 1.0f, TEX_TOP_RIGHT));
		vertices.push_back(new Vertex(    x,     y, z + l, 1.0f, 1.0f, 1.0f, TEX_TOP_LEFT));

		//Right
		vertices.push_back(new Vertex(x + w, y + h,     z, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_LEFT));
		vertices.push_back(new Vertex(x + w, y + h, z + l, 1.0f, 1.0f, 1.0f, TEX_BOTTOM_RIGHT));
		vertices.push_back(new Vertex(x + w,     y, z + l, 1.0f, 1.0f, 1.0f, TEX_TOP_RIGHT));
		vertices.push_back(new Vertex(x + w,     y,     z, 1.0f, 1.0f, 1.0f, TEX_TOP_LEFT));
	}


	//vertices.push_back(new Vertex(nx, ny, nz, nr, ng, nb, ntex));
}

BBox::~BBox(void)
{
	for(verticesIter = vertices.begin(); verticesIter != vertices.end(); verticesIter++) {
        delete (*verticesIter);
        (*verticesIter) = NULL;
    }
    vertices.clear();
}
