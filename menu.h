#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Menu_SubMenu 0
#define Menu_Action  1 

union MenuAction
{   
    void (*action) (void);
    struct Menu *menu;
};


struct Menu
{   
    char * prompt;
    struct MenuItem *items;
};

struct MenuItem{
    char letter;
    char *description;
    int type; // 0:Menu 1:Function
    union MenuAction menuaction;

};

void menu_set_root(struct Menu * root);
void menu_process_user_input(char input);
static void _show_prompt(void);