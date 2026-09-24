# US123 C Algorithms
Core em C99/C11 com buffers fixos e sem alocação dinâmica. `udp_receiver.c` isola I/O Winsock2 do parsing/validação.

## Windows / MinGW
`gcc -std=c11 demo_main.c telemetry_parser.c telemetry_validator.c telemetry_sequence.c telemetry_pipeline.c udp_receiver.c -lws2_32 -o us123_demo.exe`

O parser é deliberadamente específico ao schema da V0 e serve como referência acadêmica; não implica certificação SCADE.
