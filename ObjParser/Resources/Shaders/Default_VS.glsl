#version 330 core

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec2 atexCoord;
layout(location = 2) in vec3 aNormal;

out vec3 fragmentPos;
out vec2 texCoord;
out vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	texCoord = atexCoord;
	//normal = aNormal;
	normal = mat3(transpose(inverse(model))) * aNormal;  
	fragmentPos = vec3(model * vec4(aPosition, 1.0f)); // fragment position in world space
	gl_Position = projection * view * vec4(fragmentPos, 1.0f);
};