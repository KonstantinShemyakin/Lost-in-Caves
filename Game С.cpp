# include "TXlib.h"
# include <iostream>
# include <string>
# include <cmath>
# include <ctime>
int x_blocks [10] [30] = {{},{},{},{},{},{},{},{},{},{}};

int xy_blocks_break [2] [10] = {{}/*x*/,{}/*y*/};

int xy_bullet [2] [5] = {{}/*x*/,{}/*y*/};

int opt_bullet [2] = {};

int opt_pick [2] = {};

int opt [2] = {};

bool opt_menu [2] = {true, false};

int xy_enemy [2] [5] = {{}/*x*/,{}/*y*/};

int xy_bonus [2] [2] = {{30 + 60*12 - 21, 30 + 60*6 - 9}/*x*/,{115, 115}/*y*/};

int xy_exit [2] = {};

char menu_opt [4][19] = {"LOST IN CAVES", "CAMPAING", "EXIT"};

bool bullet_way [5] = {false, false, false, false, false};

bool endingcamp [2] = {false, false};

bool enemy_way [5] = {false, false, false, false, false};//!Отвечает за направление движения:False - вправо, True - влево.

bool enemy_live [5] = {false, false, false, false, false};

bool pick_pist [2] = {false, false};

int bl_range = 60;

int y_blocks [10] = {bl_range*0.5, bl_range*1.5, bl_range*2.5, bl_range*3.5, bl_range*4.5, bl_range*5.5, bl_range*6.5, bl_range*7.5, bl_range*8.5, bl_range*9.5};

bool hero_bonus [2] = {false, false};

bool hero_bonus_func [2] = {false, false};

void Heroanim (float *x_hero, float *y_hero, float height, float length);

void hero_inter(float *x_hero, float *y_hero, float vel_x, float *vel_y, float height, float length, bool *hero_way, bool *wall_game_l, bool *wall_game_r);

void update();

void game(float bl_range, float *x_hero_adr, float *y_hero_adr, float vel_x, float *vel_y, float height, float length, bool *wall_game_l, bool *wall_game_r, bool *floor_game, bool *hero_way, int range_en, int level);

void floor_wall_ch(float bl_range, float *x_hero, float *y_hero, float length, float height,  bool *wall_game_l, bool *wall_game_r, bool *floor_game);

void level_seting_camp_1(float bl_range);

void level_seting_camp_2(float bl_range);

void level_startpos_1(float *x_hero, float *y_hero);

void level_startpos_2(float *x_hero, float *y_hero);

void level_draw(float bl_range, float *x_hero_adr, float *y_hero_adr, float height, float length, float range_en);

void CAMPAING(float bl_range, float *x_hero_adr, float *y_hero_adr, float vel_x, float *vel_y_adr, float height, float length, bool *wall_game_l, bool *wall_game_r, bool *floor_game, bool *hero_way, int range_en);

void Menu_inter(float bl_range, float *x_hero_adr, float *y_hero_adr, float vel_x, float *vel_y_adr, float height, float length, bool *wall_game_l, bool *wall_game_r, bool *floor_game, bool *hero_way, int range_en, bool *exiti);

void Start_menu(float bl_range, float *x_hero_adr, float *y_hero_adr, float vel_x, float *vel_y_adr, float height, float length, bool *wall_game_l, bool *wall_game_r, bool *floor_game, bool *hero_way, int range_en, bool *exiti);

void Draw_menu();

void Pointer (int x, int y);

void enemy_log(int bl_range, float *x_hero, float *y_hero, int vel_en, int range_en, float length, float height, int level);

void Bonus_log(float bl_range, int vel_x, float range_en, float *x_hero, float *y_hero, bool *hero_way, float height, float length);

void exit_log(int l, float *x_hero, float *y_hero);

void Death(int level, float bl_range, float *x_hero_adr, float *y_hero_adr);

void kill_enemy(int n);

void Destroy_bl(int l);

void Pickaxe(float *x_hero, float *y_hero, float height, float length);

void Draw_pickaxe_R(int x, int y);

void Draw_pickaxe_L(int x, int y);

void Draw_pickaxe(int x, int y, bool hero_way);

void Draw_enemy(int x, int y, float range_en);

void Draw_bullet(int x, int y);

void Draw_exit(int x, int y);

void Cleare();

