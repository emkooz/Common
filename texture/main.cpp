#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <SOIL.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "texture.h"

static unsigned int Width = 800;
static unsigned int Height = 600;

int main()
{
	
	//OpenGL Setup
	if (!glfwInit())
	{
		std::cout << "GLFW failed to initialize!\n";
		return 1;
	}
	glfwOpenWindow(Width,Height,0,0,0,0,0,0,GLFW_WINDOW);
	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW failed to initialize!\n";
		return 1;
	}
	glfwSetWindowTitle("it's done.");
	glViewport(0,0,Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,0,0,0,0,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(1,0,0,1);
	//OpenGL Setup end
	
	Texture tex;
	
	/*// If you had a class, this would be in the contructor.
	GLuint programID = LoadShaders ("tex.vert" , "tex.frag"); std::cout << programID << std::flush;
	
	GLuint img = SOIL_load_OGL_texture("runner_01.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);

	std::vector <glm::vec2> Verts;
	Verts.push_back (glm::vec2 (-1.0f , -1.0f));
	Verts.push_back (glm::vec2 (-1.0f , 1.0f));
	Verts.push_back (glm::vec2 (1.0f , 1.0f));
	Verts.push_back (glm::vec2 (1.0f , -1.0f));

	std::vector <glm::vec2> UV;
	UV.push_back (glm::vec2 (0.0f , 1.0f));
	UV.push_back (glm::vec2 (0.0f , 0.0f));
	UV.push_back (glm::vec2 (1.0f , 0.0f));
	UV.push_back (glm::vec2 (1.0f , 1.0f));


	GLuint VertBuffer;
	glGenBuffers (1 , &VertBuffer);
	glBindBuffer (GL_ARRAY_BUFFER, VertBuffer);
	glBufferData (GL_ARRAY_BUFFER , Verts.size()*sizeof(glm::vec2) , &Verts[0] , GL_STATIC_DRAW);

	GLuint UVBuffer;
	glGenBuffers (1 , &UVBuffer);
	glBindBuffer (GL_ARRAY_BUFFER , UVBuffer);
	glBufferData (GL_ARRAY_BUFFER , UV.size()*sizeof(glm::vec2) , &UV[0] , GL_STATIC_DRAW);
	// Constructor end. */

	while (true)
	{
		
		glClear (GL_COLOR_BUFFER_BIT);

		tex.Draw();
	
		// This would be in the classes Draw() function.
		// Shader failure/success added.
		
		/*if (programID == NULL) // Was not able to compile, fallback.
		{
		glEnableClientState (GL_VERTEX_ARRAY);
		glBindBuffer (GL_ARRAY_BUFFER , VertBuffer);
		glVertexPointer (2 , GL_FLOAT , 0 , NULL);

		glEnableClientState (GL_TEXTURE_COORD_ARRAY);
		glBindBuffer (GL_ARRAY_BUFFER , UVBuffer);
		glTexCoordPointer (2 , GL_FLOAT , 0 , NULL);

		glEnable (GL_TEXTURE_2D);
		glBindTexture (GL_TEXTURE_2D , img);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glColor4f(1,1,1,1);
		glDrawArrays (GL_QUADS , 0 , Verts.size());

		glDisable (GL_TEXTURE_2D);
		glDisable(GL_BLEND);

		glDisableClientState (GL_VERTEX_ARRAY);
		glDisableClientState (GL_TEXTURE_COORD_ARRAY);
		}
		
		else // Is able to compile.
		{
			glUseProgram (ProgramID);
			
					   glActiveTexture (GL_TEXTURE0);
	   glBindTexture (GL_TEXTURE_2D , TextureID);
	   glUniform1i (TextureID , 0);

	   glEnableVertexAttribArray (0);
	   glBindBuffer (GL_ARRAY_BUFFER , VertBuffer);
	   glVertexAttribPointer ( 0 , 3 , GL_FLOAT , GL_FALSE , 0 , NULL);

	   glEnableVertexAttribArray (1);
	   glBindBuffer (GL_ARRAY_BUFFER , UVBuffer);
	   glVertexAttribPointer ( 1 , 2 , GL_FLOAT , GL_FALSE , 0 , NULL);


	   glEnable(GL_BLEND);
	   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	   glEnable(GL_TEXTURE_2D);
		 glDrawArrays (GL_QUADS , 0 , Verts.size());
	   glDisable(GL_TEXTURE_2D);
	   glDisable(GL_BLEND);

	   glDisableVertexAttribArray (0);
	   glDisableVertexAttribArray (1);
		}	
		// Draw function end.*/

		glfwSwapBuffers();

		if (glfwGetKey (GLFW_KEY_ESC))
		{
			return 0;
		}
	}
}
