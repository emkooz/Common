#include <iostream>  // Mainly for 
#include <fstream>   // loading
#include <string>    // the
#include <vector>    // shader

#include <GL/glew.h>
#include <glfw.h>

GLuint LoadShader (const char * vertex_file_path,const char * fragment_file_path)