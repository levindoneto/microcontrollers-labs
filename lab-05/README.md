# LAB 05 | INTERRUPTIONS

## Theory

The interruptions on the Galileo Gen2 can be generated in the rising and falling edges individually or together The pins *IO2* and *IO3* have two GPIO pins attached to them **in order to enable interruptions in both signal edges**.

The use of the functions as `system()` and `popen()` instead of the usual ones of I/O on C*C++ are not recommended, once each execution of them implies a use of a `fork()` and a new shell instance.

## How to enable an interruption

** Pseudofile: **
`/sys/class/gpio/gpioXX/edge`,

where *edge* can be:

-  "rising".
-  "falling".
-  "both".
-  "none.

Once the interruption is enabled, it can be received by a program withing the user's workspace by a **polling** on the file `/sys/class/gpio/gpioXX/value` with the use of the function `poll()` for awaiting a event **POLLPRI**.

## Experiments


