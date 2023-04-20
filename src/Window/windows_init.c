/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:59:12 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/19 21:16:07 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/graphic_engine.h"

bool init_win( void )
{
    t_data * data = getData();
    
    if (SDL_Init(SDL_INIT_EVERYTHING))
        ft_error("SDL_INIT FAILED ");


    SDL_DisplayMode display_mode = { 0 };
    if (SDL_GetCurrentDisplayMode(0, &display_mode))
        ft_error("SDL GET CURRENT DISPLAY MODE FAILED ");
    
    data->w_win = 1020;//display_mode.w;
    data->h_win = 720;//display_mode.h;

    data->n_pixel = data->w_win * data->h_win;
        
    data->win = SDL_CreateWindow("QuadTree", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, data->w_win, data->h_win, 0);
    if (!data->win)
        ft_error("SDL_CREATE WINDOW FAILED ");
    data->color_buffer = (u_int32_t *)calloc(sizeof(u_int32_t), data->n_pixel);
    if (!data->color_buffer)
    {
        perror("ERROR MALLOC ");
        return (FAIL);   
    }
    data->renderer = SDL_CreateRenderer(data->win, -1, 0);
    if (!data->renderer)
        ft_error("SDL_CREATE_RENDERER FAILED ");

    // if (SDL_SetWindowFullscreen(data->win, SDL_WINDOW_FULLSCREEN)) // set full screen
    //     ft_error("SDL SET WINDOW FULLSCREEN ");
    return (SUCCESS);
}

