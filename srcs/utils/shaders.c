#include "../../includes/main.h"


void		shaders(t_gltools *gl)
{
	gl->shader_vertex_text =
		"#version 400\n"
		"\n"
		"layout (location = 0) in vec4	inPosition;\n"
		"layout (location = 1) in vec4	inColor;\n"
		"layout (location = 2) in vec2	inTexture;\n"
		"\n"
		"uniform mat4	model;\n"
		"uniform mat4	view;\n"
		"uniform mat4	projection;\n"
		"\n"
 		"out vec3	vColor;\n"
		"out vec2	vTexture;\n"
		"\n"
		"void	main()\n"
		"{\n"
		"	vColor		= vec3(inColor.x, inColor.y, inColor.z);\n"
		"	vTexture	= inTexture;\n"
		"\n"
		"	vec4	tmp	= vec4(inPosition.x, inPosition.y, inPosition.z, 1);"
		"	gl_Position = tmp * model * view * projection;\n"
		"}\n";
	gl->shader_fragment_text =
		"#version 400\n"
		"\n"
		"struct	Light {\n"
		"	bool	is_active;\n"
		"	vec4	pos, dir, color;\n"
		"	vec4	ambient, diffuse, specular;\n"
		"};\n"
		"\n"
		"in vec3	vColor;\n"
		// "in vec3	gNormal;\n"
		// "in vec4	gPosition;\n"
		"in vec2	vTexture;\n"
		// "\n"
		"uniform Light		light;"
		// "uniform vec4		campos;\n"
		"uniform sampler2D	texture_color;\n"
		"uniform float		progress;"
		"\n"
		"out vec4	FragColor;\n"
		"\n"
		"void	main()\n"
		"{\n"
		"	if (light.is_active) {\n" // ==========================================
		// "		vec4	color = mix(vec4(gColor, 1), texture(texture_color, vTexture), progress);\n"
		// "		\n" // ambient
		// "		vec4	ambient		= color * light.ambient;\n"
		// "		\n" // diffuse
		// "		vec3	n			= normalize(Normal);\n"
		// "		vec3	light_dir	= vec3(normalize(light.pos - Position));\n"
		// "		float	diff		= max(dot(n, light_dir), 0);\n"
		// "		vec4	diffuse		= color * light.diffuse * diff;\n"
		// "		\n" // specular
		// "		vec3	view_dir	= vec3(normalize(campos - Position));\n"
		// "		vec3	reflect_dir	= reflect(-light_dir, n);\n"
		// "		float	spec		= pow(max(dot(view_dir, reflect_dir), 0), 32);\n"
		// "		vec4	specular	= color * light.specular * spec;\n"
		// "		\n"
		// "		FragColor = (ambient + diffuse + specular);\n"
		// "		FragColor = texture(texture_color, vTexture);\n"
		"		FragColor = vec4(0, 0, 0, 1);\n"
		"	} else {\n"
		"		FragColor = mix(vec4(vColor, 1), texture(texture_color, vTexture), progress);\n"
		"	}\n"
		"}\n";
}
