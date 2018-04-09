### PID
* Proportional - This term tries to adjust the steering angle back to
the center of the lane.
* Integral - This term is to try to adjust for systematic bias,
things such as steering drift due to wheel alignment.
* Derivative - This term is to dampen the oscillation due to the
proportional part. When we are already counter-steering to come
back to the center of the lane, we want to reduce the amount of
counter-steer if the cte is now smaller in comparison to what it
was before.

### Hyperparameter tuning
```
PID(double Kp = 0.2, double Ki = 0.004, double Kd = 3.0);
```
Started with the default parameters from the lecture above and
tuned manually.

Mostly adjusted Kd which is the derivative portion. This is to
smooth out the oscillations from the proportional part. Ki is
relatively unchanged and small since we don't have much bias/drift
in the simulator it seems. The turns are relatively wide and so it
also seems that we don't need to change Kp much which controls
how quickly we oscillate. In this case I tended to favor a wide
turn for smoothness.

Ended with:
```
PID(double Kp = 0.12, double Ki = 0.0, double Kd = 3.5);
```