int main()
{
    bool floor_game = true, wall_game_r = true, wall_game_l = true;
    bool hero_way = false;//!Хранит направление движения героя:False - вправо, True - влево.
    bool exiti = false;
    float vel_x = 3, vel_y = 5;
    float height_hero = 60, length_hero = 40;
    float bl_range = 60;
    float x_hero, y_hero;
    int range_en = 30;
    txCreateWindow (960, 540);
    Start_menu(bl_range, &x_hero, &y_hero, vel_x, &vel_y, height_hero, length_hero, &wall_game_l, &wall_game_r, &floor_game, &hero_way, range_en, &exiti);
    txDisableAutoPause();
    return 0;
}
//////////////////////////////
void Start_menu (float bl_range, float *x_hero_adr, float *y_hero_adr, float vel_x, float *vel_y_adr, float height, float length, bool *wall_game_l, bool *wall_game_r, bool *floor_game, bool *hero_way, int range_en, bool *exiti)
{
        while(*exiti == false)
        {
            Menu_inter(bl_range, x_hero_adr, y_hero_adr, vel_x, vel_y_adr, height, length, wall_game_l, wall_game_r, floor_game, hero_way, range_en, exiti);
            Draw_menu();
            update();
        }
}
void Menu_inter (float bl_range, float *x_hero_adr, float *y_hero_adr, float vel_x, float *vel_y_adr, float height, float length, bool *wall_game_l, bool *wall_game_r, bool *floor_game, bool *hero_way, int range_en, bool *exiti)
{
    if ((opt[0] == 1) && (opt[1] <= 10))
    {
        opt[1] += 1;
    }
    else
    {
        opt[0] = 0;
        opt[1] = 0;
    }
    if (GetAsyncKeyState(VK_DOWN) && (opt[0] != 1))
    {
        if (opt_menu[1] == true)
        {
            opt_menu[1] = false;
            opt_menu[0] = true;
            opt[0] = 1;
        }
        else
        {
            opt_menu[1] = true;
            opt_menu[0] = false;
            opt[0] = 1;
        }
    }
    if ((GetAsyncKeyState(VK_UP)) && (opt[0] != 1))
    {
        if (opt_menu[0] == true)
        {
            opt_menu[0] = false;
            opt_menu[1] = true;
            opt[0] = 1;
        }
        else
        {
            opt_menu[1] = false;
            opt_menu[0] = true;
            opt[0] = 1;
        }

    }
    if ((GetAsyncKeyState(VK_SPACE)) || (GetAsyncKeyState(VK_LBUTTON)))
    {
        if (opt_menu[0] == true)
        {
            for (int i = 0; i < 2; i++)
            {
                endingcamp[i] = false;
                hero_bonus[i] = false;
                hero_bonus_func[i] = false;
            }
            CAMPAING(bl_range, x_hero_adr, y_hero_adr, vel_x, vel_y_adr, height, length, wall_game_l, wall_game_r, floor_game, hero_way, range_en);
        }
        if (opt_menu[1] == true)
        {
            *exiti = true;
        }
    }
}

void Draw_menu()
{
    float x_text, y_text;
    txSetColor (TX_WHITE);
    //!Background x - 240, 720; y - 180
    txSetFillColor (TX_DARKGRAY);
    for (int i = 0; i < 10; i++)
    {
        for (int b = 0, c = bl_range/2; b < 16;c+=bl_range, b++)
        {
            txRectangle (c - bl_range/2, y_blocks[i] - bl_range/2,c + bl_range/2, y_blocks[i] + bl_range/2);
        }
    }
    //!Options and Name
    txSetColor (TX_BLACK);
    for (int i = 0; i < 4; i++)
    {
        if(i == 0)
        {
            txSetFillColor (TX_LIGHTGRAY);
            txSelectFont ("Comic Sans MS", 60, 40, FW_BOLD);
            x_text = txGetTextExtentX (menu_opt[i]);
            y_text = txGetTextExtentY (menu_opt[i]);
            txDrawText (480 - x_text/2, 60, 480 + x_text/2, 60 + y_text, menu_opt[i]);
        }
        else if (i == 1)
        {
            if((endingcamp[0] == true) && (endingcamp[1] == true))
            {
                menu_opt[1][0] = 'C';
                menu_opt[1][1] = 'A';
                menu_opt[1][2] = 'M';
                menu_opt[1][3] = 'P';
                menu_opt[1][4] = 'A';
                menu_opt[1][5] = 'I';
                menu_opt[1][6] = 'N';
                menu_opt[1][7] = 'G';
                menu_opt[1][8] = '(';
                menu_opt[1][9] = 'c';
                menu_opt[1][10] = 'o';
                menu_opt[1][11] = 'm';
                menu_opt[1][12] = 'p';
                menu_opt[1][13] = 'l';
                menu_opt[1][14] = 'e';
                menu_opt[1][15] = 't';
                menu_opt[1][16] = 'e';
                menu_opt[1][17] = ')';
            }
            txSelectFont ("Impact", 30, 20, FW_BOLD);
            x_text = txGetTextExtentX (menu_opt[i]);
            y_text = txGetTextExtentY (menu_opt[i]);
            txDrawText (480 - x_text/2, 270, 480 + x_text/2, 270 + y_text, menu_opt[i]);
            if ((txMouseX() <= 480 + x_text/2) && (txMouseX() >= 480 - x_text/2) && (txMouseY() <= 270 + y_text) && (txMouseY() >= 270))
            {
                opt_menu[i - 1] = true;
                opt_menu[i] = false;
            }
            if (opt_menu[i - 1])
            {
                Pointer(480 - x_text/2 - 10, 270 + 40*(i - 1) + y_text/2);
            }
        }
        else
        {
            txSelectFont ("Impact", 30, 20, FW_BOLD);
            x_text = txGetTextExtentX (menu_opt[i]);
            y_text = txGetTextExtentY (menu_opt[i]);
            txDrawText (480 - x_text/2, 270 + 40*(i - 1), 480 + x_text/2, 270 + 40*(i - 1) + y_text, menu_opt[i]);
            if ((txMouseX() <= 480 + x_text/2) && (txMouseX() >= 480 - x_text/2) && (txMouseY() <= 270 + 40*(i - 1) + y_text) && (txMouseY() >= 270 + 40*(i - 1)))
            {
                opt_menu[i - 1] = true;
                opt_menu[i - 2] = false;
            }
            if (opt_menu[i - 1])
            {
                Pointer(480 - x_text/2 - 10, 270 + 40*(i - 1) + y_text/2);
            }
        }
    }
}

