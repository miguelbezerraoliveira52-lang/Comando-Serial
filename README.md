# Prática 1A — Comando Serial

Projeto desenvolvido para a disciplina de **Fundamentos de Sistemas Ciberfísicos**, utilizando **ESP32**, **Arduino IDE** e **Wokwi**.

## Sobre o projeto

O projeto demonstra o controle de um LED através do **Monitor Serial**. O ESP32 recebe um comando enviado pelo usuário, interpreta a instrução e altera o estado do LED.

## Comandos

| Comando | Função                         |
| ------- | ------------------------------ |
| `A`     | Liga o LED                     |
| `B`     | Faz o LED piscar continuamente |
| `C`     | Desliga o LED                  |

## Circuito

* ESP32 DevKitC
* LED
* Resistor de 220 Ω
* GPIO 2

### Conexões

* GPIO 2 → ânodo (+) do LED
* Cátodo (-) → resistor de 220 Ω → GND

## Comunicação Serial

A comunicação é configurada em:

```text
115200 baud
```

## Funcionamento

O programa recebe uma letra pelo Monitor Serial, identifica o comando e executa a ação correspondente no LED. Durante a piscada, o programa continua aceitando novos comandos.

## Tecnologias utilizadas

* C++
* Arduino IDE
* ESP32
* Wokwi
