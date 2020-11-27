#include <iostream>
#include <string>


std::string parenthesed_text_removed(std::string text) {
    for (std::string::size_type count = 0, pos = text.find('('); pos != std::string::npos; pos = text.find('(', pos)) {
        for (std::string::size_type i = pos + 1; i != text.length(); ++i) {
            if (text[i] == '(') {
                ++count;
            }
            else if (text[i] == ')') {
                if (count != 0) {
                    --count;
                }
                else {
                    text.erase(pos, i - pos + 1);
                    break;
                }
            }
        }
    }

    return text;
}


int main() {
    std::string text;
    std::getline(std::cin, text);
    std::cout << parenthesed_text_removed(text) << std::endl;
}