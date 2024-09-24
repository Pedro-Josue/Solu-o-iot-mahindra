# Solução iot mahindra

## Visão Geral

Este projeto demonstra a implementação de uma solução de IoT (Internet das Coisas) utilizando dispositivos físicos, uma infraestrutura em nuvem baseada em contêineres Docker e o ecossistema FIWARE. A solução integra uma plataforma de hardware baseada em Arduino com um backend robusto para processar, armazenar e analisar dados em tempo real. Além disso, o projeto inclui um frontend interativo para visualização dos dados e interações com a plataforma Formula-E.

## Arquitetura Proposta

A arquitetura da solução está dividida em três camadas principais:

### 1. Camada IoT (Hardware)
- **Dispositivos:** Sensores e atuadores conectados a uma plataforma Arduino.
- **Comunicação:** Utilizando o protocolo MQTT para enviar dados dos sensores e receber comandos de controle para os atuadores.

### 2. Camada Backend (Nuvem)
- **Orquestração de Contêineres:** Utilização de Docker para isolar os serviços.
- **Plataforma FIWARE:** O backend é composto pelos seguintes componentes:
  - **Orion Context Broker:** Responsável pela gestão de dados de contexto IoT.
  - **STH-Comet:** Armazena e gerencia séries temporais dos dados enviados pelos dispositivos IoT.
  - **MongoDB:** Banco de dados utilizado para persistência de dados.
  - **IoT Agent MQTT:** Traduz os dados provenientes do protocolo MQTT para o formato compatível com o Orion.
  - **MQTT Broker (Mosquitto):** Facilita a comunicação entre os dispositivos IoT e o backend através do protocolo MQTT.

### 3. Camada Frontend (Interativo)
- **Site da Formula-E:** Interface web interativa que permite a visualização dos dados dos dispositivos IoT e das séries temporais, além de integrar quizzes e outras interações relacionadas à Formula-E.

### Diagrama de Arquitetura

![Diagrama da Arquitetura]![diagrama do iot](https://github.com/user-attachments/assets/7e55db3a-c2f7-4715-a1d1-5a219206c137)

## Recursos Necessários

### Hardware:
- **Plataforma Arduino** (com suporte a comunicação Wi-Fi ou via cabo).
- **Sensores MQTT:** Sensores para coleta de dados ambientais, como temperatura, umidade, etc.
- **Atuadores MQTT:** Dispositivos que podem ser controlados remotamente via MQTT.

### Backend:
- **Docker:** Para rodar os contêineres FIWARE, MongoDB e o broker MQTT.
- **FIWARE Orion Context Broker:** Para gerenciar e processar os dados IoT.
- **STH-Comet:** Para gerenciar séries temporais.
- **MongoDB:** Banco de dados para armazenamento.
- **IoT Agent MQTT:** Agente responsável pela conversão de dados MQTT.
- **MQTT Broker (Mosquitto):** Servidor para comunicação entre dispositivos IoT e o backend.
