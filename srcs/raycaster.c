
#include "../includes/game.h"

/*square cubes!

the ray distance is converted to vertical lines that will make the walls

1- use triangles on the horizental grid line =>save distance
2- use triangles on the vertical grid lines => save distance

3- compare both and the one that hits closer will be used as the vertical line's strip

*/

/**/
/*this function has to be called in create window*/
/*static void CastARay(t_game *game)
{
	
	
}
*/

void	drawPlayer(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (!game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		perror("window");
		exit(1);
	}
	ft_putstr_fd("in draw player\n", 1);
    drawRectangle(game, (TILE * game->playerPos->x), (TILE * game->playerPos->y), 20, 20, RED_PIXEL);
	// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->grp->ennemi_one,
	// 	(TILE * game->playerPos->x), (TILE * game->playerPos->y));
    printf("game->playerPos->x : %d\n", game->playerPos->x);
    printf("game->playerPos->y : %d\n", game->playerPos->y);
	drawLine(game, game->playerPos->x * TILE, game->playerPos->y  * TILE, (game->playerPos->x
		+ game->playerPosDelta->x) * TILE, (game->playerPos->y + game->playerPosDelta->y) * TILE, SHINAECOLOR);
    // drawRays3D(game);
	// draw3d(game);
	// my_mlx_pixel_put(&(game->img), (int)game->playerPos->x + TILE,
		// (int)game->playerPos->y + TILE, create_rgb(255, 255, 255);
}

/*
int	move(int keysym, t_game *game)
{
	if (keysym == XK_a)
	{
		game->playerAngle -= 0.1;
		if (game->playerAngle < 0)
		{
			game->playerAngle += 2 * PI;
		}
		game->playerPosDelta->x = cos(game->playerAngle) * 3;
		game->playerPosDelta->y = sin(game->playerAngle) * 3;
		// if (game->playerPos->x > 0)
		//     game->playerPos->x -= 1;
	}
	if (keysym == XK_d)
	{
		game->playerAngle += 0.1;
		if (game->playerAngle > 2 * PI)
		{
			game->playerAngle -= 2 * PI;
		}
		game->playerPosDelta->x = cos(game->playerAngle) * 3;
		game->playerPosDelta->y = sin(game->playerAngle) * 3;
		// if (game->playerPos->x < game->window_x)
		//     game->playerPos->x += 1;
	}
	if (keysym == XK_w)
	{
		game->playerPos->x += game->playerPosDelta->x;
		game->playerPos->y += game->playerPosDelta->y;
		// if (game->playerPos->y > 0)
		//     game->playerPos->y -= 1;
	}
	if (keysym == XK_s)
	{
		game->playerPos->x -= game->playerPosDelta->x;
		game->playerPos->y -= game->playerPosDelta->y;
		// if (game->playerPos->y < game->window_y)
		//     game->playerPos->y += 1;
	}
	return (0);
}
*/

int	move(int keysym, t_game *game)
{
	double	olddirX;
	double	moveSpeed;
	double oldplaneX;
	double	rotatSpeed;

	rotatSpeed = 0.042;
	moveSpeed = 0.083;
	oldplaneX = game->planeX;
	olddirX = game->dirX;
	if (keysym == XK_Right)
	{
		game->dirX = game->dirX * cos(-rotatSpeed) - game->dirY * sin(-rotatSpeed);
		game->dirY = olddirX * sin(-rotatSpeed) + game->dirY * cos(-rotatSpeed);
		game->planeX = game->planeX * cos(-rotatSpeed) - game->planeY * sin(-rotatSpeed);
		game->planeY = oldplaneX * sin(-rotatSpeed) + game->planeY * cos(-rotatSpeed);
	}
	if (keysym == XK_Left)
	{
		game->dirX = game->dirX * cos(rotatSpeed) - game->dirY * sin(rotatSpeed);
		game->dirY = olddirX * sin(rotatSpeed) + game->dirY * cos(rotatSpeed);
		game->planeX = game->planeX * cos(rotatSpeed) - game->planeY * sin(rotatSpeed);
		game->planeY = oldplaneX * sin(rotatSpeed) + game->planeY * cos(rotatSpeed);
	}

	if (keysym == XK_a)
	{
		if (game->map[(int)((game->posX - game->dirY * moveSpeed - 0.000001))][(int)(game->posY)] != '1')
			game->posX -= game->dirY * moveSpeed - 0.000001;
		if (game->map[(int)(game->posX)]
			[((int)(game->posY + game->dirX * moveSpeed - 0.000001))] != '1')
			game->posY += game->dirX * moveSpeed - 0.000001;
	}
	if (keysym == XK_d)
	{
		if (game->map[(int)((game->posX + game->dirY * moveSpeed - 0.000001))]
			[(int)(game->posY)] != '1')
			game->posX += game->dirY * moveSpeed - 0.000001;
		if (game->map[(int)(game->posX)]
			[((int)(game->posY - game->dirX * moveSpeed - 0.000001))] != '1')
			game->posY -= game->dirX * moveSpeed - 0.000001;
	}
	if (keysym == XK_w)
	{
		if (game->map[(int)(game->posX + game->dirX * moveSpeed - 0.000001)][(int)(game->posY - 0.000001)] != '1')
			game->posX += game->dirX * moveSpeed;
		if (game->map[(int)(game->posX - 0.000001)][((int)(game->posY + game->dirY * moveSpeed - 0.000001))] != '1')
			game->posY += game->dirY * moveSpeed;
	}
	if (keysym == XK_s)
	{
		if (game->map[(int)((game->posX - game->dirX * moveSpeed - 0.000001))]
			[(int)(game->posY - 0.000001)] != '1')
			game->posX -= game->dirX * moveSpeed;
		if (game->map[(int)(game->posX - 0.000001)]
			[((int)(game->posY - game->dirY * moveSpeed - 0.000001))] != '1')
			game->posY -= game->dirY * moveSpeed;
	}
	return (0);
}