void Pointer (int x, int y)
{
        txSetColor (TX_BLACK);
        txSetFillColor (TX_RED);
        POINT point [3] = {{x - 8, y - 8}, {x - 8, y + 8}, {x, y}};
        txPolygon (point, 3);
}

void Heroanim (float *x_hero, float *y_hero, float height, float length)
{
    //!Legs
    txSetColor (TX_BLACK);
    txSetFillColor (TX_BROWN);
    txRectangle (*x_hero - length/4, *y_hero, *x_hero, *y_hero + height/3);
    txRectangle (*x_hero + length/4, *y_hero, *x_hero, *y_hero + height/3);
    //!Body
    txSetFillColor (TX_RED);
    txRectangle (*x_hero + length/4, *y_hero - height/3, *x_hero - length/4, *y_hero);
    //!Hands, head
    txSetFillColor (TX_ORANGE);
    txRectangle (*x_hero + length/4, *y_hero - height/3, *x_hero - length/4, *y_hero - height/1.5);
    POINT hnd_1 [4] = {{*x_hero + length/4, *y_hero}, {*x_hero + length/2, *y_hero}, {*x_hero + length/2, *y_hero - height/6}, {*x_hero + length/4, *y_hero - height/3}};
    POINT hnd_2 [4] = {{*x_hero - length/4, *y_hero}, {*x_hero - length/2, *y_hero}, {*x_hero - length/2, *y_hero - height/6}, {*x_hero - length/4, *y_hero - height/3}};
    txPolygon (hnd_1, 4);
    txPolygon (hnd_2, 4);
}

void Draw_pickaxe_R(int x, int y)
{
    //!Рукоять
    txSetColor(TX_BLACK);
    txSetFillColor (TX_BROWN);
    POINT pick_hn [4] = {{x - 2, y - 2}, {x + 2, y + 2}, {x + 23, y - 19}, {x + 19, y - 23}};
    txPolygon (pick_hn, 4);
    //!Наконечник
    txSetFillColor (TX_LIGHTGRAY);
    POINT pick_end [5] = {{x + 35, y - 22/3}, {x + 30, y - 30}, {x + 7, y - 35}, {x + 19, y - 23}, {x + 23, y - 19}};
    txPolygon (pick_end, 5);
}

void Draw_pickaxe_L(int x, int y)
{
    //!Рукоять
    txSetColor(TX_BLACK);
    txSetFillColor (TX_BROWN);
    POINT pick [4] = {{x + 2, y - 2}, {x - 2, y + 2}, {x - 23, y - 19}, {x - 19, y - 23}};
    txPolygon (pick, 4);
    //!Наконечник
    txSetFillColor (TX_LIGHTGRAY);
    POINT pick_end [5] = {{x - 35, y - 22/3}, {x - 30, y - 30}, {x - 7, y - 35}, {x - 19, y - 23}, {x - 23, y - 19}};
    txPolygon (pick_end, 5);
}

void Draw_pickaxe(int x, int y, bool hero_way)
{
    if (hero_way == false)
    {
        Draw_pickaxe_R(x, y);
    }
    else
    {
        Draw_pickaxe_L(x - 30, y);
    }
}

void Draw_pistol_R(int x, int y)
{
    txSetColor (TX_BLACK);
    txSetFillColor (TX_LIGHTGRAY);
    POINT pistol [6] = {{x - 5, y}, {x + 5, y}, {x + 5, y - 8}, {x + 30, y - 8}, {x + 30, y - 20}, {x - 5, y - 20}};
    txPolygon (pistol, 6);
}

void Draw_pistol_L(int x, int y)
{
    txSetColor (TX_BLACK);
    txSetFillColor (TX_LIGHTGRAY);
    POINT pistol [6] = {{x + 5, y}, {x - 5, y}, {x - 5, y - 8}, {x - 30, y - 8}, {x - 30, y - 20}, {x + 5, y - 20}};
    txPolygon (pistol, 6);
}

void Draw_pistol(int x, int y, bool hero_way)
{
    if (hero_way == false)
    {
        Draw_pistol_R(x, y);
    }
    else
    {
        Draw_pistol_L(x - 30, y);
    }
}

