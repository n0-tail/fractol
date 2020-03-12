/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:42:30 by anikkane          #+#    #+#             */
/*   Updated: 2020/03/09 11:42:32 by anikkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

t_code   *fractal_name(void)
{
    static t_code array[1] = {{"mandelbrot"}};
    return (array);

}

t_code   *fractal_check(char *str)
{
    t_code   *f_data;
    int i;

    i = 0;
    if (!(f_data = (t_code * )malloc(sizeof(t_code))))
    exit(1);
    f_data = fractal_name();
    while (f_data[i].name != NULL)
    {
        if (ft_strcmp(f_data[i].name, str) == 0)
        {
            printf("%s", f_data[i].name);
        return (&f_data[i]);
        }
            i++;
    }
    return (&f_data[i]);
}

t_fractal   *init(void  *mlx_ptr)
{
    t_fractal   *f_data;
    if (!(f_data = (t_fractal* )malloc(sizeof(t_fractal))))
    exit(1);
    f_data->win = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "mandelbrot");
    	f_data->mlx = mlx_ptr;
	if (!(f_data->image = mlx_new_image(f_data->mlx, WIDTH, HEIGHT)))
		exit(1);
	set_data(f_data);
	f_data->data_addr = mlx_get_data_addr(
		f_data->image,
		&(f_data->bits_per_pixel),
		&(f_data->size_line),
		&(f_data->endian));
    
    return (f_data);


}