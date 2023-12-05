/*********************************************************
  Exemplo para demonstrar o uso de software timer
*********************************************************/
/*inclusão das Biblioteca do FreeRTOS*/
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

//Define as constantes dos pinos do LED e Botão
#define LED1 2 //azul
#define LED2 4 //vermelho
#define BT 18

/*
Declara os manipuladores das tarefas e dos timers
Declara as funções da tarefa 1 e funções callback dos timers
*/
TaskHandle_t xTask1;
TimerHandle_t xTimer1, xTimer2;
void vTask1(void *pvParametes);
void callBackTimer1(TimerHandle_t xTimer);
void callBackTimer2(TimerHandle_t xTimer);

void setup()
{
  Serial.begin(9600);
  //Configura os pinos dos LEDs como saida e o botão como entrada
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BT, INPUT_PULLUP);
  //Cria as tasks e os timers
  //e inicia o timer1
  xTimer1 = xTimerCreate("TIMER1", pdMS_TO_TICKS(1000), pdTRUE, 0, callBackTimer1); //timer periódico
  xTimer2 = xTimerCreate("TIMER2", pdMS_TO_TICKS(10000), pdFALSE, 0, callBackTimer2); //timer one-shot
  xTaskCreate(vTask1, "TASK1", configMINIMAL_STACK_SIZE + 1024, NULL, 1, &xTask1);
  xTimerStart(xTimer1, 0);
}

void loop()
{
  vTaskDelay(pdMS_TO_TICKS(1000));
}

void vTask1(void *pvParametes)
{
  uint8_t debouncingTime = 0;
  while (1)
  {
    //Verifica se o botao foi pressionado
    //com uma logica simples de debouncing
    if ((digitalRead(BT) == LOW) && (xTimerIsTimerActive( xTimer2 ) == pdFALSE))
    {
      //Se o botão foi pressionado
      //Inicia o timer2 e para o timer1
      //tambem acende o LED vermelho e apaga o LED azul
      debouncingTime++;
      if (debouncingTime >= 10) {
        debouncingTime = 0;
        xTimerStart(xTimer2, 0);
        digitalWrite(LED2, HIGH);
        Serial.println("Iniciando o Timer 2 ...");
        xTimerStop(xTimer1, 0);
        digitalWrite(LED1, LOW);
        Serial.println("Desligando o Timer 1 ...");
      }
    }
    else
    {
      debouncingTime = 0;
    }
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}

//Chamada a cada execucao do timer1 (periodico)
void callBackTimer1(TimerHandle_t xTimer)
{
  //Inverte o valor do LED azul
  digitalWrite(LED1, !digitalRead(LED1));
}

//One shoot
void callBackTimer2(TimerHandle_t xTimer)
{
  //Apaga o LED vermelho
  //e inicia novamente o timer1
  digitalWrite(LED2, LOW);
  xTimerStart(xTimer1, 0);
  Serial.println("Ligando o Timer 1 ...");
}