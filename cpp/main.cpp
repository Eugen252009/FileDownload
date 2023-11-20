#include <curl/curl.h>
#include <fstream>
#include <iostream>
#include <string>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                            void *userp) {
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

int main(void) {
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL,
                     "https://lupricht.net/picture.jpg");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    std::ofstream myfile;

    // Open the file
    myfile.open("picture.jpg");

    // Check if the file is successfully opened
    if (!myfile.is_open()) {
      std::cerr << "Error opening file!" << std::endl;
      return 1; // Return an error code
    }
    myfile << readBuffer;
    myfile.close();
  }
  return 0;
}
