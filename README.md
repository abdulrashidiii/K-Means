# K-Means
My C++ implementation of Lloyd's algorithm K-Means clustering

A short python script utilizing scikit-learn is included for comparison of compute times. <br>

## Benchmark of computation times compared with scikit-learn

| Implementation | 100k x 5 matrix | ~1M x 5 matrix |
| -------------- | --------------- | -------------- |
| C++ (vector)   | 2.5396 seconds  | 25.0443 seconds |
| Python (sklearn) | 3.396 seconds | 23.030 seconds |

Present implementation does not scale well with large data.

## Future:
Next thing to do is reimplement using the Eigen library and vectorize some operations.
