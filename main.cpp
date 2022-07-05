#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
    std::string url = "http://httpbin.org/html";
    cpr::Response r = cpr::Get(cpr::Url(url), cpr::Header({{"accept", "text/html"}}));

    int start = r.text.find("<h1>") + 4;
    int end = r.text.find("</h1>");
    std::cout << r.text.substr(start, end - start) << std::endl;
}
