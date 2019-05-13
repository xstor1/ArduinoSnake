#include <UTFT.h>
#define blocksize 6
#define xmax 16
#define ymax 28
#define LCD_BL 2
extern uint8_t SmallFont[];
UTFT mlcd(ITDB18SP, 4, 3, 7, 6, 5); //get lcd controler(model,data,clk,cs,rst,control)
int displayHeight = mlcd.getDisplayYSize();
int fontHeight = 10;
#define buttonA 0
#define buttonB 47
#define buttonC 91
#define buttonD 132
#define buttonE 546





class Menu{
  const char* menuItems[3] = {"Hrát", "O nás", "Konec"};
  int arraySize = 3;
  int topItem = 0;
  int itemsInDisplay = 15;
  int selectedItem = 0;
  int fontHeight = 10;

public: void render()
  {
    Serial.print("render started");
     mlcd.setFont(SmallFont);
  for (int i = this->topItem; i < this->arraySize && i < this->itemsInDisplay+this->topItem; i++)
  {
    
    mlcd.setColor(255, 150, 0);    
    if (i == this->selectedItem)
    {
      mlcd.setColor(0, 255, 0);
      mlcd.print(this->menuItems[i], 10, this->fontHeight * (i-this->topItem));
    }
    else
    {     
      Serial.print("top item");
      Serial.println(this->topItem);
      Serial.print("i");
      Serial.println(i);
      mlcd.print(this->menuItems[i], 10, this->fontHeight * (i-this->topItem));
    }
  }  
  } 
public:  bool isDownInMenu()
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
public: void enter()
{
    delay(100);
}
public: void up()
{
   
  if(this->selectedItem != this->arraySize)
  {  Serial.println("up pressed");
     this->selectedItem++;
    if(this->isDownInMenu())
    {
      mlcd.clrScr(); 
      this->topItem++;
    }
   
  }
    delay(100);
}

public: void down()
{
  
  if (this->selectedItem != 0)
  { Serial.println("down pressed");
      
    if(this->selectedItem==topItem)
    {
      mlcd.clrScr(); 
     this->topItem--;
    }  
   this->selectedItem--;
  }
    delay(100);
}
  
  
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





//char *menuItems[] = {"Pavouk", "Larva", "spider","Lul","Play","to je sranda", "Lul","123","456","4589","123456","456789","123456","7894576","123456","123456","aohj","sadasddsa","sddsaasd","45sa"};
//char *menuItems[] = {"Hrát", "O nás", "Konec"};
Menu* currentMenu =  new Menu();
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
currentMenu->render();
}


void enter()
{
  currentMenu->enter();
   
}
void up()
{
  currentMenu->up();
}

void down()
{
  currentMenu->down();
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
