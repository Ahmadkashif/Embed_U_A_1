Steps to initialize GPIO:
1. Enable clock for the port and wait for its stabilizing
2. Unlock port (needed only for PD7 and PF0)
3. Enable digital function of the pins
4. Disable analog function of the pin (by default disabled,
so we can skip this step)
5. Disable alternate function of port (by default disabled,
so we can skip this step)
6. Clear PCTL register to select regular digital I/O (by
default cleared, so we can skip this step)
7. Set direction of pin
8. Enable changes to digital port
9. Enable/disable Pullup/PullDown resistor