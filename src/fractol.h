#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "stdio.h"
# include <fcntl.h>
# include "math.h"
# include "../libft/libft.h"

# define WIDTH      1000
# define HEIGHT     1000

typedef struct		s_code
{
    char    *name;

}					t_code;

typedef struct		s_complex
{
	double		re;
	double		im;
}					t_complex;

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

typedef struct      s_fractal
{ 
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	int         	x;
    int         	y;
    void			*win;
	void			*mlx;
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				mouse;
	int				endian;
	int				fractol_nbr;
	int				max_iteration;
	int				color_shift;
}                   t_fractal;

t_code      *fractal_name(void);
t_code       *fractal_check(char *str);
int             end(char *reason);
t_fractal       *init(void *mlx_ptr);
t_color	get_color(int iteration, t_fractal *f_data);
void	draw_fractal_part(t_fractal *f_data);
void	put_pixel(t_fractal *f_data, int x, int y, t_color color);
void set_data(t_fractal *f_data);
t_complex	init_complex(double re, double im);
int		iterate_mandelbrot(t_fractal *f_data);



#endif