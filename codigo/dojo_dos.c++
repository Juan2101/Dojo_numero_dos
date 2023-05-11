// C++ code
//
#define constitucion 12
#define san_juan 11
#define independencia 10
#define moreno 9
#define pulsador 17
#define buzzer 3
#define A 7
#define B 6
#define C 16
#define D 15
#define E 14
#define F 5
#define G 4

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(constitucion, OUTPUT);
  pinMode(san_juan, OUTPUT);
  pinMode(independencia, OUTPUT);
  pinMode(moreno, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(pulsador, INPUT_PULLUP);
  Serial.begin(9600);
}

void prender_sonar_apagar(int led, int hz)
{
  digitalWrite(led, HIGH);
  tone(buzzer,hz,200);
  delay(1000);
  digitalWrite(led, LOW);
  delay(2000);
}

void display_off()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void display(int num)
{
  switch(num)
  {
    case 0:
    	digitalWrite(A, HIGH);
    	digitalWrite(B, HIGH);
    	digitalWrite(C, HIGH);
    	digitalWrite(D, HIGH);
    	digitalWrite(E, HIGH);
    	digitalWrite(F, HIGH);
    break;
    case 1:
        digitalWrite(B, HIGH);
    	digitalWrite(C, HIGH);
    break;
    case 2:
    	digitalWrite(A, HIGH);
    	digitalWrite(B, HIGH);
        digitalWrite(D, HIGH);
    	digitalWrite(E, HIGH);
    	digitalWrite(G, HIGH);
    break;
    case 3:
        digitalWrite(A, HIGH);
    	digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
    	digitalWrite(D, HIGH);
    	digitalWrite(G, HIGH);
    break;
    case 4:
    	digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
    	digitalWrite(F, HIGH);
    	digitalWrite(G, HIGH);
    break;
    case 5:
     	digitalWrite(A, HIGH);
    	digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
    	digitalWrite(F, HIGH);
    	digitalWrite(G, HIGH);
    break;
    case 6:
        digitalWrite(A, HIGH);
    	digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
    	digitalWrite(E, HIGH);
    	digitalWrite(F, HIGH);
    	digitalWrite(G, HIGH);
    break;
    case 7:
    	digitalWrite(A, HIGH);
    	digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
    break;
    case 8:
        digitalWrite(A, HIGH);
    	digitalWrite(B, HIGH);
    	digitalWrite(C, HIGH);
    	digitalWrite(D, HIGH);
    	digitalWrite(E, HIGH);
    	digitalWrite(F, HIGH);
    	digitalWrite(G, HIGH);
    break;
    case 9:
        digitalWrite(A, HIGH);
    	digitalWrite(B, HIGH);
    	digitalWrite(C, HIGH);
    	digitalWrite(D, HIGH);
    	digitalWrite(F, HIGH);
    	digitalWrite(G, HIGH);
    break;
  }
}

bool flag = false;

void loop()
{
  int p = digitalRead(pulsador);
  if(p == 0 or flag)
  {
    flag = true;
  	display(3);
  	prender_sonar_apagar(constitucion,260);
  	display_off();
  	display(2);
  	prender_sonar_apagar(san_juan,359);
  	display_off();
  	display(1);
  	prender_sonar_apagar(independencia,440);
  	display_off();
  	display(0);
  	prender_sonar_apagar(moreno,566);
  	display_off();
  }
}