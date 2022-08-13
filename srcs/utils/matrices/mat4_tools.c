#include "main.h"


void		mat4_identity(mat4 m)
{
	ft_memset(m, 0, sizeof(float) * 16);
	m[0] = 1.0f;
	m[5] = 1.0f;
	m[10] = 1.0f;
	m[15] = 1.0f;
}

void		mat4_print(mat4 m)
{
	unsigned int	i;

	for (i = 0; i < 16; i += 4)
		printf("[ %4f | %4f | %4f | %4f ]\n", m[0 + i], m[1 + i], m[2 + i], m[3 + i]);
}

void		mat4_translate(mat4 m, float x, float y, float z)
{
	m[3] += x;
	m[7] += y;
	m[11] += z;
}
