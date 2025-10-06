import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Load raw data
raw_df = pd.read_csv('./unfiltered_results.csv', header=None)
raw_pressure = raw_df[0].values
raw_mean = np.mean(raw_pressure)

# Load filtered data
lowpass = pd.read_csv('./filtered_results_lowpass.csv', header=None)[0].values
highpass = pd.read_csv('./filtered_results_highpass.csv', header=None)[0].values
bandpass = pd.read_csv('./filtered_results_bandpass.csv', header=None)[0].values
bandstop = pd.read_csv('./filtered_results_bandstop.csv', header=None)[0].values

# Shift all filters by raw mean for visual comparison
lowpass_shifted = lowpass + raw_mean
highpass_shifted = highpass + raw_mean
bandpass_shifted = bandpass + raw_mean
bandstop_shifted = bandstop + raw_mean

plt.figure(figsize=(12, 8))
plt.plot(raw_pressure[0:135], label="Raw data", color='blue', linewidth=1.5)
plt.plot(lowpass_shifted[0:135], label="Lowpass FIR (shifted)", color='orange', linewidth=1.5)
plt.plot(highpass_shifted[0:135], label="Highpass FIR (shifted)", color='green', linewidth=1.5)
plt.plot(bandpass_shifted[0:135], label="Bandpass FIR (shifted)", color='red', linewidth=1.5)
plt.plot(bandstop_shifted[0:135], label="Bandstop FIR (shifted)", color='purple', linewidth=1.5)


def show_label():
    plt.xlabel("Sample index")
    plt.ylabel("Pressure value")
    plt.title("Raw vs Filtered Pressure Samples (shifted for comparison)")
    plt.legend()
    plt.grid(True)
    plt.show()

plt.figure(figsize=(12, 8))
plt.plot(raw_pressure[0:135], label="Raw data", color='blue', linewidth=1.5)
plt.plot(lowpass[0:135], label="Lowpass FIR ", color='orange', linewidth=1.5)
plt.plot(highpass[0:135], label="Highpass FIR ", color='green', linewidth=1.5)
plt.plot(bandpass[0:135], label="Bandpass FIR ", color='red', linewidth=1.5)
plt.plot(bandstop[0:135], label="Bandstop FIR ", color='purple', linewidth=1.5)

def show_label2():
    plt.xlabel("Sample index")
    plt.ylabel("Pressure value")
    plt.title("Raw vs Filtered Pressure Samples ")
    plt.legend()
    plt.grid(True)
    plt.show()



if __name__ == "__main__":
    show_label()
    show_label2()