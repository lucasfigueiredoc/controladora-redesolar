//Lucas Figueiredo Câmara
//11/05/2022

void BAIXO(void);
void ALTO(void);
void Ciclos(void);
void lcdImpress(void);



#include <LiquidCrystal.h>
#define hora 0

#define energiaPlaca  9
#define energiaRua  10
#define leituraBat  1
#define manual 8

#define baixaCarga 23.4
#define altaCarga 25.4

bool valorManual;
int Ciclo;
//0 = bat off
//1 = bat on man, voltage > 23
//2 = bat off for time
//3 = bat off for voltage


int tempo;

float valorBat;
float resultadoBat;
int contador = 3000;
float Voltagem, v;
float resultado;
float r1=1000000;
float r2=100000;
float smooth[10];

byte teste = 3;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

    tempo = millis();
    Serial.begin(9600);
//    pinMode(9, OUTPUT);// pinmod de entrada e saida de dados.
    pinMode(energiaPlaca, OUTPUT);
    //digitalWrite(energiaPlaca, LOW);
    pinMode(energiaRua, OUTPUT);
    //  digitalWrite(energiaRua, LOW);
    pinMode(leituraBat, INPUT);
    pinMode(manual, INPUT);
	pinMode(hora, INPUT);
  
    analogWrite(9, 50);   //config da tela
    lcd.begin(16, 2);
    lcd.setCursor(0,0);
    
                
}

void loop() {


    if(digitalRead(manual)==HIGH){
        valorManual = !valorManual;
        contador = tempo;
        if (contador == tempo){
            lcd.setCursor(5,0);
            lcd.print("AAA");
            contador = 0;
        }
    
    }
    if(Voltagem > baixaCarga){
            if(valorManual == true ){
                Ciclo = 0;


        }
            if(valorManual == false){
                Ciclo = 2;

        }


    }else if(Voltagem < baixaCarga){
        Ciclo = 1;



    }

    

  
    // if(Tempo for maior que 8hram e menor que 16hrpm){
    //     if(Voltagem > baixaCarga)
    //     Ciclo = 3;

    // }

    Ciclos();

    //leitura do valor em Volt da bateria para apresentar na tela

    Serial.print(Ciclo);

    lcd.setCursor(0,0);

    lcdImpress();

}

void BAIXO(){
    lcd.setCursor(0,1);
    lcd.print("BAT [X] RUA [ ]");

}
void ALTO(){
    lcd.setCursor(0,1);
    lcd.print("BAT [ ] RUA [X]");

}
void Ciclos(){

    if(Ciclo == 0) {
        digitalWrite(energiaRua, HIGH);
        digitalWrite(energiaPlaca, LOW);
        ALTO();
}

    if(Ciclo == 1) {
        digitalWrite(energiaRua, HIGH);
        digitalWrite(energiaPlaca, LOW);
        ALTO();

}

    if(Ciclo == 2){
        digitalWrite(energiaRua, LOW);
        digitalWrite(energiaPlaca, HIGH);
        BAIXO();

} 

    if(Ciclo == 3){
        digitalWrite(energiaRua, HIGH);
        digitalWrite(energiaPlaca, LOW);
        BAIXO();

} 
      if(Ciclo == 4){
        digitalWrite(energiaRua, HIGH);
        digitalWrite(energiaPlaca, LOW);
        BAIXO();

} 





}

void lcdImpress(void){

    
  v =(analogRead(leituraBat)*5)/1023.0;
  Voltagem =(v/(r2/(r1+r2)));
  lcd.setCursor(0,0);
  lcd.print(Voltagem);
  lcd.setCursor(4,0);
  lcd.print(" : V");





}

