#include <UTFT.h>
#define blocksize 6
#define xmax 16
#define ymax 28
#define LCD_BL 2
extern uint8_t SmallFont[];
UTFT mlcd(ITDB18SP, 4, 3, 7, 6, 5); //get lcd controler(model,data,clk,cs,rst,control)
#define buttonA 0
#define buttonB 47
#define buttonC 91
#define buttonD 132
#define buttonE 546
//char *menuItems[] = {"Pavouk", "Larva", "spider","Lul","Play","to je sranda", "Lul","123","456","4589","123456","456789","123456","7894576","123456","123456","aohj","sadasddsa","sddsaasd","45sa"};
char *menuItems[] = {"Hrát", "O nás", "Konec"};
int displayHeight = mlcd.getDisplayYSize();
int arraySize = 20;
int topItem = 0;
int itemsInDisplay = 15;
int selectedItem = 0;
int fontHeight = 10;
void setup()
{
  Serial.begin(9600);
  pinMode(A0, 0); //ADK pin A0
  pinMode(LCD_BL, OUTPUT);
  digitalWrite(LCD_BL, HIGH);
  srand(1024);
  mlcd.InitLCD(0);
  mlcd.clrScr(); //refresh the lcd

  // timer.every(500,timelisten); //AUTO GAME
  // timer.every(10,keyListener); //ADK listen

}

void loop()
{
  paint();
  keyListener();
}
void paint()
{

  mlcd.setFont(SmallFont);
  for (int i = topItem; i < arraySize && i < itemsInDisplay+topItem; i++)
  {
    
    mlcd.setColor(255, 150, 0);    
    if (i == selectedItem)
    {
      mlcd.setColor(0, 255, 0);
      mlcd.print(menuItems[i], 10, fontHeight * (i-topItem));
    }
    else
    {     
      Serial.print("top item");
      Serial.println(topItem);
      Serial.print("i");
      Serial.println(i);
      mlcd.print(menuItems[i], 10, fontHeight * (i-topItem));
    }
  }
}
void enter()
{
    delay(100);
}
void up()
{
   
  if(selectedItem != arraySize)
  {  Serial.println("up pressed");
     selectedItem++;
    if(isDownInMenu())
    {
      mlcd.clrScr(); 
      topItem++;
    }
   
  }
    delay(100);
}
bool isDownInMenu()
{
  Serial.print("selected Item \0");
  Serial.println(selectedItem);
  Serial.print("top Item \0");
  Serial.println(topItem);
  if(itemsInDisplay==(selectedItem-topItem))
  {
    return true;
  }
  else{
    return false;
    }
}
void down()
{
  
  if (selectedItem != 0)
  { Serial.println("down pressed");
      
    if(selectedItem==topItem)
    {
      mlcd.clrScr(); 
      topItem--;
    }  
    selectedItem--;
  }
    delay(100);
}
void keyListener()
{

  int value = analogRead(A0);
  if (value < 150 && value > 100)
  {
    enter();
  }
  else if (value < 20)
  {
    down();
  }
  else if (value > 70 && value < 100)
  {
    up();
  }
}
class Menu{
//const  char* menuItems[] = {"Hrát", "O nás", "Konec"};
  int displayHeight = mlcd.getDisplayYSize();
  int arraySize = 20;
  int topItem = 0;
  int itemsInDisplay = 15;
  int selectedItem = 0;
  int fontHeight = 10;
  
  
  };
class Snake{
  int length;
  int colorR;
  int colorG;
  int colorB;
  void render()
  {
      
  }
   };
   class GameBoard{
    int colorR;
    int colorG;
    int colorB;
    void render()
    {
      }
    
    };
