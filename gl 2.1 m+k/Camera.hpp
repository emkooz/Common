#ifndef CAMERA_HANDLER
#define CAMERA_HANDLER

#include <iostream>
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Cam
{
				// SERIOUSLY ONLY TEMPORARY JUST NEED TO GET SOMETHING QUICK BEFORE I GO
private:	
glm::mat4 Projection, View, MVP;

int MouseX , MouseY, LastMX, LastMY;
float HorizontalAngle;
float VerticalAngle;
glm::vec3 Direction, Right, Up , Position;
float Speed;
float MouseSpeed;
float FoV;
int width;
int height;

public:
void CameraInit(float fov , int w , int h , glm::mat4 Model);
void UpdateCamera(float dt , glm::mat4 Model);

glm::mat4 GetMVP();

float GetSpeed();
void SetSpeed();

float GetMouseSpeed();
void SetMouseSpeed();

float GetFoV();
void SetFov();

};
#endif
