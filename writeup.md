﻿﻿﻿[//]: # (Image References)
[image1]: ./results/Dataset_1.PNG
[image2]: ./results/Dataset_2.PNG﻿


# Unscented Kalman Filter
This is Project 4 of Udacity Self-Driving Car Nanodegree program. 
The goal of the project is to apply a PID Controller for steering a vehicle around the Simulator Track.

The project was created with the Udacity [Starter Code](https://github.com/udacity/CarND-PID-Control-Project).

## [Rubric](https://review.udacity.com/#!/rubrics/824/view) Points

## Content of this repo
- `scr` a directory with the project code:
  - `main.cpp`  reads in data, and applies the PID Controller
  - `PID.cpp`  initializes the PID parameters and calculates the PID output depending on the p-, d- i-errors
- `CMakeLists.txt`
- `README.md` Description of the Project by Udacity
- `writeup_template.md` for submission of this Project


##Result
The PID components lead to following vehicle beahvior:

  - p-Part: keeps the vehicle on straight tracks in the middle of the road , with an oscillation around the "target: cte=0"
  - i-Part: trims the vehicle on the "target: cte=0" and will help avoid oscillation around cte=0 on a straight track. On a curvy track the i-part tends to influence the steering bevhior negatively by gaining to much error on curves. A reset of the i-error (e.g. when cte is 0 again) would avoid the contribution of large gains created by permanent deviation. 
  - d-Part:  ist essential for steering action in sharp turns. The increase of cte compared to the last cte will lead to a large d-error output. This leads to a counteract reaction to keep the vehicle especially on sharp turns on the track.


Adaptations for better Performance:

```
if (cte>1){
    return Kp*p_error + Ki*i_error + cte*Kd*d_error;
  }
  else{
    return Kp*p_error + Ki*i_error + Kd*d_error;
  };
```
This feature helps to increase the PID performance on sharp turns by a weighted d-part with the acutal cte.

The final PID Parameters, manually tuned, are:
`p:-0.08  i:0  d:-0.45` 
















