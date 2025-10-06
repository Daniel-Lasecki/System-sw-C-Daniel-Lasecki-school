import pandas as pd
import matplotlib.pyplot as plt

#load unfiltered data
unfiltered_df = pd.read_csv('./unfiltered_results.csv', header=None)
unfiltered_pressure = unfiltered_df[0].values

# Load filtered data
filtered_df_lowpass = pd.read_csv('./filtered_results_lowpass.csv', header=None)
filtered_pressure_lowpass = filtered_df_lowpass[0].values 

filtered_df_highpass = pd.read_csv('./filtered_results_highpass.csv', header=None)
filtered_pressure_highpass = filtered_df_highpass[0].values 

filtere_df_bandpass = pd.read_csv('./filtered_results_bandpass.csv', header=None)
filtered_pressure_bandpass = filtere_df_bandpass[0].values

filtere_df_bandstop = pd.read_csv('./filtered_results_bandstop.csv', header=None)
filtered_pressure_bandstop = filtere_df_bandstop[0].values




plt.figure(figsize=(10, 8))
plt.plot(unfiltered_pressure[0:100], label="Raw data", color='blue')
plt.plot(filtered_pressure_lowpass[0:100], label="lowpass fir", color='orange')
plt.plot(filtered_pressure_highpass[0:100], label="highpass fir", color='green')
plt.plot(filtered_pressure_bandpass[0:100], label="bandpass fir", color='red')
plt.plot(filtered_pressure_bandstop[0:100], label="bandstop fir", color='purple')
plt.xlabel("Näyte")
plt.ylabel("Arvo")
plt.title("Raw vs Filtered pressure samples")
plt.legend()
plt.grid(True)
plt.show()
