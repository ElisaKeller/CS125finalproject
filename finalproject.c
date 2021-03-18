/*lol*/
/*Ascii palm tree: http://onlinesgamestips.com/2013/07/weekly-browser-game-update-ripple-dot-zero-penguin-get-a-second-chance-with-the-lucky-peach-for-the-king-ascent/ 
*/

/*Ask user diffuculty level: level 1(stationary banana); level 2 (falling banana); level 3 (skeet banana)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS (80)
#define COLS (111)


/*from prof marriot in class moving img*/
void clearScreen(){
  sleep(1);
  printf("\e[2J\e[H");
}

void print_array(char lines[ROWS][COLS]){

  int x;
  for (x=0; x< ROWS; x++){
  if (x==3){
   printf("\e[0;33m %s\n", lines[x]);
  }
  else{
   printf("\e[1;34m %s\n", lines[x]);
  }
}
}

/*void level_1_win_animation(){
  int y; 
  clearScreen();
  print_array(intro);
  for(y=1; y< (ROWS-1); y++){   
    clearScreen();
    intro[y][y]='<';
    print_array(intro);  
    intro[y][y]=' ';
  } 
  changeColor(4);
  for(y=1; y< (ROWS-1); y++){   
    clearScreen();
    intro[y][y]='>';
    intro[y-1][y]='>';
    print_array(intro);  
    intro[y][y]=' ';
    intro[y-1][y]=' ';
  } 
  changeColor(4);
}
*/


/*random height generator*/
int level_1_banana_y_coordinate()
{
 int y_coordinate;
  y_coordinate=rand()%56+14;
  return y_coordinate;
}



/*random distance generator*/
/*int level_3_banana_x_coordinate()
{
 int x_coordinate;
  x_coordinate=rand()%20+9;
  return x_coordinate;
}*/

int level_1_decide_collect(int level_1_height_guess){
  int y_coordinate=level_1_banana_y_coordinate();
  if (level_1_height_guess==y_coordinate)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}





int main (){
  int level_1_height_guess, banana_collect=0,check,attempt;
  
  
  /*instructions*/
  printf("******************************Welcome to banana-rang******************************\n");
  printf("The goal of the game is to collect bananas by throwing your boomerang at them.\n");
  printf("To throw your boomerang, type your guess for the banana's height and press enter.\n");
  printf("Once you catch 1 banana you will move on to the next level.\n");
  printf("Good luck!\n");
  srand(time(NULL));
  
  while (banana_collect==0){
  char intro[ROWS][COLS]={ 
    "***********************************************************************************************",
    "1                                                                                              ",
    "2                                                                        _____                 ",
    "3                                                                  _..._/   - \\__..._          ",
    "4                                                               .-'   -   -    - -   '-.       ",
    "5                                                             .' -  .---. ###- .---.   -'.     ", 
    "6                                                            /  _.-'##.-'##### '-.##'-._  \\    ",
    "7                                                            |/'   ##'--  ###   - '##   '\\|    ",
    "8                                                                 .'- .-'(----)'-.- '.         ",
    "9                                                                / .-'###(----)###'-. \\        ",
    "10                                                              | /  ####(----)#### \\- |       ",
    "11                                                               \\|   ###(----)###   |/        ",
    "12                                                                       (----)                ",/*bananas start falling from here 12-24*/
    "13                                                                       (----)                ",
    "14                                                                       (----)                ",
    "15                                                                       (----)                ",
    "16                                                                       (----)                ",
    "17                                                                       (----)                ",
    "18                                                                       (----)                ",
    "19                                                                       (----)                ",
    "20        _,,,_                                                          (----)                ",
    "21      (d.   .b)                                                        (----)                ",
    "22    \\   ((T))  <                                                       (----)                ",
    "23    /  \\|   |/                                                         (----)                ",/*<bommerang distance changes from 14-70*/
    "24____\\_('')_('')________________________________________________________/----\\________________"};
            
  printf("|Level 1|\n");          
  
  print_array(intro);
  
  do{
  printf("Guess the height of the banana: \n");
  check=scanf("%d",&level_1_height_guess);            
  scanf("%*[^\n]");
  }while(check==0);
  
  int win_or_loose = level_1_decide_collect(level_1_height_guess);        
  banana_collect = banana_collect + win_or_loose;
  printf("You collected %d banana's\n", banana_collect);
  attempt=attempt+1;
  };
  
  return 0;
}
            


/********************************************************************************
--------------------------------To do--------------------------------------------
Level 1
-initialize all variables
-keep track of attempts
-create 2 animations; win and loose
-Add (boomerang to banana) motion {same}
-Creat input loop until 2 bananas collected
-Add banana collection motion )> (banana to monkey) {win}
-Add boomerang missing collection {loose} 
-Add colors to background
-Add colors to boomerang
-Add color to banana
-Debug level 1 and save


Level 2
-Add banana falling motion
-make boomerang fast enough to 
  reach banana (keep it possible
-make banana initial height not
  too low
  
  
Level 3 
-Make parabolic Arc
-Animate parabolic arc
-Animate banana collection  
  
  
Optional
-Have bommerang make a "straight line to banana" starting from the monkey's hand
-Create leader board by rewriting a .c file
-Initialize funtions before main
-Add splat animation if miss
-Create level selection

***********************************************************************************/
           
           
