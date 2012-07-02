#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SOIL.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Camera.hpp"

static unsigned int Width = 800;
static unsigned int Height = 600;

Cam Camera;

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
	glfwSetWindowTitle("");
	glViewport(0,0,Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,0,0,0,0,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(1,0,0,1);
	//OpenGL Setup end
	std::cout << "\nGL init.";
	
	float vertices[] = {
		-0.5 , -0.5, 0,
		0 , 0.5, 0,
		0.5 , -0.5, 0
   };
	
	GLuint vbo;
	glGenBuffers (1 , &vbo);
	glBindBuffer (GL_ARRAY_BUFFER , vbo);
	glBufferData (GL_ARRAY_BUFFER , sizeof (vertices) , vertices , GL_STATIC_DRAW);
	
	glm::mat4 Model = glm::mat4 (1.0f);
	 

	
	Camera.CameraInit(45.0f , Width , Height , Model);
	
	float LastTime = glfwGetTime(); // (for deltatime)

	while (true)
	{
		float DeltaTime = glfwGetTime() - LastTime; // Deltatime init
		LastTime = glfwGetTime(); // update for deltatime

		Camera.UpdateCamera (DeltaTime , Model);

	
		glClearColor (0.0f , 0.0f , 0.0f , 1.0f);
		glClear (GL_COLOR_BUFFER_BIT);
		
		glEnableClientState (GL_VERTEX_ARRAY); 
		glBindBuffer (GL_ARRAY_BUFFER , vbo);
		glVertexPointer (3 , GL_FLOAT , 0 , NULL);
		
		/*glMatrixMode (GL_PROJECTION);
		glLoadMatrixf (&Projection[0][0]);
		*/
		glMatrixMode (GL_MODELVIEW);
		glLoadMatrixf (&Camera.GetMVP()[0][0]);
		
		glDrawArrays (GL_TRIANGLES , 0 , 3);
		
		glDisableClientState (GL_VERTEX_ARRAY);

			
		glfwSwapBuffers();

		if (glfwGetKey (GLFW_KEY_ESC))
			return 0;
	}
	

}
