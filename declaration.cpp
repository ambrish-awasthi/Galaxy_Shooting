#define VARA 30
#define VARB 30
#define VARC 50
#define VARD 15
#define STAR_MAX 200
#define STAR_MIN 100
#define STAR_MIN_SIZE 100
#define STAR_MAX_SIZE 150
#define MAX_MAX_BOMB 50
#define BOMB_MIN_SEC 3
#define BOMB_MAX_SEC 15
#define BULLET_SEC 3
#define PADDING_BELOW 30
#define SCORE_BOARD_HEIGHT 36
#define SCORE_BOARD_WIDTH 110
#define SCORE_BOARD_PADDING 20
#define UNIT_ANGLE 10
#define MAX_ANGLE 50
extern bool isRotate;
extern float ship_rotation;
extern GLdouble width,height;
extern double seg_len;
extern int game_state;

//Background Star variable
extern int star_pos[STAR_MAX][2],k,num_stars;
extern float star_size[STAR_MAX];
extern unsigned int BACKGROUND_REFRESH_DELAY;

//Main Ship variables
extern int ship_x,ship_y;
extern GLfloat ship_points[13][2];
extern bool ship_left,ship_right;
extern unsigned int ship_span, FPS, UNIT_MOVE;

//Bomb variable
extern unsigned int MAX_BOMB;
extern GLfloat bomb_pos[MAX_MAX_BOMB][2];
extern bool bomb_present[MAX_MAX_BOMB],bomb_shape[MAX_MAX_BOMB];
extern unsigned int BOMB_COUNT,bomb_speed[MAX_MAX_BOMB],bomb_color[MAX_MAX_BOMB][3];

// Bullet variable
extern std::vector<struct bullet> bullets;

//Score variables
extern long long int curr_score,high_score;

//Mouse Hover Variables
extern bool quit_mouse_hover_yes, quit_mouse_hover_no;
extern bool pause_mouse_hover_resume, pause_mouse_hover_quit;
extern bool start_mouse_hover_start, start_mouse_hover_quit;
extern int left_bound_quit_yes, right_bound_quit_yes, left_bound_quit_no, right_bound_quit_no, up_bound_quit, down_bound_quit;
extern int left_bound_pause_quit, right_bound_pause_quit, left_bound_pause_resume, right_bound_pause_resume, up_bound_pause, down_bound_pause;
extern int left_bound_start, right_bound_start, up_bound_start_quit, down_bound_start_quit, up_bound_start_start, down_bound_start_start;
