#include "main.h"


int			gl_textures(t_env *env)
{
	t_image	image;
	int		i = -1;

	while (++i < TEXTURES_MAX) {
		glGenTextures(1, &env->gl.textures[i]);
		glBindTexture(GL_TEXTURE_2D, env->gl.textures[i]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		image = env->images[i];
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.w, image.h, 0, GL_BGR, GL_UNSIGNED_BYTE, image.ptr);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	return (0);
}
