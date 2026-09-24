#ifndef TELEMETRY_PARSER_H
#define TELEMETRY_PARSER_H

#include "telemetry_types.h"

typedef struct {
    TelemetryStatus status;
    const char *field;
} TelemetryParseResult;

TelemetryParseResult telemetry_parse_json(
    const char *json,
    TelemetryPacket *packet
);

#endif
