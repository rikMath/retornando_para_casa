import matplotlib
import matplotlib.pyplot as plt
import numpy as np


labels = ['100', '500', '1000', '5000', '10000', '50000', '100000', '200000']
insertion = [0.000023, 0.000131, 0.000447, 0.008616, 0.023343, 0.545155, 3.060924, 10.415637]
comb = [0.000032, 0.000142, 0.000337, 0.001975, 0.004413, 0.014834, 0.034159, 0.157906]
heap = [0.000041, 0.000164, 0.000337, 0.002006, 0.004325, 0.01343, 0.030235, 0.073013]
quick = [0.00003, 0.000107, 0.000204, 0.001059, 0.002144, 0.006042, 0.01265, 0.02849]
modified_quick = [0.000032, 0.000106, 0.000205, 0.00106, 0.002158, 0.00606, 0.01253, 0.027748]


x = np.arange(len(labels))
width = 0.35

fig, ax = plt.subplots()

ax.bar(x - width, comb, width/2, label='Comb Sort')
ax.bar(x-width/2, heap, width/2, label='Heap Sort')
ax.bar(x, quick, width/2, label='Quick Sort')
ax.bar(x + width/2, modified_quick, width/2, label='Modified Quick Sort')

# ax.bar(x - width, insertion, width/3, label='Insertion Sort')
# ax.bar(x-2*width/3, comb, width/3, label='Comb Sort')
# ax.bar(x-width/3, heap, width/3, label='Heap Sort')
# ax.bar(x, quick, width/3, label='Quick Sort')
# ax.bar(x + width/3, modified_quick, width/3, label='Modified Quick Sort')

ax.set_ylabel('Tempo de execução em segundos')
ax.set_xlabel('Tamanho do arquivo de entrada')
ax.set_title('Dados decrescentes')
ax.set_xticks(x)
ax.set_xticklabels(labels)
ax.legend()


fig.tight_layout()

plt.show()
