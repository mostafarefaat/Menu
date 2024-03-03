#include "menu.h"

#define MAX_Menu_Depth 10

static struct Menu * menupath[MAX_Menu_Depth] = {0};   // array of pointers to menu structure
static int current_menu = 0;                          // holds the index of last selected menu


static void _show_prompt(void)
{
    printf("\033[1;33m");
    printf("( ");
    for(int i = 0; i< current_menu; i++){
        printf("%s -> ", menupath[i]->prompt);
    }
    printf("%s", menupath[current_menu]->prompt);
    printf(" )");
    printf("\033[0m");
}
void menu_set_root(struct Menu * root)
{
    menupath[current_menu] = root;
    _show_prompt();
}
void menu_process_user_input(char input)
{
    switch (input)
    {
    case '?':  // help msg 
        struct MenuItem * menu_item_ = menupath[current_menu]->items; 
        while(menu_item_->letter != 0){
            printf("%c - %s\n", menu_item_->letter, menu_item_->description);
            menu_item_++;
        }
    break;

    case '0': // parent menu
        if(current_menu > 0){
             current_menu--;
        }
    break;
    
    default: // process an input
        int menu_item_found = 0;
        struct MenuItem * menu_item = menupath[current_menu]->items;

        while(menu_item->letter != 0){
            if(menu_item->letter == input){
                menu_item_found = 1;
                break;
            }
            menu_item++;
        }
        if(menu_item_found == 1){

            if(menu_item->type == Menu_SubMenu){
                if(current_menu < MAX_Menu_Depth-1){
                    menupath[++current_menu] = menu_item->menuaction.menu;
                }
                else{
                    printf("Sorry out of boundary !...\n");
                }   
            }
            else if(menu_item->type == Menu_Action){
                menu_item->menuaction.action();   
            }
        }
        else{
            printf("Sorry this %c is not present in the menu !...\n",input);
        }
    break;
    }

    _show_prompt();

}