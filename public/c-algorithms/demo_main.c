#include <stdio.h>
#include <string.h>

#include "telemetry_pipeline.h"
#include "udp_receiver.h"

int main(void) {
    char buffer[4096];
    TelemetryPipelineState state;
    TelemetryPacket packet;

    memset(&state, 0, sizeof(state));

    if (udp_receiver_init(5005)) {
        puts("UDP init failed");
        return 1;
    }

    puts("Listening on 127.0.0.1:5005");

    for (;;) {
        int received = udp_receiver_read(buffer, sizeof(buffer));
        if (received <= 0)
            continue;

        TelemetryProcessResult result = telemetry_process(
            buffer,
            &state,
            &packet
        );

        printf(
            "\nRAW PACKET RECEIVED\nSEQ: %u\nPARSING/VALIDATION: %s\n",
            packet.seq,
            result.status == TELEMETRY_OK ? "OK" : "REJECTED"
        );

        if (result.status == TELEMETRY_OK) {
            printf(
                "PACKET VALID\n%s\nlat: %.4f\nlon: %.4f\n"
                "alt: %.3f km\nvel: %.3f km/s\n",
                packet.sat_id,
                packet.pos.lat,
                packet.pos.lon,
                packet.pos.alt_km,
                packet.pos.vel_kms
            );
        } else {
            printf(
                "status=%d field=%s\n",
                (int)result.status,
                result.field ? result.field : "-"
            );
        }
    }

    udp_receiver_close();
    return 0;
}
