#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
#include<string>
#include<iostream>
#include<vector>
struct bullet{
   int x,y;
};
#include "declaration.cpp"
#include "galaxy_utility.cpp"
#include "Drawing.cpp"
#include "move.cpp"
#include "callback.cpp"
bool isRotate = false;
float ship_rotation = 0;
// Bullet variable
std::vector<struct bullet> bullets;
//Mouse Hover Variables
bool quit_mouse_hover_yes, quit_mouse_hover_no;
bool pause_mouse_hover_resume, pause_mouse_hover_quit;
bool start_mouse_hover_start, start_mouse_hover_quit;
int left_bound_quit_yes, right_bound_quit_yes, left_bound_quit_no, right_bound_quit_no, up_bound_quit, down_bound_quit;
int left_bound_pause_quit, right_bound_pause_quit, left_bound_pause_resume, right_bound_pause_resume, up_bound_pause, down_bound_pause;
int left_bound_start, right_bound_start, up_bound_start_quit, down_bound_start_quit, up_bound_start_start, down_bound_start_start;

GLdouble width=800,height=600;
double seg_len;
int game_state;//Game State Values 1 = Start Menu 2 = In Action 3 = Pause MenuS 4 = Quit 5 = Exit- ThankYou Screen

//Star Variable
int star_pos[STAR_MAX][2],k,num_stars;
float star_size[STAR_MAX];
unsigned int BACKGROUND_REFRESH_DELAY;

// Bomb variable
unsigned int MAX_BOMB;
GLfloat bomb_pos[MAX_MAX_BOMB][2];
bool bomb_present[MAX_MAX_BOMB],bomb_shape[MAX_MAX_BOMB];
unsigned int BOMB_COUNT,bomb_speed[MAX_MAX_BOMB],bomb_color[MAX_MAX_BOMB][3];



//Main Ship Variables
bool ship_left, ship_right;
int ship_x = (width/2) - VARA - (VARB/2.0), ship_y = PADDING_BELOW;
unsigned int ship_span = VARA + VARA + VARB, FPS = 60, UNIT_MOVE;

//Score Variables
long long int curr_score,high_score;
void init()
{
    set_settings();//initiliazes buffer_refresh_delay ,MAX_BOMB,UNIT_MOVE
    unsigned int i,seg_len_local=  width/MAX_BOMB;
    srand(time(NULL));
    curr_score =0;
    k=0;
    ship_left=false;ship_right=false,game_state=1;
    quit_mouse_hover_yes = quit_mouse_hover_no = false;
    pause_mouse_hover_quit = pause_mouse_hover_resume = false;
    start_mouse_hover_quit = start_mouse_hover_start = false;
    get_high_score();
    for(i=0;i<MAX_BOMB;i++)
    {
        bomb_pos[i][0] = (seg_len_local*i) + VARD + rand()%((int)(seg_len_local - VARD - VARD + 1));
        bomb_pos[i][1] = height-(3*VARD);
        bomb_shape[i] = rand()%2;
        bomb_speed[i] = BOMB_MIN_SEC + (rand()%((int)(BOMB_MAX_SEC-BOMB_MIN_SEC+1)));
        bomb_present[i]=true;
        bomb_color[i][0] = rand()%10000;
        bomb_color[i][1] = rand()%10000;
        bomb_color[i][2] = rand()%10000;
    }
    BOMB_COUNT = MAX_BOMB;
}
int main(int argc,char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize ((int)width,(int)height);
	glutCreateWindow ("Galaxy shooting");
	init ();
	glutDisplayFunc(mainDisplay);
	glutReshapeFunc(reshape);
    glutKeyboardFunc(normal_key);
    glutKeyboardUpFunc(normal_key_up);
    glutSpecialFunc(keyboard_func);
    glutSpecialUpFunc(keyboard_up_func);
    glutPassiveMotionFunc(mouse_motion);
    glutMouseFunc(mouse_func);
    glutTimerFunc(100,timer_function,0);
    glutMainLoop();

	return 0;
}
