// Krokový motor a driver

// čísla pinů pro digitální výstupy
const int in1 =  8;
const int in2 =  9;
const int in3 = 10;
const int in4 = 11;
const int fastForwards = 7;
const int fastBackwards = 6;
const int normal = 5;

// proměnná pro nastavení rychlosti,
// se zvětšujícím se číslem se rychlost zmenšuje
// rychlost v ml/h = 52.734375/timestep
// bacha nastavuje se jinde
int timestep = 1;
// 1 - dopredu rychle, -1 - dozadu rychle, 0 - nikam, 11 - dopredu pomalu
int direction = 1;


void setup() {
  // inicializace digitálních výstupů
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(fastForwards, INPUT);
  pinMode(fastBackwards, INPUT);
  pinMode(normal, INPUT);
}

void loop() {
  // plná rotace o 360 stupňů = 512 volání
  // funkce rotacePoSmeru() či rotaceProtiSmeru()
  if (digitalRead(fastForwards) == HIGH) {
    timestep = 1;
    direction = 1;
  } else if (digitalRead(fastBackwards) == HIGH) {
    timestep = 1;
    direction = -1;
  } else if (digitalRead(normal) == HIGH) {
    if (direction == 11) {
      direction = 0;
      delay(500);
    } else {
    timestep = 53;   //TADY
    direction = 11;
    delay(500);
    }
  } else {
    if (direction != 11) {
      direction = 0;
    }
  }

  if (direction == 1 || direction == 11) {
    rotacePoSmeru();
  } else if (direction == -1) {
      rotaceProtiSmeru();
  } else {
    delay(1);
  }
}

// zde následují funkce pro volání jednotlivých
// kroků pro otočení po či proti směru hodinových
// ručiček
void rotacePoSmeru() {
  krok1();
  krok2();
  krok3();
  krok4();
  krok5();
  krok6();
  krok7();
  krok8();
}
void rotaceProtiSmeru() {
  krok8();
  krok7();
  krok6();
  krok5();
  krok4();
  krok3();
  krok2();
  krok1();
}
// každý krok obsahuje výrobcem dané pořadí
// pro správné spínání motoru a následnou
// pauzu, kterou určujeme rychlost otáčení
void krok1(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(timestep);
}
void krok2(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(timestep);
}
void krok3(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(timestep);
}
void krok4(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(timestep);
}
void krok5(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(timestep);
}
void krok6(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  delay(timestep);
}
void krok7(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(timestep);
}
void krok8(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(timestep);
}