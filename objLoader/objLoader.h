#ifndef MODELLOADER
#define MODELLOADER

#include <iostream>
#include <vector>
#include <glm\glm.hpp>
#include <string>
//#include <fstream>

bool loadOBJ(const char* filepath , std::vector <glm::vec3> &OutVerts,
									std::vector <glm::vec2> &OutUV,
									std::vector <glm::vec3> &OutNormals);
#endif