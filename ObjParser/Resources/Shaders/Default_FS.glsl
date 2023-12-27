#version 330 core

out vec4 FragColor;

in vec3 fragmentPos;
in vec2 texCoord;
in vec3 normal;

uniform vec3 lightColor;
uniform vec3 lightPosition;
uniform vec3 viewPos;

uniform vec3 ambientColor;
uniform vec3 diffuseColor;
uniform float specularExponent;
uniform vec3 specularColor;

uniform sampler2D tex;

void main()
{
	float ambientStrength = 0.1f;
	vec3 ambient = ambientStrength * ambientColor;

	// Diffuse
	 vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPosition - fragmentPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * diffuseColor;

	// Specular
	float specularStrength = 1.0f;
	vec3 viewDir = normalize(viewPos - fragmentPos);
	vec3 reflectDir = reflect(-lightDir, norm);  
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), specularExponent);
	vec3 specular = specularStrength * spec * specularColor; 

	vec3 phong = (ambient + diffuse + specular) * lightColor;
	FragColor =  texture(tex, texCoord) * vec4(phong, 1.0f);

};