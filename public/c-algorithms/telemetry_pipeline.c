#include "telemetry_pipeline.h"

#include "telemetry_parser.h"
#include "telemetry_validator.h"

TelemetryProcessResult telemetry_process(
    const char *raw,
    TelemetryPipelineState *state,
    TelemetryPacket *output
) {
    TelemetryParseResult parsed = telemetry_parse_json(raw, output);
    if (parsed.status != TELEMETRY_OK)
        return (TelemetryProcessResult){parsed.status, parsed.field};

    TelemetryValidationResult validated = telemetry_validate(output);
    if (validated.status != TELEMETRY_OK)
        return (TelemetryProcessResult){validated.status, validated.field};

    TelemetryStatus sequence_status = telemetry_sequence_check(
        &state->sequence,
        output->seq
    );

    return (TelemetryProcessResult){
        sequence_status,
        sequence_status == TELEMETRY_OK ? 0 : "seq"
    };
}
