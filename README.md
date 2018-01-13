# PID_controler
Implementation of a PID controller in C++

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

## Reflection
#### Effect of the P, I, D component of the PID algorithm

- Componenent **P** (**P**roportional): This component is used to steer the car to the center line. The problem of using this parameter alone is to overshoot the line and potentialy leave the road. 

- Component **I** (**I**ntegral): This component is used to remove a potential bias induced by the front wheels, if they are not well aligned for example. This problem is called systematic bias. In our case, the car on the similator doesn't have any bias. Used alone, the car is goes in circle.

- Component **D*** (**D**ifferencial): This component is used to compensate the P parameter. It helps to do a smoother approach the the center line.

#### Choose the right parameters

I tried to program  the twiddle algorithm to fine tune the parameter, but it didn't work well. So, I finally tune the parameters manually by adding or substracting 1 to `P` and `D` regarding the `CTE` values.
