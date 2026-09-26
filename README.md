# US123 — Telemetry Decoder

Demonstrador acadêmico desenvolvido para a **Sprint 1 da CE-235 — Sistemas de Tempo Real**, no contexto do **Projeto SPRB-TR/BD — Time 2 (Segmento Ground)**.

O projeto implementa uma prova de conceito para o fluxo **Time 1 → recepção da telemetria → parsing → validação → visualização → Time 2**, apoiando a atividade da US123 relacionada ao estudo e tratamento dos dados recebidos.

## Visão geral

A aplicação foi construída em **React + Vite + TypeScript** e utiliza um conjunto de **180 pacotes simulados** armazenados em `public/data/telemetry_mock.jsonl`.

O demonstrador:

- lê os pacotes simulados de telemetria;
- executa parsing dos dados;
- verifica sequência e faixas esperadas;
- apresenta os resultados para inspeção;
- mantém uma implementação C independente em `public/c-algorithms`;
- separa a camada de I/O UDP do núcleo de processamento, servindo como referência para futura integração com **ANSYS SCADE / imported operators**.

> Este projeto é um demonstrador acadêmico e não afirma certificação ou validação pelo ANSYS SCADE.

## Projeto acadêmico

Esta implementação está documentada como uma subsprint da **US123** no repositório oficial do Projeto SPRB-TR/BD.

- **Issue / Subsprint #70:** https://github.com/Projeto-SPRB-TR-BD/Projeto-SPRB-TR-BD/issues/70
- **US123 principal #41:** https://github.com/Projeto-SPRB-TR-BD/Projeto-SPRB-TR-BD/issues/41
- **Sprint 1 — documentação:** https://leonardocamargorossato.github.io/CE235-Sistemas-Tempo-Real/#/sprint1
- **Portal CE-235:** https://leonardocamargorossato.github.io/CE235-Sistemas-Tempo-Real/

## Aplicação publicada

**Telemetry Decoder:**  
https://leonardocamargorossato.github.io/US123-Telemetry-Decoder/

## Executar localmente

```bash
npm install
npm run dev
```

## Tecnologias

- React
- Vite
- TypeScript
- C
- GitHub Pages
- Git/GitHub

## Repositórios e navegação

- **Este repositório — Telemetry Decoder:** https://github.com/LeonardoCamargoRossato/US123-Telemetry-Decoder
- **Portal CE-235 — código-fonte:** https://github.com/LeonardoCamargoRossato/CE235-Sistemas-Tempo-Real
- **Issue oficial / Subsprint #70:** https://github.com/Projeto-SPRB-TR-BD/Projeto-SPRB-TR-BD/issues/70

## Autor

**Leonardo Camargo Rossato**  
Arquiteto de Soluções · Doutorando no ITA

Para conhecer meus outros projetos, pesquisa e atuação profissional:

**Site pessoal / Portfólio:**  
https://leonardocamargorossato.github.io/LCR-SolutionsArchitecture-IA-Quantum/#/