void Draw_enemy(int x, int y, float range_en)
{
    //!legs
    txSetColor(TX_BLACK);
    txSetFillColor(TX_ORANGE);
    POINT leg_1 [5] = {{x + range_en/6, y + range_en/6}, {x + range_en/6, y + range_en/2}, {x + range_en/2, y + range_en/2}, {x + range_en/3, y + range_en/3}, {x + range_en/3, y + range_en/6}};
    POINT leg_2 [5] = {{x - range_en/6, y + range_en/6}, {x - range_en/6, y + range_en/2}, {x - range_en/2, y + range_en/2}, {x - range_en/3, y + range_en/3}, {x - range_en/3, y + range_en/6}};
    txPolygon (leg_1, 5);
    txPolygon (leg_2, 5);
    //!Body
    txSetColor(TX_WHITE);
    txSetFillColor(TX_WHITE);
    txRectangle (x + range_en/3, y + range_en/6, x - range_en/3, y - range_en/6);
    txRectangle (x + range_en/6, y - range_en/3, x - range_en/6, y + range_en/6);
    txCircle (x, y - range_en/3, range_en/6);
    txCircle (x + range_en/3, y, range_en/6);
    txCircle (x - range_en/3, y, range_en/6);
    //!teeth
    txSetColor(TX_BLACK);
    txSetFillColor(TX_RED);
    POINT tooth_1 [3] = {{x, y}, {x + range_en/6, y}, {x + range_en/12, y + range_en/6}};
    POINT tooth_2 [3] = {{x, y}, {x - range_en/6, y}, {x - range_en/12, y + range_en/6}};
    txPolygon (tooth_1, 3);
    txPolygon (tooth_2, 3);
    //!eyes
    txSetFillColor (TX_BLACK);
    txCircle (x, y - range_en/3, 2);
    txCircle (x + range_en/3, y, 2);
    txCircle (x - range_en/3, y, 2);
}

void Draw_bullet(int x, int y)
{
    txSetColor (TX_WHITE);
    txSetFillColor (TX_YELLOW);
    txEllipse (x - 7.5, y - 3, x + 7.5, y + 3);
}

void Draw_exit(int x, int y)
{
    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txCircle (x, y - 15, 15);
    txRectangle (x - 15, y - 15, x + 15, y + 30);
}
//////////////////////////
void hero_inter (float *x_hero, float *y_hero, float vel_x, float *vel_y, float height,
                 float length, bool *hero_way, bool *wall_game_l, bool *wall_game_r)
{
    if (GetAsyncKeyState(VK_RIGHT))
    {
        if (*wall_game_r == false)
        {
            *x_hero+=vel_x;
            *hero_way = false;
        }
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        if (*wall_game_l == false)
        {
            *x_hero-=vel_x;
            *hero_way = true;
        }
    }
    if((GetAsyncKeyState(VK_DOWN)) && (hero_bonus_func[0] == false) && (hero_bonus[0] == true))
    {
        hero_bonus_func[0] = !hero_bonus_func[0];
        if (hero_bonus_func[1])
        {
            hero_bonus_func[1] = false;
        }

    }
    if((GetAsyncKeyState(VK_UP)) && (hero_bonus_func[1] == false) && (hero_bonus[1] == true))
    {
        hero_bonus_func[1] = !hero_bonus_func[1];
        if (hero_bonus_func[0])
        {
            hero_bonus_func[0] = false;
        }
    }
    if (opt_pick[0] == 1)
    {
        if (opt_pick[1] < 25)
        {
            opt_pick[1]+=1;
        }
        else
        {
            opt_pick[1] = 0;
            opt_pick[0] = 0;
        }
    }
    if ((hero_bonus_func[0] == true) && (GetAsyncKeyState(VK_SPACE)))
    {
        for (int l = 0; l < 10; l++)
        {
            if ((xy_blocks_break[1][l] != 0) && (xy_blocks_break[0][l] != 0) && (opt_pick[0] == 0))
            {
                if ((*x_hero <= xy_blocks_break[0][l] + 60) && (*x_hero >= xy_blocks_break[0][l] - 60) && (*y_hero <= xy_blocks_break[1][l] + 100) && (*y_hero >= xy_blocks_break[1][l] - 100))
                {
                    Destroy_bl(l);
                    opt_pick[0] = 1;
                }
            }
        }
    }
    if (opt_bullet[0] == 1)
    {
        if (opt_bullet[1] < 50)
        {
            opt_bullet[1]+=1;
        }
        else
        {
            opt_bullet[1] = 0;
            opt_bullet[0] = 0;
        }
    }
    if ((hero_bonus_func[1] == true) && (GetAsyncKeyState(VK_SPACE)))
    {
        for (int i = 0; i < 5; i++)
        {
            if ((xy_bullet[0][i] == 0) && (xy_bullet[1][i] == 0) && (opt_bullet[0] == 0) && (*hero_way == false))
            {
                xy_bullet[0][i] = (*x_hero) + 25;
                xy_bullet[1][i] = (*y_hero) - 14;
                bullet_way[i] = *hero_way;
                opt_bullet[0] = 1;
                break;
            }
            if ((xy_bullet[0][i] == 0) && (xy_bullet[1][i] == 0) && (opt_bullet[0] == 0) && (*hero_way == true))
            {
                xy_bullet[0][i] = (*x_hero) - 25;
                xy_bullet[1][i] = (*y_hero) - 14;
                bullet_way[i] = *hero_way;
                opt_bullet[0] = 1;
                break;
            }
        }
    }
}

