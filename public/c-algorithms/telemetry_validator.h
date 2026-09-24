#ifndef TELEMETRY_VALIDATOR_H
#define TELEMETRY_VALIDATOR_H

#include "telemetry_types.h"

typedef struct {
    TelemetryStatus status;
    const char *field;
    double value;
    double min;
    double max;
} TelemetryValidationResult;

TelemetryValidationResult telemetry_validate(const TelemetryPacket *packet);

#endif
