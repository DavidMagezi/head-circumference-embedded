# head circumference embedded

A neural network was trained to measure fetal [head-circumference](https://github.com/DavidMagezi/head-circumference) on ultrasound images, using pytorch on a PC. This can then be deployed on an embedded system using a different C++ machine-learning library (for example, see [embedded example](https://github.com/DavidMagezi/embedded_example)).


## Set up
See [setup](/setup) for details of installing libraries and downloading data set 

## Active Geometry Shape Model
To fit an ellipse, an [active geometry shape model](https:://doi.org/10.1016/j.cviu.2012.08.004), modified from the [github repository](https://github.com/wq2012/AGSM) shall be used. This approach is based on [gradient vector flow](https://www.iacl.ece.jhu.edu/static/gvc/).
