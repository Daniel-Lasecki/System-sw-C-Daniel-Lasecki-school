# LAB3


Tip: the **most** important tip of all: Read through the whole lab instruction before starting the work.
## Introduction

In this lab exercise you will implement a digital filter, which calculates moving average (MA) of the incoming data stream. For definition of MA, see: 

https://en.wikipedia.org/wiki/Moving_average

As you can see, in the MA-filter, you are multiplying each data point with the same **coefficient**, 1/k, where k is the length of the filter.

![MA](images/MA.png)

For example, if you want to calculate the average of 5 data points, you divide each data point (1-5) value by 5 (=  multiply by 1/5) and then sum them all together. Moving average means that on a next round you will compute the same for data points 2-6 and so on. As a result, you will get a "smoothed" version of the original signal, meaning that sharp changes (=high frequency components) are filtered out and instead a signal with slow changes (low frequencies components) are passed. Thus, the term **low-pass filter (LPF)**.

The structure of such a compute engine (filter) can be depicted like below:

![FIR](images/FIR.png)
*A direct form discrete-time **FIR filter** of order _N_. The top part is an _N_-stage delay line with _N_ + 1 taps. Each unit delay is a _z_−1 operator in [Z-transform](https://en.wikipedia.org/wiki/Z-transform "Z-transform") notation.*

Source: https://en.wikipedia.org/wiki/Finite_impulse_response

If the coefficient b is same (1/N) for all "taps", we have a moving average filter. If it varies, we have a different filter, which can be low-pass, high-pass, band-pass, band-stop, etc. The mathematics behind different filter implementations is not in the scope of this course, but you can still design those using online tools, like:

[TFilter - Free online FIR filter design (engineerjs.com)](http://t-filter.engineerjs.com/)

![Tfilter](images/Tfilter.png)

Note that you can have the coefficients nicely as an array, just save those in a suitable header file (like coeffs-h) and use them in your filter. You can also find a ready made C-implementation of the filter under "Source Code"-tab. Use it if you want, but make sure that you understand what is happening there. If that seems to be too complex, design the filter yourself, you will learn much more.

Also, as a student of TUAS, you have access to MATLAB, which **The Too**l for digital signal processing (DSP).  You can run MATLAB online on your web browser.

[How Is a Moving Average Filter Different from an FIR Filter? - MATLAB & Simulink - MathWorks Nordic](https://se.mathworks.com/help/dsp/ug/how-is-moving-average-filter-different-from-an-fir-filter.html)




## The specs

We want to create an application, which reads in the data from csv-file (comma separated values) and writes it out to another .csv-file after applying out digital filter to it.  Illustrate the operation of your filter by plotting the original and filtered data with excel (or use some python-code or MATLAB - as long as you provide a graphical presentation of the outcome.)

Filter type:

- Step 1: MA(x)
- Step 2: A lowpass/high pass/bandpass/bandstop based on your own parameters
			

Number of taps (=x): 
- 2 last numbers of your student number
- in case of 0x -> swap the numbers -> x0

Input data lenght:
- 500 samples (or more)

Input data type:
- You can decide your self! It can be for example:
	- stock value of NOK1V
	- Temperature of Turku during this year, with one hour resolution
	- Even an audio file (in raw wave-format!), adjust the filter lenght/ sample lenght then accordingly and provide means to playback the sound before and after filtering. MATLAB can do that easily.
- TIP: You can use artificial data.... 
	 ![GPT](images/GPT.png)
	
From where to get the data to the filter?
- From the file, which contains the data you have created/captured earlier.
	- Step 1: you can use fixed file name in your source code (like my_data.csv)
	- Step 2: user is asked to enter it (scanf function to read user input)
	- Step 3: take it from command line arguments (see argc, argv, parsing command line parameters)

- When using file operations, have a look at POSIX file library (for C)
	
Where to save the data?
- To the file
	- Step 1: you can use fixed file name
	- Step 2: user is asked to enter it (scanf function)
	- Step 3: take it from command line arguments (see argc, argv)


**Tip:** start with step 1 and move on until the "whole" program works, then start to work on more features. Hopefully you were reading the first tip.

## Returning the lab

Commit your solution to git, just the code. 

Keep the graphical illustration and be prepared to show it to teacher.
