typedef struct	s_gen
{
	float4	clr;
	int	obj_num;
	int	light_num;
	int	recursion;
	int	antialliasing;
	int	effect;
}				t_gen;

typedef struct	s_cam
{
	float4	ori;
	float4	dir;
	float	fov;
	float	pitch;
	float	yaw;
}				t_cam;

typedef struct	s_obj
{
	float4	ori;
	float4	rot;
	float4	o_axis;
	float4	clr;
	float	radius;
	float	k;
	float	ambient;
	float	specular;
	float	phong;
	float	reflective;
	float	refractive;
	float	refractive_n;
	float	height_min;
	float	height_max;
	float	bump;
	int		type;
	int		mirror;
	int		damier;
}				t_obj;

typedef struct	s_scene
{
	float4	viewdirection;
	float4	u;
	float4	up;
	float4	v;
	float4	viewplaneupleftpoint;
	float	aspectratio;
	float	viewplanewidth;
	float	viewplaneheight;
	float	xincvect;
	float	yincvect;
}				t_scene;

typedef struct	s_light
{
	float4	ori;
	float4	clr;
	float	radius;
}				t_light;

typedef struct	s_vect
{
	float4	ori;
	float4	dir;
}				t_vect;

typedef struct	s_inter
{
	t_vect	point;
	float4	clr;
	float	ambient;
	float	specular;
	float	phong;
	float	t;
	float	reflective;
	float	refractive;
	float	n1;
	float	n2;
	float	bump;
	int	mirror;
}				t_inter;

typedef struct	s_var
{
	float	a;
	float	b;
	float	c;
	float	det;
	float	t;
	float	t_shade;
	float	t1;
	float	t2;
	float	th;
	float	m1;
	float	m2;
	float	tmp;
	float	refractive;
	int	plane_norm;
}				t_var;

static float	fade(float t)
{
	return (t * t * t * (t * (t * 6.0f - 15.0f) + 10.0f));
}

static float	lerp(float t, float a, float b)
{
	return (a + t * (b - a));
}

