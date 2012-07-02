#include "Camera.hpp"

void Cam::CameraInit (float fov , int w , int h , glm::mat4 Model)
{
	FoV = fov;
	width = w;
	height = h;
	Speed = 3.0f;
	MouseSpeed = 0.05;
	
	Position = glm::vec3 (0.0 , 0.0 , 3.0);

	Projection = glm::perspective(FoV, (float)width / (float)height, 0.1f, 100.0f);
    View       = glm::lookAt(
                                                                Position,
                                                                glm::vec3(0,0,0),
                                                                glm::vec3(0,1,0)
                                                   );
   // Model      = glm::mat4(1.0f);
	MVP        = Projection * View * Model;
}

void Cam::UpdateCamera (float dt , glm::mat4 Model)
{
	LastMX = MouseX; LastMY = MouseY;
	glfwGetMousePos (&MouseX, &MouseY);


	HorizontalAngle +=  0.005 * (LastMX - MouseX );
    VerticalAngle   +=  0.005 * (LastMY - MouseY );
		
		// Move forward
	if (glfwGetKey( 'W' ) == GLFW_PRESS)
		Position += Direction * dt * Speed;
	
	// Move backward
	if (glfwGetKey( 'S' ) == GLFW_PRESS)
		Position -= Direction * dt * Speed;
	
	// Strafe right
	if (glfwGetKey( 'D' ) == GLFW_PRESS)
		Position += Right * dt * Speed;
	
	// Strafe left
	if (glfwGetKey( 'A' ) == GLFW_PRESS)
		Position -= Right * dt * Speed;
	

		 // Direction : Spherical coordinates to Cartesian coordinates conversion
        Direction = glm::vec3(
                cos(VerticalAngle) * sin(HorizontalAngle), 
                sin(VerticalAngle),
                cos(VerticalAngle) * cos(HorizontalAngle)
        );
        
        // Right vector
        Right = glm::vec3(
                sin(HorizontalAngle - 3.14f/2.0f), 
                0,
                cos(HorizontalAngle - 3.14f/2.0f)
        );
        
        // Up vector
        Up = glm::cross( Right, Direction );

		View       = glm::lookAt(
                                                                Position,           // Camera is here
                                                                Position + Direction, // and looks here : at the same position, plus "direction"
                                                                Up                  // Head is up (set to 0,-1,0 to look upside-down)
                                                   );
        MVP        = Projection * View * Model;
}

glm::mat4 Cam::GetMVP()
{
	return MVP;
}
