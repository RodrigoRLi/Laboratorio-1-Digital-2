/**********************************************
*Universidad del Valle de Guatemala
*Nombre: Rodrigo Fernando Recinos Lopez
*Fecha: 26/07/2026
*Curso: Electronica digital 2
*Laboratorio 1: Contador de decadas y binario
***********************************************/
#include <Arduino.h>
#include <stdio.h>
#include <stdint.h>
#include <driver/gpio.h>

//Definición de variables
int bt1 = 23;
int bt2 = 22;
int bt3 = 21;
int led1 = 33;
int led2 = 25;
int led3 = 26;
int led4 = 27;
int  estadoanteriorbt3 = 0;
int  estadoanteriorbt2 = 0;
int  estadoanteriorbt1 = 0;
int contadorbin = 0;
int contadordec =0;
int modo = 0;



//funcion de contador de decadas
void mododecada ()
{
int estadobt2 = digitalRead(bt2);
int estadobt3 = digitalRead(bt3);

//boton para incrementar
 delay(15);
  if (estadobt2 == LOW){
    estadoanteriorbt2 = 0;
  }
  if (estadoanteriorbt2 == LOW && estadobt2 ==HIGH){
    contadordec++;
    if (contadordec == 4){
      contadordec = 0;
    }
    estadoanteriorbt2 = 1;
    delay(15);
  }
 

//boton para decrementar
  delay(15);
  if (estadobt3 == HIGH){
    estadoanteriorbt3 = 1;
  }
  if (estadoanteriorbt3 == HIGH && estadobt3 ==LOW){
    if (contadordec == 0) {
      contadordec = 3;
    }
    else{
      contadordec--;
    }
    
    estadoanteriorbt3 = 0;
    delay(15);
  }
  //casos según contador de decadas
switch (contadordec)
  {
  
  case 0:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    break;
  case 1:
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    break;
  case 2:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    break;
  case 3:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    break;
  
  
  
  }
  
}

//funcion para contador binario
void modobin(){
  int estadobt2 = digitalRead(bt2);
  int estadobt3 = digitalRead(bt3);
//boton para incrementar
 delay(15);
  if (estadobt2 == LOW){
    estadoanteriorbt2 = 0;
  }
  if (estadoanteriorbt2 == LOW && estadobt2 ==HIGH){
    contadorbin++;
    if (contadorbin == 16){
      contadorbin = 0;
    }
    estadoanteriorbt2 = 1;
    delay(15);
  }
 

//boton para decrementar
  delay(15);
  if (estadobt3 == HIGH){
    estadoanteriorbt3 = 1;
  }
  if (estadoanteriorbt3 == HIGH && estadobt3 ==LOW){
    if (contadorbin == 0) {
      contadorbin = 15;
    }
    else{
      contadorbin--;
    }
    
    estadoanteriorbt3 = 0;
    delay(15);
  }
  //casos según contador binario
switch (contadorbin)
  {
  case 0:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    break;
  case 1:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    break;
  case 2:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    break;
  case 3:
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    break;
  case 4:
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    break;
  case 5:
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    break;
  case 6:
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    break;
  case 7:
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    break;
  case 8:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    break;
  case 9:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    break;
  case 10:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    break;
  case 11:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    break;
  case 12:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    break;
  case 13:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    break;
  case 14:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    break;
  case 15:
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    break;
  }
}

//tipo de variables
void setup() {
  Serial.begin(115200);
  pinMode(bt1,INPUT);
  pinMode(bt2,INPUT);
  pinMode(bt3,INPUT_PULLDOWN);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
}

void loop() {
  int estadobt1 = digitalRead(bt1);
  //boton para cambio de modo
  delay(15);
  if (estadobt1 == HIGH){
    estadoanteriorbt1 = 1;
  }
  if (estadoanteriorbt1 == 1 && estadobt1 ==LOW){
    modo++;
    if (modo == 2){
      modo = 0;
    }
    estadoanteriorbt1 = 0;
    delay(15);
  }
  //casos segun modo
  switch (modo)
  {
  case 0:
    mododecada();
    break;
  case 1:
    modobin();
    break;
  }
  Serial.print(modo);



  
  
}