static float	grad(int hash, float x, float y, float z)
{
    int		h;
	float	u;
	float	v;

	h = hash & 15;
	u = h < 8 ? x : y;
	v = h < 4 ? y : h == 12|| h == 14 ? x : z;
    return (((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v));
}

static float	noise(float x, float y, float z)
{
	int permutation[] = {151,160,137,91,90,15,
		131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
		190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
		88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
		77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
		102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
		135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
		5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
		223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
		129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
		251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
		49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
		138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180,151,
		160,137,91,90,15,131,13,201,95,96,53,194,233, 7,225,140, 36,103,30,69,142,8,
		99,37,240,21,10,23,190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,
		35,11,32,57,177,33, 88,237,149, 56,87,174,20,125,136,171,168, 68,175,74,165,
		71,134,139,48,27,166, 77,146,158,231, 83,111,229,122,60,211,133,230,220,105,
		92,41,55,46,245,40,244,102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,
		208, 89,18,169,200,196,135,130,116,188,159,86,164,100,109,198,173,186, 3,64,
		52,217,226,250,124,123,5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,
		16,58,17,182,189, 28, 42,223,183,170,213,119,248,152, 2, 44,154,163, 70,221,
		153,101,155,167, 43,172,9, 129, 22,39,253, 19,98,108,110,79,113,224,232,178,
		185, 112,104,218,246,97,228,251, 34,242,193,238,210,144, 12,191,179,162,241,
		81,51,145,235,249,14,239,107,49,192,214, 31,181,199,106,157,184, 84,204,176,
		115,121,50,45,127, 4,150,254,138,236,205,93,222,114,67,29,24,72,243,141,128,
		195,78,66,215,61,156,180};
	int		X;
	int		Y;
	int		Z;
	float	u;
	float	v;
	float	w;
	int		A;
	int		AA;
	int		AB;
	int		B;
	int		BB;
	int		BA;

	X = (int)floor(x) & 255;
	Y = (int)floor(y) & 255;
	Z = (int)floor(z) & 255;
	x -= (float)floor(x);
	y -= (float)floor(y);
	z -= (float)floor(z);
	u = fade(x);
	v = fade(y);
	w = fade(w);
	A = permutation[X] + Y;
	AA = permutation[A] + Z;
	AB = permutation[A + 1] + Z;
	B = permutation[X + 1] + Y;
	BA = permutation[B] + Z;
	BB = permutation[B + 1] + Z;
	return (lerp(w, lerp(v, lerp(u, grad(permutation[AA], x, y, z),
						grad(permutation[BA], x-1, y, z)),
						lerp(u, grad(permutation[AB], x, y - 1, z),
						grad(permutation[BB], x - 1, y - 1, z))),
						lerp(v, lerp(u, grad(permutation[AA + 1], x, y, z - 1),
						grad(permutation[BA + 1], x - 1, y, z - 1)),
						lerp(u, grad(permutation[AB + 1], x, y - 1, z - 1),
						grad(permutation[BB + 1], x - 1, y - 1, z - 1)))));
}

static void	bump_mapping(t_inter *inter)
{
	float4	noise_tmp;

	noise_tmp.w = 0.0f;
	noise_tmp.x = inter->point.ori.x / inter->bump;
	noise_tmp.y = inter->point.ori.y / inter->bump;
	noise_tmp.z = inter->point.ori.z / inter->bump;
	noise_tmp.x = noise(noise_tmp.x, noise_tmp.y, noise_tmp.z);
	noise_tmp.y = noise(noise_tmp.y, noise_tmp.z, noise_tmp.x);
	noise_tmp.z = noise(noise_tmp.z, noise_tmp.x, noise_tmp.y);
	inter->point.dir = normalize(inter->point.dir + noise_tmp * 0.1f);
}

static float4	reflected_ray(float4 norm, float4 ray_dir)
{
	float4	ray;
	float	i;

	i = -dot(norm, ray_dir);
	ray = normalize(norm * 2.0f * i + ray_dir);
	return (ray);
}

static float4	refracted_ray(float n1, float n2, float4 norm, float4 ray_dir)
{
	float	ratio_n;
	float	cosi;
	float	k;
	float4	ray;

	ray = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	cosi = -dot(ray_dir, norm);
	ratio_n = n1 / n2;
	k = 1.0f - ratio_n * ratio_n * (1.0f - cosi * cosi);
	if (k < 0.0f)
		return (ray);
	ray = normalize(ratio_n * ray_dir + (ratio_n * cosi - sqrt(k)) * norm);
	return (ray);
}

static t_inter	init_inter(__constant t_gen *gen)
{
	t_inter	inter;

	inter.point.ori = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	inter.point.dir = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	inter.t = 0.0f;
	inter.clr = gen->clr;
	inter.ambient = 0.0f;
	inter.specular = 0.0f;
	inter.phong = 0.0f;
	inter.reflective = 0.0f;
	inter.refractive = 0.0f;
	inter.n1 = 1.0f;
	inter.n2 = 1.0f;
	inter.mirror = 0;
	return (inter);
}

static t_scene	init_scene(__constant t_cam *cam)
{
	t_scene	scene;
	float4	tmp1;
	float4	tmp2;

	scene.viewdirection = cam->dir;
	scene.up = (float4)(0.0f, 1.0f, 0.0f, 0.0f);
	scene.u = cross(scene.viewdirection, scene.up);
	scene.v = cross(scene.u, scene.viewdirection);
	scene.viewplanewidth = tan(cam->fov / 2.0f);
	scene.aspectratio = 576.0f / 1024.0f;
	scene.viewplaneheight = scene.aspectratio * scene.viewplanewidth;
	tmp1 = scene.v * scene.viewplaneheight / 2.0f;
	tmp2 = scene.u * scene.viewplanewidth / 2.0f;
	scene.viewplaneupleftpoint = cam->ori + scene.viewdirection + tmp1 - tmp2;
	scene.xincvect = scene.viewplanewidth / 1024.0f;
	scene.yincvect = scene.viewplaneheight / 576.0f;
	return (scene);
}

static t_vect	get_ray(__constant t_scene *scene, __constant t_cam *cam, float x, float y)
{
	t_vect	vect;
	float4	tmp1;
	float4	tmp2;
	float4	viewplanepoint;

	tmp1 = scene->u * x * scene->xincvect;
	tmp2 = scene->v * y * scene->yincvect;
	viewplanepoint = scene->viewplaneupleftpoint + tmp1 - tmp2;
	vect.ori = cam->ori;
	vect.dir = viewplanepoint - vect.ori;
	vect.dir = normalize(vect.dir);
	return (vect);
}

static void	damier(t_inter *inter, __constant t_obj *obj, int i)
{
	int	x1;
	int	y1;
	int	z1;

	x1 = (int)((inter->point.ori.x + 3893343.0f) / 6.0f) % 2;
	y1 = (int)((inter->point.ori.y + 3893343.0f) / 6.0f) % 2;
	z1 = (int)((inter->point.ori.z + 3893343.0f) / 6.0f) % 2;
	if (x1 ^ y1 ^ z1)
		inter->clr = obj[i].clr;
	else
		inter->clr = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	inter->clr.w = obj[i].clr.w;
}

static int	draw_sphere(t_vect ray, t_var *var,
			__constant t_obj *obj, int i, float tmp)
{
	float4	origin_to_obj;

	origin_to_obj = ray.ori - obj[i].ori;
	var->b = dot(ray.dir, origin_to_obj);
	var->c = dot(origin_to_obj, origin_to_obj) - (obj[i].radius * obj[i].radius);
	var->det = var->b * var->b - var->c;
	if (var->det >= 0.0f)
	{
		var->t1 = -var->b - sqrt(var->det);
		var->t2 = -var->b + sqrt(var->det);
		if (var->t2 > 0.0f && (var->t1 > var->t2 || var->t1 < 0.0f))
		{
			var->tmp = var->t1;
			var->t1 = var->t2;
			var->t2 = var->tmp;
		}
		if (var->t1 > 0.0f)
		{
			var->t = var->t1;
			if (var->refractive > obj[i].refractive && var->t <= tmp)
			{
				var->t_shade = var->t;
				var->refractive = obj[i].refractive;
			}
			return (1);
		}
	}
	return (0);
}

static void	inter_sphere(t_vect ray, t_var var, t_inter *inter,
			__constant t_obj *obj, int i)
{
	if (!inter->t || inter->t > var.t)
	{
		inter->t = var.t;
		if (!obj[i].damier)
			inter->clr = obj[i].clr;
		inter->ambient = obj[i].ambient;
		inter->specular = obj[i].specular;
		inter->phong = obj[i].phong;
		inter->reflective = obj[i].reflective;
		inter->refractive = obj[i].refractive;
		inter->mirror = obj[i].mirror;
		inter->bump = obj[i].bump;
		inter->point.ori = ray.ori + ray.dir * var.t;
		inter->point.dir = inter->point.ori - obj[i].ori;
		inter->point.dir = normalize(inter->point.dir);
		if (inter->bump)
			bump_mapping(inter);
		if (obj[i].damier)
			damier(inter, obj, i);
		if (var.t2 < 0.0f)
		{
			inter->point.dir = -inter->point.dir;
			inter->n1 = obj[i].refractive_n;
		}
		else
			inter->n2 = obj[i].refractive_n;
	}
}

static int	draw_plane(t_vect ray, t_var *var,
			__constant t_obj *obj, int i, float tmp)
{
	float4	origin_to_obj;
	float4	norm;
	float	t1;

	origin_to_obj = ray.ori - obj[i].ori;
	norm = obj[i].o_axis;
	var->plane_norm = 1;
	var->tmp = dot(ray.dir, norm);
	if (var->tmp > 0.0f)
	{
		var->plane_norm = 0;
		norm = -obj[i].o_axis;
		var->tmp = dot(ray.dir, norm);
	}
	if (var->tmp)
	{
		t1 = -dot(origin_to_obj, norm) / var->tmp;
		if (t1 > 0.0f)
		{
			var->t = t1;
			if (var->refractive > obj[i].refractive && var->t <= tmp)
			{
				var->t_shade = var->t;
				var->refractive = obj[i].refractive;
			}
			return (1);
		}
	}
	return (0);
}

static void	inter_plane(t_vect ray, t_var var, t_inter *inter,
			__constant t_obj *obj, int i)
{
	if (!inter->t || inter->t > var.t)
	{
		inter->t = var.t;
		if (!obj[i].damier)
			inter->clr = obj[i].clr;
		inter->ambient = obj[i].ambient;
		inter->specular = obj[i].specular;
		inter->phong = obj[i].phong;
		inter->reflective = obj[i].reflective;
		inter->refractive = obj[i].refractive;
		inter->mirror = obj[i].mirror;
		inter->bump = obj[i].bump;
		inter->n2 = obj[i].refractive_n;
		inter->point.ori = ray.ori + ray.dir * var.t;
		if (obj[i].damier)
			damier(inter, obj, i);
		if (var.plane_norm)
			inter->point.dir = obj[i].o_axis;
		else
			inter->point.dir = -obj[i].o_axis;
		if (inter->bump)
			bump_mapping(inter);
	}
}

static int	draw_cylinder_bis(t_vect ray, t_var *var,
			__constant t_obj *obj, int i, float4 origin_to_obj, float tmp)
{
	var->m1 = dot(ray.dir, obj[i].o_axis) * var->t1 +
		dot(origin_to_obj, obj[i].o_axis);
	var->m2 = dot(ray.dir, obj[i].o_axis) * var->t2 +
		dot(origin_to_obj, obj[i].o_axis);
	if (var->t1 > 0.0f && (!obj[i].height_max ||
		(var->m1 >= 0.0f && var->m1 <= obj[i].height_max)))
	{
		var->t = var->t1;
		if (var->refractive > obj[i].refractive && var->t <= tmp)
		{
			var->t_shade = var->t;
			var->refractive = obj[i].refractive;
		}
		return (1);
	}
	if (var->m2 >= 0.0f && var->m2 <= obj[i].height_max)
		if (var->m1 < 0.0f || var->m1 > obj[i].height_max)
			if (var->t2 > 0.0f)
			{
				var->t = var->t2;
				if (var->refractive > obj[i].refractive && var->t <= tmp)
				{
					var->t_shade = var->t;
					var->refractive = obj[i].refractive;
				}
				return (2);
			}
	return (0);
}

static int	draw_cylinder(t_vect ray, t_var *var,
			__constant t_obj *obj, int i, float tmp)
{
	float4	origin_to_obj;

	origin_to_obj = ray.ori - obj[i].ori;
	var->a = 1.0f - pown(dot(ray.dir, obj[i].o_axis), 2);
	var->b = dot(ray.dir, origin_to_obj) - dot(ray.dir, obj[i].o_axis) *
		dot(origin_to_obj, obj[i].o_axis);
	var->c = dot(origin_to_obj, origin_to_obj) -
		pown(dot(origin_to_obj, obj[i].o_axis), 2) - pown(obj[i].radius, 2);
	var->det = pown(var->b, 2) - var->a * var->c;
	if (var->det >= 0.0f)
	{
		var->t1 = (-var->b - sqrt(var->det)) / var->a;
		var->t2 = (-var->b + sqrt(var->det)) / var->a;
		if (var->t2 > 0.0f && (var->t1 > var->t2 || var->t1 < 0.0f))
		{
			var->tmp = var->t1;
			var->t1 = var->t2;
			var->t2 = var->tmp;
		}
		return (draw_cylinder_bis(ray, var, obj, i, origin_to_obj, tmp));
	}
	return (0);
}

static void	inter_cylinder(t_vect ray, t_var var, t_inter *inter,
			__constant t_obj *obj, int i, int j)
{
	if (!inter->t || inter->t > var.t)
	{
		inter->t = var.t;
		if (!obj[i].damier)
			inter->clr = obj[i].clr;
		inter->ambient = obj[i].ambient;
		inter->specular = obj[i].specular;
		inter->phong = obj[i].phong;
		inter->reflective = obj[i].reflective;
		inter->refractive = obj[i].refractive;
		inter->mirror = obj[i].mirror;
		inter->bump = obj[i].bump;
		inter->point.ori = ray.ori + ray.dir * var.t;
		if (obj[i].damier)
			damier(inter, obj, i);
		if (j)
		{
			inter->point.dir = inter->point.ori - obj[i].ori -
				obj[i].o_axis * var.m1;
			inter->point.dir = normalize(inter->point.dir);
			if (var.t2 < 0.0f)
			{
				inter->point.dir = - inter->point.dir;
				inter->n1 = obj[i].refractive_n;
			}
			else
				inter->n2 = obj[i].refractive_n;
		}
		else
		{
			inter->point.dir = inter->point.ori - obj[i].ori -
				obj[i].o_axis * var.m2;
			inter->point.dir = - normalize(inter->point.dir);
			inter->n1 = obj[i].refractive;
		}
		if (inter->bump)
			bump_mapping(inter);
	}
}

static int	draw_cone_bis(t_vect ray, t_var *var,
			__constant t_obj *obj, int i, float4 origin_to_obj, float tmp)
{
	var->m1 = dot(ray.dir, obj[i].o_axis) * var->t1 +
		dot(origin_to_obj, obj[i].o_axis);
	var->m2 = dot(ray.dir, obj[i].o_axis) * var->t2 +
		dot(origin_to_obj, obj[i].o_axis);
	if (var->t1 > 0.0f && ((!obj[i].height_max && !obj[i].height_min) ||
		(var->m1 >= obj[i].height_min && var->m1 <= obj[i].height_max)))
	{
		var->t = var->t1;
		if (var->refractive > obj[i].refractive && var->t <= tmp)
		{
			var->t_shade = var->t;
			var->refractive = obj[i].refractive;
		}
		return (1);
	}
	if (var->m2 >= obj[i].height_min && var->m2 <= obj[i].height_max)
		if (var->m1 < obj[i].height_min || var->m1 > obj[i].height_max)
			if (var->t2 > 0.0f)
			{
				var->t = var->t2;
				if (var->refractive > obj[i].refractive && var->t <= tmp)
				{
					var->t_shade = var->t;
					var->refractive = obj[i].refractive;
				}
				return (2);
			}
	return (0);
}

static int	draw_cone(t_vect ray, t_var *var,
			__constant t_obj *obj, int i, float tmp)
{
	float4	origin_to_obj;

	origin_to_obj = ray.ori - obj[i].ori;
	var->a = 1.0f - (1.0f + pown(obj[i].k, 2)) *
		pown(dot(ray.dir, obj[i].o_axis), 2);
	var->b = dot(ray.dir, origin_to_obj) - (1.0f + pown(obj[i].k, 2)) *
		(dot(ray.dir, obj[i].o_axis) * dot(origin_to_obj, obj[i].o_axis));
	var->c = dot(origin_to_obj, origin_to_obj) - (1 + pown(obj[i].k, 2)) *
		pown(dot(origin_to_obj, obj[i].o_axis), 2);
	var->det = pown(var->b, 2) - var->a * var->c;
	if (var->det >= 0.0f)
	{
		var->t1 = (-var->b - sqrt(var->det)) / var->a;
		var->t2 = (-var->b + sqrt(var->det)) / var->a;
		if (var->t2 > 0.0f && (var->t1 > var->t2 || var->t1 < 0.0f))
		{
			var->tmp = var->t1;
			var->t1 = var->t2;
			var->t2 = var->tmp;
		}
		return (draw_cone_bis(ray, var, obj, i, origin_to_obj, tmp));
	}
	return (0);
}

static void	inter_cone(t_vect ray, t_var var, t_inter *inter,
			__constant t_obj *obj, int i, int j)
{
	if (!inter->t || inter->t > var.t)
	{
		inter->t = var.t;
		if (!obj[i].damier)
			inter->clr = obj[i].clr;
		inter->ambient = obj[i].ambient;
		inter->specular = obj[i].specular;
		inter->phong = obj[i].phong;
		inter->reflective = obj[i].reflective;
		inter->refractive = obj[i].refractive;
		inter->mirror = obj[i].mirror;
		inter->bump = obj[i].bump;
		inter->point.ori = ray.ori + ray.dir * var.t;
		if (obj[i].damier)
			damier(inter, obj, i);
		if (j)
		{
			inter->point.dir = inter->point.ori - obj[i].ori -
				(obj[i].o_axis * (1 + pown(obj[i].k, 2)) * var.m1);
			inter->point.dir = normalize(inter->point.dir);
			if (var.t2 < 0.0f)
				inter->n1 = obj[i].refractive_n;
			else
				inter->n2 = obj[i].refractive_n;
		}
		else
		{
			inter->point.dir = inter->point.ori - obj[i].ori -
				(obj[i].o_axis * (1 + pown(obj[i].k, 2)) * var.m2);
			inter->point.dir = - normalize(inter->point.dir);
			inter->n1 = obj[i].refractive;
		}
		if (inter->bump)
			bump_mapping(inter);
	}
}

static int	get_first_inter(__constant t_gen *gen, t_inter *inter,
			t_vect ray, __constant t_obj *obj, float *t)
{
	int	i;
	int	j;
	t_var	var;

	i = 0;
	var.t = 0.0f;
	*t = 0.0f;
	while (i < gen->obj_num)
	{
		if (obj[i].type == 1)
			if (draw_sphere(ray, &var, obj, i, 0.0f))
				inter_sphere(ray, var, inter, obj, i);
		if (obj[i].type == 2)
			if (draw_plane(ray, &var, obj, i, 0.0f))
				inter_plane(ray, var, inter, obj, i);
		if (obj[i].type == 3)
		{
			if ((j = draw_cylinder(ray, &var, obj, i, 0.0f)) == 1)
				inter_cylinder(ray, var, inter, obj, i, 1);
			if (j == 2)
				inter_cylinder(ray, var, inter, obj, i, 0);
		}
		if (obj[i].type == 4)
		{
			if ((j = draw_cone(ray, &var, obj, i, 0.0f)) == 1)
				inter_cone(ray, var, inter, obj, i, 1);
			if (j == 2)
				inter_cone(ray, var, inter, obj, i, 0);
		}
		i++;
	}
	if (inter->t)
	{
		*t = inter->t;
		return (1);
	}
	else
		return (0);
}

static float	inter_shade(t_vect shade, float tmp, __constant t_obj *obj, __constant t_gen *gen)
{
	t_var	var;
	float4	vect_dir_len;
	float	vect_len;
	int	i;

	i = 0;
	var.t = 0.0f;
	var.t_shade = 0.0f;
	var.refractive = 1.0f;
	while (i < gen->obj_num)
	{
		if (obj[i].type == 1)
			if (draw_sphere(shade, &var, obj, i, tmp))
				if (!var.refractive && length(shade.dir * var.t_shade) <= tmp)
					return (0.0f);
		if (obj[i].type == 2)
			if (draw_plane(shade, &var, obj, i, tmp))
				if (!var.refractive && length(shade.dir * var.t_shade) <= tmp)
					return (0.0f);
		if (obj[i].type == 3)
			if (draw_cylinder(shade, &var, obj, i, tmp))
				if (!var.refractive && length(shade.dir * var.t_shade) <= tmp)
					return (0.0f);
		if (obj[i].type == 4)
			if (draw_cone(shade, &var, obj, i, tmp))
				if (!var.refractive && length(shade.dir * var.t_shade) <= tmp)
					return (0.0f);
		i++;
	}
	if (var.refractive && length(shade.dir * var.t_shade) <= tmp)
		return (var.refractive);
	else
		return (1.0f);
}

static float4	specular(t_inter inter, t_vect ray, float4 point_to_light, __constant t_light *light, float shade, int i)
{
	float4	diffuse;
	float4	phong;
	float4	blinn_dir;
	float	j;
	float	tmp;

	j = 0.0f;
	diffuse = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	if (!inter.mirror)
		diffuse = inter.clr * light[i].clr / 255.0f * shade;
	phong = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	blinn_dir = point_to_light - ray.dir;
	if ((tmp = length(blinn_dir)) != 0.0f)
		if ((j = dot((1.0f / tmp) * blinn_dir, inter.point.dir)) > 0.0f)
			phong = light[i].clr * pow(j, inter.phong);
	return ((diffuse + phong) * inter.specular);
}

static float4	shade(t_inter inter, t_vect ray, __constant t_gen *gen,
							  __constant t_obj *obj, __constant t_light *light)
{
	float4	radiance;
	t_vect	shade_vect;
	float	shade;
	float	refractive;
	float	tmp;
	int	i;

	i = 0;
	radiance = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	if (!inter.mirror)
		radiance = inter.clr * inter.ambient;
	while (i < gen->light_num)
	{
		shade_vect.ori = inter.point.ori + inter.point.dir * 0.01f;
		shade_vect.dir = light[i].ori - shade_vect.ori;
		tmp = length(shade_vect.dir) + 0.01f;
		shade_vect.dir = normalize(shade_vect.dir);
		if ((refractive = inter_shade(shade_vect, tmp, obj, gen)) > 0.0f)
			if ((shade = dot(shade_vect.dir,
				inter.point.dir)) > 0.0f)
				radiance += specular(inter, ray,
					shade_vect.dir, light, shade, i) * refractive;
		i++;
	}
	radiance.w = inter.clr.w;
	return (radiance);
}

static float4	get_pixel_reflective(float *opacity, t_vect ray, float reflective, __constant t_gen *gen, __constant t_obj *obj, __constant t_light *light)
{
	float4	clr;
	int	i;
	t_inter	inter;
	float	t;

	i = 0;
	clr = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	while (i < gen->recursion && reflective)
	{
		inter = init_inter(gen);
		if (get_first_inter(gen, &inter, ray, obj, &t))
			inter.clr = shade(inter, ray, gen, obj, light);
		clr += inter.clr * reflective;
		if (inter.clr.w < *opacity)
			*opacity = inter.clr.w;
		ray.dir = reflected_ray(inter.point.dir, ray.dir);
		ray.ori = inter.point.ori + ray.dir * 0.01f;
		reflective = inter.reflective;
		i++;
	}
	return (clr);
}

static float4	get_pixel_refractive(float *opacity, t_vect ray, float refractive, float n1, __constant t_gen *gen, __constant t_obj *obj, __constant t_light *light)
{
	float4	clr;
	int	i;
	t_inter	inter;
	float	t;

	i = 0;
	clr = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	while (i < gen->recursion && refractive != 0.0f && (ray.dir.x != 0.0f ||
		ray.dir.y != 0.0f || ray.dir.z != 0.0f))
	{
		inter = init_inter(gen);
		if (get_first_inter(gen, &inter, ray, obj, &t))
			inter.clr = shade(inter, ray, gen, obj, light);
		if (inter.n1 == 1.0f)
			inter.n1 = n1;
		clr += inter.clr * refractive;
		if (inter.clr.w < *opacity)
			*opacity = inter.clr.w;
		ray.dir = refracted_ray(inter.n1, inter.n2, inter.point.dir, ray.dir);
		ray.ori = inter.point.ori + ray.dir * 0.01f;
		refractive = inter.refractive;
		n1 = inter.n2;
		i++;
	}	
	return (clr);
}

static int	light_sphere(t_vect ray, t_var *var,
			__constant t_light *light, int i)
{
	float4	origin_to_light;

	origin_to_light = ray.ori - light[i].ori;
	var->b = dot(ray.dir, origin_to_light);
	var->c = dot(origin_to_light, origin_to_light) -
		(light[i].radius * light[i].radius);
	var->det = var->b * var->b - var->c;
	if (var->det >= 0.0f)
	{
		var->t1 = -var->b - sqrt(var->det);
		var->t2 = -var->b + sqrt(var->det);
		if (var->t2 > 0.0f && (var->t1 > var->t2 || var->t1 < 0.0f))
		{
			var->tmp = var->t1;
			var->t1 = var->t2;
			var->t2 = var->tmp;
		}
		if (var->t1 > 0.0f)
		{
			var->t = var->t1;
			return (1);
		}
	}
	return (0);
}

static int	direct_lighting(float4 *clr, t_vect ray, __constant t_light *light,
	__constant t_gen *gen, float *opacity, float t)
{
	float4	origin_to_light;
	t_vect	shade_vect;
	float4	point_norm;
	int	i;
	float	j;
	t_var	var;
	int	tmp;
	float4	blinn_dir;
	float	tmp_blinn;

	i = 0;
	tmp = 0;
	while (i < gen->light_num)
	{
		if (light_sphere(ray, &var, light, i))
			if (!t || var.t < t)
			{
				shade_vect.ori = ray.ori + ray.dir * var.t;
				shade_vect.dir = normalize(ray.ori - light[i].ori);
				point_norm = normalize(shade_vect.ori - light[i].ori);
				blinn_dir = shade_vect.dir - ray.dir;
				if ((tmp_blinn = length(blinn_dir)) != 0.0f)
					if ((j = dot((1.0f / tmp_blinn) * blinn_dir, point_norm)) > 0.0f)
				{
					tmp = 1;
					if (*opacity < light[i].clr.w)
						*opacity = light[i].clr.w;
					*clr += light[i].clr * j;
				}
			}
		i++;
	}
	if (tmp)
		return (1);
	else
		return (0);
}

static uchar4	get_pixel(t_vect ray, __constant t_gen *gen,  __constant t_obj *obj,
	__constant t_light *light)
{
	uchar4	clr;
	float	opacity;
	t_inter	inter;
	t_vect	reflective;
	t_vect	refractive;
	float4	light_clr;
	float	t;

	inter = init_inter(gen);
	light_clr = (float4)(0.0f, 0.0f, 0.0f, 0.0f);
	if (get_first_inter(gen, &inter, ray, obj, &t))
	{
		inter.clr = shade(inter, ray, gen, obj, light);
		opacity = inter.clr.w;
		reflective.dir = reflected_ray(inter.point.dir, ray.dir);
		reflective.ori = inter.point.ori + reflective.dir * 0.01f;
		refractive.dir = refracted_ray(inter.n1, inter.n2, inter.point.dir, ray.dir);
		refractive.ori = inter.point.ori + refractive.dir * 0.01f;
		inter.clr += get_pixel_reflective(&opacity, reflective, inter.reflective, gen, obj, light);
		inter.clr += get_pixel_refractive(&opacity, refractive, inter.refractive, inter.n2, gen, obj, light);
		inter.clr.w = opacity;
	}
	if (direct_lighting(&light_clr, ray, light, gen, &opacity, t))
	{
		inter.clr += light_clr;
		inter.clr.w = opacity;
	}
	clr.x = (inter.clr.x > 255.0f ? 255 : (uchar)inter.clr.x);
	clr.y = (inter.clr.y > 255.0f ? 255 : (uchar)inter.clr.y);
	clr.z = (inter.clr.z > 255.0f ? 255 : (uchar)inter.clr.z);
	clr.w = (uchar)inter.clr.w;
	return (clr);
}

static uchar4	filter(short4 clr, uchar opacity, __constant t_gen *gen)
{
	uchar4	ret;
	float4	tmp;

	ret.x = (uchar)clr.x;
	ret.y = (uchar)clr.y;
	ret.z = (uchar)clr.z;
	if (gen->effect == 1)
	{
		ret.y = ret.x;
		ret.z = ret.x;
	}
	if (gen->effect == 2)
	{
		ret.x = ret.y;
		ret.z = ret.y;
	}
	if (gen->effect == 3)
	{
		ret.x = ret.z;
		ret.y = ret.z;
	}
	if (gen->effect == 4)
	{
		tmp.x = 0.393f * (float)ret.x + 0.769f * (float)ret.y +
			0.189f * (float)ret.z;
		tmp.y = 0.349f * (float)ret.x + 0.686f * (float)ret.y +
			0.168f * (float)ret.z;
		tmp.z = 0.272f * (float)ret.x + 0.534f * (float)ret.y +
			0.131f * (float)ret.z;
		ret.x = (tmp.x > 255.0f ? 255 : (uchar)tmp.x);
		ret.y = (tmp.y > 255.0f ? 255 : (uchar)tmp.y);
		ret.z = (tmp.z > 255.0f ? 255 : (uchar)tmp.z);
	}
	ret.w = opacity;
	return (ret);
}

__kernel void rt(__global uchar4 *pixel, __constant t_gen *gen,
	__constant t_cam *cam, __constant t_obj *obj, __constant t_light *light, __constant t_scene *scene)
{
	int	x_pos;
	int	y_pos;
	float	x;
	float	y;
	float	inc;
	t_vect	ray;
	short4	clr;
	uchar4	tmp;
	uchar	opacity;

	x_pos = get_global_id(0);
	y_pos = get_global_id(1);
	y = (float)y_pos;
	clr = (short4)(0, 0, 0, 0);
	opacity = 0.0f;
	inc = 1.0f / sqrt((float)gen->antialliasing);
	while (y < (float)y_pos + 1.0f)
	{
		x = (float)x_pos;
		while (x < (float)x_pos + 1.0f)
		{
			ray = get_ray(scene, cam, x, y);
			tmp = get_pixel(ray, gen, obj, light);
			if (!opacity || opacity > tmp.w)
				opacity = (uchar)tmp.w;
			clr.x += (short)tmp.x;
			clr.y += (short)tmp.y;
			clr.z += (short)tmp.z;
			x += inc;
		}
		y += inc;
	}
	clr /= (short)gen->antialliasing;
	pixel[y_pos * 1024 + x_pos] = filter(clr, opacity, gen);
}
