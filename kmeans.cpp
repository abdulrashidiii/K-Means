#ifndef KMEANS_H_
#define KMEANS_H_

#include "kmeans.hpp"

// class constructor
kMeans::kMeans(string csv_fname, unsigned int K, unsigned int n_iter)
{
  K = K;
  n_iter = n_iter;

  ReadCSV(csv_fname);

  for(unsigned int i=0; i<K; i++)
  {
    centroids.push_back(Random(n_col));
  }

  Run(&data, &K, &n_iter);
  WriteOutput();
}

// read data from a CSV file
void kMeans::ReadCSV(string csv_fname)
{
  ifstream infile;
  infile.open(csv_fname);
  string line;

  if(!infile)
  {
    cout << "Error: Unable to open csv file." << endl;
    exit(1);
  }

  while(getline(infile, line))
  {
    stringstream ss(line);
    string buff;

    point point_i;

    while(getline(ss, buff, ','))
    {
      point_i.coords.push_back(stod(buff));
    }
    data.push_back(point_i);
    n_row = data.size();
    n_col = point_i.coords.size();
  }
}

void kMeans::Run(vector<point>* data, unsigned int* K, unsigned int* n_iter)
{
  int n = data->size();

  for(unsigned int iter=0; iter<*n_iter; iter++)
  {
    // Calculate distance from centroid and assign cluster
    for(unsigned int i=0; i<*K; i++)
    {
      int clusterID = i;
  
      for(vector<point>::iterator j = data->begin(); j != data->end(); j++)
      {
        double dist = Distance(j->coords, centroids[i]);
        if(dist < j->centroid_dist)
        {
          j->centroid_dist = dist;
          j->cluster = clusterID;
        }
      }
    }
  
    vector<int> n_points;
    vector<vector<double>> sums;
  
    for(unsigned int i=0; i<*K; i++)
    {
      n_points.push_back(0);
      vector<double> sum_i;
      for(unsigned int j=0; j<n_col; j++)
      {
        sum_i.push_back(0.0);
      }
      sums.push_back(sum_i);
    }
  
    // Calculate new centroid from the cluster assignments
    for(vector<point>::iterator i = data->begin(); i != data->end(); i++)
    {
      n_points[i->cluster] += 1;
      for(unsigned int j=0; j<n_col; j++)
      {
        sums[i->cluster][j] += i->coords[j];
      }
      i->centroid_dist = __DBL_MAX__;
    }
  
    for(unsigned int i=0; i<*K; i++)
    {
      for(unsigned int j=0; j<n_col; j++)
      {
        centroids[i][j] = sums[i][j] / n_points[i];
      }
    }
  }
}

// random number generator
vector<double> kMeans::Random(unsigned int n_col)
{
  static random_device seed;
  mt19937 generator(seed());
  uniform_real_distribution<double> dis(0.0, 1.0);
  vector<double> rand;
  for(unsigned int i=0; i<n_col; i++)
  {
    rand.push_back(dis(generator));
  }
  return rand;
}

// distance formula
double kMeans::Distance(vector<double> a, vector<double> b)
{
  if(a.size() == b.size())
  {
    int length = a.size();
    float sum=0;
    for(unsigned int i=0; i<length; i++)
    {
      sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
  }
  else
  {
    cout << "Vector Error" << endl;
    exit(1);
  }
}

void kMeans::WriteOutput(void)
{
  out_fname = "cpp_labels.dat";
  output.open(out_fname);
  for(vector<point>::iterator i=data.begin(); i!=data.end(); i++)
  {
    output << i->cluster << endl;
  }
}

#endif
