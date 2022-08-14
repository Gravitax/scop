#include "main.h"


void		mat4_projection(mat4 m, float fov, float near, float far, float ratio)
{
	float	e;

	mat4_identity(m);
	fov = (float)ft_to_radians(fov);
	e = 1 / (tanf(fov * 0.5f));

	// HEIGHT RATIO
	m[0] = ratio * e;
	m[5] = e;
	m[10] = far / (near - far);
	m[11] = (-far * near) / (near - far);
	m[14] = 1;

	// WIDTH RATIO
	// m[0] = e / ratio;
	// m[5] = e;
	// m[10] = (near + far) / (near - far);
	// m[11] = (2 * near * far) / (near - far);
	// m[14] = -1;
}

void		mat4_lookat(mat4 m, t_vec3d from, t_vec3d to, t_vec3d world_up)
{
	t_vec3d		forward, up, right;

	forward = vec_normalize(vec_sub(from, to));
    right = vec_cross(vec_normalize(world_up), forward);
    up = vec_cross(forward, right);

	m[0] = -right.x;
	m[1] = -right.y;
	m[2] = -right.z;
	m[3] = 0;
	m[4] = up.x;
	m[5] = up.y;
	m[6] = up.z;
	m[7] = 0;
	m[8] = forward.x;
	m[9] = forward.y;
	m[10] = forward.z;
	m[11] = 0;
	m[12] = -from.x;
	m[13] = -from.y;
	m[14] = -from.z;
	m[15] = 1;
}

void		mat4_view(t_camera *camera)
{
	t_vec3d	dir, up, target;

	dir = mat4_x_vec3d(camera->rot_xyz, camera->target);
	target = vec_add(camera->pos, dir);
	up = mat4_x_vec3d(camera->rot_xyz, camera->up);
	mat4_lookat(camera->view, camera->pos, target, up);
}
