#include "telemetry_validator.h"

#define CHECK_RANGE(FIELD, MIN, MAX, NAME)                         \
    if ((FIELD) < (MIN) || (FIELD) > (MAX))                       \
        return (TelemetryValidationResult){                        \
            TELEMETRY_INVALID_RANGE, NAME, (double)(FIELD), MIN, MAX \
        }

TelemetryValidationResult telemetry_validate(const TelemetryPacket *packet) {
    if (!packet || !packet->sat_id[0])
        return (TelemetryValidationResult){
            TELEMETRY_MISSING_FIELD, "sat_id", 0, 0, 0
        };

    CHECK_RANGE(packet->pos.lat, -90, 90, "pos.lat");
    CHECK_RANGE(packet->pos.lon, -180, 180, "pos.lon");
    CHECK_RANGE(packet->pos.alt_km, 0, 100000, "pos.alt_km");
    CHECK_RANGE(packet->pos.vel_kms, 0, 20, "pos.vel_kms");
    CHECK_RANGE(packet->pos.gnss_sats, 0, 64, "pos.gnss_sats");
    CHECK_RANGE(packet->pos.pdop, 0, 100, "pos.pdop");
    CHECK_RANGE(packet->eps.bus_v, 0, 20, "eps.bus_v");
    CHECK_RANGE(packet->eps.bat_soc, 0, 100, "eps.bat_soc");
    CHECK_RANGE(packet->eps.bat_t, -100, 150, "eps.bat_t");
    CHECK_RANGE(packet->eps.solar_w, 0, 1000, "eps.solar_w");
    CHECK_RANGE(packet->obc.cpu, 0, 100, "obc.cpu");
    CHECK_RANGE(packet->comm.rssi_dbm, -200, 0, "comm.rssi_dbm");
    CHECK_RANGE(packet->comm.snr_db, -50, 100, "comm.snr_db");

    return (TelemetryValidationResult){TELEMETRY_OK, 0, 0, 0, 0};
}
