#include "../includes/game.h"
#include <time.h>
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
    // double time = 0; //time of current frame
    // double oldTime = 0; //time of previous frame


    for(int x = 0; x < game->maxMapWidth; x++)
    {
        //calculate ray position and direction
        // double cameraX = 2 * x / (double)(game->maxMapWidth) - 1; //x-coordinate in camera space
        double rayDirX = dirX + planeX * game->playerPos->x;
        double rayDirY = dirY + planeY * game->playerPos->x;
        //which box of the map we're in
        int mapX = (int)(posX);
        int mapY = (int)(posY);
        //length of ray from current position to next x or y-side
        double sideDistX;
        double sideDistY;
        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;
        //what direction to step in x or y-direction (either +1 or -1)
        int stepX;
        int stepY;
        int hit = 0; //was there a wall hit?
        //was a NS or a EW wall hit?
        //calculate step and initial sideDist
         if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
       //perform DDA
      while(hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          game->side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          game->side = 1;
        }
        //Check if ray has hit a wall
        if(game->map[mapX][mapY] > 0) hit = 1; 
    }
     if(game->side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
      int lineHeight = (int)(game->mapCharHeight / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + game->mapCharHeight / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + game->mapCharHeight / 2;
      if(drawEnd >= game->mapCharHeight) drawEnd = game->mapCharHeight - 1;

      //choose wall color
    //   ColorRGB color;
    //   switch(worldMap[mapX][mapY])
    //   {
    //     case 1:  color = RGB_Red;    break; //red
    //     case 2:  color = RGB_Green;  break; //green
    //     case 3:  color = RGB_Blue;   break; //blue
    //     case 4:  color = RGB_White;  break; //white
    //     default: color = RGB_Yellow; break; //yellow
    //   }

    //   //give x and y sides different brightness
    //   if(game->side == 1) {color = color / 2;}

    //   //draw the pixels of the stripe as a vertical line
      
    //   verLine(x, drawStart, drawEnd, color);
    for (int y1 = drawStart; y1 <= drawEnd; y1++) {
        mlx_pixel_put(game->mlx_ptr, game->win_ptr,x, y1, create_rgb(1,0,0)); // Set the pixel at (x, y) to the specified color
    renderGame(game);
    }
    // }
 //timing for input and FPS counter
    // oldTime = time;
    // time = clock();
    // double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    // dprintf(1,"%f",1.0 / frameTime); //FPS counter
    // redraw();
    // cls();

    //speed modifiers
    // double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    // double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
    // readKeys();
    //move forward if no wall in front of you
    // if(keyDown(SDLK_UP))
    // {
    //   if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
    //   if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
    // }
    // //move backwards if no wall behind you
    // if(keyDown(SDLK_DOWN))
    // {
    //   if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
    //   if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    // }
    // //rotate to the right
    // if(keyDown(SDLK_RIGHT))
    // {
    //   //both camera direction and camera plane must be rotated
    //   double oldDirX = dirX;
    //   dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
    //   dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
    //   double oldPlaneX = planeX;
    //   planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
    //   planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    // }
    // //rotate to the left
    // if(keyDown(SDLK_LEFT))
    // {
    //   //both camera direction and camera plane must be rotated
    //   double oldDirX = dirX;
    //   dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
    //   dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
    //   double oldPlaneX = planeX;
    //   planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
    //   planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    // }
  }
    /********lodev end*********/
}