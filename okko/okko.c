#include <stdlib.h>
#include <unistd.h>

typedef struct		s_complex
{
	double	r;
	double	i;
}					t_complex;
static double		escape(t_complex z, t_complex c, double max_iter)
{
	double	iter;
	double	r_sqr;
	double	i_sqr;
	iter = 0.0;
	r_sqr = 0.0;
	i_sqr = 0.0;
	while (r_sqr + i_sqr <= 4 && iter < max_iter)
	{
		z.i = 2 * (z.i * z.r) + c.i;
		z.r = r_sqr - i_sqr + c.r;
		r_sqr = z.r * z.r;
		i_sqr = z.i * z.i;
		iter++;
	}
	return (iter);
}
static void			print_mandelbrot(int width, int height)
{
	char	c;
	int		x;
	int		y;
	double	center_x;
	double	center_y;
	y = -1;
	center_x = -0.7;
	center_y = 0.0;
	while (++y < height)
	{
		x = -1;
		while (++x < width && (c = 32 + ((int)escape((t_complex){0.0, 0.0},
							(t_complex){(-2.0 + x * 4.0 / width) + center_x,
							(-2.0 + y * 4.0 / height) + center_y},
							100.0) % 94)))
			write(1, &c, 1);
		write(1, "\n", 1);
	}
}
int					main(int argc, char **argv)
{
	if (argc == 3)
		print_mandelbrot(atoi(argv[1]), atoi(argv[2]));
	else
		print_mandelbrot(80, 60);
}
