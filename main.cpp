#include <iostream>
#include <string>
#include <vector>
#include <cpr/cpr.h>

void request(const std::string query, const std::vector<cpr::Pair> &args){

    if(query == "get"){
        std::string parameters = "?";

        for(int i = 0; i < args.size(); ++i){
            parameters += args[i].key + "=" + args[i].value;
          
            if(i != args.size()) parameters += "&";
        }

        cpr::Url url = cpr::Url{"http://www.httpbin.org/" + query + parameters};
        cpr::Response r = cpr::Get(url);

        std::cout << r.text << std::endl;
    } else if(query == "post"){
        cpr::Url url = cpr::Url{"http://www.httpbin.org/" + query};
        cpr::Response r = cpr::Post(url, cpr::Payload(args.begin(), args.end()));
        std::cout << r.text << std::endl;
    }
};


int main(int, char**){
    std::cout << "Hello, from 30_3_queries_with_arguments!\n";

    
    std::string key, value;
    
    std::vector<cpr::Pair> args;
    
    std::cout << "Enter some names of arguments and its value and type of request(get/post)." << std::endl;
    std::cout << "Type a name: ";
    std::cin >> key;

    while(key != "get" && key != "post"){
        std::cout << "Type a value: ";
        std::cin >> value;
        args.emplace_back(cpr::Pair(key,value));
        std::cout << "Type a name: ";
        std::cin >> key;
    }

    request(key, args);

    return 0;
}
