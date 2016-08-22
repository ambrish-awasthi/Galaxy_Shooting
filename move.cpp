//this file contains animation function
void main_ship_move()
{
    if(ship_left)
    {
        if(ship_x >= (int)UNIT_MOVE)
        {
            ship_x -= UNIT_MOVE;
        }
        else{
            ship_x =0;
        }
    }
    else if(ship_right )
    {

        if(ship_x <= width-ship_span -UNIT_MOVE)
        ship_x += UNIT_MOVE;
        else if(ship_x <= width-ship_span)
            ship_x = width - ship_span;
    }

}
void bomb_move()
{
    unsigned int i;
    float temp = height / ((float)FPS);
     for(i=0;i<MAX_BOMB;i++)
     {
            bomb_pos[i][1] -= temp / bomb_speed[i];
            if(bomb_pos[i][1]<PADDING_BELOW)
            {
                bomb_present[i]=false;
                BOMB_COUNT--;
            }
     }
}
void bullet_move()
{
    unsigned int i;
    float temp = height /((float)FPS);
    temp /= BULLET_SEC;
    for(i=0;i<bullets.size();i++)
    {
        bullets[i].y += temp;
        if(bullets[i].y>=height){
            bullets.erase(bullets.begin()+i);
            i--;
        }
    }
}
bool collision_bomb_bullet(struct bullet b,int j)
{
    //j represents index of bomb
    if(bomb_present[j]==false) return false;
    if(b.y<(bomb_pos[j][1]-VARD)) return false;
    if(b.y>(bomb_pos[j][1]+VARD)) return false;
    if(b.x<(bomb_pos[j][0]-VARD)) return false;
    if(b.x>(bomb_pos[j][0]+VARD)) return false;
    return true;
}
bool collision_bomb_ship(int j)
{
     //j represents index of bomb
     if(!bomb_present[j]) return false;
     if(bomb_pos[j][1]-VARD>ship_y+VARC) return false;
     if(bomb_pos[j][0]+VARD<ship_x) return false;
      if(isRotate)
        if(bomb_pos[j][0]-VARD>ship_x+ship_span*(cosf(ship_rotation))) return false;
     if(bomb_pos[j][0]-VARD>ship_x+ship_span) return false;

     int diffy = bomb_pos[j][1]-VARD-ship_y;
     int diffx = bomb_pos[j][0]-ship_x;


    if(diffx+VARD<VARA)
    {
        if(diffx+VARD==0)
        return false;
       // by checking slope lines
        if((VARC)/(2.0*VARA) < (diffy)/(diffx+VARD))
        return false;
        else
        return true;
    }
    else if(diffx+VARD < VARA+VARB)
    {
        if(diffy < VARC)
            return true;//if inside rectangle return ture
        //check for collision in top triangle


            if(diffx+VARD>VARA+VARB/2.0)
            return true;//right side of upper triangle
            else //CHECK WITH SLOPE
            {
                if(diffx+VARD==VARA)
                return false;

                if(((VARC*2)/(VARB*3))<((diffy-VARC/2.0)/(diffx+VARD-VARA)))
                return false;
                else
                return true;
            }
    }

        else //check slope of right wing and decide
        {
            if(VARA + VARA + VARB== diffx - VARD)
            return false;

            if((VARC/(2.0*VARA)) < (diffy / (VARA + VARA + VARB - (diffx - VARD))))
            return false;
            else
            return true;
        }
   // }
    return false;

}
void detect_collisions()
{
    //To detect collision between main_ship and bomb
    unsigned int i,j;
    for(i=0;i<bullets.size();i++) {
        for(j=0;j<MAX_BOMB;j++)
           {
              if(bomb_present[j] && collision_bomb_bullet(bullets[i],j))
              {
                  curr_score += BOMB_MAX_SEC - bomb_speed[j]+1;
                  bomb_present[j]=false;
                  BOMB_COUNT--;
                  bullets.erase(bullets.begin()+i);
                  i--;
                  break;
              }
           }
    }

    //to detect collision between main ship and bomb
    unsigned int z;
    for(z = 0; z < BOMB_COUNT; z++)
    {
        if(collision_bomb_ship(z))
        {
            game_state = 5;
        }
    }
}
void ship_rotate(){
  if(ship_rotation <= MAX_ANGLE - UNIT_ANGLE)
    ship_rotation += UNIT_ANGLE;

}
void timer_function(int v)
{
    if(game_state == 2)
    {
        main_ship_move();
        ship_rotate();
        bomb_move();
        bullet_move();
        detect_collisions();
    }
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,  timer_function,v);
}