/*this is the raycasting function*/
/*img will be initialized here all the time 
it is also destroyed after being put to window, I have no Idea why*/

static void initImage(t_game *game)
{
	game->img = malloc(1 * sizeof(t_img));
	if(!game->img)
	{
		//free this
		ft_error("malloc");
		exit(EXIT_FAILURE);
	}
	game->img->mlx_img = mlx_new_image(game->mlx_ptr, game->window_x, game->window_y);
	if(!game->img->mlx_img)
	{
		//freethis
		exit(EXIT_FAILURE);
	}
	game->img->addr = mlx_get_data_addr(game->img->mlx_img, &game->img->bpp, &game->img->line_len, &game->img->endian);

}

static void RayPosAndDir(t_game *game, int x)
{
	game->cameraX = 2 * x / (double)game->window_x - 1; //x-coordinate in camera space
	game->rayDirX = game->dirX + game->planeX * game->cameraX;
	game->rayDirY = game->dirY + game->planeY * game->cameraX;
	game->mapX = (int)game->posX;
	game->mapY = (int)game->posY;
	game->deltaDistX = fabs(1 / game->rayDirX);
	game->deltaDistY = fabs(1 / game->rayDirY);
	// ft_putstr_fd("in ray dir\n", 1);

}

static void StepAndInitialSideDist(t_game *game)
{
	if (game->rayDirX < 0)
	{
		// ft_putstr_fd("raydirx < 0 \n", 1);
		game->stepX = -1;
		game->sideDistX = (game->posX - game->mapX) * game->deltaDistX;
		
	}
	else
	{
		// ft_putstr_fd("raydirx >= 0 \n", 1);
		game->stepX = 1;
		game->sideDistX = (game->mapX + 1.0 - game->posX) * game->deltaDistX;
	}
	if (game->rayDirY < 0)
	{
		// ft_putstr_fd("raydiry < 0 \n", 1);
		game->stepY = -1;
		game->sideDistY = (game->posY - game->mapY) * game->deltaDistY;
	}
	else
	{
		// ft_putstr_fd("raydiry >= 0 \n", 1);
		game->stepY = 1;
		game->sideDistY = (game->mapY + 1.0 - game->posY)
			* game->deltaDistY;
		
	}
	// ft_putstr_fd("in step side \n", 1);

}

static void PerformDDA(t_game *game)
{
	int hit;
	
	hit = 0;
	while (hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (game->sideDistX < game->sideDistY)
		{
			// ft_putstr_fd("sideDistX < sideDistY \n", 1);
			game->sideDistX += game->deltaDistX;
			game->mapX += game->stepX;
			game->side = 0;
			// ft_putstr_fd("in performDDA \n", 1);
		}
		else
		{
			// ft_putstr_fd("sideDistX > sideDistY \n", 1);
			game->sideDistY += game->deltaDistY;
			game->mapY += game->stepY;
			game->side = 1;
		}
		//Check if ray has hit a wall
		if (game->map[game->mapX][game->mapY] == '1')
		{
			// ft_putstr_fd("A wall has been hit \n", 1);
			hit = 1;
		}
	}
	//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if(game->side == 0)
		game->perpWallDist = (game->sideDistX - game->deltaDistX);
	else
	    game->perpWallDist = (game->sideDistY - game->deltaDistY);
	// ft_putstr_fd("in DDA \n", 1);
	
}

