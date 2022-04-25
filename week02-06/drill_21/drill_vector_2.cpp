//Drill_21_vector_2

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>

template<typename C>
void print(const C& c, char sep='\n'){
    std::cout << "Container elements:\n";

    for(const auto elem : c){
        std::cout << elem << sep;
    }

    std::cout << std::endl;
}

class Less_than{
    double v;
    public:
        Less_than(double vv) : v{vv} {}
        bool operator()(const double val) {return val < v;}
};

int main(){
    try{
        const std::string iname {"input2.txt"};
        std::ifstream ifs {iname};
        if(!ifs) throw std::runtime_error("could not read file " + iname);

        std::vector<double> vd;

        for(double d; ifs >> d;){
            vd.push_back(d);
        }

        print(vd);

        std::vector<int> vi (vd.size());
        std::copy(vd.begin(), vd.end(), vi.begin());
        /*for(auto& d : vd){
            vi.push_back(d);
        }*/

        print(vi);

        for(int i = 0; i < vd.size(); i++){
            std::cout << vd[i] << "\t\t" << vi[i] << std::endl;
        }

        double vd_sum = std::accumulate(vd.begin(), vd.end(), 0.0);
        double vi_sum = std::accumulate(vi.begin(), vi.end(), 0.0);
        double diff = 0;
        if(vd_sum >= vi_sum)
            diff = vd_sum - vi_sum;
        else
            diff = vi_sum - vd_sum;

        std::cout << "\nsum of vd: " << vd_sum << " | sum of vi: " << vi_sum << " | diff: " << diff << std::endl << std::endl;

        std::reverse(vd.begin(), vd.end());
        print(vd);

        double vd_mean = vd_sum / vd.size();
        std::cout << "Mean value of vd: " << vd_mean << std::endl;

        std::vector<double> vd2;
        for(auto& v : vd){
            if(v < vd_mean)
                vd2.push_back(v);
        }

        /*copy_if
        std::vector<double> vd2 (vd.size());
        auto it = std::copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(vd_mean));
        vd2.resize(std::distance(vd2.begin(), it));*/
        
        print(vd2);


        std::sort(vd.begin(), vd.end());
        print(vd);


    } catch(std::exception& e){
        std::cout << e.what() << std::endl;
        return 1;
    } catch(...){
        std::cout << "unknown error" << std::endl;
        return 2;
    }
}