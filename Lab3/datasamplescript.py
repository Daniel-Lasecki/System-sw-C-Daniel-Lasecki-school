import csv
import random


pressure_samples_random = [round(random.uniform(950, 1050), 2) for _ in range(1000)]

with open('pressure_samples.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)

    for sample in pressure_samples_random:
        writer.writerow([sample])