//////////////////////////////
void update ()
{
    txSleep (1);
    txSetFillColor (TX_WHITE);
    txClear ();
}
//////////////////////////////
void game (float bl_range, float *x_hero_adr, float *y_hero_adr, float vel_x, float *vel_y,
           float height, float length, bool *wall_game_l, bool *wall_game_r, bool *floor_game, bool *hero_way, int range_en, int level)
{
    hero_inter (x_hero_adr, y_hero_adr, vel_x, vel_y, height, length, hero_way, wall_game_l, wall_game_r);
    floor_wall_ch (bl_range, x_hero_adr, y_hero_adr, length, height, wall_game_l, wall_game_r, floor_game);
    level_draw (bl_range, x_hero_adr, y_hero_adr, height, length, range_en);
    Bonus_log (bl_range, vel_x, range_en, x_hero_adr, y_hero_adr, hero_way, height, length);
    enemy_log (bl_range, x_hero_adr, y_hero_adr, vel_x, range_en, length, height, level);
    exit_log (level, x_hero_adr, y_hero_adr);
    Heroanim (x_hero_adr, y_hero_adr, height, length);
    update();
}
//////////////////////////////
void Pickaxe(float *x_hero, float *y_hero, float height, float length)
{
    if ((*x_hero <= xy_bonus[0][0] + 40) && (*x_hero >= xy_bonus[0][0] - 40) && (*y_hero <= xy_bonus[1][0] + 40) && (*y_hero >= xy_bonus[1][0] - 40))
    {
        hero_bonus[0] = true;
    }
    if (hero_bonus[0] == false)
    {
        Draw_pickaxe_R(xy_bonus[0][0], xy_bonus[1][0]);
    }
}

void Pistol(float* x_hero, float *y_hero)
{
    if ((*x_hero <= xy_bonus[0][1] + 40) && (*x_hero >= xy_bonus[0][1] - 40) && (*y_hero <= xy_bonus[1][1] + 40) && (*y_hero >= xy_bonus[1][1] - 40))
    {
        hero_bonus[1] = true;
    }
    if (hero_bonus[1] == false)
    {
        Draw_pistol_R(xy_bonus[0][1], xy_bonus[1][1]);
    }
}
//////////////////////////////
void floor_wall_ch (float bl_range, float *x_hero, float *y_hero, float length, float height, bool *wall_game_l, bool *wall_game_r, bool *floor_game)
{
    //!Проверка пола
    for (int i = 0; i < 10; i++)
    {
        if ((xy_blocks_break[0][i] != 0) && (((((*x_hero + length/2) <= (xy_blocks_break[0][i] + bl_range/2)) && ((*x_hero + length/2) >= (xy_blocks_break[0][i] - bl_range/2))) ||
           (((*x_hero - length/2) <= (xy_blocks_break[0][i] + bl_range/2)) && ((*x_hero - length/2) >= (xy_blocks_break[0][i] - bl_range/2)))) &&
           (((*y_hero + height/3) <= (xy_blocks_break[1][i] + bl_range/2)) && ((*y_hero + height/3) >= (xy_blocks_break[1][i] - bl_range/2)))))
        {
            *floor_game = true;
            break;
        }
        else
        {
            *floor_game = false;
        }
        if ((*y_hero < (y_blocks[i] + bl_range/2)) && (*y_hero > (y_blocks[i] - bl_range/2)))
        {
            for (int b = 0; b < 30; b++)
            {
                if ((x_blocks[i+1][b] != 0) && (((((*x_hero + length/2) <= (x_blocks[i+1][b] + bl_range/2)) && ((*x_hero + length/2) >= (x_blocks[i+1][b] - bl_range/2))) ||
                    (((*x_hero - length/2) <= (x_blocks[i+1][b] + bl_range/2)) && ((*x_hero - length/2) >= (x_blocks[i+1][b] - bl_range/2)))) &&
                    (((*y_hero + height/3) <= (y_blocks[i+1] + bl_range/2)) && ((*y_hero + height/3) >= (y_blocks[i+1] - bl_range/2)))))
                {
                    *floor_game = true;
                    break;
                }
                else
                {
                    *floor_game = false;
                }
            }
            break;
        }
    }
    //!Проверка стен
    for (int i = 0; i < 10; i++)
    {
        if ((xy_blocks_break[1][i] != 0) && (*y_hero <= (xy_blocks_break[1][i] + bl_range/2)) && (*y_hero >= (xy_blocks_break[1][i] - bl_range/2)))
        {
            if ((xy_blocks_break[0][i] != 0) && (((*x_hero + length/2) <= (xy_blocks_break[0][i] + bl_range/2 + 1)) && ((*x_hero + length/2) >= (xy_blocks_break[0][i] - bl_range/2 - 1))))
                    {
                        *wall_game_r = true;
                        break;
                    }
                    else
                    {
                        *wall_game_r = false;
                    }
            if ((xy_blocks_break[0][i] != 0) && (((*x_hero - length/2) <= (xy_blocks_break[0][i] + bl_range/2 + 1)) && ((*x_hero - length/2) >= (xy_blocks_break[0][i] - bl_range/2 - 1))))
                    {
                        *wall_game_l = true;
                        break;
                    }
                    else
                    {
                        *wall_game_l = false;
                    }
        }
        if ((*y_hero <= (y_blocks[i] + bl_range/2)) && (*y_hero >= (y_blocks[i] - bl_range/2)))
        {
            for (int b = 0; b < 30; b++)
            {
                if ((x_blocks[i][b] != 0) && (((*x_hero + length/2) <= (x_blocks[i][b] + bl_range/2 + 1)) && ((*x_hero + length/2) >= (x_blocks[i][b] - bl_range/2 - 1))))
                {
                    *wall_game_r = true;
                    break;
                }
                else
                {
                    *wall_game_r = false;
                }
            }
            for (int b = 0; b < 30; b++)
            {
                if ((x_blocks[i][b] != 0) && (((*x_hero - length/2) <= (x_blocks[i][b] + bl_range/2 + 1)) && ((*x_hero - length/2) >= (x_blocks[i][b] - bl_range/2 - 1))))
                {
                    *wall_game_l = true;
                    break;
                }
                else
                {
                    *wall_game_l = false;
                }
            }
            break;
        }
    }
}

