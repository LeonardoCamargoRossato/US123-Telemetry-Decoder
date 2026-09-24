#ifndef TELEMETRY_PIPELINE_H
#define TELEMETRY_PIPELINE_H

#include "telemetry_sequence.h"

typedef struct {
    TelemetrySequenceState sequence;
} TelemetryPipelineState;

typedef struct {
    TelemetryStatus status;
    const char *field;
} TelemetryProcessResult;

TelemetryProcessResult telemetry_process(
    const char *raw,
    TelemetryPipelineState *state,
    TelemetryPacket *output
);

#endif
