#include "telemetry_sequence.h"

TelemetryStatus telemetry_sequence_check(
    TelemetrySequenceState *state,
    uint32_t seq
) {
    state->received++;

    if (!state->initialized) {
        state->initialized = true;
        state->last_seq = seq;
        return TELEMETRY_OK;
    }

    if (seq == state->last_seq)
        return TELEMETRY_DUPLICATE_PACKET;

    if (seq > state->last_seq + 1) {
        state->lost += seq - state->last_seq - 1;
        state->last_seq = seq;
        return TELEMETRY_SEQUENCE_GAP;
    }

    state->last_seq = seq;
    return TELEMETRY_OK;
}
