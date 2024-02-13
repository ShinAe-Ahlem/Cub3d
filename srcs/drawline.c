#include "../includes/game.h"

void    drawRays3D(t_game *game)
{
    int r; //ray
    int mx; // (probably x coord in map)
    int my;//  (probably x coord in map)
    int mp;//  (probably map position where the ray touches the wall (or not-_-))
    int dof;//direction of focus
    float rx;
    float ry;
    float ra; // rayAngle
    float xo; // x offset (variation of x coord)
    float yo; // y offset (variation of y coord)
    float aTan; // negative inverse of tangent
    float nTan; // negative inverse of tangent

    // int i;
    // i = 0;
    ra = game->playerAngle;
    r = 0;
    while (r < 1)
    {
        // ------------------CHECK HORIZANTAL LINES-------------------------
        dof = 0; //direction of focus
        aTan = -1/tan(ra);
        /* 1: FIND THE FIRST x and y where the ray hits a horizantal line */
        if (ra > PI) // looking down 
        {
            ry = (((int)game->playerPos->y>>6)<<6)-0.0001; // to erase values after decimal point.
            rx = (game->playerPos->y - ry) * aTan + game->playerPos->x;
            yo = -5000;
            xo = -yo * aTan;
        }
        if (ra < PI) // looking up
        {
            ry = (((int)game->playerPos->y>>6)<<6)+64; // to erase values after decimal point.
            rx = (game->playerPos->y - ry) * aTan + game->playerPos->x;
            yo = 5000;
            xo = -yo * aTan;
        }
        if (ra == 0 || ra == PI) //looking straight right or left
        {
            rx = game->playerPos->x;
            ry = game->playerPos->y;
            dof = 8;
        }
        while (dof < 8) //max x/Y his ap is 8x8
        {
            mx = (int)(rx)>>6;
            my = (int)(ry)>>6;
            mp = my * game->maxMapWidth + mx;

            if (mp < game->maxMapWidth * game->mapCharHeight && game->map[my][mx] == '1')

            {
                dof = 1;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }

            drawLine(game, game->playerPos->x + TILE, game->playerPos->y + TILE, rx, ry, BLUE);
        }

        //------------------CHECK VERTICAL LINES-------------------------
        dof = 0; //direction of focus
        nTan = -tan(ra);
        /* 1: FIND THE FIRST x and y where the ray hits a horizantal line */
        if (ra > P2 && ra < P3) // looking left
        {
            rx = (((int)game->playerPos->x>>6)<<6)-0.0001; // to erase values after decimal point.
            ry = (game->playerPos->x - rx) * (nTan + game->playerPos->y);
            xo = -64;
            yo = -yo * nTan;
        }
        if (ra < P2 || ra > P3) // looking right
        {
            rx = (((int)game->playerPos->x>>6)<<6)+64; // to erase values after decimal point.
            ry = (game->playerPos->x - rx) * (nTan + game->playerPos->y);
            xo = 64;
            yo = -yo * nTan;
        }
        if (ra == 0 || ra == PI) //looking straight up or down
        {
            ry = game->playerPos->y;
            rx = game->playerPos->x;
            dof = 8;
        }
        while (dof < 8) //max x/Y his ap is 8x8
        {
            mx = (int)(rx)>>6;
            my = (int)(ry)>>6;
            mp = my * game->maxMapWidth + mx;
            if (mp < game->maxMapWidth * 8 && game->map[my][mx] == 1)
            {
                dof = 8;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
            drawLine(game, game->playerPos->x + TILE, game->playerPos->y + TILE, rx, ry, WHITE);

        }

        float nTan;
        dof = 0; //direction of focus
        nTan = -tan(ra);
        if (ra > P2 && ra <P3) // looking left
        {
            ry = (((int)game->playerPos->y>>6)<<6)-0.0001;
            rx = (game->playerPos->y - ry) * nTan + game->playerPos->x;
            yo = -5000;
            xo = -yo * nTan;
        }
        if (ra < P2 || ra > P3) // looking right
        {
            ry = (((int)game->playerPos->y>>6)<<6)+64; // to erase values after decimal point.
            rx = (game->playerPos->y - ry) * nTan + game->playerPos->x;
            yo = 5000;
            xo = -yo * nTan;
        }
        if (ra == 0 || ra == PI) //looking straight up or down
        {
            rx = game->playerPos->x;
            ry = game->playerPos->y;
            dof = 8;
        }
        while (dof < 1)
        {
            mx = (int)(rx)>>6;
            my = (int)(ry)>>6;
            mp = my * game->maxMapWidth + mx;
            if (mp < game->maxMapWidth * game->mapCharHeight && game->map[my][mx] == '1')
            {
                dof = 1;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
            drawLine(game, game->playerPos->x * TILE, game->playerPos->y * TILE, rx, ry, WHITE);
        }

        r++;
    }

}

//This functions draw a line using MLX functions
void    drawLine(t_game *game, int x0, int y0, int x1, int y1, int color)
{
    int dx;  //delta (until next point)
    int dy;
    int sx;  //step (direction of the x)
    int sy;
    int error;
    int error2;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    sx = (x0 < x1) ? 1 : -1;
    sy = (y0 < y1) ? 1 : -1;
    error = dx - dy;

    while (x0 != x1 || y0 != y1)
    {
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, x0, y0, color);
        error2 = 2 * error;
        if (error2 > -dy)
        {
            error -= dy;
            x0 += sx;
        }
        if (error2 < dx)
        {
            error += dx;
            y0 += sy;
        }
    }
}

void    drawRectangle(t_game *game, int x, int y, int width, int height, int color)
{
    drawLine (game, x, y, x + width, y, color);
    drawLine (game, x, y, x, y + height, color);
    drawLine (game, x + width, y, x + width, y+ height, color);
    drawLine (game, x, y + height, x + width, y + height, color);
}


void draw3d(t_game *game)
{
    /*******lodev start*****************/
    double posX = game->playerPos->x, posY = game->playerPos->y;  //x and y start position
    double dirX = -1, dirY = 0; //initial direction vector
    double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame


    for(int x = 0; x < game->maxMapWidth; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)(game->maxMapWidth) - 1; //x-coordinate in camera space
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;
    }
    /********lodev end*********/
}