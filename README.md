Simple "blink leds" programs for various development boards. These
are used for testing of pico]OS, but can also be used as programming examples.

Test system starts a few threads. Each threads blinks a led.
System also tests semaphores and thread priorities (a low priority
threads runs in tight loop for a while and is interrupted
by higher priority thread as necessary).

For supported boards, see readme in each subdirectory.

To get this stuff compiled, you need:

- compiler toolchain
- gnu make (windows users can use MSYS or msysGit)
- other libraries (unpacked/cloned at same level as this one, not inside this module):
  - picoos
  - picoos-micro
  - cmsis-ports (for Arm Cortex-M targets)

