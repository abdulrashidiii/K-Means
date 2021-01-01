from sklearn.cluster import KMeans
import numpy as np

data = np.loadtxt('test_data.csv', delimiter=',')

kmeans = KMeans(n_clusters=5, max_iter=100, n_jobs=1)
kmeans.fit(data)
np.savetxt('py_labels.dat', kmeans.labels_)
