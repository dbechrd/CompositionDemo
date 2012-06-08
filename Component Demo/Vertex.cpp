#include "Vertex.h"

//Constructor Sets Coords and Color
Vertex::Vertex(float nx, float ny, float nz, float nr, float ng, float nb, texCoord ntex, float na) {
    x = nx;
    y = ny;
    z = nz;

	r = nr;
	g = ng;
	b = nb;
	a = na;

    tex = ntex;
}

Vertex::~Vertex(){

}

//Retrieve X
float Vertex::X(){
    return x;
}

//Assign X
void Vertex::X(float nx) {
    x = nx;
}

//Retrieve Y
float Vertex::Y(){
    return y;
}

//Assign Y
void Vertex::Y(float ny) {
    y = ny;
}

//Retrieve Z
float Vertex::Z(){
    return z;
}

//Assign Z
void Vertex::Z(float nz) {
    z = nz;
}

//Retrieve R
float Vertex::R(){
    return r;
}

//Assign R
void Vertex::R(float nr) {
    r = nr;
}

//Retrieve G
float Vertex::G(){
    return g;
}

//Assign G
void Vertex::G(float ng) {
    g = ng;
}

//Retrieve B
float Vertex::B(){
    return b;
}

//Assign B
void Vertex::B(float nb) {
    b = nb;
}

//Retrieve A
float Vertex::A(){
    return a;
}

//Assign A
void Vertex::A(float na) {
    a = na;
}

//Retrieve Texture Coord
texCoord Vertex::Tex(){
    return tex;
}

//Assign Texture Coord
void Vertex::Tex(texCoord ntex) {
    tex = ntex;
}