void Bonus_log(float bl_range, int vel_x, float range_en, float *x_hero, float *y_hero, bool *hero_way, float height, float length)
{
    if (hero_bonus_func[1] == true)
    {
        Draw_pistol (*x_hero + 15, *y_hero, *hero_way);
    }
    if (hero_bonus_func[0] == true)
    {
        Draw_pickaxe(*x_hero + 15, *y_hero, *hero_way);
    }
    //!Pistol logic
    for (int i = 0; i < 5; i++)
    {
        if ((xy_bullet[0][i] != 0) && (xy_bullet[1][i] != 0))
        {
            if(bullet_way[i] == false)
            {
                xy_bullet[0][i]+=vel_x*2;
            }
            else
            {
                xy_bullet[0][i]-=vel_x*2;
            }
        }
        for (int b = 0; b < 10; b++)
        {
            if ((xy_bullet[1][i] <= (y_blocks[b] + bl_range/2)) && (xy_bullet[1][i] >= (y_blocks[b] - bl_range/2)))
            {
                for (int l = 0; l < 30; l++)
                {
                    if ((x_blocks[b][l] != 0) && (xy_bullet[0][i] <= (x_blocks[b][l] + bl_range/2)) && (xy_bullet[0][i] >= (x_blocks[b][l] - bl_range/2)))
                    {
                        xy_bullet[0][i] = 0;
                        xy_bullet[1][i] = 0;
                    }
                }
            }
        }
        for (int e = 0; e < 5; e++)
        {
            if (enemy_live[e] == true)
            {
                if ((xy_bullet[0][i] <= (xy_enemy[0][e] + range_en/2)) && (xy_bullet[0][i] >= (xy_enemy[0][e] - range_en/2)) &&
                    (xy_bullet[1][i] <= (xy_enemy[1][e] + range_en/2)) && (xy_bullet[1][i] >= (xy_enemy[1][e] - range_en/2 - 5)))
                {
                    kill_enemy(e);
                    xy_bullet[0][i] = 0;
                    xy_bullet[1][i] = 0;
                }
            }
        }
    }
    if (pick_pist[0] == true)
    {
        Pickaxe(x_hero, y_hero, height, length);
    }
    if (pick_pist[1] == true)
    {
        Pistol(x_hero, y_hero);
    }
}

void exit_log(int l, float *x_hero, float *y_hero)
{
    if ((*x_hero <= xy_exit[0] + 30) && (*x_hero >= xy_exit[0] - 30) && (*y_hero <= xy_exit[1] + 60) && (*y_hero >= xy_exit[1] - 60))
    {
        endingcamp[l - 1] = true;
    }
}

void Destroy_bl(int l)
{
    xy_blocks_break[0][l] = 0;
    xy_blocks_break[1][l] = 0;
}

void kill_enemy(int n)
{
    enemy_live[n] = false;
}

void Death(int level, float bl_range, float *x_hero_adr, float *y_hero_adr)
{
    Sleep(500);
    if (level == 1)
    {
        level_seting_camp_1(bl_range);
        level_startpos_1(x_hero_adr, y_hero_adr);
    }
    if (level == 2)
    {
        level_seting_camp_2(bl_range);
        level_startpos_2(x_hero_adr, y_hero_adr);
    }
}

void enemy_log(int bl_range, float *x_hero, float *y_hero, int vel_en, int range_en, float length, float height, int level)
{
   for (int n = 0; n < 5; n++)
   {
     if (enemy_live[n] == true)
     {
        if (enemy_way[n] == true)
        {
            xy_enemy[0][n] -= vel_en;
        }
        if (enemy_way[n] == false)
        {
            xy_enemy[0][n] += vel_en;
        }
        for (int b = 0; b < 10; b++)
        {
            if ((xy_enemy[1][n] <= y_blocks[b] + bl_range/2) && (xy_enemy[1][n] >= y_blocks[b] - bl_range/2))
            {
              for (int i = 0; i < 16; i++)
              {
                    if ((x_blocks[b][i] != 0) && ((((xy_enemy[0][n] - range_en/2) <= (x_blocks[b][i] + bl_range/2 + 1)) && ((xy_enemy[0][n] - range_en/2) >= (x_blocks[b][i] - bl_range/2 - 1))) ||
                       (((xy_enemy[0][n] + range_en/2) <= (x_blocks[b][i] + bl_range/2 + 1)) && ((xy_enemy[0][n] + range_en/2) >= (x_blocks[b][i] - bl_range/2 - 1)))))
                    {
                        enemy_way[n] = !enemy_way[n];
                        break;
                    }
              }
              break;
            }
        }
        if ((((xy_enemy[0][n] + range_en/2)<=(*x_hero + length/2)) && ((xy_enemy[0][n] + range_en/2)>=(*x_hero - length/2)) ||
             ((xy_enemy[0][n] - range_en/2)<=(*x_hero - length/2)) && ((xy_enemy[0][n] - range_en/2)>=(*x_hero + length/2))) &&
           ((((xy_enemy[1][n] + range_en/2) >= (*y_hero - height/2)) && ((xy_enemy[1][n] + range_en/2) <= (*y_hero + height/2))) ||
            (((xy_enemy[1][n] - range_en/2) >= (*y_hero - height/2)) && ((xy_enemy[1][n] - range_en/2) <= (*y_hero + height/2)))))
        {
            Death(level, bl_range, x_hero, y_hero);
        }
     }
   }
}

