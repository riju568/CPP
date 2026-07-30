#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>
#include <exception>
#include <cstdlib>

/**
 * **10.25 (New string split method) The split method in the String class returns an
 * array of strings consisting of the substrings split by the delimiters. However, the
 * delimiters are not returned. Implement the following new method that returns
 * an array of strings consisting of the substrings split by the matching delimiters,
 * including the matching delimiters.
  * <p>
 * public static String[] split(String s, String regex)
 * For example, split("ab#12#453", "#") returns ab, #, 12, #, 453 in an
 * array of String, and split("a?b?gf#e", "[?#]") returns a, b, ?, b, gf,
 * #, and e in an array of String.
 */
static std::vector<std::string> split(const std::string &s, const std::string &regex_str)
{
    if (regex_str.empty())
    {
        return {s};
    }

    std::vector<std::string> tokens;
    std::regex reg(regex_str);
    auto words_begin = std::sregex_iterator(s.begin(), s.end(), reg);
    auto words_end = std::sregex_iterator();
    std::size_t last_pos = 0;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        const std::smatch &match = *i;
        std::size_t match_pos = match.position();
        std::size_t match_len = match.length();
        if (match_pos > last_pos)
        {
            tokens.push_back(s.substr(last_pos, match_pos - last_pos));
        }
        tokens.push_back(match.str());
        last_pos = match_pos + match_len;
    }

    if (last_pos < s.length())
    {
        tokens.push_back(s.substr(last_pos));
    }

    return tokens;
}
static void print_vector(const std::vector<std::string> &vec)
{
    std::cout << "[";
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "\"" << vec[i] << "\"" << (i + 1 < vec.size() ? ", " : "");
    }
    std::cout << "]\n";
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::string s1 = "ab#12#453";
        std::string regex1 = "#";
        std::string s2 = "a?b?gf#e";
        std::string regex2 = "[?#]";
        std::cout << "split(\"ab#12#453\", \"#\"): ";
        print_vector(split(s1, regex1));
        std::cout << "split(\"a?b?gf#e\", \"[?#]\"): ";
        print_vector(split(s2, regex2));
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
}