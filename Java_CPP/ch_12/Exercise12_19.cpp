#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <cstdlib>
#include <curl/curl.h>


class CurlGlobalGuard
{
public:
    CurlGlobalGuard()
    {
        if (curl_global_init(CURL_GLOBAL_DEFAULT) != CURLE_OK)
        {
            throw std::runtime_error("Failed to initialize global cURL environment.");
        }
    }

    ~CurlGlobalGuard()
    {
        curl_global_cleanup();
    }
    CurlGlobalGuard(const CurlGlobalGuard&) = delete;
    CurlGlobalGuard& operator=(const CurlGlobalGuard&) = delete;
};
static std::size_t write_data_callback(void* contents, std::size_t size, std::size_t nmemb, void* userp)
{
    const std::size_t total_size = size * nmemb;
    std::string* buffer = static_cast<std::string*>(userp);
    buffer->append(static_cast<const char*>(contents), total_size);
    return total_size;
}
std::string fetch_url_content(const std::string& url)
{
    CURL* curl = curl_easy_init();
    if (!curl)
    {
        throw std::runtime_error("Failed to create cURL handle.");
    }
    std::string response_buffer;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_buffer);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Follow HTTP 301/302 redirects
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 15L);        // 15-second timeout
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);     // Treat HTTP >= 400 as errors
    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl); 

    if (res != CURLE_OK)
    {
        throw std::runtime_error(std::string("cURL transfer failed: ") + curl_easy_strerror(res));
    }
    return response_buffer;
}
std::size_t count_words(const std::string& text)
{
    std::istringstream stream(text);
    std::string word;
    std::size_t word_count = 0;

    while (stream >> word)
    {
        word_count++;
    }
    return word_count;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        CurlGlobalGuard curl_guard;
        const std::string url = "http://se.cs.depaul.edu/Java/Chapter04/Lincoln.txt";
        std::cout << "Fetching Gettysburg Address from " << url << "...\n";
        std::string content = fetch_url_content(url);
        std::size_t total_words = count_words(content);
        std::cout << "Number of words in the Gettysburg Address is " << total_words << ".\n";
        return EXIT_SUCCESS;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}