void Cleare()
{
    for(int i = 0; i < 10; i++)
    {
        xy_blocks_break[0][i] = 0;
        xy_blocks_break[1][i] = 0;
        for(int b = 0; b < 30; b++)
        {
            x_blocks[i][b] = 0;
        }
    }
    for(int i = 0; i < 5; i++)
    {
        enemy_live[i] = false;
        xy_bullet[0][i] = 0;
        xy_bullet[1][i] = 0;
    }
    pick_pist[0] = false;
    pick_pist[1] = false;
}

//////////////////////////////КАРТЫ ДЛЯ ИГРЫ
void level_startpos_1(float *x_hero, float *y_hero)
{
    *x_hero = 90;
    *y_hero = 100;
}

void level_seting_camp_1(float bl_range)
{
    for(int i = bl_range/2, n = 0; n < 16; i+=bl_range, n++)
    {
        x_blocks[0][n] = i;
    }
    x_blocks [1] [0] = bl_range/2;
    x_blocks [1] [1] = bl_range/2 + bl_range*15;
    for(int i = bl_range/2, n = 0; n < 7; i+=bl_range, n++)
    {
        x_blocks[2][n] = i;
    }
    for(int i = bl_range/2 + bl_range*8, n = 8; n < 16; i+=bl_range, n++)
    {
        x_blocks[2][n] = i;
    }
    for(int i = bl_range/2 + bl_range*8, n = 8; n < 16; i+=bl_range, n++)
    {
        x_blocks[3][n] = i;
    }
    x_blocks[3][1] = bl_range/2 + bl_range*6;
    x_blocks[4][0] = bl_range/2 + bl_range*15;
    x_blocks[4][1] = bl_range/2 + bl_range*6;
    for(int i = bl_range/2 + bl_range*8, n = 8; n < 16; i+=bl_range, n++)
    {
        x_blocks[4][n] = i;
    }
    x_blocks[5][0] = bl_range/2 + bl_range*15;
    x_blocks[5][1] = bl_range/2 + bl_range*6;
    for(int i = bl_range/2 + bl_range*8, n = 8; n < 16; i+=bl_range, n++)
    {
        x_blocks[5][n] = i;
    }
    x_blocks[6][0] = bl_range/2 + bl_range*15;
    x_blocks[6][1] = bl_range/2 + bl_range*6;
    for(int i = bl_range/2 + bl_range*8, n = 8; n < 16; i+=bl_range, n++)
    {
        x_blocks[6][n] = i;
    }
    x_blocks[7][0] = bl_range/2 + bl_range*15;
    x_blocks[7][1] = bl_range/2 + bl_range*6;
    x_blocks[8][0] = bl_range/2 + bl_range*15;
    for(int i = bl_range/2 + bl_range*6, n = 6; n < 16; i+=bl_range, n++)
    {
        x_blocks[8][n] = i;
    }
    xy_blocks_break[0][0] = bl_range/2 + bl_range*7;
    xy_blocks_break[0][1] = bl_range/2 + bl_range*7;
    xy_blocks_break[0][3] = bl_range/2 + bl_range*8;
    xy_blocks_break[0][4] = bl_range/2 + bl_range*9;
    xy_blocks_break[0][5] = bl_range/2 + bl_range*10;
    xy_blocks_break[1][0] = y_blocks[2];
    xy_blocks_break[1][1] = y_blocks[4];
    xy_blocks_break[1][3] = y_blocks[7];
    xy_blocks_break[1][4] = y_blocks[7];
    xy_blocks_break[1][5] = y_blocks[7];
    enemy_live [0] = false;
    enemy_live [1] = false;
    enemy_live [2] = false;
    enemy_live [3] = false;
    enemy_live [4] = false;
    xy_exit [0] = bl_range/2 + bl_range*14;
    xy_exit [1] = y_blocks[7];
    pick_pist [0] = true;
    pick_pist [1] = false;
}

void level_startpos_2(float *x_hero, float *y_hero)
{
    *x_hero = 90;
    *y_hero = 100;
}

