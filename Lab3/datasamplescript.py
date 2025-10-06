import csv
import random
from datetime import datetime, timedelta


pressure_samples_random = [round(random.uniform(650, 1050), 5) for _ in range(500)]


sample_interval = 0.01  

with open('unfiltered_results.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)

    for i, sample in enumerate(pressure_samples_random):
        writer.writerow([sample])