static void calculateWallHeight(t_game *game)
{
	//Calculate height of line to draw on screen
	game->lineHeight = (int)(game->window_y/ game->perpWallDist);

	//calculate lowest and highest pixel to fill in current stripe
	game->drawStart = -game->lineHeight/2 + game->window_y/2 ;
	if(game->drawStart < 0)
		game->drawStart = 0;
	game->drawEnd = game->lineHeight / 2 + game->window_y/ 2;
	if(game->drawEnd >= game->window_y)
		game->drawEnd =game->window_y- 1;
	// ft_putstr_fd("in calculate\n", 1);

}

static void texturingCalculation(t_game *game)
{
	game->texNum = game->map[game->mapX][game->mapY] - 1;//1 subtracted from it so that texture 0 can be used!

	//calculate value of game->wallX
	//where exactly the wall was hit
	if (game->side == 0) 
		game->wallX = game->posY + game->perpWallDist * game->rayDirY;
	else
		game->wallX = game->posX + game->perpWallDist * game->rayDirX;
	game->wallX -= floor((game->wallX));

	//x coordinate on the texture
	game->texX = (int)(game->wallX * texWidth);

	if(game->side == 0 && game->rayDirX > 0) 
		game->texX = texWidth - game->texX - 1;
	if(game->side == 1 && game->rayDirY < 0) 
		game->texX = texWidth - game->texX - 1;


	// How much to increase the texture coordinate per screen pixel
	game->step = 1.0 * texHeight / game->lineHeight;
	// Starting texture coordinate
	game->texPos = (game->drawStart - game->window_y / 2 + game->lineHeight / 2) * game->step;
	// ft_putstr_fd("in calculation\n", 1);

}


void render(t_game *game, int x)
{
	int y;
	int color1;
	int color2;
	int	color3;

	color1 = create_rgb(game->floor.red, game->floor.green, game->floor.blue);
	color2 = create_rgb(game->ceiling.red, game->ceiling.green, game->ceiling.blue);
	y = 0;
	while (y < game->drawStart)
	{
		my_mlx_pixel_put(game->img, x, y, color2);
		y++;
	}
	// ft_putstr_fd("ceiling ok\n", 1);
	while(y < game->drawEnd)
	{
		// ft_putstr_fd("wall\n", 1);	
		/*here I need to draw textures*/
		// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->grp->north, x, y);
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		game->texY = (int)game->texPos * (texHeight - 1);
		// if (game->texY < 0)
		// 	game->texY = 0;
		// if (game->texY > texHeight)
		// 	game->texY = 0;
		// if (game->texX > texWidth)
		// 	game->texX = 0;
		// if (game->texX < 0)
		// 	game->texX = 0;
		game->texPos += game->step;
		color3 = game->texAddress[0][texHeight * game->texY + game->texX];
		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if(game->side == 1) 
			color3 = (color3 >> 1) & 8355711;
		// dprintf(1, "texX = %d\n", game->texX);
		// dprintf(1, "texY = %d\n", game->texY);

		my_mlx_pixel_put(game->img, x, y, color3);
		// my_mlx_pixel_put(&game->img, x, y, SHINAECOLOR);
		y++;

	}
	// ft_putstr_fd("walls ok\n", 1);
	y = game->drawEnd;
	while (y < game->window_y)
	{
		my_mlx_pixel_put(game->img, x, y, color1);
		y++;
	}
	// ft_putstr_fd("floor ok\n", 1);
	// ft_putstr_fd("********************************in render*******************************************\n", 1);
}

int renderNextFrame(t_game *game)
{
	int x; //will be used to sample every column of the screan
	
	x = 0;
	initImage(game);
	// initTextures(game);
	/*Raycasting loop*/
	while(x < game->window_x)
	{
	    // ft_putstr_fd("************in render next frame****************\n", 1);
		/* the ray starts at the postion of the player //lodev*/
		//calculate ray position and direction
		RayPosAndDir(game, x);
		StepAndInitialSideDist(game);
		PerformDDA(game); //check if a wall is hit
		calculateWallHeight(game);
		texturingCalculation(game);
		render(game, x);
	    // ft_putstr_fd("after pixel put\n", 1);
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->mlx_img, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->img->mlx_img);
	return(1);//presonaly I prefer 0 but I guess this is a loop_hook thing
}