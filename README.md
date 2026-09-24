# US123 — Telemetry Decoder
V0 acadêmica React/Vite/TypeScript para demonstrar Time 1 → processamento → Time 2.

## Executar
```bash
npm install
npm run dev
```

A simulação web lê 180 pacotes de `public/data/telemetry_mock.jsonl`, executa parser, validação de faixa e sequência em TypeScript e mostra o resultado. A pasta `public/c-algorithms` contém uma implementação C independente, com I/O UDP separado do core, preparada como referência para futura integração com SCADE/imported operators.

O projeto não afirma certificação ou validação pelo ANSYS SCADE.
