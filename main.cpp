#include <iostream>
#include <string>
#include <vector>
#include <cpr/cpr.h>

bool post_request(const std::string query, const std::vector<cpr::Pair> &args){
    cpr::Url url = cpr::Url{"http://www.httpbin.org/" + query};
    if(query == "get"){
        cpr::Response r = cpr::Get(url, args);
        std::cout << r.text << std::endl;
    } else if(query == "post"){
        cpr::Response r = cpr::Post(url, cpr::Payload(args.begin(), args.end()));
        std::cout << r.text << std::endl;
    }


};


int main(int, char**){
    std::cout << "Hello, from 30_3_queries_with_arguments!\n";

    
    std::string key, value;
    
    std::vector<cpr::Pair> param;
    
    std::cout << "Enter some names of arguments and its value and type of request(get/post)." << std::endl;
    std::cout << "Type a name: ";
    std::cin >> key;

    while(key != "get" || key != "post"){
        std::cout << "Type a value: ";
        std::cin >> value;
        param.emplace_back(cpr::Pair(key,value));
        std::cout << "Type a name: ";
        std::cin >> key;
    }

 
    return 0;
}


/* 
#include <iostream>
#include <map>
#include <vector>
#include <initializer_list>
#include <cpr/cpr.h>

void GETRequest(const std::map<std::string, std::string>&);
void POSTRequest(const std::map<std::string, std::string>&);

using namespace std;

int main()
{
    map<string, string> args;
    string arg;
    getline(cin, arg);

    while(arg != "get" && arg != "post")
    {
        string value;
        getline(cin, value);
        args.insert(pair(arg, value));
        getline(cin, arg);
    }

    if(arg == "get")
    {
        GETRequest(args);
    }else if(arg == "post")
    {
        POSTRequest(args);
    }

    return 0;
}

void GETRequest(const map<string, string> &args)
{
    string serviceName = "http://httpbin.org/get?";

    for(auto it = args.begin(); it != args.end(); ++it)
        serviceName += it->first + "=" + it->second + "&";

    serviceName = serviceName.substr(0, serviceName.length()-1);
    auto responce = cpr::Get(cpr::Url(serviceName)).text;

    cout << responce << endl;
}

void POSTRequest(const map<string, string> &args)
{
    vector<cpr::Pair> pairs;
    for(auto it = args.begin(); it != args.end(); ++it, ++i)
    {
        cpr::Pair pair(it->first, it->second);
        pairs.push_back(pair);
    }

    auto responce = cpr::Post(cpr::Url("http://httpbin.org/post"),
                              cpr::Payload(pairs.begin(), pairs.end())).text;

    cout << responce << endl;
}*/