void level_seting_camp_2(float bl_range)
{
    for(int i = bl_range/2, n = 0; n < 11; i+=bl_range, n++)
    {
        x_blocks[0][n] = i;
    }
    x_blocks [1] [0] = bl_range/2;
    x_blocks [1] [11] = bl_range/2 + bl_range*10;
    for(int i = bl_range/2, n = 0; n < 9; i+=bl_range, n++)
    {
        x_blocks[2][n] = i;
    }
    for(int i = bl_range/2 + bl_range*10, n = 11; n < 15; i+=bl_range, n++)
    {
        x_blocks[2][n] = i;
    }
    x_blocks [3] [0] = bl_range/2;
    x_blocks [3] [14] = bl_range/2 + bl_range*13;
    x_blocks [4] [0] = bl_range/2;
    for(int i = bl_range/2 + bl_range*2, n = 3; n < 15; i+=bl_range, n++)
    {
        x_blocks[4][n] = i;
    }
    x_blocks [5] [0] = bl_range/2;
    x_blocks [5] [14] = bl_range/2 + bl_range*13;
    for(int i = bl_range/2, n = 0; n < 14; i+=bl_range, n++)
    {
        x_blocks[6][n] = i;
    }
    xy_blocks_break[0][0] = bl_range/2 + bl_range*9;
    xy_blocks_break[0][1] = bl_range/2 + bl_range;
    xy_blocks_break[1][0] = y_blocks[2];
    xy_blocks_break[1][1] = y_blocks[4];
    enemy_live[0] = true;
    enemy_live[1] = true;
    enemy_live[2] = true;
    enemy_live[3] = true;
    enemy_live[4] = false;
    xy_enemy[0][0] = bl_range/2 + bl_range*3;
    xy_enemy[0][1] = bl_range/2 + bl_range*10;
    xy_enemy[0][2] = bl_range/2 + bl_range;
    xy_enemy[0][3] = bl_range/2 + bl_range*9;
    xy_enemy[1][0] = y_blocks[3] + 15;
    xy_enemy[1][1] = y_blocks[3] + 15;
    xy_enemy[1][2] = y_blocks[5] + 15;
    xy_enemy[1][3] = y_blocks[5] + 15;
    xy_exit[0] = bl_range/2 + bl_range*12;
    xy_exit[1] = y_blocks[5];
    pick_pist[1] = true;
    pick_pist[0] = false;
}

void level_draw(float bl_range, float *x_hero_adr, float *y_hero_adr, float height, float length, float range_en)
{
    txSetColor (TX_BLACK);
    txSetFillColor (TX_DARKGRAY);
    for (int i = 0; i < 10; i++)
    {
        for (int b = 0, c = bl_range/2; b < 16;c+=bl_range, b++)
        {
            txRectangle (c - bl_range/2, y_blocks[i] - bl_range/2,c + bl_range/2, y_blocks[i] + bl_range/2);
        }
    }
    txSetFillColor (TX_GRAY);
    for (int i = 0; i < 10; i++)
    {
        for (int b = 0; b < 30; b++)
        {
            if (x_blocks[i][b] != 0)
            {
                txRectangle (x_blocks[i][b] - bl_range/2, y_blocks[i] - bl_range/2, x_blocks[i][b] + bl_range/2, y_blocks[i] + bl_range/2);
            }
        }
        if ((xy_blocks_break[0][i] != 0) && (xy_blocks_break[1][i] != 0))
        {
            txRectangle (xy_blocks_break[0][i] - bl_range/2, xy_blocks_break[1][i] - bl_range/2, xy_blocks_break[0][i] + bl_range/2, xy_blocks_break[1][i] + bl_range/2);
            txLine (xy_blocks_break[0][i], xy_blocks_break[1][i] - bl_range/2, xy_blocks_break[0][i], xy_blocks_break[1][i] + bl_range/2);
            txLine (xy_blocks_break[0][i] - bl_range/2, xy_blocks_break[1][i], xy_blocks_break[0][i] + bl_range/2, xy_blocks_break[1][i]);
        }
    }
    Draw_exit(xy_exit[0], xy_exit[1]);
    for (int e = 0; e < 5; e++)
    {
        if(enemy_live[e] == true)
        {
            Draw_enemy(xy_enemy[0][e], xy_enemy[1][e], range_en);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if ((xy_bullet[0][i] != 0) && (xy_bullet[1][i] != 0))
        {
            Draw_bullet(xy_bullet[0][i], xy_bullet[1][i]);
        }
    }

}

void CAMPAING(float bl_range, float *x_hero_adr, float *y_hero_adr, float vel_x, float *vel_y_adr, float height, float length, bool *wall_game_l, bool *wall_game_r, bool *floor_game, bool *hero_way, int range_en)
{
    for (int lev = 0; lev < 2; lev++)
    {
        if(lev == 0)
        {
            level_startpos_1(x_hero_adr, y_hero_adr);
            level_seting_camp_1(bl_range);
        }
        if(lev == 1)
        {
            level_startpos_2(x_hero_adr, y_hero_adr);
            level_seting_camp_2(bl_range);
        }
        while (endingcamp[lev] == false)
        {
            while (*floor_game == true)
            {
                game(bl_range, x_hero_adr, y_hero_adr, vel_x, vel_y_adr, height, length, wall_game_l, wall_game_r, floor_game, hero_way, range_en, lev + 1);
                if (endingcamp[lev] == true)
                {
                    break;
                }
            }
            while (*floor_game == false)
            {
                *y_hero_adr+=*vel_y_adr;
                game(bl_range, x_hero_adr, y_hero_adr, vel_x, vel_y_adr, height, length, wall_game_l, wall_game_r, floor_game, hero_way, range_en, lev + 1);
                if (endingcamp[lev] == true)
                {
                    break;
                }
            }
        }
        Cleare();
    }
}

