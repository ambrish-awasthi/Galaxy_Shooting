//Utility Function to draw circles
#include "declaration.cpp"
void cirsetpix(int circenx, int circeny, int x, int y)
{
	glVertex2i(circenx+x,circeny+y);
	glVertex2i(circenx+x,circeny-y);
	glVertex2i(circenx-x,circeny+y);
	glVertex2i(circenx-x,circeny-y);
	glVertex2i(circenx+y,circeny+x);
	glVertex2i(circenx+y,circeny-x);
	glVertex2i(circenx-y,circeny+x);
	glVertex2i(circenx-y,circeny-x);
}
void dispcir(int circenx, int circeny, int cirrad)
{
	int x = 0, y = cirrad;
	int dec = 1-cirrad;
	glPointSize(4);
	glBegin(GL_POINTS);
	cirsetpix(circenx,circeny,x,y);
	while(y>x)
	{
		if(dec>=0)
		{
			dec+=2-(2*y);
			y--;
		}
		dec += 3 + (2*x);
		x++;
		cirsetpix(circenx,circeny,x,y);
	}
	glEnd();
}

void add_bullet()
{
    struct bullet tp;
    tp.x = ship_x + VARA + (VARB/2.0);
    tp.y = ship_y + (4.0*VARC)/3.0;
    bullets.push_back(tp);
}

void set_settings()
{
    int d_max,d_unit,d_refresh;

    d_max=10;
    d_unit=5;
    d_refresh=200;

        MAX_BOMB=d_max;
        UNIT_MOVE=d_unit;
        BACKGROUND_REFRESH_DELAY=d_refresh;
}
void get_high_score(){
  FILE *in;
  in = fopen("highscore","rb");
  if(in == NULL)
  {
      high_score =0;
  }
  else{
     fread(&high_score,1,sizeof(long long int),in);
     fclose(in);
  }

}
void set_high_score(){
   if(curr_score <= high_score) return;
    high_score = curr_score;
   FILE *out;
   out = fopen("highscore","wb");
   if(out == NULL)
   {
       return;
   }
   fwrite(&high_score, 1, sizeof(long long int), out);
   fclose(out);

}
void exit_game()
{
    set_high_score();
    bullets.clear();
    printf("Thank You For Playing Galaxy Shooting !!\n\n\n");
    printf("This Game was made by :\n1. Ambrish Awasthi (86/13)\n2. Amit Gautam (87/13)\n3. Deepak Kumar (93/13) \n4.Gaurav Sharma  (526/14)\nHarcourt Butler Technological Institute, Kanpur");
    printf("\n\nYour Score : %lld\nHigh Score : %lld\n\n",curr_score,high_score);
    exit(0);
}
