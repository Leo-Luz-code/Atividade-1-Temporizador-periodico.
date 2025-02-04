# Atividade 1: Temporizador Periódico (Semáforo)

Este projeto implementa um semáforo utilizando a função `add_repeating_timer_ms()` do Pico SDK. O sistema alterna entre os LEDs vermelho, amarelo e verde a cada 3 segundos, simulando o funcionamento de um semáforo real.

## Componentes Utilizados
1. Microcontrolador Raspberry Pi Pico W
2. 03 LEDs (vermelho, amarelo e verde)
3. 03 Resistores de 330 Ω

## Funcionamento
- O semáforo inicia no LED vermelho.
- A cada 3 segundos, a cor do semáforo muda na sequência: Vermelho → Amarelo → Verde → Vermelho.
- A mudança de estado dos LEDs é realizada dentro da função de callback do temporizador.
- A cada segundo, uma mensagem é impressa na porta serial para monitoramento.
- Foi utilizado o ambiente BitDogLab para experimentação com o LED RGB nos GPIOs 11, 12 e 13.

## Requisitos Atendidos
1. O acionamento dos LEDs inicia na cor vermelha, seguindo a ordem correta.
2. O temporizador foi ajustado para um atraso de 3 segundos.
3. A função de callback `repeating_timer_callback()` gerencia a mudança de estado dos LEDs.
4. A estrutura de repetição `while` imprime mensagens a cada segundo para depuração.
5. O experimento foi testado com a Ferramenta BitDogLab.

## Como Compilar e Executar
1. Clone ou baixe este repositório.
2. Configure o ambiente de desenvolvimento do Raspberry Pi Pico W com CMake e o SDK.
3. Compile o código usando os seguintes comandos (ou a extensão do VS Code do Raspberry Pi Pico):
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```
4. Carregue o arquivo `.uf2` gerado no Raspberry Pi Pico W.
5. Utilize o terminal serial do VS Code para visualizar as mensagens de depuração.

## Testes e Validação
- Teste da sequência correta de iluminação dos LEDs.
- Teste do tempo de troca entre os estados (3 segundos).
- Teste de impressão de mensagens na porta serial.
- Teste de execução no BitDogLab.

## Autor
Leonardo Luz - Aluno do Embarcatech

