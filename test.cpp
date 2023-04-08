#include <iostream>
#include <map>
#include <algorithm>
#include <boost/thread.hpp>

int main(){
    std::cout << "hello world" << std::endl;

    std::map<int, std::shared_ptr<std::string>> mapIntToStrPtr;
    mapIntToStrPtr[0] = std::make_shared<std::string>("Zero");
    mapIntToStrPtr[1] = std::make_shared<std::string>("One");

    for (auto it = mapIntToStrPtr.begin(); it != mapIntToStrPtr.end(); ++it){
        std::cout << it->first << "\t" << *(it->second) << std::endl;
    }

    std::for_each(mapIntToStrPtr.begin(), mapIntToStrPtr.end(), [](std::pair<int, std::shared_ptr<std::string>> kvp){
        std::cout << kvp.first << "\t" << *(kvp.second) << std::endl;
    });
    
    auto t1 = std::make_shared<boost::thread>([](){
        for (int i = 0 ; i < 5 ; ++i){
            std::cout << "From thread: " << i << std::endl;
        }
    });
    t1->join();
    std::cout << "end thread" << std::endl;
}