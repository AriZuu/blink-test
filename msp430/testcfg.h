#if defined(_REL) || defined(SMALL_STACK)
#define MAIN_STACK_SIZE 96
#define IDLE_STACK_SIZE 38
#define TEST_STACK_SIZE 50
#else
#define MAIN_STACK_SIZE	150
#define IDLE_STACK_SIZE 50
#define TEST_STACK_SIZE 110
#endif
