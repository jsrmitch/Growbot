#include <wiringPi.h>
#include "ActuatorService.grpc.pb.h"

int main()
{
    wiringPiSetup();
    Actuators::Service service();
    return 0;
}
