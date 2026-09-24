#include "telemetry_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *find_key(const char *json, const char *key) {
    char pattern[64];
    snprintf(pattern, sizeof(pattern), "\"%s\"", key);
    return strstr(json, pattern);
}

static int extract_number(
    const char *json,
    const char *key,
    double *output
) {
    const char *cursor = find_key(json, key);
    char *end;

    if (!cursor) return 0;
    cursor = strchr(cursor, ':');
    if (!cursor) return -1;

    cursor++;
    *output = strtod(cursor, &end);
    return end == cursor ? -1 : 1;
}

static int extract_string(
    const char *json,
    const char *key,
    char *output,
    size_t output_size
) {
    const char *cursor = find_key(json, key);
    const char *start;
    const char *end;
    size_t length;

    if (!cursor) return 0;
    cursor = strchr(cursor, ':');
    if (!cursor) return -1;

    start = strchr(cursor, '"');
    if (!start) return -1;
    end = strchr(start + 1, '"');
    if (!end) return -1;

    length = (size_t)(end - start - 1);
    if (length >= output_size) length = output_size - 1;
    memcpy(output, start + 1, length);
    output[length] = '\0';
    return 1;
}

#define EXTRACT_NUMBER(KEY, DESTINATION, FIELD)                         \
    do {                                                                \
        double value;                                                   \
        int result = extract_number(json, KEY, &value);                \
        if (result == 0)                                                \
            return (TelemetryParseResult){TELEMETRY_MISSING_FIELD, KEY};\
        if (result < 0)                                                 \
            return (TelemetryParseResult){TELEMETRY_INVALID_TYPE, KEY}; \
        DESTINATION.FIELD = value;                                      \
    } while (0)

TelemetryParseResult telemetry_parse_json(
    const char *json,
    TelemetryPacket *packet
) {
    double value;
    int result;

    if (!json || !packet)
        return (TelemetryParseResult){TELEMETRY_PARSE_ERROR, "json"};

    memset(packet, 0, sizeof(*packet));

    if (extract_string(json, "sat_id", packet->sat_id, sizeof(packet->sat_id)) <= 0)
        return (TelemetryParseResult){TELEMETRY_MISSING_FIELD, "sat_id"};
    if (extract_string(json, "ts_utc", packet->timestamp, sizeof(packet->timestamp)) <= 0)
        return (TelemetryParseResult){TELEMETRY_MISSING_FIELD, "ts_utc"};
    if (extract_string(json, "mode", packet->mode, sizeof(packet->mode)) <= 0)
        return (TelemetryParseResult){TELEMETRY_MISSING_FIELD, "mode"};

    result = extract_number(json, "seq", &value);
    if (result <= 0)
        return (TelemetryParseResult){
            result ? TELEMETRY_INVALID_TYPE : TELEMETRY_MISSING_FIELD,
            "seq"
        };
    packet->seq = (uint32_t)value;

    EXTRACT_NUMBER("lat", packet->pos, lat);
    EXTRACT_NUMBER("lon", packet->pos, lon);
    EXTRACT_NUMBER("alt_km", packet->pos, alt_km);
    EXTRACT_NUMBER("vel_kms", packet->pos, vel_kms);
    EXTRACT_NUMBER("pdop", packet->pos, pdop);

    extract_number(json, "gnss_sats", &value);
    packet->pos.gnss_sats = (uint8_t)value;

    EXTRACT_NUMBER("bus_v", packet->eps, bus_v);
    extract_number(json, "bat_soc", &value);
    packet->eps.bat_soc = (uint8_t)value;
    EXTRACT_NUMBER("bat_t", packet->eps, bat_t);
    EXTRACT_NUMBER("solar_w", packet->eps, solar_w);

    extract_number(json, "cpu", &value);
    packet->obc.cpu = (uint8_t)value;
    extract_number(json, "resets", &value);
    packet->obc.resets = (uint16_t)value;
    extract_string(json, "fw", packet->obc.fw, sizeof(packet->obc.fw));

    extract_number(json, "rssi_dbm", &value);
    packet->comm.rssi_dbm = (int16_t)value;
    EXTRACT_NUMBER("snr_db", packet->comm, snr_db);

    return (TelemetryParseResult){TELEMETRY_OK, 0};
}
