#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec4 position;
layout(location = 1) in vec2 vertexUV;

// Output data ; will be interpolated for each fragment.
out vec2 UV;

void main(){

	// Output position of the vertex, in clip space : MVP * position
	gl_Position =  vec4 (position.xyz , 1);
	
	// UV of the vertex. No special space for this one.
	UV = vertexUV;
}
