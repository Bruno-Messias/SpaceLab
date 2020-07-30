#include "CppUTestExt/MockSupport_c.h"
#include "mock_ttc_interface.h"

void
mock_ttc_initialize (void)
{
    mock_c()->actualCall ("initialize_ttc");
}

mock_ttc_transmitter(int *packet_buf)
{
    mock_c()->actualCall ("transmiter_ttc");    
            ///->withIntParameters("packet_buf", *packet_buf); // ! Error
}

