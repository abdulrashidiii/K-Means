#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <random>
#include <chrono>

using namespace std;

struct point
{
  vector<double> coords; // N-dimensional coordinates of the point
  int cluster = -1; // cluster assignment, initially assigned no cluster
  double centroid_dist = __DBL_MAX__; // distance to the nearest cluster
};

class kMeans
{
  protected:
    void ReadCSV(string);
    void Run(vector<point>* data, unsigned int*, unsigned int*);
    vector<double> Random(unsigned int);
    double Distance(vector<double>, vector<double>);
    unsigned int n_row=0;
    unsigned int n_col=0;
    void WriteOutput(void);
    ofstream output; 
    string out_fname;

  public:
    unsigned int K;
    unsigned int n_iter;
    vector<point> data;
    vector<vector<double>> centroids;
    kMeans(string, unsigned int, unsigned int);
};
