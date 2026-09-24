#ifndef TELEMETRY_SEQUENCE_H
#define TELEMETRY_SEQUENCE_H

#include "telemetry_types.h"

typedef struct {
    uint32_t last_seq;
    bool initialized;
    uint32_t received;
    uint32_t lost;
} TelemetrySequenceState;

TelemetryStatus telemetry_sequence_check(
    TelemetrySequenceState *state,
    uint32_t seq
);

#endif
