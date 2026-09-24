#ifndef TELEMETRY_TYPES_H
#define TELEMETRY_TYPES_H

#include <stdbool.h>
#include <stdint.h>

#define SAT_ID_SIZE 16
#define MODE_SIZE 16
#define FW_SIZE 16

typedef struct {
    double lat;
    double lon;
    double alt_km;
    double vel_kms;
    uint8_t gnss_sats;
    double pdop;
} TelemetryPosition;

typedef struct {
    double bus_v;
    uint8_t bat_soc;
    double bat_t;
    double solar_w;
} TelemetryEPS;

typedef struct {
    double q[4];
    double rate_dps[3];
} TelemetryADCS;

typedef struct {
    uint8_t cpu;
    uint16_t resets;
    char fw[FW_SIZE];
} TelemetryOBC;

typedef struct {
    int16_t rssi_dbm;
    double snr_db;
} TelemetryComm;

typedef struct {
    char sat_id[SAT_ID_SIZE];
    uint32_t seq;
    char timestamp[32];
    char mode[MODE_SIZE];
    TelemetryPosition pos;
    TelemetryEPS eps;
    TelemetryADCS adcs;
    TelemetryOBC obc;
    TelemetryComm comm;
} TelemetryPacket;

typedef enum {
    TELEMETRY_OK = 0,
    TELEMETRY_PARSE_ERROR,
    TELEMETRY_MISSING_FIELD,
    TELEMETRY_INVALID_TYPE,
    TELEMETRY_INVALID_RANGE,
    TELEMETRY_SEQUENCE_GAP,
    TELEMETRY_DUPLICATE_PACKET
} TelemetryStatus;

#endif
