#ifndef TEXTURE_EXAMPLE
#define TEXTURE_EXAMPLE

#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <SOIL.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Texture
{
	public:
	Texture();
	GLuint LoadShaders (const char * vert , const char * frag);
	void Draw();
	
	private:
	GLuint programID;
	GLuint img;
	
	std::vector <glm::vec2> Verts;
	std::vector <glm::vec2> UV;
	
	GLuint VertBuffer;
	GLuint UVBuffer;
	
	
};


#endif
