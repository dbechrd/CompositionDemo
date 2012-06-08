#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

enum texCoord{
    TEX_NONE = 0,
    TEX_BOTTOM_LEFT = 1,
    TEX_BOTTOM_RIGHT = 2,
    TEX_TOP_RIGHT = 3,
    TEX_TOP_LEFT = 4
};

class Vertex{

    private:

        //Coordinates
        float x;
        float y;
        float z;

        //Color
        float r;
        float g;
        float b;

        //Alpha
        float a;

        //Texture Coord
        texCoord tex;

    public:

        //Constructor
        Vertex(float nx = 0.0, float ny = 0.0, float nz = 0.0, float nr = 0.0, float ng = 0.0, float nb = 0.0, texCoord ntex = TEX_NONE, float na = 1.0);
        ~Vertex();

        //Overloaded Coordinate Assignment / Retrieval
        float X();
        void X(float nx);
        float Y();
        void Y(float ny);
        float Z();
        void Z(float nz);
        float R();
        void R(float nr);
        float G();
        void G(float ng);
        float B();
        void B(float nb);
        float A();
        void A(float na);
        texCoord Tex();
        void Tex(texCoord ntex);

};

#endif // POINT_H_INCLUDED
