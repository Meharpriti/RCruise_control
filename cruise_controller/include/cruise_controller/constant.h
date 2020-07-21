#include <stdint.h>
#include <unordered_map>
#include <functional>
namespace cruise_controller
{
    static constexpr  char kEmittedVelocity[]{"velocity"};
    static constexpr  char kConsumeRosbag[]{"datatopic"};
    static constexpr  char kEmittedDynamics[]{"vehicledynamics"};
    static constexpr  char kTriggerStatus[]{"trigger"};
    static constexpr int publisher_queue_size{1};
    static constexpr int subscriber_queue_size{1};
    static constexpr  char InputFilePath[]{"/home/abc/dev_ws/src/cruise_controller/InputData/Vehicle_parameter.csv"};
    typedef enum status_t_
    {
        ON,
        OFF,
        SET_INC,
        SET_DEC,
        BREAK,
        CLUTCH
    }status_t;
}

