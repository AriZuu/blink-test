Simple "blink leds" programs for various development boards. These
are used for testing of pico]OS, but can also be used as programming examples.

Test system starts a few threads. Each threads blinks a led.
System also tests semaphores and thread priorities (a low priority
threads runs in tight loop for a while and is interrupted
by higher priority thread as necessary).

For supported boards, see readme in each subdirectory.
