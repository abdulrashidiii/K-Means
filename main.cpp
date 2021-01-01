#include "kmeans.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
  string csv_name;
  unsigned int K, n_iter;

  if(argc != 4)
  {
    cerr << "Usage: " << argv[0] << " \"csv file\" " << "k " << "n_iter" << endl;
    exit(1);
  }
  else
  {
    csv_name = argv[1];
    K = stoul(argv[2]);
    n_iter = stoul(argv[3]);
    kMeans test(csv_name, K, n_iter);
  }
}
