#include <log4c.h>

int main(int argc, char* argv[])
{
    LOG4C_Init(".", "main", LOG4C_FLAG_DEFAULT);
    LOG4C_SetLevel(LOG4C_INFO);

    LOG4P("[TEST] This is print message.");
    LOG4E("[TEST] This is error message.");
    LOG4W("[TEST] This is warn message.");
    LOG4I("[TEST] This is info message.");
    LOG4D("[TEST] This is debug message.");

    LOG4C_Term();
}