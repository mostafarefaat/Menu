#include "menu.h"

void _new_file(void)
{
    printf("%s\n",__func__);

}

void _open_file(void)
{
    printf("%s\n",__func__);
    
}

void _copy_to_clip_board(void)
{
    printf("%s\n",__func__);

}

void _copy_to_file(void)
{
    printf("%s\n",__func__);
    
}

void _paste(void)
{
    printf("%s\n",__func__);

}

void _select_all(void)
{
    printf("%s\n",__func__);
    
}
/*-------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------*/

struct MenuItem File_Menu_item[] = 
{
    {'n', "Create new file", Menu_Action, {.action = _new_file}},
    {'o', "Open an existing file", Menu_Action, {.action = _open_file}},
    {0},
};

struct Menu File_Menu = 
{
    "File", 
     File_Menu_item
};
/*-------------------------------------------------------------------------*/

struct MenuItem Copy_Menu_item[] = 
{
    {'c', "Copy to clipboard", Menu_Action, {.action = _copy_to_clip_board} },
    {'f', "Copy to file", Menu_Action, {.action = _copy_to_file} },
    {0},
};

struct Menu Copy_Menu = 
{
    "Copy", 
     Copy_Menu_item
};
/*-------------------------------------------------------------------------*/

struct MenuItem Edit_Menu_item[] = 
{
    {'c', "Copy a text", Menu_SubMenu, {.menu = &Copy_Menu} },
    {'v', "Paste a text", Menu_Action, {.action = _paste}  },
    {'a', "Select all text", Menu_Action, {.action = _select_all} },
    {0},
};

struct Menu Edit_Menu = 
{
    "Edit", 
     Edit_Menu_item
};
/*-------------------------------------------------------------------------*/

struct MenuItem Root_Menu_item[] = 
{
    {'f', "File", Menu_SubMenu, {.menu = &File_Menu} },
    {'e', "Edit", Menu_SubMenu, {.menu = &Edit_Menu} },
    {0},
};

struct Menu Root__Menu = 
{
    "Root", 
     Root_Menu_item
};
/*-------------------------------------------------------------------------*/
int main(int argc, char *argv[]){
    char input[4];
    menu_set_root(&Root__Menu);
    while (1)
    {   
        fgets(input,4,stdin);
        menu_process_user_input(input[0]);
        
    }
    
    return 0;
}