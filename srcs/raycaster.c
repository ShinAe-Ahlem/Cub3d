
#include "../includes/game.h"

static void RayPosAndDir(t_game *game, int x)
{
	game->cameraX = 2 * x / (double)game->window_x - 1;
	game->rayDirX = game->dirX + game->planeX * game->cameraX;
	game->rayDirY = game->dirY + game->planeY * game->cameraX;
	game->mapX = (int)game->posX;
	game->mapY = (int)game->posY;
	game->deltaDistX = fabs(1 / game->rayDirX);
	game->deltaDistY = fabs(1 / game->rayDirY);
}

static void StepAndInitialSideDist(t_game *game)
{
	if (game->rayDirX < 0)
	{
		game->stepX = -1;
		game->sideDistX = (game->posX - game->mapX) * game->deltaDistX;
	}
	else
	{
		game->stepX = 1;
		game->sideDistX = (game->mapX + 1.0 - game->posX) * game->deltaDistX;
	}
	if (game->rayDirY < 0)
	{
		game->stepY = -1;
		game->sideDistY = (game->posY - game->mapY) * game->deltaDistY;
	}
	else
	{
		game->stepY = 1;
		game->sideDistY = (game->mapY + 1.0 - game->posY) * game->deltaDistY;	
	}
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
			game->sideDistX += game->deltaDistX;
			game->mapX += game->stepX;
			if (game->stepX > 0)
				game->dir = 1;
			else
				game->dir = 3;
			game->side = 0;
		}
		else
		{
			game->sideDistY += game->deltaDistY;
			game->mapY += game->stepY;
			if (game->stepY > 0)
				game->dir = 2;
			else
				game->dir = 0;
			game->side = 1;
		}
		//Check if ray has hit a wall
		if (game->map[game->mapX][game->mapY] == '1')
			hit = 1;
	}
	//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if(game->side == 0)
		game->perpWallDist = (game->sideDistX - game->deltaDistX);
	else
	    game->perpWallDist = (game->sideDistY - game->deltaDistY);
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

int renderNextFrame(t_game *game)
{
	int x; //will be used to sample every column of the screan
	
	x = 0;
	initImage(game);
	/*Raycasting loop*/
	while(x < game->window_x)
	{
		/* the ray starts at the postion of the player //lodev*/
		//calculate ray position and direction
		RayPosAndDir(game, x);
		StepAndInitialSideDist(game);
		PerformDDA(game); //check if a wall is hit
		calculateWallHeight(game);
		texturingCalculation(game);
		render(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->mlx_img, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->img->mlx_img);
	return(1);//presonaly I prefer 0 but I guess this is a loop_hook thing
}