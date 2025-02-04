#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/time.h"

// Definição dos GPIOs para os LEDs
#define RED_PIN 11    // Led vermelho
#define YELLOW_PIN 12 // Led amarelo
#define GREEN_PIN 13  // Led verde

// Armazenando o estado do led em uma variável (vermelho = 0, amarelo = 1, verde = 2)
int led_state = 0;

// Função para inicializar todos os leds
void initialize_all_leds()
{
    gpio_init(RED_PIN);
    gpio_set_dir(RED_PIN, GPIO_OUT);
    gpio_init(YELLOW_PIN);
    gpio_set_dir(YELLOW_PIN, GPIO_OUT);
    gpio_init(GREEN_PIN);
    gpio_set_dir(GREEN_PIN, GPIO_OUT);
}

// Função para desligar todos os LEDs
void turn_off_leds()
{
    gpio_put(RED_PIN, 0);
    gpio_put(YELLOW_PIN, 0);
    gpio_put(GREEN_PIN, 0);
}

// Função de callback para o temporizador periódico
bool repeating_timer_callback(struct repeating_timer *t)
{
    turn_off_leds(); // Desliga os LEDs

    // Atualiza o estado do semáforo
    switch (led_state)
    {
    case 0:
        gpio_put(RED_PIN, 1);
        led_state = 1;
        break;
    case 1:
        gpio_put(YELLOW_PIN, 1);
        led_state = 2;
        break;
    default:
        gpio_put(GREEN_PIN, 1);
        led_state = 0;
        break;
    }

    return true; // Mantém o temporizador ativo
}

int main()
{
    stdio_init_all();

    while (true)
    {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
